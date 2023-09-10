/*
============================================================================
Name : 21.c
Author : Farman Ahmed
Description : Write a program, call fork and print the parent and child process id.
Date: 10th September, 2023.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>
int main(){
    pid_t parent= getppid();
    pid_t process= getpid();
    pid_t pid=fork();
    printf("child process: %d\n",process);
    printf("parent process: %d\n",parent);
}