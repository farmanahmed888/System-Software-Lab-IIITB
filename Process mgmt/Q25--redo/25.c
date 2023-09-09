#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(){
    int status;
    pid_t pid,child_pid[3];
    for(int i=0;i<3;i++){
        pid=fork();
        if(pid==-1){
            printf("fork failed%d\n",i);
        }else if(pid==0){
            printf("child process %d \n",i);
            printf("child pid %d\n",getpid());
            sleep(10);
            printf("child pid done %d \n",getpid());
        }else{
            child_pid[i]=pid;
        }
    }
    pid_t pickpid=child_pid[2];
    printf("parent waiting for pid%d\n",pickpid);
    pid=waitpid(pickpid, &status, 0);
    if(pid==-1){
        printf("waitpid error\n");
    }
    if(WIFEXITED(status)){
        printf("Parent: Child with PID %d exited with status %d\n",pid,WIFEXITED(status));
    }
}