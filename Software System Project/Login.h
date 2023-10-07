#ifndef LOGIN_H
#define LOGIN_H
#include <stdio.h>
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
#endif