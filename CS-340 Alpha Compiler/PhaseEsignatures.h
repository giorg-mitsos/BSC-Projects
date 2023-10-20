#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include <math.h>

#define AVM_STACKSIZE 4096
#define AVM_WIPEOUT(m) memset(&(m), 0, sizeof(m))
#define AVM_TABLE_HASHSIZE 211
#define AVM_STACKENV_SIZE 4
#define AVM_MAX_INSTRUCTIONS (unsigned)nop_v
#define AVM_ENDING_PC codeSize
#define AVM_NUMACTUALS_OFFSET +4
#define AVM_SAVEDPC_OFFSET +3
#define AVM_SAVEDTOP_OFFSET +2
#define AVM_SAVEDTOPSP_OFFSET +1

#define execute_add execute_arithmetic
#define execute_sub execute_arithmetic
#define execute_div execute_arithmetic
#define execute_mod execute_arithmetic
#define execute_mul execute_arithmetic


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


//instruction
typedef struct{
    vmpcode opcode;
    struct vmarg result;
    struct vmarg arg1;
    struct vmarg arg2;
    unsigned srcLine;
}instruction;

instruction *instructions = (instruction*)0;
instruction* code = (instruction*)0;

//avm_memcell_t
typedef enum{
    number_m =0,
    string_m =1,
    bool_m   =2,
    table_m  =3,
    userfunc_m = 4,
    libfunc_m = 5,
    nil_m = 6,
    undef_m = 7
}avm_memcell_t;

//userfunc
typedef struct userfunc{
    unsigned address;
    unsigned localSize;
    char* id;
}userfunc;


struct avm_table;

//avm_memcell
typedef struct avm_memcell_s{
    avm_memcell_t type;
    union{
        double numVal;
        char* strVal;
        unsigned char boolVal;
        struct avm_table *tableVal;
        unsigned funcVal;
        char *libfuncVal;
    }data;
}avm_memcell;


//avm_table_bucket
typedef struct avm_table_bucket{
    avm_memcell key;
    avm_memcell value;
    struct avm_table_bucket* next;
}avm_table_bucket;

//avm_table
typedef struct avm_table{
    unsigned refCounter;
    avm_table_bucket* strIndexed[AVM_TABLE_HASHSIZE];
    avm_table_bucket* numIndexed[AVM_TABLE_HASHSIZE];
    unsigned total;
}avm_table;

char* typeStrings[]={"number","string","boolean","table","userfunc","libfunc","nil","undef"};

avm_memcell stack[AVM_STACKSIZE];


int avm_error(char* format,...); //ok

int avm_warning(char* format, ...); //ok

static void avm_initstack(void); //ok

avm_memcell* avm_translate_operand(vmarg* arg, avm_memcell* reg); //ok

void avm_tableincrefcounter(avm_table* t); // ok

void avm_tablebucketsinit(avm_table_bucket** p); //ok

avm_table* avm_tablenew(void); // ok

double consts_getnumber(unsigned index); // ok

char*  consts_getstring(unsigned index); //ok

char*  libfuncs_getused(unsigned index); //ok

void avm_memcellclear(avm_memcell *m); //ok

void avm_tablebucketdestroy(avm_table_bucket** p); //ok

void avm_tabledestroy(avm_table* t); //ok

void avm_tabledecrefcounter(avm_table* t); //ok

void avm_assign(avm_memcell* lv, avm_memcell* rv); //ok

void avm_dec_top(void); //ok

void avm_push_envvalue(unsigned val); //ok

void avm_callsaveenvironment(void); //ok

userfunc* getfuncinfo(unsigned address); //ok

unsigned avm_get_envvalue(unsigned i); //ok

//START libraryfunc dispatcher
typedef void (*library_func_t)(void); 

void libfunc_print(void); //ok
void libfunc_typeof(void); //ok
void libfunc_totalarguments(void); //ok
void libfunc_sin(void); //ok
double sina(double y){
    return sin(y);
}
void libfunc_cos(void); //ok
double cosa(double y){
    return cos(y);
}

library_func_t namedLibrary[12]={
    libfunc_print,
    libfunc_typeof,
    libfunc_totalarguments,
    libfunc_sin,
    libfunc_cos
};


library_func_t avm_getlibraryfunc(char *id); // ok

void avm_calllibfunc(char *id); //ok

unsigned avm_totalactuals(void); //ok

avm_memcell* avm_getactual(unsigned i); //ok

avm_memcell* avm_tablegetelem(avm_table* table, avm_memcell* index); //TODO

void avm_tablesetelem(avm_table* table, avm_memcell* index, avm_memcell* content); //TODO


void avm_registerlibfunc(char *id, library_func_t addr); //TODO

//START ToString Dispatcher 
typedef char* (*tostring_func_t)(avm_memcell*);


