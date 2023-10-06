#ifdef SERVER_H
#define SERVER_H
#include <stdio.h>
#include <strings.h>
#include <fcntl.h>
#include <unistd.h>



#include "Menus.h"
#include "Login.h"
#include "dofunctions.h"
int main(){
    //call main menu
    MainMenu();
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1: 
                printf("Enter Credentials\n");
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
                }
        case 2: FacultyMenu(); break;
        case 3: StudentMenu(); break;
        default: printf("Wrong Choice. Exiting...\n");break;
    }
    return 0;
}
#endif