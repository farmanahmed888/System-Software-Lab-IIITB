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
        printf("Error changing status Student\n");
        return -1;
    }
    while(read(fd,&buffStudent,sizeof(buffStudent))>0){
        if(strcmp(buffStudent.rollno,updateStudent.rollno)==0){
            lseek(fd,-1*sizeof(buffStudent),SEEK_CUR);
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

int AddCourse(struct Course addCourse){
    const char* fileName="Courses.txt";
    int fd=open(fileName,O_WRONLY|O_APPEND,0666);
    if(fd==-1){
        printf("Error Adding Course\n");
        return -1;
    }
    write(fd,&addCourse,sizeof(addCourse));
    
    return 0;
}

int removeCourse(const char* removeCourse){
    struct Course buffCourse;
    const char* fileName="Courses.txt";
    int fd=open(fileName,O_RDWR,0666);
    if(fd==-1){
        printf("Error removing Course\n");
        return -1;
    }
    while(read(fd,&buffCourse,sizeof(buffCourse))>0){
        if(strcmp(buffCourse.course_code,removeCourse)==0){
            buffCourse.status=0;
            lseek(fd,-1*sizeof(buffCourse),SEEK_CUR);
            write(fd,&removeCourse,sizeof(removeCourse));
            return 1;
        }
    }
    return 0;
}