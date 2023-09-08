#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(){
    pid_t pid;
    pid=fork();
    int abc=-1;
    if(pid<0){
        printf("forkfailed\n");
        exit(1);
    }
    if(pid==0){
        printf("In child\n");
        exit(0);
    }else{
        sleep(10);
        printf("In parent\n");
    }
    return 0;
}