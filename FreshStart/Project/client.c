#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

#define buffsz 100000


int main(int argc, char* argv[]){
    if(argc<3){
        printf("less arguments\n");
        return -1;
    }
    int sockfd,newsockfd,portno,n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[buffsz];
    if(sockfd<0){
        printf("Creating socket failed\n");
        return -1;
    }
    portno=atoi(argv[2]);
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0){
        printf("Error opening socket\n");
        return -1;
    }
    server=gethostbyname(argv[1]);
    if(server==NULL){
        printf("Error, no such host\n");
        return -1;
    }
    bzero((char*) &serv_addr,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    bcopy((char*)server->h_addr,(char*)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port=htons(portno);
    if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0){
        printf("connection failed\n");
        return -1;
    }
    while(1){
        //read
        bzero(buffer,buffsz);
        read(sockfd,buffer,buffsz);
        printf("Server:\n %s\n",buffer);
        //read


        //write choice
        printf("Input Choice\n");
        int choice;
        scanf("%d",&choice);
        write(sockfd,&choice,sizeof(int));
        //write choice
        if(choice==1){
            //authentication input

            //read input email msg
            bzero(buffer,buffsz);
            read(sockfd,buffer,buffsz);
            printf("Server:\n %s\n",buffer);
            //read input email msg

            //write inputEmail
            char inputEmail[100];
            scanf("%s",inputEmail);
            write(sockfd,&inputEmail,sizeof(inputEmail));
            //write inputEmail 

            //read input Password msg
            bzero(buffer,buffsz);
            read(sockfd,buffer,buffsz);
            printf("Server:\n %s\n",buffer);
            //read input Password msg

            //write inputPassword
            char inputPassword[100];
            scanf("%s",inputPassword);
            write(sockfd,&inputPassword,sizeof(inputPassword));
            //write inputPassword 
            //authentication input
            
            //authenticate Check
            int isValid;
            read(sockfd,&isValid,sizeof(int));
            if(isValid==1){
                ADMIN:
                //read adminMenu msg
                bzero(buffer,buffsz);
                read(sockfd,buffer,buffsz);
                printf("Server:\n %s\n",buffer);
                //read adminMenu msg

                //write adminMenu choice
                int adminChoice;
                scanf("%d",&adminChoice);
                write(sockfd,&adminChoice,sizeof(int));
                //write adminMenu choice
                if(adminChoice==1){
                    //read student name
                    bzero(buffer,buffsz);
                    read(sockfd,buffer,buffsz);
                    printf("Server:\n %s\n",buffer);
                    //read student name
                    
                    //input student name
                    char inputStudentName[100];
                    scanf("%s",inputStudentName);
                    write(sockfd,&inputStudentName,sizeof(inputStudentName));
                    //input student name

                    //read student rollno
                    bzero(buffer,buffsz);
                    read(sockfd,buffer,buffsz);
                    printf("Server:\n %s\n",buffer);
                    //read student rollno

                    //input student rollno
                    char inputStudentRollno[100];
                    scanf("%s",inputStudentRollno);
                    write(sockfd,&inputStudentRollno,sizeof(inputStudentRollno));
                    //input student rollno

                    //read student emailID
                    bzero(buffer,buffsz);
                    read(sockfd,buffer,buffsz);
                    printf("Server:\n %s\n",buffer);
                    //read student emailID

                    //input student emailID
                    char inputStudentEmailID[100];
                    scanf("%s",inputStudentEmailID);
                    write(sockfd,&inputStudentEmailID,sizeof(inputStudentEmailID));
                    //input student emailID

                    //read student password
                    bzero(buffer,buffsz);
                    read(sockfd,buffer,buffsz);
                    printf("Server:\n %s\n",buffer);
                    //read student password

                    //input student password
                    char inputStudentPassword[100];
                    scanf("%s",inputStudentPassword);
                    write(sockfd,&inputStudentPassword,sizeof(inputStudentPassword));
                    //input student password

                    //read checker
                    int checker;
                    read(sockfd,&checker,sizeof(int));
                    //read checker
                    if(checker==-1){
                        break;
                    }else if(checker==0){
                        break;
                    }else if(checker==1){
                        //read addStudentEntry
                        int addStudentEntry;
                        read(sockfd,&addStudentEntry,sizeof(int));
                        //read addStudentEntry
                        if(addStudentEntry==-1){
                            break;
                        }else{
                            //read student added successfully!!!
                            bzero(buffer,buffsz);
                            read(sockfd,buffer,buffsz);
                            printf("Server:\n %s\n",buffer);
                            break;
                            //read student added successfully!!!
                        }
                    }else{
                        break;
                    }
                }
                else if(adminChoice==2){
                    //read Faculty name
                    bzero(buffer,buffsz);
                    read(sockfd,buffer,buffsz);
                    printf("Server:\n %s\n",buffer);
                    //read Faculty name
                    
                    //input Faculty name
                    char inputFacultyName[100];
                    scanf("%s",inputFacultyName);
                    write(sockfd,&inputFacultyName,sizeof(inputFacultyName));
                    //input Faculty name

                    //read Faculty rollno
                    bzero(buffer,buffsz);
                    read(sockfd,buffer,buffsz);
                    printf("Server:\n %s\n",buffer);
                    //read Faculty rollno

                    //input Faculty rollno
                    char inputFacultyRollno[100];
                    scanf("%s",inputFacultyRollno);
                    write(sockfd,&inputFacultyRollno,sizeof(inputFacultyRollno));
                    //input Faculty rollno

                    //read Faculty emailID
                    bzero(buffer,buffsz);
                    read(sockfd,buffer,buffsz);
                    printf("Server:\n %s\n",buffer);
                    //read Faculty emailID

                    //input Faculty emailID
                    char inputFacultyEmailID[100];
                    scanf("%s",inputFacultyEmailID);
                    write(sockfd,&inputFacultyEmailID,sizeof(inputFacultyEmailID));
                    //input Faculty emailID

                    //read Faculty password
                    bzero(buffer,buffsz);
                    read(sockfd,buffer,buffsz);
                    printf("Server:\n %s\n",buffer);
                    //read Faculty password

                    //input Faculty password
                    char inputFacultyPassword[100];
                    scanf("%s",inputFacultyPassword);
                    write(sockfd,&inputFacultyPassword,sizeof(inputFacultyPassword));
                    //input Faculty password

                    //read checker
                    int checker;
                    read(sockfd,&checker,sizeof(int));
                    //read checker
                    if(checker==-1){
                        break;
                    }else if(checker==0){
                        break;
                    }else if(checker==1){
                        //read addFacultyEntry
                        int addFacultyEntry;
                        read(sockfd,&addFacultyEntry,sizeof(int));
                        //read addFacultyEntry
                        if(addFacultyEntry==-1){
                            break;
                        }else{
                            //read Faculty added successfully!!!
                            bzero(buffer,buffsz);
                            read(sockfd,buffer,buffsz);
                            printf("Server:\n %s\n",buffer);
                            break;
                            //read Faculty added successfully!!!
                        }
                    }else{
                        break;
                    }
                }
                else if(adminChoice==3){
                    //read Student UID
                    bzero(buffer,buffsz);
                    read(sockfd,buffer,buffsz);
                    printf("Server:\n %s\n",buffer);
                    //read Student UID
                    
                    //input Student UID
                    char inputStudentRollno[100];
                    scanf("%s",inputStudentRollno);
                    write(sockfd,&inputStudentRollno,sizeof(inputStudentRollno));
                    //input Student UID

                    //read checker
                    int checker;
                    read(sockfd,&checker,sizeof(int));
                    //read checker                   

                    if(checker==-1){
                        //unable to access database
                        break;
                    }else if(checker==0){
                        //duplicate entry

                        //read student msg
                        bzero(buffer,buffsz);
                        read(sockfd,buffer,buffsz);
                        printf("Server:\n %s\n",buffer);
                        //read student msg

                    }else if(checker==1){
                        //unique entry

                        //read student not found
                        bzero(buffer,buffsz);
                        read(sockfd,buffer,buffsz);
                        printf("Server:\n %s\n",buffer);
                        //read student not found
                        break;
                    }else{
                        break;
                    }
                }
                else if(adminChoice==4){
                    //read Student UID
                    bzero(buffer,buffsz);
                    read(sockfd,buffer,buffsz);
                    printf("Server:\n %s\n",buffer);
                    //read Student UID
                    
                    //input Student UID
                    char inputStudentRollno[100];
                    scanf("%s",inputStudentRollno);
                    write(sockfd,&inputStudentRollno,sizeof(inputStudentRollno));
                    //input Student UID

                    //read checker
                    int checker;
                    read(sockfd,&checker,sizeof(int));
                    //read checker                   

                    if(checker==-1){
                        //unable to access database
                        break;
                    }else if(checker==0){
                        //duplicate entry

                        //read student msg
                        bzero(buffer,buffsz);
                        read(sockfd,buffer,buffsz);
                        printf("Server:\n %s\n",buffer);
                        //read student msg

                    }else if(checker==1){
                        //unique entry

                        //read student not found
                        bzero(buffer,buffsz);
                        read(sockfd,buffer,buffsz);
                        printf("Server:\n %s\n",buffer);
                        //read student not found
                        break;
                    }else{
                        break;
                    }
                }
                else if(adminChoice==5){
                    //update student

                    //read input rollnumber msg
                    bzero(buffer,buffsz);
                    read(sockfd,buffer,buffsz);
                    printf("Server:\n %s\n",buffer);
                    //read input rollnumber msg

                    //write input rollnumber
                    char inputStudentRollno[100];
                    scanf("%s",inputStudentRollno);
                    write(sockfd,&inputStudentRollno,sizeof(inputStudentRollno));
                    //write input rollnumber

                    //read checker
                    int checker;
                    read(sockfd,&checker,sizeof(int));
                    //read checker  

                    if(checker==-1){
                        //unable to access database
                        break;
                    }else if(checker==0){
                        //duplicate entry

                        //read name/pass
                        bzero(buffer,buffsz);
                        read(sockfd,buffer,buffsz);
                        printf("Server:\n %s\n",buffer);
                        //read name/pass

                        //write namepass value
                        int namePass;
                        scanf("%d",&namePass);
                        write(sockfd,&namePass,sizeof(int));
                        //write namepass value
                        if(namePass==1){
                            //read enter new name
                            bzero(buffer,buffsz);
                            read(sockfd,buffer,buffsz);
                            printf("Server:\n %s\n",buffer);
                            //read enter new name

                            //input new name
                            char inputNewName[100];
                            scanf("%s",inputNewName);
                            write(sockfd,&inputNewName,sizeof(inputNewName));
                            //input new name

                            //read msg updation
                            bzero(buffer,buffsz);
                            read(sockfd,buffer,buffsz);
                            printf("Server:\n %s\n",buffer);
                            //read msg updation
                            break;
                        }
                        else if(namePass==2){
                            //read enter new password
                            bzero(buffer,buffsz);
                            read(sockfd,buffer,buffsz);
                            printf("Server:\n %s\n",buffer);
                            //read enter new password

                            //input new password
                            char inputNewPassword[100];
                            scanf("%s",inputNewPassword);
                            write(sockfd,&inputNewPassword,sizeof(inputNewPassword));
                            //input new password

                            //read msg updation
                            bzero(buffer,buffsz);
                            read(sockfd,buffer,buffsz);
                            printf("Server:\n %s\n",buffer);
                            //read msg updation
                            break;
                        }
                        else{
                            break;
                        }

                    }else if(checker==1){
                        //unique entry

                        //read student not found
                        bzero(buffer,buffsz);
                        read(sockfd,buffer,buffsz);
                        printf("Server:\n %s\n",buffer);
                        //read student not found
                        break;
                    }else{
                        break;
                    }

                }
                else if(adminChoice==6){
                    //update faculty
                    //read input rollnumber msg
                    bzero(buffer,buffsz);
                    read(sockfd,buffer,buffsz);
                    printf("Server:\n %s\n",buffer);
                    //read input rollnumber msg

                    //write input uid
                    char inputFacultyUID[100];
                    scanf("%s",inputFacultyUID);
                    write(sockfd,&inputFacultyUID,sizeof(inputFacultyUID));
                    //write input rollnumber

                    //read checker
                    int checker;
                    read(sockfd,&checker,sizeof(int));
                    //read checker  

                    if(checker==-1){
                        //unable to access database
                        break;
                    }else if(checker==0){
                        //duplicate entry

                        //read name/pass
                        bzero(buffer,buffsz);
                        read(sockfd,buffer,buffsz);
                        printf("Server:\n %s\n",buffer);
                        //read name/pass

                        //write namepass value
                        int namePass;
                        scanf("%d",&namePass);
                        write(sockfd,&namePass,sizeof(int));
                        //write namepass value
                        if(namePass==1){
                            //read enter new name
                            bzero(buffer,buffsz);
                            read(sockfd,buffer,buffsz);
                            printf("Server:\n %s\n",buffer);
                            //read enter new name

                            //input new name
                            char inputNewName[100];
                            scanf("%s",inputNewName);
                            write(sockfd,&inputNewName,sizeof(inputNewName));
                            //input new name

                            //read msg updation
                            bzero(buffer,buffsz);
                            read(sockfd,buffer,buffsz);
                            printf("Server:\n %s\n",buffer);
                            //read msg updation
                            break;
                        }
                        else if(namePass==2){
                            //read enter new password
                            bzero(buffer,buffsz);
                            read(sockfd,buffer,buffsz);
                            printf("Server:\n %s\n",buffer);
                            //read enter new password

                            //input new password
                            char inputNewPassword[100];
                            scanf("%s",inputNewPassword);
                            write(sockfd,&inputNewPassword,sizeof(inputNewPassword));
                            //input new password

                            //read msg updation
                            bzero(buffer,buffsz);
                            read(sockfd,buffer,buffsz);
                            printf("Server:\n %s\n",buffer);
                            //read msg updation
                            break;
                        }
                        else{
                            break;
                        }

                    }else if(checker==1){
                        //unique entry

                        //read faculty not found
                        bzero(buffer,buffsz);
                        read(sockfd,buffer,buffsz);
                        printf("Server:\n %s\n",buffer);
                        //read faculty not found
                        break;
                    }else{
                        break;
                    }
                }
                else if(adminChoice==7){break;}
                else{break;}
            }else{
                printf("Authentication failed\n");
                break;
            }
            //authenticate Check
        }else if(choice==2){

        }else if(choice==3){

        }else{
            printf("exiting...\n");
            break;
        }

        
        
    }
    close(sockfd);
    return 0;
}