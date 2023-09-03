#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(){
    pid_t pid1=fork();
    int status;
    if(pid1<0){
        printf("fork failed\n");
    }
    if(pid1==0){
        printf("in child pid1: %d\n",getpid());
    }else{
        printf("in parent pid1: %d\n",getppid());
        pid_t pid2=fork();
        pid_t w = waitpid(pid2, &status, WUNTRACED | WCONTINUED);
        if(pid2<0){
            printf("fork failed\n");
        }
        if(pid2==0){
            printf("in child pid2: %d\n",getpid());
            printf("parent-child pid2 will wait for me to finish first\n");
            sleep(10);
        }else{
            printf("in parents-child pid2: %d\n",getppid());
            printf("will wait for 10 seconds for %d to finish\n",pid2);
        }
    }
}