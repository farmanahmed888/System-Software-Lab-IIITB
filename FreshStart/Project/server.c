#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#include"Authenticator.h"
#include"Database.h"
#include"Search.h"
#include"Add.h"

#define buffsz 100000


int main(int argc, char* argv[]){
    if(argc<2){
        printf("less arguments\n");
        return -1;
    }
    int sockfd,newsockfd,portno,n;
    char buffer[buffsz];
    struct sockaddr_in serv_addr,cli_addr;
    socklen_t clilen;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0){
        printf("Creating socket failed\n");
        return -1;
    }
    bzero((char*)&serv_addr,sizeof(serv_addr));
    portno=atoi(argv[1]);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=INADDR_ANY;
    serv_addr.sin_port=htons(portno);
    if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0){
        printf("Unable to bind\n");
        return -1;
    }
    listen(sockfd,5);
    clilen=sizeof(cli_addr);
    newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clilen);
    if(newsockfd<0){
        printf("error on accept\n");
        return -1;
    }
    //communication between a client and server starts
    while(1){
        //write main menu
        char* mainMenu="Welcome to Academia\n"
                        "Enter your Choice\n"
                        "1. Admin\n"
                        "2. Professor\n"
                        "3. Student\n";
        
        write(newsockfd,mainMenu,strlen(mainMenu));
        //write main menu



        //read choice
        int choice;
        read(newsockfd,&choice,sizeof(int));
        //read choice
        if(choice==1){
            //authentication input

            //write input email msg
            char* EmailMsg="Enter Email:\n";
            write(newsockfd,EmailMsg,strlen(EmailMsg));
            //write input email msg

            //read input email
            char inputEmail[100];
            read(newsockfd,&inputEmail,sizeof(inputEmail));
            //read input email

            //write input Password msg
            char* PasswordMsg="Enter Password:\n";
            write(newsockfd,PasswordMsg,strlen(PasswordMsg));
            //write input Password msg

            //read input password
            char inputPassword[100];
            read(newsockfd,&inputPassword,sizeof(inputPassword));
            //read input password
            int isValid=AuthenticateAdmin(inputEmail,inputPassword);

            //write isvalid to client
            write(newsockfd,&isValid,sizeof(isValid));
            //write isvalid to client
            if(isValid==1){
                //Authentication Successful
                //write adminMenu msg
                char* adminMenu="Welcome to Admin Menu\n"
                                "1.Add Student\n"
                                "2.Add Faculty\n"
                                "3.Activate Student\n"
                                "4.Deactivate Student\n"
                                "5.Update Student Details\n"
                                "6.Update Faculty Details\n"
                                "7.Exit\n";
                write(newsockfd,adminMenu,strlen(adminMenu));
                //write adminMenu msg
                
                //read adminMenu choice
                int adminChoice;
                read(newsockfd,&adminChoice,sizeof(int));
                //read adminMenu choice
                if(adminChoice==1){
                    struct Student addStudent;
                    
                    //write student name
                    char* msg="Enter student name\n";
                    write(newsockfd,msg,strlen(msg));
                    //write student name

                    //read student name
                    read(newsockfd,&addStudent.name,sizeof(addStudent.name));
                    //read student name
                    
                    //write student rollno
                    msg="Enter student rollno\n";
                    write(newsockfd,msg,strlen(msg));
                    //write student rollno

                    //read student rollno
                    read(newsockfd,&addStudent.rollno,sizeof(addStudent.rollno));
                    //read student rollno

                    //write student emailID
                    msg="Enter student emailID\n";
                    write(newsockfd,msg,strlen(msg));
                    //write student emailID

                    //read student emailID
                    read(newsockfd,&addStudent.emailId,sizeof(addStudent.emailId));
                    //read student emailID

                    //write student password
                    msg="Enter student password\n";
                    write(newsockfd,msg,strlen(msg));
                    //write student password

                    //read student password
                    read(newsockfd,&addStudent.password,sizeof(addStudent.password));
                    //read student password
                    int checker=searchStudent(addStudent.rollno);

                    //write checker
                    write(newsockfd,&checker,sizeof(int));
                    //write checker
                    addStudent.status=1;

                    
                    if(checker==-1){
                        //unable to access database
                        break;
                    }else if(checker==0){
                        //duplicate entry
                        break;

                    }else if(checker==1){
                        //unique entry
                        int addStudentEntry=AddStudent(addStudent);
                        //write addStudentEntry
                        write(newsockfd,&addStudentEntry,sizeof(int));
                        //write addStudentEntry
                        if(addStudentEntry==-1){
                            break;
                        }else{
                            //write student added successfully!!!
                            msg="Student added successfully!!!\n";
                            write(newsockfd,msg,strlen(msg));
                            break;
                            //write student added successfully!!!
                        }

                    }else{
                        break;
                    }

                }
                else if(adminChoice==2){
                    struct Faculty addFaculty;
                    
                    //write Faculty name
                    char* msg="Enter faculty name\n";
                    write(newsockfd,msg,strlen(msg));
                    //write Faculty name

                    //read Faculty name
                    read(newsockfd,&addFaculty.name,sizeof(addFaculty.name));
                    //read Faculty name
                    
                    //write Faculty rollno
                    msg="Enter faculty UID\n";
                    write(newsockfd,msg,strlen(msg));
                    //write Faculty rollno

                    //read Faculty uid
                    read(newsockfd,&addFaculty.facultyUID,sizeof(addFaculty.facultyUID));
                    //read Faculty uid

                    //write Faculty emailID
                    msg="Enter faculty emailID\n";
                    write(newsockfd,msg,strlen(msg));
                    //write Faculty emailID

                    //read Faculty emailID
                    read(newsockfd,&addFaculty.emailId,sizeof(addFaculty.emailId));
                    //read Faculty emailID

                    //write Faculty password
                    msg="Enter Faculty password\n";
                    write(newsockfd,msg,strlen(msg));
                    //write Faculty password

                    //read Faculty password
                    read(newsockfd,&addFaculty.password,sizeof(addFaculty.password));
                    //read Faculty password
                    int checker=searchFaculty(addFaculty.facultyUID);

                    //write checker
                    write(newsockfd,&checker,sizeof(int));
                    //write checker

                    
                    if(checker==-1){
                        //unable to access database
                        break;
                    }else if(checker==0){
                        //duplicate entry
                        break;

                    }else if(checker==1){
                        //unique entry
                        int addFacultyEntry=AddFaculty(addFaculty);
                        //write addFacultyEntry
                        write(newsockfd,&addFacultyEntry,sizeof(int));
                        //write addFacultyEntry
                        if(addFacultyEntry==-1){
                            break;
                        }else{
                            //write Faculty added successfully!!!
                            msg="Faculty added successfully!!!\n";
                            write(newsockfd,msg,strlen(msg));
                            break;
                            //write Faculty added successfully!!!
                        }

                    }else{
                        break;
                    }

                }
                else if(adminChoice==3){
                    struct Student activateThisStudent;
                    //write Student UID
                    char* msg="Enter Student rollno\n";
                    write(newsockfd,msg,strlen(msg));
                    //write Student UID

                    //read Student UID
                    read(newsockfd,&activateThisStudent.rollno,sizeof(activateThisStudent.rollno));
                    //read Student UID

                    int checker=searchStudent(activateThisStudent.rollno);
                    //write checker
                    write(newsockfd,&checker,sizeof(int));
                    //write checker

                    if(checker==-1){
                        //unable to access database
                        break;
                    }else if(checker==0){
                        //duplicate entry
                        activateThisStudent.status=1;
                        //update status in database
                        updateStatusStudent(activateThisStudent);
                        //update status in database
                        
                        msg="Student status activated\n";

                        //write student msg
                        write(newsockfd,msg,strlen(msg));
                        //write student msg

                    }else if(checker==1){
                        //unique entry
                        msg="No such student exist\n";

                        //write student not found
                        write(newsockfd,msg,strlen(msg));
                        //write student not found
                        
                        break;
                    }else{
                        break;
                    }
                }
                else if(adminChoice==4){
                    struct Student deactivateThisStudent;
                    //write Student UID
                    char* msg="Enter Student rollno\n";
                    write(newsockfd,msg,strlen(msg));
                    //write Student UID

                    //read Student UID
                    read(newsockfd,&deactivateThisStudent.rollno,sizeof(deactivateThisStudent.rollno));
                    //read Student UID

                    int checker=searchStudent(deactivateThisStudent.rollno);
                    //write checker
                    write(newsockfd,&checker,sizeof(int));
                    //write checker

                    if(checker==-1){
                        //unable to access database
                        break;
                    }else if(checker==0){
                        //duplicate entry
                        deactivateThisStudent.status=0;
                        //update status in database
                        updateStatusStudent(deactivateThisStudent);
                        //update status in database
                        
                        msg="Student status deactivated\n";

                        //write student msg
                        write(newsockfd,msg,strlen(msg));
                        //write student msg

                    }else if(checker==1){
                        //unique entry
                        msg="No such student exist\n";

                        //write student not found
                        write(newsockfd,msg,strlen(msg));
                        //write student not found
                        
                        break;
                    }else{
                        break;
                    }
                }
                else if(adminChoice==5){
                    //update student

                    //write input rollnumber
                    char* msg="Input Rollnumber of student to update\n";
                    write(newsockfd,msg,strlen(msg));
                    //write input rollnumber
                    char inputrollno[100];
                    //read Student UID
                    read(newsockfd,inputrollno,sizeof(inputrollno));
                    //read Student UID

                    int checker=searchStudent(inputrollno);
                    //write checker
                    write(newsockfd,&checker,sizeof(int));
                    //write checker

                    if(checker==-1){
                        //unable to access database
                        break;
                    }else if(checker==0){
                        //duplicate entry
                        int updateNamePass;

                        //write nam/pass
                        msg="Do you want to update Name or Password\n"
                            "1. Name\n"
                            "2. Password\n";
                        write(newsockfd,msg,strlen(msg));
                        //write nam/pass

                        //read namepass value
                        int namePass;
                        read(newsockfd,&namePass,sizeof(int));
                        //read namepass value

                        if(namePass==1){
                            //update Name
                            struct Student updateName;
                            int fd=open("Student.txt",O_RDWR,0666);
                            while(read(fd,&updateName,sizeof(updateName))>0){
                                if(strcmp(updateName.rollno,inputrollno)==0){
                                    //write msg to enter new name
                                    msg="Enter new name\n";
                                    write(newsockfd,msg,strlen(msg));
                                    //write msg to enter new name

                                    //read new name
                                    read(newsockfd,updateName.name,sizeof(updateName.name));
                                    //read new name

                                    lseek(fd,-1*sizeof(updateName),SEEK_CUR);
                                    write(fd,&updateName,sizeof(updateName));

                                    //write msg updation successful
                                    msg="Name has been updated\n";
                                    write(newsockfd,msg,strlen(msg));
                                    //write msg updation successful
                                    break;
                                }
                            }
                            break;
                            

                        }else if(namePass==2){
                            //update password
                            struct Student updatePassword;
                            int fd=open("Student.txt",O_RDONLY,0666);
                            while(read(fd,&updatePassword,sizeof(updatePassword))>0){
                                if(strcmp(updatePassword.rollno,inputrollno)==0){
                                    //write msg to enter new password
                                    msg="Enter new password\n";
                                    write(newsockfd,msg,strlen(msg));
                                    //write msg to enter new password

                                    //read new password
                                    read(newsockfd,updatePassword.password,sizeof(updatePassword.password));
                                    //read new password
                                    lseek(fd,-1*sizeof(updatePassword),SEEK_CUR);
                                    write(fd,&updatePassword,sizeof(updatePassword));

                                    //write msg updation successful
                                    msg="Name has been updated\n";
                                    write(newsockfd,msg,strlen(msg));
                                    //write msg updation successful
                                    break;
                                }
                            }
                            break;
                        }else{
                            break;
                        }

                    }else if(checker==1){
                        //unique entry
                        msg="No such student exist\n";

                        //write student not found
                        write(newsockfd,msg,strlen(msg));
                        //write student not found
                        
                        break;
                    }else{
                        break;
                    }

                }
                else if(adminChoice==6){
                    //update faculty
                    //write input rollnumber
                    char* msg="Input facUID of faculty to update\n";
                    write(newsockfd,msg,strlen(msg));
                    //write input rollnumber
                    char inputUID[100];
                    //read Student UID
                    read(newsockfd,inputUID,sizeof(inputUID));
                    //read Student UID

                    int checker=searchFaculty(inputUID);
                    //write checker
                    write(newsockfd,&checker,sizeof(int));
                    //write checker

                    if(checker==-1){
                        //unable to access database
                        break;
                    }else if(checker==0){
                        //duplicate entry
                        int updateNamePass;

                        //write nam/pass
                        msg="Do you want to update Name or Password\n"
                            "1. Name\n"
                            "2. Password\n";
                        write(newsockfd,msg,strlen(msg));
                        //write nam/pass

                        //read namepass value
                        int namePass;
                        read(newsockfd,&namePass,sizeof(int));
                        //read namepass value

                        if(namePass==1){
                            //update Name
                            struct Faculty updateName;
                            int fd=open("Faculty.txt",O_RDWR,0666);
                            while(read(fd,&updateName,sizeof(updateName))>0){
                                if(strcmp(updateName.facultyUID,inputUID)==0){
                                    //write msg to enter new name
                                    msg="Enter new name\n";
                                    write(newsockfd,msg,strlen(msg));
                                    //write msg to enter new name

                                    //read new name
                                    read(newsockfd,updateName.name,sizeof(updateName.name));
                                    //read new name

                                    lseek(fd,-1*sizeof(updateName),SEEK_CUR);
                                    write(fd,&updateName,sizeof(updateName));

                                    //write msg updation successful
                                    msg="Name has been updated\n";
                                    write(newsockfd,msg,strlen(msg));
                                    //write msg updation successful
                                    break;
                                }
                            }
                            break;
                            

                        }else if(namePass==2){
                            //update password
                            struct Student updatePassword;
                            int fd=open("Student.txt",O_RDONLY,0666);
                            while(read(fd,&updatePassword,sizeof(updatePassword))>0){
                                if(strcmp(updatePassword.rollno,inputUID)==0){
                                    //write msg to enter new password
                                    msg="Enter new password\n";
                                    write(newsockfd,msg,strlen(msg));
                                    //write msg to enter new password

                                    //read new password
                                    read(newsockfd,updatePassword.password,sizeof(updatePassword.password));
                                    //read new password
                                    lseek(fd,-1*sizeof(updatePassword),SEEK_CUR);
                                    write(fd,&updatePassword,sizeof(updatePassword));

                                    //write msg updation successful
                                    msg="Name has been updated\n";
                                    write(newsockfd,msg,strlen(msg));
                                    //write msg updation successful
                                    break;
                                }
                            }
                            break;
                        }else{
                            break;
                        }

                    }else if(checker==1){
                        //unique entry
                        msg="No such Faculty exist\n";

                        //write student not found
                        write(newsockfd,msg,strlen(msg));
                        //write student not found
                        
                        break;
                    }else{
                        break;
                    }

                }
                else if(adminChoice==7){break;}
                else{break;}
            }

            //authentication input
        }else if(choice==2){

        }else if(choice==3){
            //faculty login
            //write input email msg
            char* EmailMsg="Enter Email:\n";
            write(newsockfd,EmailMsg,strlen(EmailMsg));
            //write input email msg

            //read input email
            char inputEmail[100];
            read(newsockfd,&inputEmail,sizeof(inputEmail));
            //read input email

            //write input Password msg
            char* PasswordMsg="Enter Password:\n";
            write(newsockfd,PasswordMsg,strlen(PasswordMsg));
            //write input Password msg

            //read input password
            char inputPassword[100];
            read(newsockfd,&inputPassword,sizeof(inputPassword));
            //read input password
            int isValid=AuthenticateFaculty(inputEmail,inputPassword);

            //write isvalid to client
            write(newsockfd,&isValid,sizeof(isValid));
            //write isvalid to client
        }else{
            printf("wrong choice\n");
            break;
        }        
    }
    close(newsockfd);
    close(sockfd);
    return 0;
}