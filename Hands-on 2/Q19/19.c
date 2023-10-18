/*
============================================================================
Name : 19.c
Author : Farman Ahmed
Description : Create a FIFO file by
a. mknod command
Date: 14th Oct, 2023.
============================================================================
*/
#include <sys/stat.h>
#include <stdio.h>
int main(){
    int fd=mknod("myfifo",S_IFIFO|0666,0);
    if(fd==-1){
        printf("error\n");
        return -1;
    }
    printf("success\n");
    return 0;
}