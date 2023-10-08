#ifndef MENUS_H
#define MENUS_H
#include <stdio.h>
void MainMenu(){
    printf("---x--- Welcome to Course Registraion ---x---\n");
    printf("Login Choice\n");
    printf("1. Admin\n");
    printf("2. Faculty\n");
    printf("3. Student\n");
}
void AdminMenu(){
    printf("---x--- Welcome to Admin Menu ---x---\n");
    printf("Select your choice:\n");
	printf("1.Add Student\n");
	printf("2.View Student Details\n");
	printf("3.Add Faculty\n");
	printf("4.View Faculty Details\n");
	printf("5.Activate Student\n");
	printf("6.Block Student\n");
	printf("7.Modify Student Details\n");
	printf("8.Modify Faculty Details\n");
	printf("9.Logout and Exit\n");
}
void FacultyMenu(){
    printf("---x--- Welcome to Faculty Menu ---x---\n");
    printf("Select your choice:\n");
	printf("1.View Offering Courses\n");
	printf("2.Add New Courses\n");
	printf("3.Remove Course from Catalog\n");
	printf("4.Change Password\n");
	printf("5.Logout and Exit\n");
}
void StudentMenu(){
    
}
#endif