char* number_tostring(avm_memcell*);    //ok
char* string_tostring(avm_memcell*);    //ok
char* bool_tostring(avm_memcell*);  //ok
char* table_tostring(avm_memcell*); //ok
char* userfunc_tostring(avm_memcell*);  //ok
char* libfunc_tostring(avm_memcell*);   //ok
char* nil_tostring(avm_memcell*);   //ok
char* undef_tostring(avm_memcell*); //ok

tostring_func_t tostringFuncs[]={
    number_tostring,
    string_tostring,
    bool_tostring,
    table_tostring,
    userfunc_tostring,
    libfunc_tostring,
    nil_tostring,
    undef_tostring
};

char* avm_tostring(avm_memcell* m); //ok
//END ToString Dispatcher

//START execute arithmetic dispatcher
typedef double (*arithmetic_func_t)(double x, double y);

double add_impl(double x, double y); //ok
double sub_impl(double x, double y); //ok
double mul_impl(double x, double y); //ok
double div_impl(double x, double y); //ok
double mod_impl(double x, double y); //ok

arithmetic_func_t arithmeticFuncs[]={
    add_impl,
    sub_impl,
    mul_impl,
    div_impl,
    mod_impl
};

void execute_arithmetic(instruction* instr); //ok
//END arithmetic dispatcher

//START tobool Dispatcher
typedef unsigned char (*tobool_func_t)(avm_memcell*);

unsigned char number_tobool(avm_memcell* m); //ok
unsigned char string_tobool(avm_memcell* m); //ok
unsigned char bool_tobool(avm_memcell* m); //ok
unsigned char table_tobool(avm_memcell* m); //ok
unsigned char userfunc_tobool(avm_memcell* m); //ok
unsigned char libfunc_tobool(avm_memcell* m); //ok
unsigned char nil_tobool(avm_memcell* m); //ok
unsigned char undef_tobool(avm_memcell* m); //ok

tobool_func_t toboolFuncs[]={
    number_tobool,
    string_tobool,
    bool_tobool,
    table_tobool,
    userfunc_tobool,
    libfunc_tobool,
    nil_tobool,
    undef_tobool
};

unsigned char avm_tobool (avm_memcell* m); //ok



//START execute dispatcher
typedef void (*execute_func_t)(instruction*);

void execute_assign(instruction *i); //ok
void execute_add(instruction *i);   //ok (arithdispatcher)
void execute_sub(instruction *i);   //ok (arithdispatcher)
void execute_mul(instruction *i);   //ok (arithdispatcher)
void execute_div(instruction *i);   //ok (arithdispatcher)
void execute_mod(instruction *i);   //ok (arithdispatcher)
void execute_uminus(instruction *i);    //TODO
void execute_and(instruction *i);   //TODO
void execute_or(instruction *i);    //TODO
void execute_not(instruction *i);   //TODO
void execute_jeq(instruction *i);   //ok
void execute_jne(instruction *i);   //TODO
void execute_jle(instruction *i);   //TODO
void execute_jge(instruction *i);   //TODO
void execute_jlt(instruction *i);   //TODO
void execute_jgt(instruction *i);   //TODO
void execute_call(instruction *i);  //ok
void execute_pusharg(instruction *i); //ok
void execute_funcenter(instruction *i); //ok
void execute_funcexit(instruction *i); //ok
void execute_newtable(instruction *i); //ok
void execute_tablegetelem(instruction *in); //ok
void execute_tablesetelem(instruction *in); //ok
void execute_nop(instruction *i); //TODO

execute_func_t executeFuncs[]={
    execute_assign,
    execute_add,
    execute_sub,
    execute_mul,
    execute_div,
    execute_mod,
    execute_uminus,
    execute_and,
    execute_or,
    execute_not,
    execute_jeq,
    execute_jne,
    execute_jle,
    execute_jge,
    execute_jlt,
    execute_jgt,
    execute_call,
    execute_pusharg,
    execute_funcenter,
    execute_funcexit,
    execute_newtable,
    execute_tablegetelem,
    execute_tablesetelem,
    execute_nop
};
//END execute dispatcher

void execute_cycle(void); //ok

//START memclear dispatcher
typedef void (*memclear_func_t)(avm_memcell*);

void memclear_string(avm_memcell* m); // ok
void memclear_table(avm_memcell* m); //ok

memclear_func_t memclearFuncs[]={
    0,  //number
    memclear_string,
    0,  //bool
    memclear_table,
    0,  //userfunc
    0,  //libfunc
    0,  //nil
    0   //undef
};
//END memclear dispatcher

void avm_initialize(); //ok

void exec(); //ok

void decode(FILE *f); //ok






unsigned magicNumber = 13373660;
unsigned totalStringConsts, totalNumConsts, totalNamedLibfuncs, totalUserFuncs, totalGlobals, totalInstructions;
double *numConsts;
char** stringConsts;
char** namedLibfuncs;
userfunc* userFuncs;

unsigned top, topsp;
avm_memcell ax,bx,cx;
avm_memcell retval;

unsigned char executionFinished =0;
unsigned pc =0;
unsigned currLine =0;
unsigned codeSize =0;


unsigned totalActuals =0;
