/*
	Author: Giwrgos Mitsos 3660
*/

%{
    //Definitions
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
	#include "PhaseB.h" 
    //#define YY_DECL int alpha_yylex (void* yylval)


    struct alpha_token_t{
        unsigned int  numline;
        unsigned int  numToken;
        char          *content;
        char          *type;
        char		  *definition;	
        struct alpha_token_t *alpha_yylex;
    };

    struct alpha_token_t *root= NULL;
    int linecounter=1,tokencounter=0;

    void addToken(unsigned int numline,unsigned int numToken,char *content, char *type,char *definition){
        struct alpha_token_t *node = (struct alpha_token_t*)malloc(sizeof(struct alpha_token_t));
        node->alpha_yylex=NULL;
        node->content=strdup(content);
        node->numline=numline;
        node->numToken=numToken;
        node->type=type;
        node->definition=definition;
        if(root==NULL){
            root=node;
        }
        else{
            struct alpha_token_t *temp=root;
            while(temp->alpha_yylex!=NULL){
                temp=temp->alpha_yylex;
            }
            temp->alpha_yylex=node;
        }
    }

    void printlist(){
    	printf("--------------------------------- Lexical Analysis ---------------------------------\n");
        struct alpha_token_t *temp=root;
        while(temp!=NULL){
        	if (temp->definition == "PRINT_DEFINITION"){
        		if (temp->type == "STRING"){
					printf("%3d: #%d %s \t%s \t %s\n",temp->numline,temp->numToken,temp->content,temp->type,temp->content);
				}
				else{
					printf("%3d: #%d \"%s\" \t%s \t \"%s\"\n",temp->numline,temp->numToken,temp->content,temp->type,temp->content);
				}
        	}
        	else{
        		printf("%3d: #%d \"%s\" \t%s \t \"%s\"\n",temp->numline,temp->numToken,temp->content,temp->type,temp->definition);
        	}
        	temp=temp->alpha_yylex;
        }
    }
    
    void printlistfile(char *name){
    	struct alpha_token_t *temp=root;
    	FILE *fpw;
		fpw = fopen(name,"w+");
		fprintf(fpw,"--------------------------------- Lexical Analysis ---------------------------------\n");
		while(temp!=NULL){
			if (temp->definition == "PRINT_DEFINITION"){
				if (temp->type == "STRING"){
					fprintf(fpw,"%3d: #%d %s \t%s \t %s\n",temp->numline,temp->numToken,temp->content,temp->type,temp->content);
				}
				else{
					fprintf(fpw,"%3d: #%d \"%s\" \t%s \t \"%s\"\n",temp->numline,temp->numToken,temp->content,temp->type,temp->content);
				}
        	}
        	else{
        		fprintf(fpw,"%3d: #%d \"%s\" \t%s \t \"%s\"\n",temp->numline,temp->numToken,temp->content,temp->type,temp->definition);
        	}
        	temp=temp->alpha_yylex;
        }
	}
    
%}

%option noyywrap


%%
auto 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","AUTO");
			yylval.stringValue = strdup(yytext); return AUTO;
		}
case 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","CASE");
			yylval.stringValue = strdup(yytext); return CASE;
		}
char 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","CHAR");
			yylval.stringValue = strdup(yytext); return CHAR;
		}
default {addToken(linecounter,++tokencounter,yytext,"KEYWORD","DEFAULT");
			yylval.stringValue = strdup(yytext); return DEFAULT;
		}
do 		{addToken(linecounter,++tokencounter,yytext,"KEYWORD","DO");
			yylval.stringValue = strdup(yytext); return DO;
		}
double  {addToken(linecounter,++tokencounter,yytext,"KEYWORD","DOUBLE");
			yylval.stringValue = strdup(yytext); return DOUBLE;
		}
enum 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","ENUM");
			yylval.stringValue = strdup(yytext); return ENUM;
		}
extern 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","EXTERN");
			yylval.stringValue = strdup(yytext); return EXTERN;
		}
