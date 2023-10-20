#include "PhaseEsignatures.h"


void printInstr(instruction *i){
    printf("Opcde: %d\n",i->opcode);
    printf("\tResult:\n\t\tType: %d\n\t\tVal: %d\n",i->result.type,i->result.val);
    printf("\tArg1:\n\t\tType: %d\n\t\tVal: %d\n",i->arg1.type,i->arg1.val);
    printf("\tArg2:\n\t\tType: %d\n\t\tVal: %d\n",i->arg2.type,i->arg2.val);
}


static void avm_initstack(void){
    unsigned i;
    for(i=0; i<AVM_STACKSIZE; i++){
        AVM_WIPEOUT(stack[i]);
        stack[i].type = undef_m;
    }
}



void avm_tableincrefcounter(avm_table* t){
    ++t->refCounter;
}

void avm_tablebucketsinit(avm_table_bucket** p){
    unsigned i;
    for(i=0; i<AVM_TABLE_HASHSIZE; ++i){
        p[i] =(avm_table_bucket*)0;
    }
}

avm_table* avm_tablenew(void){
    avm_table* t = (avm_table*)malloc(sizeof(avm_table));
    AVM_WIPEOUT(*t);
    t->refCounter = t->total=0;
    avm_tablebucketsinit(t->numIndexed);
    avm_tablebucketsinit(t->strIndexed);
    return t;
}

double consts_getnumber(unsigned index){
    return numConsts[index];
}
char*  consts_getstring(unsigned index){
    return strdup(stringConsts[index]);
}
char*  libfuncs_getused(unsigned index){
    return strdup(namedLibfuncs[index]);
}

void avm_memcellclear(avm_memcell *m){
    if(m->type!=undef_m){
        memclear_func_t f = memclearFuncs[m->type];
        if(f)
            (*f)(m);
        m->type = undef_m;
    }
}

void avm_tablebucketdestroy(avm_table_bucket** p){
    unsigned i;
    avm_table_bucket* b;
    for(i =0; i<AVM_TABLE_HASHSIZE; ++i, ++p){
        for (b = *p; b;){
            avm_table_bucket* del =b;
            b = b->next;
            avm_memcellclear(&del->key);
            avm_memcellclear(&del->value);
        }
        p[i] = (avm_table_bucket*)0;
    }
}

void avm_tabledestroy(avm_table* t){
    avm_tablebucketdestroy(t->strIndexed);
    avm_tablebucketdestroy(t->numIndexed);
}

void avm_tabledecrefcounter(avm_table* t){
    assert(t->refCounter>0);
    if(--t->refCounter)avm_tabledestroy(t);


}

int avm_warning(char *format, ...){
    va_list argptr;             

   va_start( argptr, format );          

   while( *format != '\0' ) {
     // string
     if( *format == 's' ) {
       char* s = va_arg( argptr, char * );
       printf("%s",s);
     }
     // character
     else if( *format == 'c' ) {
       char c = (char) va_arg( argptr, int );
       printf("%c",c);
       break;
     }
     // integer
     else if( *format == 'd' ) {
       int d = va_arg( argptr, int );
       printf("%d",d);
     }          

     *format++;
   }            

   va_end( argptr );
}

void avm_assign(avm_memcell* lv, avm_memcell* rv){
    if(lv==rv)return;
    if(lv->type == table_m &&
        rv->type == table_m &&
        lv->data.tableVal == rv->data.tableVal)return;
    
    if(rv->type == undef_m)avm_warning("s","Assigning from 'undef' content!");

    avm_memcellclear(lv);
    memcpy(lv,rv,sizeof(avm_memcell));

    if(lv->type==string_m){
        lv->data.strVal = strdup(rv->data.strVal);
    }
    else if(lv->type == table_m){
        avm_tableincrefcounter(lv->data.tableVal);
    }
}

void avm_dec_top(void){
    if(!top){
        //stack overflow
        executionFinished =1;
    }
    else{
        --top;
    }
}

