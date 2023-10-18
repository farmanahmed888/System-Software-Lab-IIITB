/*
============================================================================
Name : 14.c
Author : Farman Ahmed
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 12th Oct, 2023.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main(){
    int pipefd[2];
    char msg[]="Write here";
    char buffer[100];
    if(pipe(pipefd)==-1){
        printf("error\n");
        return -1;
    }
    ssize_t num_bytes = write(pipefd[1], msg, sizeof(msg));
    if (num_bytes == -1) {
        printf("write error\n");
        return -1;
    }
    close(pipefd[1]);
    num_bytes = read(pipefd[0], buffer, sizeof(buffer));
    if (num_bytes == -1) {
        printf("read error\n");
        return -1;
    }
    printf("%s\n",buffer);
}