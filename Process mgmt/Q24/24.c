#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    pid_t pid;
    pid=fork();
    if(pid<0){
        printf("forkfailed\n");
        exit(1);
    }
    if(pid==0){
        printf("In child\n");
        sleep(30);
    }else{
        printf("In parent\n");
        exit(0);
    }
    return 0;
}