float 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","FLOAT");
			yylval.stringValue = strdup(yytext); return FLOAT;
		}
goto 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","GOTO");
			yylval.stringValue = strdup(yytext); return GOTO;
		}
int 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","INT");
			yylval.stringValue = strdup(yytext); return INT;
		}
long 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","LONG");
			yylval.stringValue = strdup(yytext); return LONG;
		}
register {addToken(linecounter,++tokencounter,yytext,"KEYWORD","REGISTER");
			yylval.stringValue = strdup(yytext); return REGISTER;
		}
short 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","SHORT");
			yylval.stringValue = strdup(yytext); return SHORT;
		}
signed  {addToken(linecounter,++tokencounter,yytext,"KEYWORD","SIGNED");
			yylval.stringValue = strdup(yytext); return SIGNED;
		}
sizeof  {addToken(linecounter,++tokencounter,yytext,"KEYWORD","SIZEOF");
			yylval.stringValue = strdup(yytext); return SIZEOF;
		}
static  {addToken(linecounter,++tokencounter,yytext,"KEYWORD","STATIC");
			yylval.stringValue = strdup(yytext); return STATIC;
		}
struct  {addToken(linecounter,++tokencounter,yytext,"KEYWORD","STRUCT");
			yylval.stringValue = strdup(yytext); return STRUCT;
		}
switch  {addToken(linecounter,++tokencounter,yytext,"KEYWORD","SWITCH");
			yylval.stringValue = strdup(yytext); return SWITCH;
		}
typedef {addToken(linecounter,++tokencounter,yytext,"KEYWORD","TYPEDEF");
			yylval.stringValue = strdup(yytext); return TYPEDEF;
		}
union 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","UNION");
			yylval.stringValue = strdup(yytext); return UNION;
		}
unsigned {addToken(linecounter,++tokencounter,yytext,"KEYWORD","UNSIGNED");
			yylval.stringValue = strdup(yytext); return UNSIGNED;
		}
void 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","VOID");
			yylval.stringValue = strdup(yytext); return VOID;
		}
volatile {addToken(linecounter,++tokencounter,yytext,"KEYWORD","VOLATILE");
			yylval.stringValue = strdup(yytext); return VOLATILE;
		}
if 		{addToken(linecounter,++tokencounter,yytext,"KEYWORD","IF");
			yylval.stringValue = strdup(yytext); return IF;
		}
else 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","ELSE");
			yylval.stringValue = strdup(yytext); return ELSE;
		}
while 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","WHILE");
			yylval.stringValue = strdup(yytext); return WHILE;
		}
for 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","FOR");
			yylval.stringValue = strdup(yytext); return FOR;
		}
function {addToken(linecounter,++tokencounter,yytext,"KEYWORD","FUNCTION");
			yylval.stringValue = strdup(yytext); return FUNCTION;
		}
return 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","RETURN");
			yylval.stringValue = strdup(yytext); return RETURN;
		}
break 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","BREAK");
			yylval.stringValue = strdup(yytext); return BREAK;
		}
continue {addToken(linecounter,++tokencounter,yytext,"KEYWORD","CONTINUE");
			yylval.stringValue = strdup(yytext);return CONTINUE;	
		}
and 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","AND");
			yylval.stringValue = strdup(yytext); return AND;
		}
not 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","NOT");
			yylval.stringValue = strdup(yytext); return NOT;
		}
or 		{addToken(linecounter,++tokencounter,yytext,"KEYWORD","OR");
			yylval.stringValue = strdup(yytext); return OR;
		}
local 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","LOCAL");
			yylval.stringValue = strdup(yytext); return LOCAL;
		}
true 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","TRUE");
			yylval.stringValue = strdup(yytext); return TRUE;
		}
false 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","FALSE");
			yylval.stringValue = strdup(yytext); return FALSE;
		}
