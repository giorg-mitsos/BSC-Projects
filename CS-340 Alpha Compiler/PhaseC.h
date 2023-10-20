/*
    Author: Giwrgos Mitsos 3660
*/

#include "HeaderB.h"

#define EXPAND_SIZE 1024
#define CURR_SIZE (total*sizeof(quad))
#define NEW_SIZE  (EXPAND_SIZE*sizeof(quad) + CURR_SIZE)



typedef enum{   
                        assign,       add,            sub,
                        mul,          ddiv,           mod,
                        uminus,       aand,           oor,
                        nnot,         if_eq,          if_noteq,
                        if_lesseq,    if_greatereq,   if_less,
                        if_greater,   call,           param,
                        ret,          getretval,      funcstart,
                        funcend,      tablecreate,    tablegetelem,
                        tablesetelem, jump,           nop,
                        _exit
            }iopcode;

typedef enum expr_t{
                var_e,
                tableitem_e,

                programfunc_e,
                libraryfunc_e,

                arithexpr_e,
                boolexpr_e,
                assignexpr_e,
                newtable_e,

                constnum_e,
                constbool_e,
                const_string_e,

                nil_e
           }expr_t;


typedef struct expr{
    expr_t  type;
    struct SymbolList *sym;
    struct expr* index;
    double numConst;
    char* strConst;
    unsigned char boolConst;
    struct expr* next;
    struct expr *prev;
    struct expr* nextIndexed;
    struct labelList* trueList;
    struct labelList* falseList;
}expr;

typedef struct{
    iopcode op;
    expr* result;
    expr* arg1;
    expr* arg2;
    unsigned label;
    unsigned line;
    unsigned taddress;
}quad;

struct funcCall{
    struct expr *elist;
    unsigned int method;
    char* funcName;
};

typedef struct labelList{
    int quadLabel;
    struct labelList* next; 
}labelList;

quad* quads = (quad*)0;
unsigned total = 0;
unsigned currQuad = 0;

int _funcTempIDCounter =0;
struct expr *_tempExpr[20] = {NULL};
int _tempExprCounter = 0;

expr *NewConstNumExpr(double d);






void Patch(int quad,int toJump){
    quads[quad].result = NewConstNumExpr(toJump);
    return;
}

void BackPatch(labelList *list, int toJump){
    labelList *temp = list;
    while(temp!=NULL){
        Patch(temp->quadLabel,toJump);
        temp=temp->next;
    }

    return;

}

labelList *NewLabelList(int quad){
    labelList *newNode = (labelList*)malloc(sizeof(labelList));
    newNode->quadLabel = quad;
    newNode->next = NULL;
    return newNode;
}

labelList* Merge(labelList* l1, labelList* l2){
    labelList *merged = l1;
    if(merged!=NULL){
        while(l1->next!=NULL){
            l1 = l1->next;
        }
        if(l2!=NULL)l1->next=l2;
        return merged;
    }
}

char* NewTemporaryID(){
    int currentID = ScopeExists(_currentScope)->temporaryIDcounter++;
    char newIDnum[5];
    sprintf(newIDnum,"%d",currentID);
    char *newID=(char *)malloc(sizeof(char)*10);
    strcpy(newID,"^t");
    strcat(newID,newIDnum);
    return newID;
}


struct SymbolList *NewTemporarySymbol(){
    char *tmpname = NewTemporaryID();
    InsertToSymbolList(Local_Variable,tmpname,_currentScope,linecounter,currScopeSpace);
    return SearchSymbolInListInScope(tmpname,_currentScope);
}

char* NewTemporaryFuncID(){
    char newIDnum[5];
    sprintf(newIDnum,"%d",_funcTempIDCounter++);
    char *newID=(char *)malloc(sizeof(char)*10);
    strcpy(newID,"^f");
    strcat(newID,newIDnum);
    return newID;
}

struct SymbolList *NewTemporaryFuncSymbol(){
    char *tmpname = NewTemporaryFuncID();
    InsertToSymbolList(User_Function,tmpname,_currentScope,linecounter,currScopeSpace);
    return SearchSymbolInListInScope(tmpname,_currentScope);
}

unsigned int IsTempName(char* s){
    return (*s == '^');
}

