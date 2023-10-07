#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "database.h"
int main(){
    struct Admin readAdmin;
    int fd=open("Admin.txt",O_RDONLY,0666);
    if(fd==-1){
        printf("Cannot store admin\n");
        return -1;
    }
    while(read(fd,&readAdmin,sizeof(readAdmin))>0){
        printf("Admin name %s\n",readAdmin.name);
        printf("Admin emailID %s\n",readAdmin.emailId);
        printf("Admin password %s\n",readAdmin.password);
    }
}