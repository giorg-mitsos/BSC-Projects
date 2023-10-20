#include <stdio.h>
#include <stdlib.h>


int main(int argc, char  *argv[]){
    FILE *binr;
    if(argc>1){
        if(!(binr = fopen(argv[1],"rb"))){
            fprintf(stderr,"Cannot read file : %s\n",argv[1]);
            exit(1);
        }
        else{
            decode(binr);
        }

    }
    
}