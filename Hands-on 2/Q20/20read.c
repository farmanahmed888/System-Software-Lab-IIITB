#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(){
    int fd=open("myfifo",O_RDONLY);
    char buff[10000];
    ssize_t r=read(fd,buff,sizeof(buff));
    //buff[r]='\0';
    printf("%s\n",buff);
    close(fd);
}