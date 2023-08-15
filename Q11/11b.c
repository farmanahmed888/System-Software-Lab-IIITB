#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
  
int main()
{
    int file_desc = open("test.txt",O_WRONLY | O_APPEND);
    dup2(file_desc, 1) ; 
    printf("I will be printed in the file test.txt\n");
return 0;
}