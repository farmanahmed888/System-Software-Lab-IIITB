/*
============================================================================
Name : 8.c
Author : Farman Ahmed
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.
Date: 10th September, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h> // For exit()
int main(){
    FILE *f1;
    f1=fopen("abc.txt", "r");
    if(f1==NULL){
        printf("error");
        exit(0);
    }
    do{
        char c=fgetc(f1);
        if(feof(f1)) break;
        printf("%c",c);
    }while(1);
    return 0;
}