void avm_push_envvalue(unsigned val){

    stack[top].type = number_m;
    stack[top].data.numVal = val;
    avm_dec_top();
}

void avm_callsaveenvironment(void){
    avm_push_envvalue(totalActuals);
    avm_push_envvalue(pc+1);
    avm_push_envvalue(top + totalActuals + 2);
    avm_push_envvalue(topsp);
}

userfunc* getfuncinfo(unsigned address){
    return &userFuncs[address];
}

unsigned avm_get_envvalue(unsigned i){
    assert(stack[i].type == number_m);
    unsigned val= (unsigned)stack[i].data.numVal;
    assert(stack[i].data.numVal == ((double)val));
    return val;
}

int avm_error(char *format, ...){
    va_list argptr;             

   va_start( argptr, format );          

   while( *format != '\0' ) {
     // string
     if( *format == 's' ) {
       char* s = va_arg( argptr, char * );
       printf("%s",s);
     }
     // character
     else if( *format == 'c' ) {
       char c = (char) va_arg( argptr, int );
       printf("%c",c);
       break;
     }
     // integer
     else if( *format == 'd' ) {
       int d = va_arg( argptr, int );
       printf("%d",d);
     }          

     *format++;
   }            

   va_end( argptr );
    executionFinished =1;
    return 1;
}

library_func_t avm_getlibraryfunc(char *id){
    if(strcmp("print",id)==0)return namedLibrary[0];
    else if(strcmp("typeof",id)==0) return namedLibrary[1];
    else if(strcmp("totalarguments",id)==0) return namedLibrary[2];
    else if(strcmp("sin",id)==0) return namedLibrary[3];
    else if(strcmp("cos",id)==0) return namedLibrary[4];
    else{
        return NULL;
    }
}

void avm_calllibfunc(char *id){
    library_func_t f = avm_getlibraryfunc(id);
    if(!f){
        avm_error("sss","Unsupported lib func '",id,"' called!");
    }
    else{
        topsp = top;
        totalActuals = 0;
        (*f)();
        if(!executionFinished){
            execute_funcexit((instruction*)0);
        }
    }
}

