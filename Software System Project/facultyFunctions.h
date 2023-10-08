#ifndef FACULTYFUNCTIONS_H
#define FACULTYFUNCTIONS_H
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


#include "Search.h"
#include "database.h"
void ViewOfferingCourse(const char* searchfacultyUID){
    //view their courses
    int fd=open("Courses.txt",O_RDONLY,0666);
    if(fd==-1){
        printf("Cannot access Faculty database\n");
        return;
    }
    struct Course thisFacultyCourse;
    while(read(fd,&thisFacultyCourse,sizeof(thisFacultyCourse))>0){
        if(strcmp(thisFacultyCourse.facultyUID,searchfacultyUID)==0){
            //found faculty courses
            printf("This Course is taken by %s\n",thisFacultyCourse.facultyUID);
            printf("Course code: %s\n",thisFacultyCourse.course_code);
            printf("Course name: %s\n",thisFacultyCourse.course_name);
            printf("Course credits: %d\n",thisFacultyCourse.credits);
        }
    }
}
void AddNewCourse(const char* inputfacultyUID){
    struct Course addThisCourse;
    printf("Enter Course Code\n");
    scanf("%s",addThisCourse.course_code);
    printf("Enter Course Name\n");
    scanf("%s",addThisCourse.course_name);
    printf("Enter Credits\n");
    scanf("%d",&addThisCourse.credits);
    printf("Enter Max Students allowed\n");
    scanf("%d",&addThisCourse.maxStudentsAllowed);
    addThisCourse.currentStudentsEnrolled=0;
    strcpy(addThisCourse.facultyUID,inputfacultyUID);



    if(universalSearch("Courses.txt", addThisCourse.course_code, 2)==0){
        printf("The course is already present\n");
        return;
    }    
    int fd=open("Courses.txt",O_RDWR|O_CREAT|O_APPEND,0666);
    if(fd==-1){
        printf("Unable to access Courses database\n");
        return;
    }
    if(write(fd,&addThisCourse,sizeof(addThisCourse))>0){
        printf("Course added with courseID:  %s",addThisCourse.course_code);
    }else{
        printf("Unable to add course with courseID:  %s",addThisCourse.course_code);
    }
    close(fd);
    return;
}
void RemoveCourse(const char* inputfacultyUID){
    
}
void ChangePassword(const char* inputfacultyUID){
    struct Faculty changeThisPassword;
    int fd= open("faculty.txt",O_RDWR,0666);
    if(fd==-1){
            printf("Unable to access Faculty database\n");
            return;
    }
    while(read(fd,&changeThisPassword,sizeof(changeThisPassword))>0){
        if(strcmp(changeThisPassword.facultyUID, inputfacultyUID)==0){
            printf("Enter New Password for faculty id: %s\n",inputfacultyUID);
            scanf("%s",changeThisPassword.password);
            if(write(fd,&changeThisPassword,sizeof(changeThisPassword))>0){
                printf("Password changed!!!\n");
                close(fd);
                return;
            }else{
                printf("Password changed failed!!!\n");
                close(fd);
                return;
            }
        }
    }
    close(fd);
}
#endif