nil 	{addToken(linecounter,++tokencounter,yytext,"KEYWORD","NIL");
			yylval.stringValue = strdup(yytext); return NIL;
		}
"=" 	{addToken(linecounter,++tokencounter,yytext,"OPERATOR","ASSIGNATION");
			yylval.stringValue = strdup(yytext); return ASSIGNATION;
		}
"+" 	{addToken(linecounter,++tokencounter,yytext,"OPERATOR","PLUS");
			yylval.stringValue = strdup(yytext); return PLUS;
		}
"-" 	{addToken(linecounter,++tokencounter,yytext,"OPERATOR","MINUS");
			yylval.stringValue = strdup(yytext); return MINUS;
		}
"*" 	{addToken(linecounter,++tokencounter,yytext,"OPERATOR","MULTIPLY");
			yylval.stringValue = strdup(yytext); return MULTIPLY;
		}
"/" 	{addToken(linecounter,++tokencounter,yytext,"OPERATOR","DIVIDE");
			yylval.stringValue = strdup(yytext); return DIVIDE;
		}
"%" 	{addToken(linecounter,++tokencounter,yytext,"OPERATOR","MODERATE");
			yylval.stringValue = strdup(yytext); return MODERATE;
		}
"==" 	{addToken(linecounter,++tokencounter,yytext,"OPERATOR","EQUAL");
			yylval.stringValue = strdup(yytext); return EQUAL;
		}
"!="	{addToken(linecounter,++tokencounter,yytext,"OPERATOR","NOT_EQUAL");
			yylval.stringValue = strdup(yytext); return NOT_EQUAL;
		}
"++" 	{addToken(linecounter,++tokencounter,yytext,"OPERATOR","PLUS_PLUS");
			yylval.stringValue = strdup(yytext); return PLUS_PLUS;
		}
"--" 	{addToken(linecounter,++tokencounter,yytext,"OPERATOR","MINUS_MINUS");
			yylval.stringValue = strdup(yytext); return MINUS_MINUS;
		}
">" 	{addToken(linecounter,++tokencounter,yytext,"OPERATOR","GREATER_THAN");
			yylval.stringValue = strdup(yytext); return GREATER_THAN;
		}
"<" 	{addToken(linecounter,++tokencounter,yytext,"OPERATOR","LESS_THAN");
			yylval.stringValue = strdup(yytext); return LESS_THAN;
		}
">=" 	{addToken(linecounter,++tokencounter,yytext,"OPERATOR","GREATER_EQUAL");
			yylval.stringValue = strdup(yytext); return GREATER_EQUAL;
		}
"<=" 	{addToken(linecounter,++tokencounter,yytext,"OPERATOR","LESS_EQUAL");
			yylval.stringValue = strdup(yytext); return LESS_EQUAL;
		}
"{" 	{addToken(linecounter,++tokencounter,yytext,"PUNCTUATION","LEFT_BRACKET");
			yylval.stringValue = strdup(yytext); return LEFT_BRACKET;
		}
"}" 	{addToken(linecounter,++tokencounter,yytext,"PUNCTUATION","RIGHT_BRACKET");
			yylval.stringValue = strdup(yytext); return RIGHT_BRACKET;
		}
"[" 	{addToken(linecounter,++tokencounter,yytext,"PUNCTUATION","LEFT_SQUARE_BRACKET");
			yylval.stringValue = strdup(yytext); return LEFT_SQUARE_BRACKET;
		}
"]" 	{addToken(linecounter,++tokencounter,yytext,"PUNCTUATION","RIGHT_SQUARE_BRACKET");
			yylval.stringValue = strdup(yytext); return RIGHT_SQUARE_BRACKET;
		}
"(" 	{addToken(linecounter,++tokencounter,yytext,"PUNCTUATION","LEFT_PARENTHESIS");
			yylval.stringValue = strdup(yytext); return LEFT_PARENTHESIS;
		}
")" 	{addToken(linecounter,++tokencounter,yytext,"PUNCTUATION","RIGHT_PARENTHESIS");
			yylval.stringValue = strdup(yytext); return RIGHT_PARENTHESIS;
		}
