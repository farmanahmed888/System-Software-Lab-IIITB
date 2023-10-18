/*
============================================================================
Name : 21prog1.c
Author : Farman Ahmed
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 15th Oct, 2023.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main(){
    int fd1=open("myfifo1",O_RDWR);
    int fd2=open("myfifo2",O_RDWR);
    if(fd1==-1){
        printf("error");
        return -1;
    }
    char buff1[1000];
    char buff2[1000];
    printf("enter something...\n");
    scanf("%[^\n]",buff1);
    write(fd1,buff1,sizeof(buff1));
    sleep(2);
    read(fd2,buff2,sizeof(buff2));
    printf("Text from fifo file is:   %s\n",buff2);

}