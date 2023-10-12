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
    int fd=open("Courses.txt",O_RDONLY,0666);
    struct Course getStudentDetails;
    while(read(fd,&getStudentDetails,sizeof(getStudentDetails))>0){
        printf("Get Course course code  %s\n",getStudentDetails.course_code);
        printf("Get Course course name  %s\n",getStudentDetails.course_name);
        printf("Get Course facultyUID  %s\n",getStudentDetails.facultyUID);
        printf("Get Course credits  %d\n",getStudentDetails.credits);
        printf("Get Course current student enrolled  %d\n",getStudentDetails.currentStudentsEnrolled);
        printf("Get Course max allowed  %d\n",getStudentDetails.maxStudentsAllowed);
    }
}