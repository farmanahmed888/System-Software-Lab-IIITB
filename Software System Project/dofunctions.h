#ifdef DOFUNCTIONS_H
#define DOFUNCTIONS_H
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "database.h"
#include "Search.h"

void AddStudent(){
    struct Student addThisStudent;
    printf("Enter Name of student\n");
    scanf("%s",addThisStudent.name);
    printf("Enter Roll Number of student\n");
    scanf("%s",addThisStudent.rollno);
    printf("Enter Email ID of student\n");
    scanf("%s",addThisStudent.emailId);
    printf("Enter Password of student\n");
    scanf("%s",addThisStudent.password);
    

    
    int checker=searchStudent("Student.txt",addThisStudent.rollno);
    if(checker==0){
        printf("Duplicate Entry\n");
        return;
    }else{
        int fd=open("Student.txt",O_RDONLY|O_CREAT|O_APPEND,0666);
        if(fd==-1){
            printf("Error in adding entry\n");
            return;
        }
        addThisStudent.status=1;
        write(fd,&addThisStudent,sizeof(addThisStudent));
        printf("Student ID is created with Roll Number:  %s\n",addThisStudent.rollno);
        close(fd);
    }
}
void ViewStudent(){
    char inputRollNo[100];
    struct Student viewThisStudent;
    printf("Enter student Roll Number\n");
    scanf("%s",inputRollNo);
    
    int checker=searchStudent("Student.txt",inputRollNo);
    if(checker==0){
        printf("---x--- Student Details ---x---\n");
        printf("Student Name:  %s\n",viewThisStudent.name);
        printf("Student Roll Number:  %s\n",viewThisStudent.rollno);
        printf("Student EmailID:   %s\n",viewThisStudent.emailId);
        printf("Student Active Status:   %d\n",viewThisStudent.status);
        printf("---x--- Student Details ---x---\n");
    }else{
        printf("Student Record Not found\n");
    }
}
void AddFaculty(){
    struct Faculty addThisFaculty;
    printf("Enter Name of faculty\n");
    scanf("%s",addThisFaculty.name);
    printf("Enter Email ID of faculty\n");
    scanf("%s",addThisFaculty.emailId);
    printf("Enter Password of faculty\n");
    scanf("%s",addThisFaculty.password);

    int checker=searchFaculty("Facutly.txt",addThisFaculty.emailId);
    if(checker==0){
        printf("Duplicate Entry\n");
        return;
    }else{
        int fd=open("Faculty.txt",O_RDONLY|O_APPEND,0666);
        if(fd==-1){
            printf("Error in adding entry\n");
            return;
        }
        write(fd,&addThisFaculty,sizeof(addThisFaculty));
        printf("Faculty ID is created with EmailID:  %s\n",addThisFaculty.emailId);
        close(fd);
    }
}
void ViewFaculty(){
    char inputEmailID[100];
    struct Faculty viewThisFaculty;
    printf("Enter EmailID of faculty\n");
    scanf("%s",inputEmailID);
    int checker=searchFaculty("Faculty.txt", inputEmailID);
    if(checker==0){
        printf("---x--- Faculty Details ---x---\n");
        printf("Faculty Name:  %s\n",viewThisFaculty.name);
        printf("Faculty EmailID:   %s\n",viewThisFaculty.emailId);
        printf("---x--- Faculty Details ---x---\n");
    }else {
        printf("Faculty Record Not found\n");
    }
}
void ActivateStudent(){
    printf("Enter Roll Number of Student to be Activated\n");
    char inputRollNo[100];
    struct Student activateThisStudent;
    scanf("%s",inputRollNo);
    int checker=searchStudent("Student.txt",inputRollNo);
    if(checker==0){
        int fd=open("Student.txt",O_RDWR,0666);
        if(fd==-1){
            printf("Error in adding entry\n");
            return;
        }
        while(read(fd,&activateThisStudent,sizeof(activateThisStudent))>0){
            if(strcmp(activateThisStudent.rollno,inputRollNo)==0){
                lseek(fd,-sizeof(activateThisStudent),SEEK_CUR);
                activateThisStudent.status=1;
                write(fd,&activateThisStudent,sizeof(activateThisStudent));
                close(fd);
                printf("Student with Roll Number %s  is now activated\n",activateThisStudent.rollno);
            }
        }
    }else{
        printf("Student Record not found\n");
    }
}
void BlockStudent(){
    printf("Enter Roll Number of Student to be Deactivated\n");
    char inputRollNo[100];
    struct Student deactivateThisStudent;
    scanf("%s",inputRollNo);
    int checker=searchStudent("Student.txt",inputRollNo);
    if(checker==0){
        int fd=open("Student.txt",O_RDWR,0666);
        if(fd==-1){
            printf("Error in adding entry\n");
            return;
        }
        while(read(fd,&deactivateThisStudent,sizeof(deactivateThisStudent))>0){
            if(strcmp(deactivateThisStudent.rollno,inputRollNo)==0){
                lseek(fd,-sizeof(deactivateThisStudent),SEEK_CUR);
                deactivateThisStudent.status=0;
                write(fd,&deactivateThisStudent,sizeof(deactivateThisStudent));
                close(fd);
                printf("Student with Roll Number %s  is now deactivated\n",deactivateThisStudent.rollno);
            }
        }
    }else{
        printf("Student Record not found\n");
    }
}
void ModifyStudent(){
    printf("Enter Roll Number of student to modify\n");
    char inputRollNo[100];
    scanf("%s",inputRollNo);
    struct Student chkStudent;
    int checker=searchStudent("Student.txt",inputRollNo);
    if(checker==0){
        int fd=open("Student.txt",O_RDWR,0666);
        if(fd==-1){
            printf("Error in modifying entry\n");
            return;
        }
        while(read(fd,&chkStudent,sizeof(chkStudent))>0){
            if(strcmp(chkStudent.rollno,inputRollNo)==0){
                printf("What do you want to modify?\n");
                printf("1. Name\n");
                printf("2. Roll Number\n");
                printf("3. Email ID\n");
                printf("4. Password\n");
                printf("5. Active/Inactive Status\n");
                printf("6. Add a course\n");
                printf("7. Drop a course\n");
                int action;
                scanf("%d",&action);
                
            }
        }
    }else{
        printf("Student Record not found\n");
    }
}
void ModifyFaculty(){

}
#endif