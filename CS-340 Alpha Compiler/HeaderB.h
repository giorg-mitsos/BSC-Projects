/*
    Author: Giwrgos Mitsos 3660
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define _isArray 0
#define _isFunction 1
#define _isFormalArgs 2
#define _isLoop 3


int yyerror(const char* yaccProvidedMessage);
int yylex(void);

extern int linecounter;
extern char *yytext;
extern FILE* yyin;

int _currentScope=0;

/* Flag Map */
int _flag[10] = {0, // _isArray 
                 0, // _isFunction - it is > 0 when inside ... func f(...here...}
                 0, // _isFormalArgs - it is > 0 when inside ... func f(...here...)
                 0, // _isLoop - it is one when inside loops
                 0,
                 0,
                 0,
                 0,
                 0,
                 0};


/* Each "Symbol" is one type of enum */
typedef enum SymbolType{Library_Function, User_Function, Local_Variable, Global_Variable, Formal_Argument}SymbolType_t;
typedef enum ScopeSpace{programVar,functionVar,formalArg}ScopeSpace_t;

ScopeSpace_t currScopeSpace = programVar;
int ScopeSpaceOffset[3]={0,0,0}; /*
                                    0 -> programVar
                                    1 -> functionVar
                                    2 -> formalArg
                                 */


/*
    liveOfSymbol -> 0: Symbol is not active
                 -> 1: Symbol is active
                 -> -1 : Special Operation if needed 

    lineOfSymbol -> x: Symbol declared in line x

    nameOfSymbol ->  : Symbol's name

    typeOfSymbol -> enum

    nextSymbol   -> A pointer to the next Symbol in this SymbolList of this ScopeList 
*/
struct SymbolList{
    int liveOfSymbol;
    int lineOfSymbol;
    int scopeOfSymbol;
    char* nameOfSymbol;
    enum SymbolType typeOfSymbol;
    struct SymbolList *nextSymbol;
    ScopeSpace_t symbolScopeSpace;
    unsigned int scopeSpaceOffset;
};
/* Shows current symbol in scope list, renews every time i get a symbol through IDENTIFIER. Helps for calling variables as functions etc. */
struct SymbolList *temporaryID = NULL; 

/*
    scope -> x : Symbol declared and is active in scope x

    headOfSymbolList -> A pointer to the first Symbol of SymbolList of current ScopeList

    nextScope -> A pointer to the next scope in this ScopeList

*/
struct ScopeList{
    int scope;
    int temporaryIDcounter;
    struct SymbolList *headOfSymbolList;
    struct ScopeList *nextScope;
};

/* Pointer to the head of ScopeList (scope = 0) */
struct ScopeList *_headOfScopeList=NULL;

/* Function Definitions */
struct ScopeList *ScopeExists(int scopeToLookFor);
void GenerateScope(int scopeToGenerate);
const char* TypeOfSymbolToString(SymbolType_t type);
int IsLibraryFunction(const char *givenName);
void InitLibraryFunctions();
void PrintSymbolTable(int err);
int InsertToSymbolList(SymbolType_t type,char *name, int scope, int line,ScopeSpace_t space);
struct SymbolList *SearchSymbolInListInScope(const char *name, int scope);
//void KillScope(int scope);



unsigned int ScopeSpaceToInt(ScopeSpace_t space){
    switch(space){
        case programVar: return 0;
        case functionVar: return 1;
        case formalArg: return 2;
    }
}

/* Returns ScopeList node of the given scopeToLookFor if exists, or NULL if does not */
struct ScopeList *ScopeExists(int scopeToLookFor){
    struct ScopeList *temp = _headOfScopeList;
    while(temp!=NULL){
        if (temp->scope == scopeToLookFor) return temp;
        temp = temp->nextScope;
    }
    return NULL;
}

/* Generate a new Scope Node and insert it sorted */
void GenerateScope(int scopeToGenerate){
    if (ScopeExists(scopeToGenerate)==NULL){
        struct ScopeList* newScopeNode = (struct ScopeList*)malloc(sizeof(struct ScopeList));
        newScopeNode->headOfSymbolList = NULL;
        newScopeNode->nextScope=NULL;
        newScopeNode->scope = scopeToGenerate;
        newScopeNode->temporaryIDcounter =0;
        if ( (_headOfScopeList == NULL) || (_headOfScopeList->scope > scopeToGenerate)){
            newScopeNode->nextScope = _headOfScopeList;
            _headOfScopeList = newScopeNode;
        }
        else{
            struct ScopeList *temp = _headOfScopeList;
            while ( (temp->nextScope!=NULL) && (temp->nextScope->scope < newScopeNode->scope) ){
                temp = temp->nextScope;
            }
            newScopeNode->nextScope = temp->nextScope;
            temp->nextScope = newScopeNode;
        }
        return;
    }
    else return;
}