unsigned int IsTempExpr(expr *e){
    return (e->sym && (e->sym->typeOfSymbol==Local_Variable || e->sym->typeOfSymbol==Global_Variable) &&IsTempName(e->sym->nameOfSymbol));
}

void Expand(){
    if(total==currQuad){
        quad *p = (quad*)malloc(NEW_SIZE);
        if(quads){
            memcpy(p,quads,CURR_SIZE);
            free(quads);
        }
        quads = p;
        total+=EXPAND_SIZE;
    }
}

void Emit(iopcode op, struct expr* result, struct expr* arg1, struct expr* arg2, unsigned label, unsigned line){
    if(currQuad == total)Expand();
    quad *newQuad = quads+currQuad++;
    newQuad->arg1 = arg1;
    newQuad->arg2 = arg2;
    newQuad->label = label;
    newQuad->line = line;
    newQuad->op = op;
    newQuad->result = result;
    newQuad->taddress = 0;
}

struct expr* NewExpr(expr_t t){
    struct expr* e = (expr *)malloc(sizeof(expr));
    memset(e,0,sizeof(expr));
    e->type = t;
    return e;
}

struct expr* NewAExpr(expr_t t,struct SymbolList *symbol){
    assert(symbol);
    struct expr *e = (expr*)malloc(sizeof(expr));

    e->next = (expr*)0;
    e->sym = symbol;
    if(symbol->typeOfSymbol == Library_Function || symbol->typeOfSymbol == User_Function){
        switch(symbol->typeOfSymbol){
            case Library_Function : e->type = libraryfunc_e; break;
            case User_Function : e->type = programfunc_e; break;
            default : assert(0);
        }
        e->strConst = strdup(symbol->nameOfSymbol);
    }
    else{
        e->type = t;
        e->strConst = strdup(symbol->nameOfSymbol);
    }
    return e;
}

struct expr* ReverseElist(expr* elis){
    struct expr* prev = NULL;
    struct expr* curr = elis;
    struct expr* next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    elis = prev;
    return elis;

}

struct expr* NewlvalueExpr(struct SymbolList *symbol){
    assert(symbol);
    struct expr *e = (expr*)malloc(sizeof(expr));
    memset(e,0,sizeof(expr));

    e->next = (expr*)0;
    e->sym = symbol;
    e->strConst = strdup(symbol->nameOfSymbol);

    if(symbol->typeOfSymbol == Library_Function || symbol->typeOfSymbol == User_Function){
        if(symbol->typeOfSymbol == Library_Function)e=NewAExpr(libraryfunc_e,symbol);
        else e=NewAExpr(programfunc_e,symbol);
    }
    else{
        e=NewAExpr(var_e,symbol);
    }
    
    //printf("\n\n%s\n\n",e->type);
    
    return e;
    
}

struct expr* NewConstNumExpr(double num){
    struct expr* e = (struct expr*)malloc(sizeof(struct expr));
    e->type = constnum_e;
    e->numConst = num;
    return e;
}

struct expr* NewConstStringExpr(const char *str){
    struct expr* e = (struct expr*)malloc(sizeof(struct expr));
    e->type = const_string_e;
    e->strConst = strdup(str);
    return e;
}

struct expr* NewConstBoolExpr(unsigned char c){
    struct expr* e = (struct expr*)malloc(sizeof(struct expr));
    e->type = constbool_e;
    e->boolConst = c;
    return e;
}

struct expr* NewConstNilExpr(){
    struct expr* e = (struct expr*)malloc(sizeof(struct expr));
    e->type = nil_e;
    e->boolConst = 'f';
    e->strConst = "NULL";
    e->numConst =0;
    return e;
}

struct expr* EmitIfTableItem(expr* e){
    if (e->type != tableitem_e)return e;
    else{
        struct expr *result = NewAExpr(var_e,NewTemporarySymbol());
        Emit(tablegetelem,result,e,e->index,currQuad,linecounter);
        return result;
    }
}



struct expr* MemberItem(expr *lval, const char *name){
    printf("HELLO MEMBERITEM\n");
    lval = EmitIfTableItem(lval);
    struct expr* item = NewAExpr(tableitem_e,lval->sym);
    item->index = NewConstStringExpr(name);
    printf("HELLO MEMBERITEM2\n");
    return item;
}



