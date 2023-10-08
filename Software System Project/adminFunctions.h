#ifndef ADMINFUNCTIONS_H
#define ADMINFUNCTIONS_H
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "database.h"
#include "Search.h"

void AddStudent(){
    struct Student addThisStudent;
    printf("Enter Name of student:\n");
    scanf("%s",addThisStudent.name);
    printf("Enter Roll Number of student:\n");
    scanf("%s",addThisStudent.rollno);
    printf("Enter Email ID of student:\n");
    scanf("%s",addThisStudent.emailId);
    printf("Enter Password of student:\n");
    scanf("%s",addThisStudent.password);
    int checker=universalSearch("Student.txt", addThisStudent.rollno,0);
    if(checker==-1){
        printf("Checking for duplicate failed\n");
        return;
    }else if(checker==0){
        printf("Duplicate entry\n");
        return;
    }else{
        int fd=open("Student.txt",O_RDWR|O_CREAT|O_APPEND,0666);
        if(fd==-1){
            printf("Unable to access student database\n");
            return;
        }
        addThisStudent.status=1;
        if(write(fd,&addThisStudent,sizeof(addThisStudent))>0){
            printf("student added successfully with roll number:  %s\n",addThisStudent.rollno);
        }else{
            printf("unable to add this student with roll number:  %s\n",addThisStudent.rollno);
            
        }
        close(fd);
    }
    
    
}
void ViewStudent(){
    char inputRollNo[100];
    struct Student viewThisStudent;
    printf("Enter student Roll Number\n");
    scanf("%s",inputRollNo);
    int fd=open("Student.txt",O_RDONLY|O_CREAT,0666);
    if(fd==-1){
        printf("Unable to search for student\n");
        return;
    }
    while(read(fd,&viewThisStudent,sizeof(viewThisStudent))>0){
        if(strcmp(inputRollNo,viewThisStudent.rollno)==0){
            //found match
            printf("Student Roll Number:   %s\n",viewThisStudent.rollno);
            printf("Student Name:   %s\n",viewThisStudent.name);
            printf("Student EmailID:   %s\n",viewThisStudent.emailId);
            printf("Student Status:   %d\n",viewThisStudent.status);
            close(fd);
            return;
        }
    }
    printf("Unable to find the record:  %s\n", inputRollNo);
    close(fd);
    return;
}
void AddFaculty(){
    struct Faculty addThisFaculty;
    printf("Enter Name of faculty\n");
    scanf("%s",addThisFaculty.name);
    printf("Enter UniqueID of faculty\n");
    scanf("%s",addThisFaculty.facultyUID);
    printf("Enter Email ID of faculty\n");
    scanf("%s",addThisFaculty.emailId);
    printf("Enter Password of faculty\n");
    scanf("%s",addThisFaculty.password);

    int checker=universalSearch("Faculty.txt",addThisFaculty.facultyUID,1);
    if(checker==-1){
        printf("Checking for duplicate failed\n");
        return;
    }else if(checker==0){
        printf("Duplicate Entry\n");
        return;
    }else{
        int fd=open("Faculty.txt",O_RDWR|O_CREAT|O_APPEND,0666);
        if(fd==-1){
            printf("Unable to access faculty database\n");
            return;
        }
        if(write(fd,&addThisFaculty,sizeof(addThisFaculty))>0){
            printf("Faculty ID is created with UniqueID:  %s\n",addThisFaculty.facultyUID);
        }else{
            printf("Unable to create Faculty with UniqueID:   %s\n",addThisFaculty.facultyUID);
        }
        close(fd);
    }
}
void ViewFaculty(){
    char inputUID[100];
    struct Faculty viewThisFaculty;
    printf("Enter UID of faculty\n");
    scanf("%s",inputUID);
    int fd=open("Faculty.txt",O_RDONLY,0666);
    if(fd==-1){
        printf("Unable to search for faculty\n");
        return;
    }
    lseek(fd,0,SEEK_SET);
    while(read(fd,&viewThisFaculty,sizeof(viewThisFaculty))>0){
        if(strcmp(inputUID,viewThisFaculty.facultyUID)==0){
            //found match
            printf("Faculty Roll Number:   %s\n",viewThisFaculty.facultyUID);
            printf("Faculty Name:   %s\n",viewThisFaculty.name);
            printf("Faculty EmailID:   %s\n",viewThisFaculty.emailId);
            close(fd);
            return;
        }
    }
    printf("Unable to find the record:  %s\n", inputUID);
    close(fd);
    return;
    
}
void ActivateStudent(){
    printf("Enter Roll Number of Student to be Activated\n");
    char inputRollNo[100];
    struct Student activateThisStudent;
    scanf("%s",inputRollNo);
    int checker=universalSearch("Student.txt",inputRollNo,0);
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
    int checker=universalSearch("Student.txt",inputRollNo,0);
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
    int checker=universalSearch("Student.txt",inputRollNo,0);
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
                printf("2. Email ID\n");
                printf("3. Password\n");
                printf("4. Active/Inactive Status\n");
                printf("5. View Courses\n");
                printf("6. Add a course\n");
                printf("7. Drop a course\n");
                int action;
                scanf("%d",&action);
                switch(action){
                    case 1:printf("Enter a new name\n");
                            {
                                scanf("%s",chkStudent.name);
                                break;
                            }
                    case 2:printf("Enter new EmailID\n");
                            {
                                scanf("%s",chkStudent.emailId);
                                break;
                            }
                    case 3:printf("Enter new password\n");
                            {
                                scanf("%s",chkStudent.password);
                                break;
                            }
                    case 4:printf("Enter new Active Status\n");
                            {
                                scanf("%d",&chkStudent.status);
                                break;
                            }
                    case 5:printf("Student has enrolled in following courses\n");
                            {
                                for(int i=0;i<6;i++){
                                    if(strcmp(chkStudent.courseEnrolled[i].course_code,"X")==0 ||
                                       strcmp(chkStudent.courseEnrolled[i].course_code,"x")==0) continue;
                                    printf("Course Code:  %s\n",chkStudent.courseEnrolled[i].course_code);
                                    printf("Course Name:  %s\n",chkStudent.courseEnrolled[i].course_name);
                                    printf("Course Credits:  %d\n",chkStudent.courseEnrolled[i].credits);
                                }
                            }
                    case 6://do later
                    case 7://do later
                    default: printf("invalid option\n");break;
                }
            }
        }
    }else{
        printf("Student Record not found\n");
    }
    return;
}
void ModifyFaculty(){
    //pending
    printf("Enter UID Number of faculty to modify\n");
    char inputUID[100];
    scanf("%s",inputUID);
    struct Faculty chkFaculty;
    int checker=universalSearch("Student.txt",inputUID,0);
    if(checker==0){
        int fd=open("Faculty.txt",O_RDWR,0666);
        if(fd==-1){
            printf("Error in modifying entry\n");
            return;
        }
        while(read(fd,&chkFaculty,sizeof(chkFaculty))>0){
            if(strcmp(chkFaculty.facultyUID,inputUID)==0){
                printf("What do you want to modify?\n");
                printf("1. Name\n");
                printf("2. Email ID\n");
                printf("3. Password\n");
                printf("4. Add new Course\n");
                printf("5. Remove new Course\n");
                int action;
                scanf("%d",&action);
                switch(action){
                    case 1:printf("Enter a new name\n");
                            {
                                scanf("%s",chkFaculty.name);
                                break;
                            }
                    case 2:printf("Enter new EmailID\n");
                            {
                                scanf("%s",chkFaculty.emailId);
                                break;
                            }
                    case 3:printf("Enter new password\n");
                            {
                                scanf("%s",chkFaculty.password);
                                break;
                            }
                    case 4:printf("Enter new Active Status\n");
                            {
                                //do later
                                break;
                            }
                    case 5:printf("Student has enrolled in following courses\n");//change this
                            {
                                //do later
                            }
                    
                    default: printf("invalid option\n");break;
                }
            }
        }
    }else{
        printf("Student Record not found\n");
    }
    return;

}
#endif