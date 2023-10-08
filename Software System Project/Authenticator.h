#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "database.h"
int AuthenticateAdmin(const char* fileName,
                      const char* inputEmail,
                      const char* inputPassword){
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
const char* AuthenticateFaculty(const char* fileName,
                      const char* inputEmail,
                      const char* inputPassword){
    int fd=open(fileName,O_RDONLY,0666);
    if(fd==-1){
        printf("Unable to authenticate faculty\n");
        const char* fail="-1";
        return fail;
    }
    struct Faculty facultychk;
    while(read(fd,&facultychk,sizeof(facultychk))>0){
        if(strcmp(facultychk.emailId,inputEmail)==0 &&
           strcmp(facultychk.password,inputPassword)==0){
            const char* UID=facultychk.facultyUID;
            printf("Authenticator prints %s\n",UID);
            return UID;
           }
    }
    return "0";
}
void AuthenticateStudent(){
    
}
#endif