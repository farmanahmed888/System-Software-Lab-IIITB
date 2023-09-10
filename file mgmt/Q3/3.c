/*
============================================================================
Name : 3.c
Author : Farman Ahmed
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 10th September, 2023.
============================================================================
*/
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
extern int errno;
int main(){
    int fd=open("foo.txt",O_RDONLY|O_CREAT);
    printf("fd =  %d\n",fd);
    if(fd==-1){
        printf("error number %d\n",errno);
        perror("program");
    }
    return 0;
}