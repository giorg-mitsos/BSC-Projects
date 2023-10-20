/*
	Author: Giwrgos Mitsos 3660
*/

%{
    /* Prologue */
    #include "PhaseD.h"

    
%}

//%define parse.error verbose
//%error-verbose
/* Grammar Initializer */
%start program 

%union{
    char* stringValue;
    int intValue;
    double realValue;
    struct SymbolList *symbol;
    struct expr *exprValue;
    struct expr *next;
    struct funcCall *funCall;
}

/* ---------------------- Tokens ---------------------- */
%token <stringValue> IDENTIFIER
%token <intValue> CONST_INT
%token <realValue> CONST_FLOAT
%token <stringValue> STRING

/* Keywords */
%token <stringValue> AUTO CASE CHAR DEFAULT DO DOUBLE ENUM EXTERN FLOAT GOTO INT LONG
                     REGISTER SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION
                     UNSIGNED VOID VOLATILE IF ELSE WHILE FOR FUNCTION RETURN BREAK
                     CONTINUE AND NOT OR LOCAL TRUE FALSE NIL

/* Operators */
%token <stringValue> EQUAL PLUS MINUS MULTIPLY DIVIDE MODERATE ASSIGNATION NOT_EQUAL
                     PLUS_PLUS MINUS_MINUS GREATER_THAN LESS_THAN GREATER_EQUAL LESS_EQUAL
                     QUESTION_MARK AMPERSAND UMINUS 

/* Punctuation Marks */
%token <stringValue> LEFT_BRACKET RIGHT_BRACKET LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET
                     LEFT_PARENTHESIS RIGHT_PARENTHESIS SEMICOLON COMMA COLON DOUBLE_COLON
                     DOT DOUBLE_DOT APOSTROPHE DEBUG

/* Comments */
%token <stringValue> LINE_COMMENT BLOCK_COMMENT

/* Set as exprValue type for the rules needed */
%type <exprValue> expr term assignexpr lvalue primary const member objectdef indexed indexedelem elist call returnstmt stmt Debugger whilestmt forstmt ifstmt dostmt
%type <funCall> normcall methodcall callsuffix
%type <symbol> funcdef
%type <intValue> M 




/* Precedence */

%right      ASSIGNATION
%left       OR
%left       AND
%nonassoc   EQUAL NOT_EQUAL
%nonassoc   GREATER_THAN GREATER_EQUAL LESS_THAN LESS_EQUAL
%left       PLUS MINUS
%left       MULTIPLY DIVIDE MODERATE 
%right      NOT PLUS_PLUS MINUS_MINUS UMINUS
%left       DOT DOUBLE_DOT 
%left       LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET
%left       LEFT_PARENTHESIS RIGHT_PARENTHESIS
%nonassoc   BASIC_IF
%nonassoc   ELSE



%% 
    /* Grammar */ 

program:    stmts               {
                                    Emit(_exit,NULL,NULL,NULL,currQuad,linecounter);
                                    printf("Grammar: program(1) | stmts\n");
                                }
            ;

stmts:      stmts stmt          {
                                    StmtReset();
                                    printf("Grammar: stmts(1) | stmts stmt\n");
                                }
            | /*Empty*/ 
            ;
M:  {$$=currQuad;}
stmt:       expr SEMICOLON          {
                                        if($1->type == boolexpr_e){
                                            
                                            BackPatch($1->trueList,currQuad);
                                            printf("%s\n\n\n",$1->strConst);
                                            Emit(assign,$1,NewConstBoolExpr('t'),NULL,currQuad,linecounter);
                                            Emit(jump,NewConstNumExpr(currQuad+2),NULL,NULL,currQuad,linecounter);
                                            BackPatch($1->falseList,currQuad);
                                            Emit(assign,$1,NewConstBoolExpr('f'),NULL,currQuad,linecounter);
                                        }
                                        printf("Grammar: stmt(1) | expr SEMICOLON\n");
                                    }
            | ifstmt                {$$=$1; printf("Grammar: stmt(2) | ifstmt\n");}
            | whilestmt             {$$=$1; printf("Grammar: stmt(3) | whilestmt\n");}
            | dostmt                {$$=$1; printf("Grammar: stmt(4) | dostmt\n");}
            | forstmt               {$$=$1; printf("Grammar: stmt(5) | forstmt \n");}
            | returnstmt            {  if(_flag[_isFunction] == 0)Error("Not in a function");
                                        else _flag[_isFunction]--;
                                        $$=NULL;
                                        printf("Grammar: stmt(6) | returnstmt\n");}
            | BREAK SEMICOLON       {   if(_flag[_isLoop]==0)Error("Not in a loop");
                                        else _flag[_isLoop]--;
                                        printf("Grammar: stmt(7) | BREAK SEMICOLON\n");}
            | CONTINUE SEMICOLON    {   if(_flag[_isLoop]==0)Error("Not in a loop");
                                        printf("Grammar: stmt(8) | CONTINUE SEMICOLON\n");}
            | block                 {printf("Grammar: stmt(9) | block\n");}
            | funcdef               {printf("Grammar: stmt(10) | funcdef\n");}
            | SEMICOLON             {printf("Grammar: stmt(11) | SEMICOLON\n");}
            | Debugger                
            //|stmt stmt              {printf("Grammar: stmt(12) | stmt stmt\n");}
            ;

