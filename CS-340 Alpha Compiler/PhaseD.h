/*
    Author: Giwrgos Mitsos 3660
*/
#include "PhaseC.h"

#define EXPAND_I_SIZE 4
#define CURR_I_SIZE (totalInstructions*sizeof(instruction))
#define NEW_I_SIZE  (EXPAND_I_SIZE*sizeof(instruction) + CURR_I_SIZE)



typedef enum vmargu{
    label_a = 0,
    global_a = 1, 
    formal_a = 2,
    local_a = 3,
    number_a = 4,
    string_a =5,
    bool_a = 6,
    nil_a = 7,
    userfunc_a = 8,
    libfunc_a = 9,
    retval_a = 10
}vmarg_t;

typedef enum{
    assign_v,   add_v,  sub_v,                  //0, 1, 2
    mul_v,      div_v,  mod_v,                  //3, 4, 5
    uminus_v,   and_v,  or_v,                   //6, 7, 8
    not_v,      jeq_v,  jne_v,                  //9, 10, 11
    jle_v,      jge_v,  jlt_v,                  //12, 13, 14
    jgt_v,      call_v, pusharg_v,              //15, 16, 17
    funcenter_v,    funcexit_v, newtable_v,     //18, 19, 20
    tablegetelem_v, tablesetelem_v, nop_v,      //21, 22, 23
    exit_v                                      //24
}vmpcode;


typedef struct vmarg{
    vmarg_t type;
    unsigned val;
}vmarg;



typedef struct{
    vmpcode opcode;
    struct vmarg result;
    struct vmarg arg1;
    struct vmarg arg2;
    unsigned srcLine;
}instruction;

instruction* instructions = (instruction*)0;
unsigned totalInstructions = 0;
unsigned currInstruction = 0;

void expandInstructions(){
    //printf("DEBUG3.1.1\n");
    if(totalInstructions == currInstruction){
       // printf("%d",NEW_I_SIZE);
       // printf("DEBUG3.1.2\n");
        instruction* i = (instruction*)malloc(NEW_I_SIZE);
       // printf("DEBUG3.1.3\n");
        if(instructions){
           // printf("DEBUG3.1.4\n");
            memcpy(i,instructions,CURR_I_SIZE);
           // printf("DEBUG3.1.5\n");
            free(instructions);
           // printf("DEBUG3.1.6\n");
        }
        instructions = i;
       // printf("DEBUG3.1.7\n");
        totalInstructions+=EXPAND_I_SIZE;
       // printf("DEBUG3.1.8\n");
    }
}

void emitIns(instruction i){
   // printf("DEBUG3.1\n");
    if(currInstruction == totalInstructions)expandInstructions();
   // printf("DEBUG3.2\n");
    instruction *newIns = instructions+currInstruction++;
   // printf("DEBUG3.3\n");
    newIns->opcode = i.opcode;
    newIns->result = i.result;
    newIns->arg1 = i.arg1;
    newIns->arg2 = i.arg2;
    newIns->srcLine = i.srcLine;
   /* printf("Opcode: %d\n",i.opcode);
        printf("\tResult: Type = %d, Value = %d\n",i.result.type,i.result.val);
        printf("\tArg1: Type = %d, Value = %d\n",i.arg1.type,i.arg1.val);
        printf("\tArg2: Type = %d, Value = %d\n",i.arg2.type,i.arg2.val);*/
    
}

struct userfunc{
    unsigned address;
    unsigned localSize;
    char* id;
};

typedef struct userfunc userfunc;


double* numConsts;
unsigned totalNumConsts=0;
char** stringConsts;
unsigned totalStringConsts=0;
char** namedLibfuncs;
unsigned totalNamedLibfuncs=0;
struct userfunc *userFuncs;
unsigned totalUserFuncs=0;


unsigned const_newstring(char* s){
    char **newConStr = (char**)malloc(sizeof(char*)*(totalStringConsts+1));
    if(totalStringConsts){
        memcpy(newConStr,stringConsts,sizeof(char*)*(totalStringConsts+1));
        free(stringConsts);
    }
    stringConsts = newConStr;
    stringConsts[totalStringConsts] = strdup(s);
    return totalStringConsts++;
}