struct expr* NewUminusExpr(expr *oldEx){
    if(oldEx->type == var_e || 
        oldEx->type == tableitem_e || 
        oldEx->type == arithexpr_e || 
        oldEx->type == assignexpr_e || 
        oldEx->type== constnum_e){
        expr* e = (expr*)malloc(sizeof(expr));
        e->type = arithexpr_e;
        e->strConst = strdup(oldEx->sym->nameOfSymbol);
        return e;
    }
    else{
        Error("Illegal expr to unary -");
        exit(1);
    }
}

struct expr* MakeCall(expr* lval, expr* elist){
    struct expr* func = EmitIfTableItem(lval);
    struct expr* temp = elist;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Emit(call,func,NULL,NULL,currQuad,linecounter);
    expr* res=NewAExpr(var_e,NewTemporarySymbol());
    Emit(getretval,res,NULL,NULL,currQuad,linecounter);
}

const char *IopcodeToString(iopcode op){
    if(op == assign)return "ASSIGN       ";
    else if(op == add)return "ADD          ";
    else if(op == sub)return "SUB          ";
    else if(op == mul)return "MUL          ";
    else if(op == ddiv)return "DIV          ";
    else if(op == mod)return "MOD          ";
    else if(op == uminus)return "UMINUS       ";
    else if(op == aand)return "AND          ";
    else if(op == oor)return "OR           ";
    else if(op == nnot)return "NOT          ";
    else if(op == if_eq)return "IF_EQ        ";
    else if(op == if_noteq)return "IF_NOTEQ     ";
    else if(op == if_lesseq)return "IF_LESSEQ    ";
    else if(op == if_greatereq)return "IF_GREATEREQ ";
    else if(op == if_less)return "IF_LESS      ";
    else if(op == if_greater)return "IF_GREATER   ";
    else if(op == call)return "CALL         ";
    else if(op == param)return "PARAM        ";
    else if(op == ret)return "RET          ";
    else if(op == getretval)return "GETRETVAL    ";
    else if(op == funcstart)return "FUNCSTART    ";
    else if(op == funcend)return "FUNCEND      ";
    else if(op == tablecreate)return "TABLECREATE  ";
    else if(op == tablegetelem)return "TABLEGETELEM ";
    else if(op == tablesetelem)return "TABLESETELEM ";
    else if(op == jump)return "JUMP        ";
    else if(op == nop)return  "NOP         ";
    else if(op == _exit)return "EXIT        ";
    else return "UNDEFINED   ";
}

const char *ExprIDToString(expr *e){

    if(e == NULL)return" ";
    if(e->type == nil_e) return "NULL";
    else if(e->type == constnum_e){
        char number[30];
        int isInteger = (int)e->numConst;
        if(isInteger == e->numConst)sprintf(number,"%.0f",e->numConst);
        else sprintf(number,"%.3f",e->numConst);
        return strdup(number);
    }
    else if(e->type == constbool_e){
        if(e->boolConst =='t')return "TRUE";
        else return "FALSE";
    }
    else return e->strConst;
}

void PrintQuad(int i){
    printf("*%d:\t",i);
    printf("%s",IopcodeToString(quads[i].op));
    if(quads[i].arg1!=NULL && quads[i].arg1->type == boolexpr_e && quads[i].arg2==NULL && quads[i].op == assign && quads[i].result!=NULL && quads[i].result->type == boolexpr_e)printf("%5s\t",quads[i].result->strConst);
    else printf("%5s\t",ExprIDToString(quads[i].result));
    printf("%s\t",ExprIDToString(quads[i].arg1));
    printf("%s\t*\n",ExprIDToString(quads[i].arg2));
}

void PrintQuads(){
    printf("\e[35m");
    printf("*************************************************\n");
    printf("*                     Quads                     *\n");
    printf("*************************************************\n");
    int i =0;
    while(i<currQuad){
        PrintQuad(i);
        i++;
    }
    printf("*************************************************\n");
    printf("Label\tOpcode\t      Result\tArg1\tArg2\n");
    printf("\e[0m");
}

void StmtReset(){
    temporaryID = NULL;
    ScopeExists(_currentScope)->temporaryIDcounter =0;
}