expr:       assignexpr                      {
                                                $$ = $1;
                                                printf("Grammar: expr(1) | assignexpr\n");
                                            }
            | expr PLUS expr                {   
                                                /* Check for type Compatibility */
                                                if($1->type==constbool_e || $3->type==constbool_e)Error("Incompatible Types");
                                                $$= NewlvalueExpr(NewTemporarySymbol());
                                                Emit(add, $$, $1, $3, currQuad, linecounter);
                                                printf("Grammar: expr(2) | expr PLUS expr\n");
                                            }
            | expr MINUS expr               {
                                                if($1->type==constbool_e || $3->type==constbool_e)Error("Incompatible Types");
                                                $$= NewlvalueExpr(NewTemporarySymbol());
                                                Emit(sub, $$, $1, $3, currQuad, linecounter);
                                                printf("Grammar: expr(3) | expr MINUS expr\n");
                                            }
            | expr MULTIPLY expr            {
                                                //char *newTemp = (char *)NewTemporaryID();
                                                //InsertToSymbolList(Local_Variable,newTemp,_currentScope,linecounter);
                                                //struct SymbolList *temp = SearchSymbolInListInScope(newTemp,_currentScope);
                                                if($1->type==constbool_e || $3->type==constbool_e)Error("Incompatible Types");
                                                $$= NewlvalueExpr(NewTemporarySymbol());
                                                Emit(mul, $$, $1, $3, currQuad, linecounter);
                                                printf("Grammar: expr(4) | expr MULTIPLY expr\n");
                                            }
            | expr DIVIDE expr              {   
                                                if($1->type==constbool_e || $3->type==constbool_e)Error("Incompatible Types");
                                                $$= NewlvalueExpr(NewTemporarySymbol());
                                                Emit(ddiv, $$, $1, $3, currQuad, linecounter);
                                                printf("Grammar: expr(5) | expr DIVIDE expr\n");
                                            }
            | expr MODERATE expr            {   
                                                if($1->type==constbool_e || $3->type==constbool_e)Error("Incompatible Types");
                                                $$= NewlvalueExpr(NewTemporarySymbol());
                                                Emit(mod, $$, $1, $3, currQuad, linecounter);
                                                printf("Grammar: expr(6) | expr MODERATE expr\n");
                                            }
            | expr GREATER_THAN expr        {   
                                            
                                                $$ = NewAExpr(boolexpr_e,NewTemporarySymbol());
                                                $$->trueList = NewLabelList(currQuad);
                                                $$->falseList = NewLabelList(currQuad+1);
                                                Emit(if_greater,NULL,$1,$3,currQuad,linecounter);
                                                Emit(jump,NULL,NULL,NULL,currQuad,linecounter);
                                                printf("Grammar: expr(7) | expr GREATER_THAN expr\n");
                                            }
            | expr GREATER_EQUAL expr       {   
                                                
                                                $$ = NewAExpr(boolexpr_e,NewTemporarySymbol());
                                                $$->trueList = NewLabelList(currQuad);
                                                $$->falseList = NewLabelList(currQuad+1);
                                                Emit(if_greatereq,NULL,$1,$3,currQuad,linecounter);
                                                Emit(jump,NULL,NULL,NULL,currQuad,linecounter);
                                                printf("Grammar: expr(8) | expr GREATER_EQUAL expr\n");
                                            }
            | expr LESS_THAN expr           {
                                                $$ = NewAExpr(boolexpr_e,NewTemporarySymbol());
                                                printf("%s\n\n",$$->sym->nameOfSymbol);
                                                $$->trueList = NewLabelList(currQuad);
                                                $$->falseList = NewLabelList(currQuad+1);
                                                Emit(if_less,NULL,$1,$3,currQuad,linecounter);
                                                Emit(jump,NULL,NULL,NULL,currQuad,linecounter);
                                                printf("Grammar: expr(9) | expr LESS_THAN expr\n");
                                            }
            | expr LESS_EQUAL expr          {
                                                $<exprValue>$ = NewAExpr(boolexpr_e,NewTemporarySymbol());
                                                printf("%s\n\n",$$->sym->nameOfSymbol);
                                                $$->trueList = NewLabelList(currQuad);
                                                $$->falseList = NewLabelList(currQuad+1);
                                                Emit(if_lesseq,NULL,$1,$3,currQuad,linecounter);
                                                Emit(jump,NULL,NULL,NULL,currQuad,linecounter);
                                                printf("Grammar: expr(10) | expr LESS_EQUAL expr\n");
                                            }
            | expr EQUAL expr               {
                                                $<exprValue>$ = NewAExpr(boolexpr_e,NewTemporarySymbol());
                                                $$->trueList = NewLabelList(currQuad);
                                                $$->falseList = NewLabelList(currQuad+1);
                                                Emit(if_eq,NULL,$1,$3,currQuad,linecounter);
                                                Emit(jump,NULL,NULL,NULL,currQuad,linecounter);
                                                printf("Grammar: expr(11) | expr EQUAL expr\n");
                                            }
            | expr NOT_EQUAL expr           {   
                                                $<exprValue>$ = NewAExpr(boolexpr_e,NewTemporarySymbol());
                                                $$->trueList = NewLabelList(currQuad);
                                                $$->falseList = NewLabelList(currQuad+1);
                                                Emit(if_noteq,NULL,$1,$3,currQuad,linecounter);
                                                Emit(jump,NULL,NULL,NULL,currQuad,linecounter);
                                                printf("Grammar: expr(12) | expr NOT_EQUAL expr\n");
                                            }
            | expr AND M expr               {  
                                                BackPatch($1->trueList,$3);
                                                $<exprValue>$ = NewAExpr(boolexpr_e,NewTemporarySymbol());
                                                $$->trueList = $4->trueList;
                                                $$->falseList = Merge($1->falseList,$4->falseList);
                                                printf("Grammar: expr(13) | expr AND expr\n");
                                            }
            | expr OR M expr                {
                                                BackPatch($1->falseList,$3);
                                                $<exprValue>$ = NewAExpr(boolexpr_e,NewTemporarySymbol());
                                                $$->trueList = Merge($1->trueList,$4->trueList);
                                                $$->falseList = $4->falseList;
                                                printf("Grammar: expr(14) | expr OR expr\n");
                                            }
            | term                          {$$=$1; printf("Grammar: expr(15) | term\n");}
            ; 