";" 	{addToken(linecounter,++tokencounter,yytext,"PUNCTUATION","SEMICOLON");
			yylval.stringValue = strdup(yytext); return SEMICOLON;
		}
"," 	{addToken(linecounter,++tokencounter,yytext,"PUNCTUATION","COMMA");
			yylval.stringValue = strdup(yytext); return COMMA;
		}
":" 	{addToken(linecounter,++tokencounter,yytext,"PUNCTUATION","COLON");
			yylval.stringValue = strdup(yytext); return COLON;
		}
"::" 	{addToken(linecounter,++tokencounter,yytext,"PUNCTUATION","DOUBLE_COLON");
			yylval.stringValue = strdup(yytext); return DOUBLE_COLON;
		}
"." 	{addToken(linecounter,++tokencounter,yytext,"PUNCTUATION","DOT");
			yylval.stringValue = strdup(yytext); return DOT;
		}
".." 	{addToken(linecounter,++tokencounter,yytext,"PUNCTUATION","DOUBLE_DOT");
			yylval.stringValue = strdup(yytext); return DOUBLE_DOT;
		}
"'" 	{addToken(linecounter,++tokencounter,yytext,"PUNCTUATION","APOSTROPHE");
			yylval.stringValue = strdup(yytext); return APOSTROPHE;
		}
"?" 	{addToken(linecounter,++tokencounter,yytext,"OPERATOR","QUESTION_MARK");
			yylval.stringValue = strdup(yytext); return QUESTION_MARK;
		}
"&" 	{addToken(linecounter,++tokencounter,yytext,"OPERATOR","AMPERSAND");
			yylval.stringValue = strdup(yytext); return AMPERSAND;
		}
"$$DEBUG" {return DEBUG;}
"&&" 	{
			addToken(linecounter,++tokencounter,yytext,"UNDEFINED CHARACTER","LOGICAL_AND");
			printf("Error: Line: %d : UNDEFINED CHARACTER : &&\n",linecounter);
			exit(1);
		}
"||" 	{
			addToken(linecounter,++tokencounter,yytext,"UNDEFINED CHARACTER","LOGICAL_OR");
			printf("Error: Line: %d : UNDEFINED CHARACTER : ||\n",linecounter);
			exit(1);
		}
"_d" 	{
			addToken(linecounter,++tokencounter,yytext,"UNDEFINED CHARACTER","_d");
			printf("Error: Line: %d : UNDEFINED CHARACTER : _d\n",linecounter);
			exit(1);
		}
"`" 	{
			addToken(linecounter,++tokencounter,yytext,"UNDEFINED CHARACTER","`");
			printf("Error: Line: %d : UNDEFINED CHARACTER : `\n",linecounter);
			exit(1);
		}
"~" 	{
			addToken(linecounter,++tokencounter,yytext,"UNDEFINED CHARACTER","~");
			printf("Error: Line: %d : UNDEFINED CHARACTER : ~\n",linecounter);
			exit(1);
		}
"!" 	{
			addToken(linecounter,++tokencounter,yytext,"UNDEFINED CHARACTER","!");
			printf("Error: Line: %d : UNDEFINED CHARACTER : !\n",linecounter);
			exit(1);
		}
"@" 	{
			addToken(linecounter,++tokencounter,yytext,"UNDEFINED CHARACTER","@");
			printf("Error: Line: %d : UNDEFINED CHARACTER : @\n",linecounter);
			exit(1);
		}
"#" 	{
			addToken(linecounter,++tokencounter,yytext,"UNDEFINED CHARACTER","#");
			printf("Error: Line: %d : UNDEFINED CHARACTER : #\n",linecounter);
			exit(1);
		}
"$" 	{
			addToken(linecounter,++tokencounter,yytext,"UNDEFINED CHARACTER","$");
			printf("Error: Line: %d : UNDEFINED CHARACTER : $\n",linecounter);
			exit(1);
		}
