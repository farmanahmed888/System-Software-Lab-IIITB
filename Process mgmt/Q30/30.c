#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    pid_t pid=fork();
    if(pid==-1){
        printf("fork failed\n");
    }
    if(pid==0){
        //child process
        sleep(10);
        int a=execlp("ls","ls","-Rl",NULL);
        //don't know how to run script at particular time
        if(a==-1) printf("command execution failed.\n");
    }else{
        //parent process
        printf("parent process\n");       
    }
}