/*
op:         PLUS                    {printf("Grammar: op(1) | PLUS\n");}
            | MINUS                 {printf("Grammar: op(2) | MINUS\n");}
            | MULTIPLY              {printf("Grammar: op(3) | MULTIPLY\n");}
            | DIVIDE                {printf("Grammar: op(4) | DIVIDE\n");}
            | MODERATE              {printf("Grammar: op(5) | MODERATE \n");}
            | GREATER_THAN          {printf("Grammar: op(6) | GREATER_THAN\n");}
            | GREATER_EQUAL         {printf("Grammar: op(7) | GREATER_EQUAL\n");}
            | LESS_THAN             {printf("Grammar: op(8) | LESS_THAN\n");}
            | LESS_EQUAL            {printf("Grammar: op(9) | LESS_EQUAL\n");}
            | EQUAL                 {printf("Grammar: op(10) | EQUAL\n");}
            | NOT_EQUAL             {printf("Grammar: op(11) | NOT_EQUAL\n");}
            | AND                   {printf("Grammar: op(12) | AND\n");}
            | OR                    {printf("Grammar: op(13) | OR\n");}
            ;
*/



term:       LEFT_PARENTHESIS expr RIGHT_PARENTHESIS     {
                                                            $$ = $2;
                                                            printf("Grammar: term(1) | LEFT_PARENTHESIS expr RIGHT_PARENTHESIS\n");
                                                        }
            | MINUS expr %prec UMINUS                   {   
                                                            char *newTemp = (char *)NewTemporaryID();
                                                            InsertToSymbolList(Local_Variable,newTemp,_currentScope,linecounter,currScopeSpace);
                                                            struct SymbolList *temp = SearchSymbolInListInScope(newTemp,_currentScope);
                                                            $$ = NewUminusExpr($2);
                                                            $$->sym = temp;
                                                            Emit(uminus,$$,$2,NewConstNumExpr(-1),currQuad,linecounter);
                                                            

                                                            printf("Grammar: term(2) | MINUS expr %prec UMINUS\n");
                                                        }
            | NOT expr                                  {   
                                                            $$ = NewExpr(boolexpr_e);
                                                            $$->sym = $2->sym;
                                                            $$->strConst = strdup($2->sym->nameOfSymbol);
                                                            $$->trueList = $2->falseList;
                                                            $$->falseList = $2->trueList;
                                                            printf("Grammar: term(3) | NOT expr\n");
                                                        }
            | PLUS_PLUS lvalue                          {   
                                                            struct SymbolList *temp = SearchSymbolInList($2->sym->nameOfSymbol);
                                                            if(temp->typeOfSymbol == Library_Function || temp->typeOfSymbol == User_Function)Error("Can not use Function as lvalue (++lvalue)");
                                                            $$ = $2;
                                                            Emit(add,$$,$$,NewConstNumExpr(1),currQuad,linecounter);
                                                            printf("Grammar: term(4) | PLUS_PLUS lvalue \n");
                                                        }
            | lvalue                                    { 
                                                            struct SymbolList *temp = SearchSymbolInList($1->sym->nameOfSymbol);
                                                            if(temp->typeOfSymbol == Library_Function || temp->typeOfSymbol == User_Function)Error("Can not use Function as lvalue (lvalue++)");
                                                        }
             PLUS_PLUS                                  {
                                                            $$ = $1;
                                                            Emit(add,$$,$$,NewConstNumExpr(1),currQuad,linecounter);
                                                            printf("Grammar: term(5) | lvalue PLUS_PLUS\n");
                                                        }
            | MINUS_MINUS lvalue                        {
                                                            struct SymbolList *temp = SearchSymbolInList($2->sym->nameOfSymbol);
                                                            if(temp->typeOfSymbol == Library_Function || temp->typeOfSymbol == User_Function)Error("Can not use Function as lvalue (--lvalue)");
                                                            $$ = $2;
                                                            Emit(sub,$$,$$,NewConstNumExpr(1),currQuad,linecounter);
                                                            printf("Grammar: term(6) | MINUS_MINUS lvalue\n");
                                                        }
            | lvalue                                    { 
                                                            struct SymbolList *temp = SearchSymbolInList($1->sym->nameOfSymbol);
                                                            if(temp->typeOfSymbol == Library_Function || temp->typeOfSymbol == User_Function)Error("Can not use Function as lvalue (lvalue--)");
                                                        }
             MINUS_MINUS                                {
                                                            $$ = $1;
                                                            Emit(sub,$$,$$,NewConstNumExpr(1),currQuad,linecounter);
                                                            printf("Grammar: term(7) | lvalue MINUS_MINUS\n");
                                                        }
            | primary                                   {$$=$1;printf("Grammar: term(8) | primary\n");}
            ;

