/*
============================================================================
Name : 12.c
Author : Farman Ahmed
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 10th September, 2023.
============================================================================
*/
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
    FILE *file = fopen("abc.txt", "r");
    int fd = fileno(file);
    int mode = fcntl(fd, F_GETFL);
    printf("mode of file descriptor is: %d\n",mode);
    return 0;
    //stackoverflow gyan
    //https://stackoverflow.com/questions/54421107/how-to-catch-file-mode
}
