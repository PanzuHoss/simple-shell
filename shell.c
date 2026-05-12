#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include <unistd.h>

#define TOK_DELIM " \t\r\n"
#define RED " \033[0;31m"
#define RESET " \e[0m"
#define TK_BUFF_SIZE 64

int s_exit(char **);
void s_loop();
char **split_line(char *);
char *read_line();
int s_execute(char **);

void main(){
    s_loop();
}

int s_exit(char **args){
    return 0;
}

void s_loop(){
    int a=1;
    char *line, **args;
    do{
        printf("> ");
        line = read_line();
        args = split_line(line);
        a=s_execute(args);
        free(line);
        free(args);
    }while(a);
}

char *read_line(){
    
    int buffersize=1024, position = 0, c;
    char * buffer = malloc(buffersize * sizeof(char));

    if(!buffer){
        fprintf(stderr,"%s Allocation Error! %s\n",RED,RESET);
        exit(EXIT_FAILURE);
    }

    while(1){
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

char **split_line(char *line){
    int buffersize= TK_BUFF_SIZE, position = 0; 
    char **tokens = malloc(buffersize*sizeof(char *));
    char *token;

    if(!tokens){
        fprintf(stderr,"%s Error in memory allocation (**split)! %s \n",RED, RESET);
        exit(EXIT_FAILURE);
    }

    token = strtok(line,TOK_DELIM);
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

int s_execute(char **args){
    pid_t cpid;
    int status;
   
    if(args[0]==NULL) return 1;

    if(strcmp(args[0],"exit")==0){
        return s_exit(args);
    }
    cpid=fork();
    
    if(cpid==0){
        if(execvp(args[0],args)<0){
            printf("Invalid Command : %s\n",args[0]);
            exit(EXIT_FAILURE);
        };
    }
        
    else if(cpid<0)
       printf(RED "ERROR IN FORKING!" RESET "\n");

    else
        waitpid(cpid,&status,WUNTRACED);
    return 1;
}