assignexpr: lvalue ASSIGNATION expr             {  
                                                    if($3->type == boolexpr_e){
                                                        $3->sym = NewTemporarySymbol();
                                                        BackPatch($3->trueList,currQuad);
                                                        Emit(assign,$3,NewConstBoolExpr('t'),NULL,currQuad,linecounter);
                                                        Emit(jump,NewConstNumExpr(currQuad+2),NULL,NULL,currQuad,linecounter);
                                                        BackPatch($3->falseList,currQuad);
                                                    }
                                                    if($1->type == tableitem_e){
                                                        Emit(tablesetelem,$3,$1,$1->index,currQuad,linecounter);
                                                        $$ = EmitIfTableItem($1);
                                                        $$->type = assignexpr_e;
                                                    }
                                                    else{
                                                        Emit(assign,$1,$3,NULL,currQuad,linecounter);
                                                        $$= NewAExpr(assignexpr_e,NewTemporarySymbol());
                                                        //$$->sym = NewTemporarySymbol();
                                                       
                                                        Emit(assign,$$,$1,NULL,currQuad,linecounter);
                                                    }
                                                    printf("Grammar: assignexpr(1) | lvalue ASSIGNATION expr\n");
                                                }
            ;

primary:    lvalue                                              {
                                                                    $$ =EmitIfTableItem($1);
                                                                    printf("Grammar: primary(1) | lvalue\n");
                                                                }
            | call                                              {   
                                                                    printf("Grammar: primary(2) | call\n");
                                                                }
            | objectdef                                         {
                                                                    $$=$1;
                                                                    printf("Grammar: primary(3) | objectdef\n");
                                                                }
            | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS        {   
                                                                    $$=NewAExpr(programfunc_e,$<symbol>2);
                                                                    printf("Grammar: primary(4) | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS\n");
                                                                }
            | const                                             {$$=$1; printf("Grammar: primary(5) | const\n");}
            ;

