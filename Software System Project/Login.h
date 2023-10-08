#ifndef LOGIN_H
#define LOGIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Authenticator.h"
int AdminLogin(){
    const char* fileName="Admin.txt";
    char inputEmail[100];
    char inputPassword[100];
    printf("Enter EmailID:\n");
    scanf("%s",inputEmail);
    printf("Enter Password:\n");
    scanf("%s",inputPassword);
    int auth=AuthenticateAdmin(fileName,inputEmail,inputPassword);
    if(auth==1){
        printf("Login Successful...\n");
    }else if(auth ==0){
        printf("Invalid Username or Password...\n");
    }else{
        printf("Login Failed...\n");
    }
    return auth;
}
const char* FacultyLogin(){
    const char* fileName="Faculty.txt";
    char inputEmail[100];
    char inputPassword[100];
    printf("Enter EmailID:\n");
    scanf("%s",inputEmail);
    printf("Enter Password:\n");
    scanf("%s",inputPassword);
    const char* auth;
    auth=AuthenticateFaculty(fileName,inputEmail,inputPassword);
    if(strcmp(auth,"-1")==0){
        printf("Login Failed...\n");
        return "-1";
    }else if(strcmp(auth,"0")==0){
        printf("Invalid Username or Password...\n");
        return "-1";
    }else{
        printf("Login Successful...  %s\n",auth);
        return auth;
    }
}
#endif