unsigned const_newnumber(double n){
    double *newConNum = (double*)malloc(sizeof(double)*(totalNumConsts+1));
    if(totalNumConsts){
        memcpy(newConNum, numConsts, sizeof(double)*(totalNumConsts+1));
        free(numConsts);
    }
    numConsts = newConNum;
    numConsts[totalNumConsts++] = n;
    return totalNumConsts-1;
}

unsigned libfuncs_newused(char* s){
    char **newConLib = (char**)malloc(sizeof(char**)*(totalNamedLibfuncs+1));
    if(totalNamedLibfuncs){
        memcpy(newConLib, namedLibfuncs,sizeof(char**)*(totalNamedLibfuncs+1));
        free(namedLibfuncs);
    }
    namedLibfuncs = newConLib;
    namedLibfuncs[totalNamedLibfuncs] = strdup(s); 
    return totalNamedLibfuncs++;
}

unsigned userfuncs_newfunc(struct SymbolList *sym){
    /*char **newConUser = (char**)malloc(sizeof(char**)*(totalUserFuncs+1));
    if(totalUserFuncs){
        memcpy(newConUser, userFuncs,sizeof(char**)*(totalUserFuncs+1));
        free(userFuncs);
    }
    userFuncs = newConUser;
    userFuncs[totalNamedLibfuncs] = strdup(sym->nameOfSymbol); 
    return totalNamedLibfuncs++;*/
}

void make_operand(expr *e,vmarg *arg);

typedef void (*generator_func_t)(quad*);

void generate(vmpcode op, quad *q){
    instruction i;
    i.opcode = op;
    i.srcLine = q->line;
    if(q->result)make_operand(q->result,&i.result);
    if(q->arg1)make_operand(q->arg1,&i.arg1);
    if(q->arg2)make_operand(q->arg2,&i.arg2);
   /* printf("Opcode: %d\n",i.opcode);
        printf("\tResult: Type = %d, Value = %d\n",i.result.type,i.result.val);
        printf("\tArg1: Type = %d, Value = %d\n",i.arg1.type,i.arg1.val);
        printf("\tArg2: Type = %d, Value = %d\n",i.arg2.type,i.arg2.val);*/
    emitIns(i);
}

void generate_relational(vmpcode op, quad q){}

void generate_ASSIGN(quad *q){generate(assign_v,q);}

void generate_ADD(quad *q){generate(add_v,q);}
void generate_SUB(quad *q){generate(sub_v,q);}
void generate_MUL(quad *q){generate(mul_v,q);}
void generate_DIV(quad *q){generate(div_v,q);}
void generate_MOD(quad *q){generate(mod_v,q);}
void generate_UMINUS(quad *q){generate(mul_v,q);}

void generate_AND(quad *q){}
void generate_OR(quad *q){}
void generate_NOT(quad *q){}

void generate_IF_EQ(quad *q){}
void generate_IF_NOTEQ(quad *q){}
void generate_IF_LESSEQ(quad *q){}
void generate_IF_GREATEREQ(quad *q){}
void generate_IF_LESS(quad *q){}
void generate_IF_GREATER(quad *q){}

void generate_CALL(quad *q){generate(call_v,q);}
void generate_PARAM(quad *q){generate(pusharg_v,q);}
void generate_RETURN(quad *q){}
void generate_GETRETVAL(quad *q){
    q->taddress = currInstruction;
    instruction t;
    t.opcode = assign_v;
    make_operand(q->result,&t.result);
    t.result.type = retval_a;
    t.arg1.type = retval_a;
    emitIns(t);
}

void generate_FUNCSTART(quad *q){}
void generate_FUNCEND(quad *q){}

void generate_NEWTABLE(quad *q){generate(newtable_v,q);}
void generate_TABLEGETELEM(quad *q){generate(tablegetelem_v,q);}
void generate_TABLESETELEM(quad *q){generate(tablesetelem_v,q);}