//for debugging purposes put $$DEBUG in any line in the input file. Change the print as wish.
Debugger:   DEBUG   {printf("\x1B[32m \n-----> %d <----- \x1B[0m\n",_currentScope);}
            ;

lvalue:     IDENTIFIER                          { 
                                                    /* If given Symbol exist in SymbolTable */
                                                    if (temporaryID=SearchSymbolInList(yylval.stringValue)){
                                                        if(isValidAccess(SearchSymbolInList(yylval.stringValue))){
                                                            $$ = NewlvalueExpr(SearchSymbolInList(yylval.stringValue));
                                            
                                                        }
                                                        else {
                                                            Error("Can not Access Variable between functions");
                                                        }
                                                        $$ = NewlvalueExpr(SearchSymbolInListInScope(yylval.stringValue,_currentScope));
                                                    }
                                                    else{
                                                        if (_currentScope == 0)InsertToSymbolList(Global_Variable,yylval.stringValue,_currentScope,linecounter,currScopeSpace);
                                                        else InsertToSymbolList(Local_Variable,yylval.stringValue,_currentScope,linecounter,currScopeSpace);
                                                        $$ = NewlvalueExpr(SearchSymbolInListInScope(yylval.stringValue,_currentScope));
                                                        
                                                    }
                                                    expr *e = $$;

                                                    printf("Grammar: lvalue(1) | IDENTIFIER\n");
                                                }
            | LOCAL IDENTIFIER                  {   if (SearchSymbolInListInScope(yylval.stringValue,_currentScope)==NULL){
                                                        if(_currentScope==0)InsertToSymbolList(Global_Variable,yylval.stringValue,0,linecounter,currScopeSpace);
                                                        else if(InsertToSymbolList(Local_Variable,yylval.stringValue,_currentScope,linecounter,currScopeSpace)==0)Error("Variable is Shadowing a Global Function");
                                                    }
                                                    printf("Grammar: lvalue(2) | LOCAL IDENTIFIER\n");
                                                }
            | DOUBLE_COLON IDENTIFIER           {   if (SearchSymbolInListInScope(yylval.stringValue,0)==NULL)Error("No Global Variable with given name");
                                                    printf("Grammar: lvalue(3) | DOUBLE_COLON IDENTIFIER\n");
                                                }

            | member                            {printf("Grammar: lvalue(4) | member\n");}
            ;

member:     lvalue DOT IDENTIFIER                                       {
                                                                            $$ = MemberItem($1,yylval.stringValue);
                                                                            printf("Grammar: member(1) | lvalue DOT IDENTIFIER\n");
                                                                        }
            | lvalue LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET      {
                                                                            $1 = EmitIfTableItem($1);
                                                                            $$ = NewAExpr(tableitem_e,SearchSymbolInList($1->sym->nameOfSymbol));
                                                                            $$->sym = $1->sym;
                                                                            $$->index = $3;
                                                                            printf("Grammar: member(2) | lvalue LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET\n");
                                                                        }
            | call DOT IDENTIFIER                                       {printf("Grammar: member(3) | call DOT IDENTIFIER\n");}
            | call LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET        {printf("Grammar: member(4) | call LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET\n");}
            ;

