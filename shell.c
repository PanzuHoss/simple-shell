#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

#define TOK_DELIM" \t\r\n"
#define RED" \033[0;31m"
#define RESET" \e[0m"
#define TK_BUFF_SIZE 64

int exit(char *);
int loop(char **);
char **split();
char *read();
int execute(char **);

void main(){
    loop();
}

int exit(char *){
    return 0;
}

int loop(char **){
    int a=0;
    char *line, **args;
    do{
        printf("> ");
        line = read();
        args = split(line);
        free(line);
        free(args);
    }while(a);
}

char read(char *){
    
    int buffersize=1024, position = 0;
    int * buffer = malloc(buffersize * sizeof(char));
    int c;

    if(!buffer){
        fprintf(stderr,"%s Allocation Error! %s\n",RED,RESET);
        exit(EXIT_FAILURE);
    }

    else{
        c = getchar();
        if(c==EOF || c =='\n'){
            buffer[position]='\0';
            return buffer;
        }
        else{
            buffer[position]=c;
        }
        
        position++;
    
        if(position >= buffersize){
            buffersize += 1024;
            buffer=realloc(buffer,buffersize);
            if(!buffer){
                fprintf(stderr,"Error in Memory reallocation\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

char **split(char *line){
    int buffersize= TK_BUFF_SIZE, position = 0;+ 
    char **tokens = malloc(buffersize*sizeof(char *));
    char *token;

    if(!token){
        fprintf(stderr,"%s Error in memory allocation (**split)! %s \n",RED, RESET);
        exit(EXIT_FAILURE);
    }

    token = strtok(NULL,TOK_DELIM);
    while(token != NULL){
        tokens[position]=token;
        position++;

        if(position >= buffersize){
            buffersize += TK_BUFF_SIZE;
            tokens = realloc(tokens,buffersize * sizeof(char *));
            if(!tokens){
                fprintf(stderr,"%s Error in Memory Allocation!%s",RED,RESET);
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL,TOK_DELIM);
    }
    tokens[position]=NULL;
    return tokens;
}