/* Return the enum SymbolType in string format */
const char* TypeOfSymbolToString(SymbolType_t type){
    switch (type){
    case Library_Function: return "Library_Function";
    case User_Function:    return "User_Function";
    case Local_Variable:   return "Local_Variable";
    case Global_Variable:  return "Global_Variable";
    case Formal_Argument:  return "Formal_Argument";
    default: return "UNDEFINED";
    }
}

/* Search if the givenName is a Library Function. Returns 1 if it is, 0 if not */
int IsLibraryFunction(const char *givenName){
    if (_headOfScopeList == NULL) return 0;
    struct SymbolList *temp = _headOfScopeList->headOfSymbolList;
    while(temp!=NULL){
        if (strcmp(givenName,temp->nameOfSymbol)==0){
            if (temp->typeOfSymbol == Library_Function)return 1;
        }
        temp=temp->nextSymbol;
    }
    return 0;
}

/* Insert the Library Funtions */
void InitLibraryFunctions(){
    InsertToSymbolList(Library_Function,"print",0,0,programVar);
    InsertToSymbolList(Library_Function,"input",0,0,programVar);
    InsertToSymbolList(Library_Function,"objectmemberkeys",0,0,programVar);
    InsertToSymbolList(Library_Function,"objecttotalmembers",0,0,programVar);
    InsertToSymbolList(Library_Function,"objectcopy",0,0,programVar);
    InsertToSymbolList(Library_Function,"totalarguments",0,0,programVar);
    InsertToSymbolList(Library_Function,"argument",0,0,programVar);
    InsertToSymbolList(Library_Function,"typeof",0,0,programVar);
    InsertToSymbolList(Library_Function,"strtonum",0,0,programVar);
    InsertToSymbolList(Library_Function,"sqrt",0,0,programVar);
    InsertToSymbolList(Library_Function,"cos",0,0,programVar);
    InsertToSymbolList(Library_Function,"sin",0,0,programVar);
}

/* Print the Symbol Table */
void PrintSymbolTable(int err){
    switch (err){
    case 1: printf("\x1B[31m\n"); break;
    default: printf("\x1B[32m\n");
    }
    printf("<---------------------------------- Symbol Table ---------------------------------->\n");
    struct ScopeList *slist = _headOfScopeList;
    struct SymbolList *sylist = NULL;
    while(slist!=NULL){
        sylist = slist->headOfSymbolList;
        printf("<------------------------------------ Scope: %d ------------------------------------>\n",slist->scope);
        while(sylist!=NULL){
            printf("|[%s]\t\"%s\",\tline: %d,\t scope: %d,\t isAlive: %d|\n",TypeOfSymbolToString(sylist->typeOfSymbol),sylist->nameOfSymbol,sylist->lineOfSymbol,slist->scope,sylist->liveOfSymbol);
            printf("NEW FEATURE: ScopeSpace: %d, ScopeSpaceOffset: %d\n",ScopeSpaceToInt(sylist->symbolScopeSpace),sylist->scopeSpaceOffset);
            sylist=sylist->nextSymbol;
        }
        slist=slist->nextScope;
    }
    printf("<------------------------------- End Of Symbol Table ------------------------------>\n");
    printf("[Type]\t\"name\",\tline,\tscope,\t isAlive\n");
    printf("\x1B[0m\n");
}