void generate_JUMP(quad *q){}
void generate_NOP(quad *q){}
void generate_EXIT(quad *q){}
/*assign_v,   add_v,  sub_v,                  //0, 1, 2
    mul_v,      div_v,  mod_v,                  //3, 4, 5
    uminus_v,   and_v,  or_v,                   //6, 7, 8
    not_v,      jeq_v,  jne_v,                  //9, 10, 11
    jle_v,      jge_v,  jlt_v,                  //12, 13, 14
    jgt_v,      call_v, pusharg_v,              //15, 16, 17
    funcenter_v,    funcexit_v, newtable_v,     //18, 19, 20
    tablegetelem_v, tablesetelem_v, nop_v,      //21, 22, 23
    exit_v  
*/
generator_func_t generators[]={
    generate_ASSIGN,

    generate_ADD,
    generate_SUB,
    generate_MUL,
    generate_DIV,
    generate_MOD,
    generate_UMINUS,

    generate_AND,
    generate_OR,
    generate_NOT,

    generate_IF_EQ,
    generate_IF_NOTEQ,
    generate_IF_LESSEQ,
    generate_IF_GREATEREQ,
    generate_IF_LESS,
    generate_IF_GREATER,

    generate_CALL,
    generate_PARAM,
    generate_RETURN,
    generate_GETRETVAL,

    generate_FUNCSTART,
    generate_FUNCEND,

    generate_NEWTABLE,
    generate_TABLEGETELEM,
    generate_TABLESETELEM,

    generate_JUMP,
    generate_NOP,
    generate_EXIT
};

void generateTargetCode(){
    int i =0;
    while(i<currQuad){
        (*generators[quads[i].op])(quads+i);
        i++;
    }
}

                /*     IN,       OUT   */
void make_operand(expr *e,vmarg *arg){
    //printf("%d\n",e->type);
    switch(e->type){
        case var_e:
        case tableitem_e:
        case arithexpr_e: 
        case boolexpr_e: 
        case assignexpr_e: 
        case newtable_e:{
            arg->val = e->sym->scopeSpaceOffset;
            switch(e->sym->symbolScopeSpace){
                case programVar: arg->type = global_a; break;
                case functionVar: arg->type = local_a; break;
                case formalArg:  arg->type = formal_a; break;
            }
            break;
        }
        case constbool_e:{
            if(e->boolConst=='f')arg->val=0;
            else arg->val = 1;
            arg->type = bool_a;
            break;
        }
        case const_string_e: {
            arg->val = const_newstring(e->strConst);
            arg->type = string_a;
            break;
        }
        case constnum_e:{
            arg->val = const_newnumber(e->numConst);
            arg->type = number_a;
            break;
        }
        case nil_e:{
            arg->type = nil_a;
            break;
        }
        case programfunc_e:{
            arg->type = userfunc_a;
            // arg->val = e->quad->taddress;
            break;
        }
        case libraryfunc_e:{
            arg->type = libfunc_a;
            arg->val = libfuncs_newused(e->sym->nameOfSymbol);
            break;
        }
        default: assert(0); break;
    }
}

int isValidVmarg(vmarg arg){
    if((int)arg.type>-1 && (int)arg.type<11){
        return 1;
    }
    return 0;
}

void printInstructions(){
    int i=0;
    while(i<currInstruction){
        //printf("%d\n",instructions[i++].opcode);
    }
}

