#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <fcntl.h>

#include"Database.h"

int AddStudent(struct Student addStudent){
    const char* fileName="Student.txt";
    int fd=open(fileName,O_WRONLY|O_APPEND,0666);
    if(fd==-1){
        printf("Error Adding Student\n");
        return -1;
    }
    write(fd,&addStudent,sizeof(addStudent));
    return 0;
}
int updateStatusStudent(struct Student updateStudent){
    struct Student buffStudent;
    const char* fileName="Student.txt";
    int fd=open(fileName,O_WRONLY,0666);
    if(fd==-1){
        printf("Error Adding Student\n");
        return -1;
    }
    while(read(fd,&buffStudent,sizeof(buffStudent))>0){
        if(strcmp(buffStudent.rollno,updateStudent.rollno)==0){
            write(fd,&updateStudent,sizeof(updateStudent));
            return 1;
        }
    }
    return 0;
}

int AddFaculty(struct Faculty addFaculty){
    const char* fileName="Faculty.txt";
    int fd=open(fileName,O_WRONLY|O_APPEND,0666);
    if(fd==-1){
        printf("Error Adding Faculty\n");
        return -1;
    }
    write(fd,&addFaculty,sizeof(addFaculty));
    
    return 0;
}