#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

struct Course{
    char course_code[100];
	char course_name[100];
    char facultyUID[100];
    int  credits;
    int  currentStudentsEnrolled;
    int  maxStudentsAllowed;
	int status;
	int studentIsEnrolled;
	//status=1 course active
	//status=0 course removed
};
struct Admin{
	char name[100];
	char emailId[100];
	char password[100];
};
struct Student{
	char name[100];
	char rollno[100];
	char emailId[100];
	char password[100];
	int  status;
	struct Course courseEnrolled;
};
struct Faculty{
	char name[100];
    char facultyUID[100];
	char password[100];
	struct Course courseOffered;
};


int main(){
    int fd=open("StudentsInCourses.txt",O_RDONLY,0666);
    struct Student abc;
    while(read(fd,&abc,sizeof(abc))>0){
        printf("course enrolled  %s\n",abc.courseEnrolled.course_code);
        printf("Course name  %s\n",abc.courseEnrolled.course_name);
        printf("course active?   %d\n",abc.courseEnrolled.status);
        printf("is student enrolled  %d\n",abc.courseEnrolled.studentIsEnrolled);
    }
    
    
}