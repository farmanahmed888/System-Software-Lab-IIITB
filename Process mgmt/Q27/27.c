/*
============================================================================
Name : 27.c
Author : Farman Ahmed
Description : Write a program to execute ls -Rl by the following system calls a. execl
b. execlp
c. execle
d. execv 
e. execvp
Date: 10th September, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//move 27.c to Process mgmt for better tree
int main(){
    //execl demo uncomment line 7
    //int a=execl("/bin/ls","ls","-Rl",NULL);
    //execl demo uncomment line 9
    //int a=execlp("ls","ls","-Rl",NULL);
    //execle demo uncomment line 11 and 12
    //char *envp[]={NULL};
    //int a=execle("/bin/ls","ls","-Rl",NULL,envp);
    //execv demo uncomment line 14 and 15
    //char *envp[]={"ls","-Rl",NULL};
    //int a=execv("/bin/ls",envp);
    //execvp demo uncomment line 17 and 18
    //char *envp[]={"ls","-Rl",NULL};
    //int a=execvp("ls",envp);
    //if(a==-1){
    //    printf("error command failed\n");
    //}
}