unsigned avm_totalactuals(void){
    return avm_get_envvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell* avm_getactual(unsigned i){
    assert(i<avm_totalactuals());
    return &stack[topsp + AVM_STACKENV_SIZE + 1 + i];
}

void libfunc_print(void){
    unsigned n = avm_totalactuals();
    unsigned i;
    printf("\e[33m");
    for (i =0; i<n; ++i){
        char *s = avm_tostring(avm_getactual(i));
        printf("%s",s);
        //free(s);
    }
    printf("\e[0m");
}

void libfunc_typeof(void){
    unsigned n = avm_totalactuals();

    if(n!=1){
        avm_error("sds","one argument (not ",n,") expected in 'typeof'!");
    }
    else{
        avm_memcellclear(&retval);
        retval.type = string_m;
        retval.data.strVal = strdup(typeStrings[avm_getactual(0)->type]);
    }
}

void libfunc_totalarguments(void){
    unsigned p_topsp = avm_get_envvalue(topsp+ AVM_SAVEDTOPSP_OFFSET);
    avm_memcellclear(&retval);

    if(!p_topsp){
        avm_error("s","'totalarguments' called outside of a function!");
        retval.type = nil_m;
    }
    else{
        retval.type = number_m;
        retval.data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
    }
}

void libfunc_sin(void){
    unsigned p_topsp = avm_get_envvalue(topsp+ AVM_SAVEDTOPSP_OFFSET);
    unsigned n = avm_totalactuals();

    if(n!=1){
        avm_error("sds","one argument (not ",n,") expected in 'typeof'!");
    }
    else{
        avm_memcellclear(&retval);
        retval.type = number_m;
        unsigned i = 0;
        retval.data.numVal = sina(avm_get_envvalue(avm_getactual(i)->data.numVal));
    }
}

void libfunc_cos(void){
    unsigned p_topsp = avm_get_envvalue(topsp+ AVM_SAVEDTOPSP_OFFSET);
    avm_memcellclear(&retval);
    retval.type = number_m;
    retval.data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
    retval.data.numVal = cosa(retval.data.numVal);
}

char* number_tostring(avm_memcell* m){
    assert(m->type == number_m);
    char str[32];
    sprintf(str,"%f",m->data.numVal);
    return strdup(str);
}
char* string_tostring(avm_memcell* m){
    assert(m->type == string_m);
    return strdup(m->data.strVal);
}
char* bool_tostring(avm_memcell* m){
    assert(m->type == bool_m);
    if(m->data.boolVal == '1')return "true";
    else return "false";
}

char* table_tostring(avm_memcell* m){
    return "";
}
char* userfunc_tostring(avm_memcell* m){
    assert(m->type==userfunc_m);
    return "Func";
}
char* libfunc_tostring(avm_memcell* m){
    assert(m->type==libfunc_m);
    return "Library_Function";
}
char* nil_tostring(avm_memcell* m){
    assert(m->type=nil_m);
    return '\0';
}
char* undef_tostring(avm_memcell* m){
    assert(m->type==undef_m);
    return "Undef";
}


char* avm_tostring(avm_memcell* m){
    assert(m->type >= 0 && m->type <=undef_m);
    return (*tostringFuncs[m->type])(m);
}

//execute arithmetic Dispatcher


double add_impl(double x, double y){return x+y;}
double sub_impl(double x, double y){return x-y;}
double mul_impl(double x, double y){return x*y;}
double div_impl(double x, double y){
    if (y==0){
        puts("Division with 0\n");
        exit(1);
    }
    return x/y;
}
double mod_impl(double x, double y){
    if(y==0){
        puts("Moderate with 0\n");
        exit(1);
    }
    return ((unsigned)x) % ((unsigned)y);
}

void execute_arithmetic(instruction* instr){
    avm_memcell* lv = avm_translate_operand(&instr->result,(avm_memcell*)0);
    avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
    avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);

    assert(lv && (&stack[AVM_STACKSIZE - 1] >= lv && lv > &stack[top] || lv == &retval));
	assert(rv1 && rv2);

    if(rv1->type!=number_m || rv2->type!=number_m){
        avm_error("s","Not a number in arithmetic operation!");
        executionFinished = 1;
    }
    else{
        arithmetic_func_t op = arithmeticFuncs[instr->opcode - add_v];
        avm_memcellclear(lv);
        lv->type = number_m;
        lv->data.numVal = (*op)(rv1->data.numVal, rv2->data.numVal);
    }
}

unsigned char number_tobool(avm_memcell* m){return m->data.numVal!=0;}
unsigned char string_tobool(avm_memcell* m){return m->data.strVal[0]!=0;}
unsigned char bool_tobool(avm_memcell* m){return m->data.boolVal;}
unsigned char table_tobool(avm_memcell* m){return 1;}
unsigned char userfunc_tobool(avm_memcell* m){return 1;}
unsigned char libfunc_tobool(avm_memcell* m){return 1;}
unsigned char nil_tobool(avm_memcell* m){return 0;}
unsigned char undef_tobool(avm_memcell* m){assert(0); return 0;}

unsigned char avm_tobool (avm_memcell* m){
    assert(m->type>=0 && m->type <undef_m);
    return (*toboolFuncs[m->type])(m);
}


void execute_assign(instruction *i){
    avm_memcell* lv = avm_translate_operand(&i->result, (avm_memcell*)0);
    avm_memcell* rv = avm_translate_operand(&i->arg1, &ax);

    assert(lv && (&stack[AVM_STACKSIZE -1]>= lv && lv> &stack[top] || lv == &retval));
    assert(rv);

    avm_assign(lv,rv);

}

