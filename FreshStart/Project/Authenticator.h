#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "Database.h"

int AuthenticateAdmin(const char* inputEmail,
                      const char* inputPassword){
    const char* fileName="Admin.txt";
    int fd=open(fileName,O_RDONLY,0666);
    if(fd==-1){
        printf("Unable to authenticate admin\n");
        return -1;
    }
    struct Admin adminchk;
    while(read(fd,&adminchk,sizeof(adminchk))>0){
        if(strcmp(adminchk.emailId,inputEmail)==0 &&
           strcmp(adminchk.password,inputPassword)==0){
            return 1;
           }
    }
    return 0;
}

#endif