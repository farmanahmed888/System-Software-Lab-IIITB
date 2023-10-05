#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main(){
    int fd=open("myfifo",O_RDWR);
    if(fd==-1){
        printf("error");
        return -1;
    }
    char buff[1000];
    printf("enter something...\n");
    scanf("%[^\n]",buff);
    int sz=write(fd,buff,sizeof(buff));
    if(sz==-1){
        printf("error\n");
        return -1;
    }
}