void execute_jeq(instruction *i){
    assert(i->result.type == label_a);
    avm_memcell* rv1 = avm_translate_operand(&i->arg1,&ax);
    avm_memcell* rv2 = avm_translate_operand(&i->arg2,&bx);

    unsigned char result = 0;
    if(rv1->type == undef_m || rv2->type == undef_m){
        avm_error("s","'undef' involved in equality!");
        executionFinished =1;
    }
    else if(rv1->type == nil_m || rv2->type == nil_m){
        result = rv1->type == nil_m && rv2->type == nil_m;
    }
    else if(rv1->type == bool_m || rv2->type == bool_m){
        result = (avm_tobool(rv1) == avm_tobool(rv2)); 
    }
    else if(rv1->type != rv2->type){
        avm_error("sssss","%s == %s is illegal!",typeStrings[rv1->type]," == ",typeStrings[rv2->type],"is illegal!");
        executionFinished = 1;
    }
    else{
        //TODO
    }
}
void execute_uminus(instruction *i){}    //TODO
void execute_and(instruction *i){}   //TODO
void execute_or(instruction *i){}    //TODO
void execute_not(instruction *i){}   //TODO
void execute_jne(instruction *i){}   //TODO
void execute_jle(instruction *i){}   //TODO
void execute_jge(instruction *i){}   //TODO
void execute_jlt(instruction *i){}   //TODO
void execute_jgt(instruction *i){}   //TODO
void execute_nop(instruction *i){}  //TODO

void execute_call(instruction *i){
    avm_memcell* func = avm_translate_operand(&i->result, &ax);
    assert(func);
    avm_callsaveenvironment();
    switch(func->type){
        case userfunc_m:{
            pc = func->data.funcVal;
            assert(pc < AVM_ENDING_PC);
            assert(code[pc].opcode == funcenter_v);
            break;
        }
        case string_m : avm_calllibfunc(func->data.strVal); break;
        case libfunc_m: avm_calllibfunc(func->data.libfuncVal); break;
        default:{
            char *s = avm_tostring(func);
            avm_error("sss","call: cannot bind ",s," to function!\n");
            free(s);
            executionFinished = 1;
        }
    }
}
void execute_pusharg(instruction *i){
                                            //WARNING egw to argument nomizw to exw sto result kai oxi sto arg1
    avm_memcell* arg = avm_translate_operand(&i->result,&ax);
    assert(arg);
    avm_assign(&stack[top],arg);
    ++totalActuals;
    avm_dec_top();
}
void execute_funcenter(instruction *i){
    avm_memcell* func = avm_translate_operand(&i->result, &ax);
    assert(func);
    assert(pc == func->data.funcVal);

    totalActuals =0;
    userfunc* funcInfo = getfuncinfo(pc);
    topsp = top;
    top = top - funcInfo->localSize;
}
void execute_funcexit(instruction *i){
    unsigned oldTop = top;
    top = avm_get_envvalue(topsp + AVM_SAVEDTOP_OFFSET);
    pc = avm_get_envvalue(topsp + AVM_SAVEDPC_OFFSET);
    topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);

    while(++oldTop <= top)avm_memcellclear(&stack[oldTop]);
}
void execute_newtable(instruction *i){
    avm_memcell* lv = avm_translate_operand(&i->result, (avm_memcell*)0);
    assert(lv && (&stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] || lv == &retval ));
    avm_memcellclear(lv);
    lv->type = table_m;
    lv->data.tableVal = avm_tablenew();
    avm_tableincrefcounter(lv->data.tableVal);

}
void execute_tablegetelem(instruction *in){
    /*avm_memcell* lv = avm_translate_operand(&in->result,(avm_memcell*)0);
    avm_memcell* t  = avm_translate_operand(&in->arg1,(avm_memcell*)0);
    avm_memcell* i  = avm_translate_operand(&in->arg2, &ax);

    assert(lv && (&stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] || lv == &retval ));
	assert(t && (&stack[AVM_STACKSIZE-1] >= t && t > &stack[top] ));
	assert(i);

    avm_memcellclear(lv);
    lv->type = nil_m;

    if(t->type != table_m){
        avm_error("illegal use of %s as table!",typeStrings[t->type]);
    }
    else{
        avm_memcell* content = avm_tablegetelem(t->data.tableVal,i);
        if(content){
            avm_assign(lv,content);
        }
        else{
            char* ts = avm_tostring(t);
            char* is = avm_tostring(i);
            avm_warning("%s[%s] not found!",ts,is);
        }
    }
*/
}
void execute_tablesetelem(instruction *in){
    /*avm_memcell* t = avm_translate_operand(&in->result,(avm_memcell*)0);
    avm_memcell* i  = avm_translate_operand(&in->arg1, &bx);
    avm_memcell* c  = avm_translate_operand(&in->arg2, &ax);

    assert(t && (&stack[AVM_STACKSIZE-1] >= t && t > &stack[top]));
	assert(i && c);

    if(t->type != table_m){
        avm_error("illegal use of type %s as table!",typeStrings[t->type]);
    }
    else{
        avm_tablesetelem(t->data.tableVal, i , c);
    }*/
}

