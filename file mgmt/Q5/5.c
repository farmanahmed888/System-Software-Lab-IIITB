/*
============================================================================
Name : 5.c
Author : Farman Ahmed
Description : Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: 10th September, 2023.
============================================================================
*/
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
extern int errno;
int main(){
    int fd1=open("foo.txt",O_RDONLY|O_CREAT);
    int fd2=open("foo.txt",O_RDONLY|O_CREAT);
    int fd3=open("foo.txt",O_RDONLY|O_CREAT);
    int fd4=open("foo.txt",O_RDONLY|O_CREAT);
    int fd5=open("foo.txt",O_RDONLY|O_CREAT);


    printf("fd =  %d\n",fd1);
    printf("fd =  %d\n",fd2);
    printf("fd =  %d\n",fd3);
    printf("fd =  %d\n",fd4);
    printf("fd =  %d\n",fd5);


    if(fd1==-1){
        printf("error number %d\n",errno);
        perror("program");
    }
    if(fd2==-1){
        printf("error number %d\n",errno);
        perror("program");
    }
    if(fd3==-1){
        printf("error number %d\n",errno);
        perror("program");
    }
    if(fd4==-1){
        printf("error number %d\n",errno);
        perror("program");
    }
    if(fd5==-1){
        printf("error number %d\n",errno);
        perror("program");
    }

    
    //infinte loop
    while(1){

    }
    return 0;
}