"^" 	{
			addToken(linecounter,++tokencounter,yytext,"UNDEFINED CHARACTER","^");
			printf("Error: Line: %d : UNDEFINED CHARACTER : ^\n",linecounter);
			exit(1);
		}
"_" 	{
			addToken(linecounter,++tokencounter,yytext,"UNDEFINED CHARACTER","_");
			printf("Error: Line: %d : UNDEFINED CHARACTER : _\n",linecounter);
			exit(1);
		}


"//".* {addToken(linecounter,++tokencounter," ","COMMENT","LINE_COMMENT");}
"/*" {
		char c=input();
		char argu[30];
		int line=linecounter;
		char previous;
		int ddouble=0;
		int nest=0;
		while(1){
			if(c=='\n'){
				linecounter++;
			}
			previous=c;
			c=input();

			if(c=='/'){
				if(previous=='*'){
					if(nest!=0){
						if(ddouble==1){
							ddouble=0;
						}else{
							addToken(line,++tokencounter," ","COMMENT","NESTED_COMMENT");
							nest--;
							ddouble=1;
						}
					}else{
						snprintf(argu,sizeof(argu),"%d - %d",line,linecounter);
						addToken(line,++tokencounter,argu,"COMMENT","BLOCK_COMMENT");
						break;
					}
				}else ddouble=0;
			}else if(c=='*'){
				if(previous=='/'){
					if(ddouble==1){
						ddouble=0;
					}else{
						nest++;
						ddouble=1;
					}
					
				}else ddouble=0;
			}else if(c==EOF){
				printf("Error: Line:%d : Block comment not closed\n",linecounter);
				exit(1);
			}else{
				ddouble=0;
			}

		}
		
}

"\"" {
	char *headofstring;
	char *str;
	char c;
	int i=0;
	int line=linecounter;
	str=malloc(sizeof(char));
	headofstring=str;
	while((c=input())!=EOF){
		if(c=='\n'){
			linecounter++;
		}
		if(c=='\\'){
			c=input();
			if(c==EOF)break;
			
			if(c=='n'){
				*(str+i)='\n';
				/*linecounter++; allazei to linecounter akoma kai otan grafeis xeirokinita to \n opote to string "\n\n\n" prosthetei 3 grammes*/
			}
			else if(c=='\\'){
				*(str+i)='\\';
			}
			else if(c=='t'){
				*(str+i)='\t';
			}
			else if(c=='\"'){
				*(str+i)='\"';
			}else{
				*(str+i)='\\';
				str=realloc(str,strlen(str)+sizeof(char));
				i++;
				*(str+i)=c;
				printf("Warning! String containts illegal escape character %c\n",c);
			}
		}else if(c=='\"'){
			/**(str+i)=c;*/
			*(str+i)='\0';
			addToken(line,++tokencounter,headofstring,"STRING",headofstring);
			yylval.stringValue = strdup(headofstring); return STRING;
			break;
		}else *(str+i)=c;
		str=realloc(str,strlen(str)+sizeof(char));
		i++;

	}
	if(c==EOF){
		printf("Error: Line:%d : String not closed\n",linecounter);
		exit(1);
	}
}

[0-9]+ {addToken(linecounter,++tokencounter,yytext,"CONST_INT","PRINT_DEFINITION");
			yylval.intValue = atoi(yytext); return CONST_INT;
		}

[0-9]+\.[0-9]+ {addToken(linecounter,++tokencounter,yytext,"CONST_FLOAT","PRINT_DEFINITION");
			yylval.realValue = atof(yytext); return CONST_FLOAT;
		}

[a-zA-Z][a-zA-Z_0-9]* {addToken(linecounter,++tokencounter,yytext,"IDENTIFIER","PRINT_DEFINITION");
			yylval.stringValue = strdup(yytext); return IDENTIFIER;
		}



\n {++linecounter;}


%%