avm_memcell* avm_translate_operand(vmarg* arg, avm_memcell* reg){
    switch(arg->type){
        /*Variables*/
        case global_a: return &stack[AVM_STACKSIZE-1-(arg->val)];
        case local_a:  return &stack[topsp-(arg->val)];
        case formal_a: return &stack[topsp+AVM_STACKENV_SIZE+1+(arg->val)];
        case retval_a: return &retval;
        case number_a: {
            reg->type = number_m;
            reg->data.numVal = consts_getnumber(arg->val);
            return reg;
        }
        case string_a: {
            reg->type= string_m;
            reg->data.strVal = strdup(consts_getstring(arg->val));
            return reg;
        }
        case bool_a:{
            reg->type = bool_m;
            reg->data.boolVal = arg->val;
            return reg;
        }
        case nil_a:{
            reg->type = nil_m;
            return reg;
        }
        case userfunc_a:{
            reg->type = userfunc_m;
            reg->data.funcVal = arg->val; /*Address already stored */
            return reg;
        }
        case libfunc_a:{
            reg->type = libfunc_m;
            reg->data.libfuncVal = libfuncs_getused(arg->val);
            return reg;
        }
        default: assert(0);
    }
}

void execute_cycle(void){
    if(executionFinished){
        return;
    }
    else{
        if(pc == AVM_ENDING_PC){
            executionFinished =1;
            return;
        }
        else{
            assert(pc<AVM_ENDING_PC);
            instruction* instr = code + pc;
            assert(
                instr->opcode>=0 && 
                instr->opcode <= AVM_MAX_INSTRUCTIONS
            );
            if(instr->srcLine)currLine = instr->srcLine;
            unsigned oldPC = pc;
            (*executeFuncs[instr->opcode])(instr);
            if(pc==oldPC)pc++;
        }
    }
}

void memclear_string(avm_memcell* m){
    assert(m->data.strVal);
    free(m->data.strVal);
}

void memclear_table(avm_memcell* m){
    assert(m->data.tableVal);
    avm_tabledecrefcounter(m->data.tableVal);
}

void exec(){
    while(executionFinished ==0)execute_cycle();
}



void avm_initialize(){
    avm_initstack();
    /*
    avm_registerlibfunc("print",libfunc_print);
    avm_registerlibfunc("typeof",libfunc_typeof);
    avm_registerlibfunc("totalarguments",libfunc_totalarguments);*/

    exec();
}

