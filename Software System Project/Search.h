#ifndef SEARCH_H
#define SEARCH_H
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "database.h"
int universalSearch(const char* fileName,
                  const char* inputUID,int flag){
    int fd=open(fileName,O_RDONLY|O_CREAT,0666);
    if(fd==-1){
        printf("checking for entry failed coz file does not exist yet\n");
        return -1;
    }
    if(flag ==0){
         struct Student searchEntry;
        //because of while loop we will move cursor, hence we need to move it back to start
        lseek(fd,0,SEEK_SET);
        while(read(fd,&searchEntry,sizeof(searchEntry))>0){
            if(strcmp(searchEntry.rollno,inputUID)==0){
                //duplicate found
                //entry present
                close(fd);
                return 0;
            }
        }
        close(fd);     
    }else if(flag==1){
        struct Faculty searchEntry;
        //because of while loop we will move cursor, hence we need to move it back to start
        lseek(fd,0,SEEK_SET);
        while(read(fd,&searchEntry,sizeof(searchEntry))>0){
            if(strcmp(searchEntry.facultyUID,inputUID)==0){
                //duplicate found
                //entry present
                close(fd);
                return 0;
            }
        }
        close(fd);
    }else if(flag==2){
        struct Course searchEntry;
        lseek(fd,0,SEEK_SET);
        while(read(fd,&searchEntry,sizeof(searchEntry))>0){
            if(strcmp(searchEntry.facultyUID,inputUID)==0){
                //duplicate found
                //entry present
                close(fd);
                return 0;
            }
        }        
    }
    close(fd);
    return 1;
}
#endif