void Binary(){
    FILE *binw;
    FILE *norm; 
    printf("Generating Binary File...\n");
    binw=fopen("out.abc","wb");
    norm=fopen("out.txt","w");
    if (!binw || !norm){
        printf("Error accessing out.abc, and out.txt. (May need deletion)\n");
        exit(1);
    }
    //Print MagicNumber
    unsigned magicNumber = 13373660;
    fprintf(norm,"magicNumber: %d\n",magicNumber);
    fwrite(&magicNumber,sizeof(magicNumber),1,binw);

    //Print array types and size of arrays
    fprintf(norm,"Arrays:\tstringConsts,\tnumConsts,\tnamedLibfuncs,\tuserFuncs\n");
    fprintf(norm,"number of stringConsts: %d\nnumber of numConsts: %d\nnumber of namedLibfuncs: %d\nnumber of userFuncs: %d\nnumber of globals: %d\n",totalStringConsts,totalNumConsts,totalNamedLibfuncs,totalUserFuncs,ScopeSpaceOffset[0]);
    fwrite(&totalStringConsts,sizeof(totalStringConsts),1,binw);
    fwrite(&totalNumConsts,sizeof(totalNumConsts),1,binw);
    fwrite(&totalNamedLibfuncs,sizeof(totalNamedLibfuncs),1,binw);
    fwrite(&totalUserFuncs,sizeof(totalUserFuncs),1,binw);
    fwrite(&ScopeSpaceOffset[0],sizeof(int),1,binw);

    //Print array values

    //Print strConsts
    int i=0;
    unsigned strSize=0;
    fprintf(norm,"stringConsts:\n");
    while(i<totalStringConsts){
        fprintf(norm,"\tIndex: %d, Value: %s\n",i,stringConsts[i]);

        strSize = strlen(stringConsts[i])+1;
        fwrite(&strSize,sizeof(strSize),1,binw);
        fwrite(stringConsts[i],strSize,1,binw);
        i++;
    }

    //Print numConsts
    i =0;
    fprintf(norm,"numConsts:\n");
    while(i<totalNumConsts){
        fprintf(norm,"\tIndex: %d, Value: %f\n",i,numConsts[i]);
        fwrite(&numConsts[i],sizeof(numConsts[i]),1,binw);
        i++;
    }

    //Print namedLibfuncs
    i =0;
    fprintf(norm,"namedLibfuncs:\n");
    while(i<totalNamedLibfuncs){
        fprintf(norm,"\tIndex: %d, Value: %s",i,namedLibfuncs[i]);

        strSize = strlen(namedLibfuncs[i])+1;
        fwrite(&strSize,sizeof(strSize),1,binw);
        fwrite(namedLibfuncs[i],strSize,1,binw);
        i++;
    }

    /*
    //Print userFuncs
    i =0;
    fprintf(norm,"userFuncs:\n");
    while(i<totalUserFuncs){
        fprintf(norm,"Index: %d, Value: %s",i,userFuncs[i]);

        strSize = strlen(userFuncs[i])+1;
        fwrite(&strSize,sizeof(strSize),1,binw);
        fwrite(userFuncs[i],strSize,1,binw);
    }
    */

    //Print Number of Instructions and instructions
    fprintf(norm,"\nNumber Of Instructions: %d\n",currInstruction);
    fwrite(&currInstruction,sizeof(currInstruction),1,binw);
    fprintf(norm,"\nInstructions:\n\n");
    i=0;
    while(i<currInstruction){
        fprintf(norm,"Opcode: %d\n",instructions[i].opcode);
        fwrite(&instructions[i].opcode,sizeof(vmpcode),1,binw);
        fprintf(norm,"\tResult:\n\t\tType:%d\n\t\tValue:%d\n\n",instructions[i].result.type,instructions[i].result.val);
        fwrite(&instructions[i].result.type,sizeof(int),1,binw);
        fwrite(&instructions[i].result.val,sizeof(unsigned),1,binw);

        printf("\e[36m");
        printf("Opcode: %d\n",instructions[i].opcode);
        printf("\tResult: Type = %d, Value = %d\n",instructions[i].result.type,instructions[i].result.val);
        if(isValidVmarg(instructions[i].arg1))printf("\tArg1: Type = %d, Value = %d\n",instructions[i].arg1.type,instructions[i].arg1.val);
        else printf("\tArg1:\n");
        if(isValidVmarg(instructions[i].arg2))printf("\tArg2: Type = %d, Value = %d\n",instructions[i].arg2.type,instructions[i].arg2.val);
        else printf("\tArg2:\n");
        printf("\e[0m");

        int Valid = isValidVmarg(instructions[i].arg1);
        int ignoreArg = 100;
        if(Valid){
            fprintf(norm,"\tArg1:\n\t\tType:%d\n\t\tValue:%d\n\n",instructions[i].arg1.type,instructions[i].arg1.val);
            fwrite(&instructions[i].arg1.type,sizeof(int),1,binw);
            fwrite(&instructions[i].arg1.val,sizeof(unsigned),1,binw);
        }
        else{    
            fprintf(norm,"\tArg1:\n\n");
            fwrite(&ignoreArg,sizeof(int),1,binw);
        }

        Valid = isValidVmarg(instructions[i].arg2);
        if(Valid){
            fprintf(norm,"\tArg2:\n\t\tType:%d\n\t\tValue:%d\n\n",instructions[i].arg2.type,instructions[i].arg2.val);
            fwrite(&instructions[i].arg2.type,sizeof(int),1,binw);
            fwrite(&instructions[i].arg2.val,sizeof(unsigned),1,binw);
        }
        else{    
            fprintf(norm,"\tArg2:\n\n");
            fwrite(&ignoreArg,sizeof(int),1,binw);
        }
        

        i++;
    }
    



    fclose(binw);
    fclose(norm);
}