void decode(FILE *f){
    //Read magic Number
    unsigned magcNum;
    fread(&magcNum,sizeof(unsigned),1,f);
    if(magcNum == magicNumber){
        printf("MagicNum :%d\n",magcNum);
    }
    else{
        printf("Magic Number doesnt match. Expected: %d. Received: %d",magicNumber,magcNum);
        exit(1);
    }
    printf("Arrays:	stringConsts,	numConsts,	namedLibfuncs,	userFuncs\n");

    //Read totalStringConsts, totalNumConsts, totalNamedLibfuncs, totalUserFuncs, totalGlobals
    unsigned totalStringConsts, totalNumConsts, totalNamedLibfuncs, totalUserFuncs, totalGlobals;
    unsigned totalInstructions;
    fread(&totalStringConsts,sizeof(unsigned),1,f);
    printf("number of stringConsts: %d\n",totalStringConsts);
    fread(&totalNumConsts,sizeof(unsigned),1,f);
    printf("number of numConsts: %d\n",totalNumConsts);
    fread(&totalNamedLibfuncs,sizeof(unsigned),1,f);
    printf("number of namedLibfuncs: %d\n",totalNamedLibfuncs);
    fread(&totalUserFuncs,sizeof(unsigned),1,f);
    printf("number of userFuncs: %d\n",totalUserFuncs);
    fread(&totalGlobals,sizeof(int),1,f);
    printf("number of globals: %d\n",totalGlobals);

    //Allocate space
    stringConsts=(char**)malloc(sizeof(char*)*(totalStringConsts));
    numConsts=(double*)malloc(sizeof(double)*totalNumConsts);
    namedLibfuncs=(char**)malloc(sizeof(char*)*(totalNamedLibfuncs));


    //Read strinConsts
    int i=0;
    unsigned strSize=0;
    printf("stringConsts:\n");
    while(i<totalStringConsts){
        fread(&strSize,sizeof(unsigned),1,f);
        stringConsts[i] = (char*)malloc(sizeof(char)*strSize);
        fread(stringConsts[i],strSize,1,f);
        printf("\tIndex: %d, Value: %s\n",i,stringConsts[i]);
        i++;
    }

    //Read numConsts
    i =0;
    printf("numConsts:\n");
    while(i<totalNumConsts){
        fread(&numConsts[i],sizeof(double),1,f);
        printf("\tIndex: %d, Value: %f\n",i,numConsts[i]);
        i++;
    }

    //Read namedLibfuncs
    i=0;
    strSize=0;
    printf("namedLibfuncs:\n");
    while(i<totalNamedLibfuncs){
        fread(&strSize,sizeof(unsigned),1,f);
        namedLibfuncs[i] = (char*)malloc(sizeof(char)*strSize);
        fread(namedLibfuncs[i],strSize,1,f);
        printf("\tIndex: %d, Value: %s\n",i,namedLibfuncs[i]);
        i++;
    }

    //Read number of Instructions and Instructions
    fread(&totalInstructions,sizeof(unsigned),1,f);
    printf("Number Of Instructions: %d\n\n", totalInstructions);
    printf("Instructions:\n\n");

    instructions = (instruction*)malloc(sizeof(instruction)*totalInstructions);
    i=0;
    while(i<totalInstructions){
        fread(&instructions[i].opcode,sizeof(vmpcode),1,f);
        printf("Opcode: %d\n",instructions[i].opcode);
        fread(&instructions[i].result.type,sizeof(int),1,f);
        printf("\tResult:\n");
        printf("\t\tType: %d\n",instructions[i].result.type);
        fread(&instructions[i].result.val,sizeof(int),1,f);
        printf("\t\tValue: %d\n",instructions[i].result.val);

        printf("\tArg1:\n");
        fread(&instructions[i].arg1.type,sizeof(int),1,f);
        if(instructions[i].arg1.type == 100){
            //IGNORE arg1
            printf("\n");
        }
        else{
            fread(&instructions[i].arg1.val,sizeof(unsigned),1,f);
            printf("\t\tType: %d\n",instructions[i].arg1.type);
            printf("\t\tValue: %d\n",instructions[i].arg1.val);
        }

        printf("\tArg2:\n");
        fread(&instructions[i].arg2.type,sizeof(int),1,f);
        if(instructions[i].arg2.type == 100){
            //IGNORE arg2
            printf("\n");
        }
        else{
            fread(&instructions[i].arg2.val,sizeof(unsigned),1,f);
            printf("\t\tType: %d\n",instructions[i].arg2.type);
            printf("\t\tValue: %d\n",instructions[i].arg2.val);
        }

        i++;

    }
    code = instructions;
    codeSize = totalInstructions;

    top = AVM_STACKSIZE - totalGlobals -1;
    topsp=top;
    avm_initialize ();
    fclose(f);

    return;
}