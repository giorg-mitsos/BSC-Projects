a:	PhaseA.l
	lex PhaseA.l
	gcc -o a.out lex.yy.c
	
b:	PhaseA.l PhaseB.y HeaderB.h
	flex --outfile=PhaseA.c PhaseA.l
	bison --yacc --defines -o PhaseB.c PhaseB.y -v
	gcc -g -o b.out PhaseA.c PhaseB.c -lfl -ly

c:	PhaseA.l PhaseB.y HeaderB.h PhaseC.h
	flex --outfile=PhaseA.c PhaseA.l
	bison --yacc --defines -o PhaseB.c PhaseB.y -v --debug --verbose
	gcc -g -o c.out PhaseA.c PhaseB.c -lfl -ly

compiler:	PhaseA.l PhaseB.y HeaderB.h PhaseC.h PhaseD.h
	flex --outfile=PhaseA.c PhaseA.l
	bison --yacc --defines -o PhaseB.c PhaseB.y -v --debug --verbose
	gcc -g -o compile PhaseA.c PhaseB.c -lfl -ly

executer:	PhaseE.c PhaseEsignatures.h PhaseEimpl.c
		gcc -o run -g PhaseE.c PhaseEimpl.c -lm


all:	PhaseA.l PhaseB.y HeaderB.h PhaseC.h PhaseD.h PhaseE.c PhaseEsignatures.h PhaseEimpl.c 
	flex --outfile=PhaseA.c PhaseA.l
	bison --yacc --defines -o PhaseB.c PhaseB.y -v --debug --verbose
	gcc -g -o compile PhaseA.c PhaseB.c -lfl -ly -lm
	gcc -o run -g PhaseE.c PhaseEimpl.c -lm
	

clear:	
	rm run compile
	rm PhaseA.c PhaseB.c
	rm *.output
	rm *.abc
	rm *.txt