/* Insert the Symbol in the Table */
int InsertToSymbolList(SymbolType_t type,char *name, int scope, int line,ScopeSpace_t space){
    //int Success = 0;
    if(IsLibraryFunction(name))return 0;
    else{
        if (ScopeExists(scope)==NULL){
            GenerateScope(scope);
            struct ScopeList* scopeList = ScopeExists(scope);
            struct SymbolList* newNode = (struct SymbolList*)malloc(sizeof(struct SymbolList));
            newNode->scopeOfSymbol = scope;
            newNode->lineOfSymbol = line;
            newNode->liveOfSymbol = 1;
            newNode->nameOfSymbol = strdup(name);
            newNode->nextSymbol = NULL;
            newNode->typeOfSymbol = type;
            newNode->symbolScopeSpace = space;
            if(type!=Library_Function)newNode->scopeSpaceOffset = ScopeSpaceOffset[ScopeSpaceToInt(space)]++;
            scopeList->headOfSymbolList = newNode;
        }
        else{
            struct ScopeList* scopeList = ScopeExists(scope);
            struct SymbolList* newNode = (struct SymbolList*)malloc(sizeof(struct SymbolList));
            newNode->scopeOfSymbol = scope;
            newNode->lineOfSymbol = line;
            newNode->liveOfSymbol = 1;
            newNode->nameOfSymbol = strdup(name);
            newNode->nextSymbol = NULL;
            newNode->typeOfSymbol = type;
            newNode->symbolScopeSpace = space;
            if(type!=Library_Function)newNode->scopeSpaceOffset = ScopeSpaceOffset[ScopeSpaceToInt(space)]++;
            if(scopeList->headOfSymbolList == NULL){
                scopeList->headOfSymbolList = newNode;
            }
            else{
                struct SymbolList* temp = scopeList->headOfSymbolList;
                while (temp->nextSymbol!=NULL){
                    temp=temp->nextSymbol;
                }
                temp->nextSymbol = newNode;
            } 
        }
    }
    return 1;
}

/* Hide the Symbols in the given Scope */
void KillScope(int scope){
    if (ScopeExists(scope)!=NULL){
        struct SymbolList *temp = ScopeExists(scope)->headOfSymbolList;
        while(temp!=NULL){
            temp->liveOfSymbol = 0;
            temp=temp->nextSymbol;
        }
    }
    else return;
}

/* LookUp for Symbol in whole List (reverse) */
struct SymbolList *SearchSymbolInList(const char* givenName){
    struct ScopeList *sliststart = _headOfScopeList;
    if(sliststart==NULL)return NULL;
    else{
        struct SymbolList *symbol;
        int scope = _currentScope;
        while(scope >=0){
            symbol = SearchSymbolInListInScope(givenName,scope);
            if (symbol!=NULL)return symbol;
            else{
                scope--;
            }
        }
        return symbol;

    }
   /* if(_headOfScopeList==NULL)return NULL;
    else{
        struct ScopeList *slist = _headOfScopeList;
        struct SymbolList *sylist = NULL;
        while(slist!=NULL){
            sylist = slist->headOfSymbolList;
            while(sylist!=NULL){
                if ( (sylist->liveOfSymbol == 1) && ( strcmp(givenName,sylist->nameOfSymbol)==0) ) return sylist;
                sylist = sylist->nextSymbol;
            }
            slist = slist->nextScope;
        }
        return NULL;
    }
*/
}

/* LookUp for Symbol in a given Scope */
struct SymbolList *SearchSymbolInListInScope(const char* givenName, int scope){
    struct ScopeList *slist = ScopeExists(scope);
    if (slist == NULL) return NULL;
    else{
        struct SymbolList *sylist = slist->headOfSymbolList;
        while(sylist!=NULL){
            if ( (sylist->liveOfSymbol == 1) && (strcmp(givenName,sylist->nameOfSymbol) == 0) ) return sylist;
            sylist = sylist->nextSymbol;
        }
        return NULL;
    }
}

/* Returns Scope of Symbol or -1 if Symbol does not exist / is hidden */
int ScopeOfSymbol(const char* givenName){
    struct SymbolList *temp = SearchSymbolInList(givenName);
    if(temp!=NULL)return temp->scopeOfSymbol;
    else return -1;
}


int yyerror(const char* yaccProvidedMessage){
    //PrintSymbolTable(1);
    fprintf(stderr, "\x1B[31m\n%s: at line %d, before token: %s\x1B[0m\n\n",yaccProvidedMessage,linecounter,yytext);
    //printf("Failure in syntax, printed every Symbol until failure.\n");
    //exit(1);
}

int isValidAccess(struct SymbolList* toBeAccessed){
    /* Access funtion */
    if(toBeAccessed->typeOfSymbol==Library_Function || toBeAccessed->typeOfSymbol==User_Function)return 1;
    /* Access Global_Variable */
    else if(toBeAccessed->typeOfSymbol == Global_Variable) return 1;
    else{
        /* Cant access variable between functions */
        if(_flag[_isFunction]>0 && toBeAccessed->scopeOfSymbol<_currentScope) return 0; 
    }
    return 1;
}


void Error(const char *err){
    yyerror(err);
}