call:       call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS                                               {
                                                                                                                struct expr* par = par = ReverseElist($3);;
                                                                                                                while(par!=NULL){
                                                                                                                    Emit(param,par,NULL,NULL,currQuad,linecounter);
                                                                                                                    par = par->next;
                                                                                                                }
                                                                                                                par = ReverseElist($3);
                                                                                                                Emit(call,$1,NULL,NULL,currQuad,linecounter);
                                                                                                                Emit(getretval,NewConstStringExpr(NewTemporaryID()),NULL,NULL,currQuad,linecounter);
                                                                                                            printf("Grammar: call(1) | call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                                        }
            | lvalue callsuffix                                                                         {   
                                                                                                        
                                                                                                            
                                                                                                            struct expr *par = ReverseElist($2->elist);
                                                                                                            while(par!=NULL){
                                                                                                                    Emit(param,par,NULL,NULL,currQuad,linecounter);
                                                                                                                    par = par->next;
                                                                                                                }
                                                                                                                par = ReverseElist($2->elist);
                                                                                                                Emit(call,$1,NULL,NULL,currQuad,linecounter);
                                                                                                                Emit(getretval,NewConstStringExpr(NewTemporaryID()),NULL,NULL,currQuad,linecounter);
                                                                                                            if($2->method==1){
                                                                                                                while(par!=NULL){
                                                                                                                    Emit(param,par,NULL,NULL,currQuad,linecounter);
                                                                                                                    par = par->next;
                                                                                                                }
                                                                                                                par = ReverseElist($2->elist);

                                                                                                            } 
                                                                                                            else{

                                                                                                            }

                                                                                                            printf("Grammar: call(2) | lvalue callsuffix\n");
                                                                                                        }
            | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS       {
                                                                                                            expr* func = NewAExpr(programfunc_e, $<symbol>2);
                                                                                                            $<exprValue>$ = MakeCall(func,$<exprValue>5);
                                                                                                            printf("Grammar: call(3) | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                                        }
            ;

callsuffix: normcall                {
                                        $<funCall>$=$<funCall>1; printf("Grammar: callsuffix(1) | normcall\n");
                                    }
            | methodcall            {$<funCall>$=$<funCall>1; printf("Grammar: callsuffix(2) | methodcall\n");}
            ;

normcall:   LEFT_PARENTHESIS elist RIGHT_PARENTHESIS        {
                                                                struct funcCall *fCall = (struct funcCall*)malloc(sizeof(struct funcCall));
                                                                $<funCall>$ = fCall;
                                                                $<funCall>$->elist = $2;
                                                                $<funCall>$->method =0;
                                                                $<funCall>$->funcName = NULL;
                                                                printf("Grammar: normcall(1) | LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                            }
            ;

methodcall: DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS          {   
                                                                                        struct funcCall *fCall = (struct funcCall*)malloc(sizeof(struct funcCall));
                                                                                        $<funCall>$ = fCall;
                                                                                        $<funCall>$->elist = $4;
                                                                                        $<funCall>$->method = 1;
                                                                                        $<funCall>$ ->funcName = $<stringValue>2;
                                                                                        printf("Grammar: methodcall(1) | DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                    }
            ;

elist:      expr                    {   
                                        $$ = $1;
                                        printf("Grammar: elist(1) | expr\n");
                                    }
            | elist COMMA expr      {   
                                        expr *temp = $1;
                                        
                                        while(temp->next!=NULL){
                                            temp=temp->next;
                                        }
                                        temp->next = $3;
                                        $<exprValue>$ = $<exprValue>1;
                                        printf("Grammar: elist(2) | elist COMMA expr\n");
                                    }
            | /*Empty*/             {
                                        $$=NewConstNilExpr();
                                        printf("Grammar: elist(3) | /*Empty*/\n");
                                    }
            ;

objectdef:  LEFT_SQUARE_BRACKET elist RIGHT_SQUARE_BRACKET          {
                                                                        expr* t = NewExpr(newtable_e);
                                                                        t->sym = NewTemporarySymbol();
                                                                        t->strConst = strdup(t->sym->nameOfSymbol); 
                                                                        Emit(tablecreate,t,NULL,NULL,currQuad,linecounter);
                                                                        int i = 0;
                                                                        expr *temp = $2;
                                                                        while(temp != NULL){
                                                                            Emit(tablesetelem,temp,t,NewConstNumExpr(i),currQuad,linecounter);
                                                                            temp = temp->next;
                                                                            i++;
                                                                        }
                                                                        $$ = t;
                                                                        printf("Grammar: objectdef(1) | LEFT_SQUARE_BRACKET elist RIGHT_SQUARE_BRACKET\n");
                                                                    }
            | LEFT_SQUARE_BRACKET indexed RIGHT_SQUARE_BRACKET      {
                                                                        expr *t = NewExpr(newtable_e);
                                                                        t->sym = NewTemporarySymbol();
                                                                        t->strConst = strdup(t->sym->nameOfSymbol); 
                                                                        Emit(tablecreate,t,NULL,NULL,currQuad,linecounter);
                                                                        expr *temp = $2;
                                                                        while(temp!=NULL){
                                                                            Emit(tablesetelem,temp->next,t,temp->index,currQuad,linecounter);
                                                                            temp = temp->nextIndexed;
                                                                        }
                                                                        $$ = t;
                                                                        printf("Grammar: objectdef(2) | LEFT_SQUARE_BRACKET indexed RIGHT_SQUARE_BRACKET\n");
                                                                    }
          /*| LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET              {printf("Grammar: objectdef(3) | LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET\n");}
            Creates shift/recude conflict with objectdef(1) because elist can be empty and so it creates LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET
          */
            ;

indexed:    indexedelem                         {
                                                    $$ = $1;
                                                    printf("Grammar: indexed(1) | indexedelem\n");
                                                }
            | indexed COMMA indexedelem         {
                                                    expr* temp=$1;
                                                    while(temp->nextIndexed!=NULL){
                                                        temp =temp->nextIndexed;
                                                    }
                                                    temp->nextIndexed = $3;
                                                    printf("Grammar: indexed(2) | indexed COMMA indexedelem\n");
                                                }
            ;

indexedelem: LEFT_BRACKET expr COLON expr RIGHT_BRACKET     {
                                                                $$ = NewExpr(tableitem_e);
                                                                $$->index = $2;
                                                                $$->next = $4;
                                                                printf("Grammar: indexedelem(1) | LEFT_BRACKET expr COLON expr RIGHT_BRACKET\n");
                                                            }
             ;

block:      LEFT_BRACKET                    {   if(_flag[_isFunction] == 0)GenerateScope(++_currentScope);} 
            RIGHT_BRACKET                   {   if(_flag[_isFunction] == 0)KillScope(_currentScope--);              
                                                printf("Grammar: block(1) | LEFT_BRACKET RIGHT_BRACKET\n");
                                                
                                            }
            | LEFT_BRACKET                  {   if(_flag[_isFunction] == 0)GenerateScope(++_currentScope); } 
            stmt stmts RIGHT_BRACKET        {   if(_flag[_isFunction] == 0)KillScope(_currentScope--);     
                                                printf("Grammar: block(2) | LEFT_BRACKET stmt stmts RIGHT_BRACKET\n");
                                            }
            ;

funcdef:    FUNCTION LEFT_PARENTHESIS       {   
                                                _flag[_isFunction]++; 
                                                _flag[_isFormalArgs]++;
                                                _tempExpr[_tempExprCounter] = NewAExpr(programfunc_e,NewTemporaryFuncSymbol());
                                                Emit(jump,NULL,NULL,NULL,currQuad,linecounter);
                                                Emit(funcstart,_tempExpr[_tempExprCounter++],NULL,NULL,currQuad,linecounter);
                                                GenerateScope(++_currentScope);
                                            } 
            idlist RIGHT_PARENTHESIS        {_flag[_isFormalArgs] =0;}
            block
                                            {   _flag[_isFunction]--;
                                                KillScope(_currentScope--);
                                                $$ = _tempExpr[--_tempExprCounter]->sym;
                                                Emit(funcend,NewAExpr(programfunc_e,SearchSymbolInList($$->nameOfSymbol)),NULL,NULL,currQuad,linecounter);
                                                _tempExpr[_tempExprCounter]==NULL;
                                                printf("Grammar: funcdef(1) | FUNCTION LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block\n");
                                            }
            | FUNCTION IDENTIFIER           {   struct SymbolList *temp = SearchSymbolInListInScope(yylval.stringValue,_currentScope);
                                                if (temp!=NULL){
                                                    if(temp->typeOfSymbol == User_Function)Error("Duplicate Function");
                                                    else if(temp->typeOfSymbol == Library_Function)Error("Function shadows Library Function");
                                                    else if(temp->typeOfSymbol == Global_Variable || temp->typeOfSymbol == Local_Variable || temp->typeOfSymbol == Formal_Argument)Error("Already declared as Variable");
                                                    else{
                                                        /*Valid Access */
                                                        _tempExpr[_tempExprCounter] = NewAExpr(programfunc_e,SearchSymbolInListInScope(yylval.stringValue,_currentScope));
                                                        Emit(jump,NULL,NULL,NULL,currQuad,linecounter);
                                                        Emit(funcstart,_tempExpr[_tempExprCounter++],NULL,NULL,currQuad,linecounter);

                                                    }
                                                    
                                                }
                                                else if(InsertToSymbolList(User_Function,yylval.stringValue,_currentScope,linecounter,currScopeSpace)==0)Error("Function shadows Library Function");
                                                else{
                                                    /*Valid Access */
                                                    temp = SearchSymbolInListInScope(yylval.stringValue,_currentScope);
                                                    _tempExpr[_tempExprCounter] = NewAExpr(programfunc_e,temp); 
                                                    Emit(jump,NULL,NULL,NULL,currQuad,linecounter);
                                                    Emit(funcstart,_tempExpr[_tempExprCounter++],NULL,NULL,currQuad,linecounter);

                                                }
                                            } 
            LEFT_PARENTHESIS                {   _flag[_isFunction]++; _flag[_isFormalArgs]++; GenerateScope(++_currentScope);} 
            idlist RIGHT_PARENTHESIS        {_flag[_isFormalArgs] =0;}
            block       
                                            {   _flag[_isFunction]--;
                                                KillScope(_currentScope--);
                                                $$ = _tempExpr[--_tempExprCounter]->sym;
                                                Emit(funcend,NewAExpr(programfunc_e,SearchSymbolInList($<stringValue>2)),NULL,NULL,currQuad,linecounter);
                                                _tempExpr[_tempExprCounter]==NULL;
                                                printf("Grammar: funcdef(2) | FUNCTION IDENTIFIER LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block\n");
                                            }
            ;

const:      CONST_INT           {
                                    $$ = NewConstNumExpr($1);
                                    printf("Grammar: const(1) | CONST_INT\n");
                                }
            | CONST_FLOAT       {   
                                    $$ = NewConstNumExpr($1);
                                    printf("Grammar: const(2) | CONST_FLOAT\n");
                                }
            | STRING            {
                                    $$ = NewConstStringExpr($1);
                                    printf("Grammar: const(3) | STRING\n");
                                }
            | NIL               {
                                    $$ = NewConstNilExpr();
                                    printf("Grammar: const(4) | NIL\n");
                                }
            | TRUE              {   
                                    $$ = NewConstBoolExpr('t');
                                    printf("Grammar: const(5) | TRUE\n");
                                }
            | FALSE             {   
                                    $$ = NewConstBoolExpr('f');
                                    printf("Grammar: const(6) | FALSE\n");
                                }
            ;

idlist:     IDENTIFIER                      {   if (_flag[_isFormalArgs]>0){
                                                    if(IsLibraryFunction(yylval.stringValue))Error("Formal Argument Shadowing global function");
                                                    else InsertToSymbolList(Formal_Argument,yylval.stringValue,_currentScope,linecounter,currScopeSpace);
                                                }
                                                printf("Grammar: idlist(1) | IDENTIFIER\n");
                                            }

            | idlist COMMA IDENTIFIER       {
                                                if (_flag[_isFormalArgs]>0){
                                                    
                                                    if(IsLibraryFunction(yylval.stringValue))Error("Formal Argument Shadowing global function");
                                                    struct SymbolList *temp = SearchSymbolInListInScope(yylval.stringValue,_currentScope);
                                                    if (temp==NULL)InsertToSymbolList(Formal_Argument,yylval.stringValue,_currentScope,linecounter,currScopeSpace);
                                                    else if(SearchSymbolInListInScope(yylval.stringValue,_currentScope))Error("Duplicate Formal Argument");
                            
                                                }
                                                printf("Grammar: idlist(2) | idlist COMMA IDENTIFIER\n");
                                            }
            | /*Empty*/                     {printf("Grammar: idlist(3) | /*Empty*/\n");}
            ;

ifstmt:     IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt %prec BASIC_IF   {printf("Grammar: ifstmt(1) | IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt %prec BASIC_IF\n");}
            | IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt      {printf("Grammar: ifstmt(2) | IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt\n");}
            ;

whilestmt:  WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS  {_flag[_isLoop]++;}
            stmt      {_flag[_isLoop]--;printf("Grammar: whilestmt(1) | WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt\n");}
            ;

dostmt:     DO LEFT_BRACKET stmt RIGHT_BRACKET WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS        {printf("Grammar: dostmt(1) | DO LEFT_BRACKET stmt RIGHT_BRACKET WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS\n");}
            ;

forstmt:    FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS {_flag[_isLoop]++;}
             stmt     {_flag[_isLoop]--;printf("Grammar: forstmt(1) | FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS stmt\n");}
            ;

returnstmt: RETURN SEMICOLON M              {   if(_flag[_isFunction]>0){
                                                    Emit(ret,NULL,NULL,NULL,currQuad,linecounter);
                                                } 
                                                printf("Grammar: returnstmt(1) | RETURN SEMICOLON\n");
                                            }

            | RETURN expr SEMICOLON         {
                                                Emit(ret,$2,NULL,NULL,currQuad,linecounter);
                                                printf("Grammar: returnstmt(2) | RETURN expr SEMICOLON\n");
                                            }
            ;        
%%






int main(int argc, char  *argv[]){
    InitLibraryFunctions();

    if(argc>1){
        if(!(yyin = fopen(argv[1],"r"))){
            fprintf(stderr,"Cannot read file : %s\n",argv[1]);
            return 1;
        }
    }
    else{
        yyin = stdin;
    }

    yyparse();
    
    PrintSymbolTable(0);
    PrintQuads();
    generateTargetCode();
    Binary();
    
    return 1;
}