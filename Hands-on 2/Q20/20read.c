/*
============================================================================
Name : 20.c
Author : Farman Ahmed
Description :Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 15th Oct, 2023.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(){
    int fd=open("myfifo",O_RDONLY);
    char buff[10000];
    ssize_t r=read(fd,buff,sizeof(buff));
    //buff[r]='\0';
    printf("%s\n",buff);
    close(fd);
}