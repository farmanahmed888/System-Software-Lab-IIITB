#ifndef SEARCH_H
#define SEARCH_H
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "database.h"
int searchStudent(const char* fileName,
                  const char* inputRollNo){
    int fd=open(fileName,O_RDONLY|O_CREAT,0666);
    if(fd==-1){
        printf("checking for entry failed coz file does not exist yet\n");
        return -1;
    }
    struct Student searchEntry;
    //because of while loop we will move cursor, hence we need to move it back to start
    lseek(fd,SEEK_SET,0);
    while(read(fd,&searchEntry,sizeof(searchEntry))>0){
        if(strcmp(searchEntry.rollno,inputRollNo)==0){
            //duplicate found
            //entry present
            close(fd);
            return 0;
        }
    }
    close(fd);
    return 1;
}
int searchFaculty(const char* fileName,
                  const char* inputEmailID){
    int fd=open(fileName,O_RDONLY);
    if(fd==-1){
        printf("checking for entry failed\n");
    }
    struct Faculty searchEntry;
    while(read(fd,&searchEntry,sizeof(searchEntry))>0){
        if(strcmp(searchEntry.emailId,inputEmailID)==0){
            close(fd);
            return 0;
        }
    }
    close(fd);
    return 1;
}
#endif