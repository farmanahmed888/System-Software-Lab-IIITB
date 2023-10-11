#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
struct Course{
    char course_code[100];
	char course_name[100];
    char facultyUID[100];
    int  credits;
    int  currentStudentsEnrolled;
    int  maxStudentsAllowed;
    int status;
};
struct Faculty{
	char name[100];
    char facultyUID[100];
	char emailId[100];
	char password[100];
	struct Course courseOffered;
};
int fun( char ans[]){
    int fd=open("Faculty.txt",O_RDWR|O_CREAT,0666);
    struct Faculty chkFaculty;
    char inputfUID[100];
    scanf("%s",inputfUID);
    while(read(fd,&chkFaculty,sizeof(chkFaculty))>0){
        if(strcmp(chkFaculty.facultyUID,inputfUID)==0){
            strcpy(ans,chkFaculty.facultyUID);
            return 1;
        }
    }
    return 0;

}
int main(){
    char ans[100];
    fun(ans);
    printf("%s\n",ans);
}