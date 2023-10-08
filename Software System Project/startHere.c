#include <stdio.h>
#include <strings.h>
#include <fcntl.h>
#include <unistd.h>



#include "Menus.h"
#include "Login.h"
#include "Search.h"
#include "adminFunctions.h"
#include "facultyFunctions.h"
int main(){
    //call main menu
    MainMenu();
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1: 
                printf("Enter Admin Credentials\n");
                {
                    int isValid=AdminLogin();
                    if(isValid==0){
                        printf("Admin Credentials not valid, hence exiting...\n");
                        break;
                    }
                    while(1){
                        AdminMenu();
                        int pick;
                        scanf("%d",&pick);
                        switch(pick){
                            case 1: AddStudent();break;
                            case 2: ViewStudent();break;
                            case 3: AddFaculty();break;
                            case 4: ViewFaculty();break;
                            case 5: ActivateStudent();break;
                            case 6: BlockStudent();break;
                            case 7: ModifyStudent();break;
                            case 8: ModifyFaculty();break;
                            case 9: break;
                            default: break;
                        }
                        if(pick==9) break;
                    }
                    break;
                }
        case 2: printf("Enter Faculty Credentials\n");
                {
                    //do something similar to admin
                    const char* facultyUID=FacultyLogin();
                    if(strcmp(facultyUID,"-1")==0){
                        printf("Faculty Credentials not valid, hence exiting...\n");
                        break;
                    }
                    while(1){
                        printf("Welcome %s\n",facultyUID);
                        FacultyMenu();
                        int pick;
                        scanf("%d",&pick);
                        switch(pick){
                            case 1: ViewOfferingCourse(facultyUID);break;
                            case 2: AddNewCourse(facultyUID);break;
                            case 3: RemoveCourse(facultyUID);break;
                            case 4: ChangePassword(facultyUID);break;
                            case 5: break;
                            default: break;
                        }
                        if(pick==5) break;
                    }
                    break;
                }
        case 3: StudentMenu(); break;
        default: printf("Wrong Choice. Exiting...\n");break;
    }
    return 0;
}