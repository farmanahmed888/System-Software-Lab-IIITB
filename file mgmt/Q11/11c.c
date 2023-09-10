/*
============================================================================
Name : 11c.c
Author : Farman Ahmed
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
c. use fcntl
Date: 10th September, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(void){
    int fdOne, fdTwo;
    fdOne = open("misc.txt", O_CREAT | O_TRUNC, S_IRWXU, O_APPEND);
    if(fdOne < 0){
        printf("Error opening / creating test.txt. ");
        if(errno==EACCES){
            printf("Error #%d (EACCES): Permission denied.\n", EACCES);
            exit(EXIT_FAILURE);
        }
    } else {
        printf("test.txt created / opened ");
        printf("with file descriptor %d.\n", fdOne);
    }
    //lets use the fcntl() function to copy the 
    //file descriptor
   if((fdTwo = fcntl(fdOne, F_DUPFD, 0))<0){
       printf("Error duplicating file descriptor.\n");
       exit(EXIT_FAILURE);
   } else {
       printf("File descriptor duplicated. ");
       printf("New file descriptor is %d.\n", fdTwo);
       write(fdTwo,"This will also be output to the file named dup.txt\n", 51);
   }
    close(fdOne);
    close(fdTwo);    
    return 0;
    
}