#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <unistd.h>
int main(){
    int fd;
    fd=open("input.txt",O_WRONLY|O_APPEND);
    int fort=fork();
    if(fort==0){
        char *childwrites="child is writing\n";
        lseek(fd, sizeof(childwrites), SEEK_CUR);
        write(fd, childwrites, sizeof(childwrites));
        printf("child has written\n");
    }else{
        char *parentwrite="parent is writing\n";
        lseek(fd, sizeof(parentwrite), SEEK_CUR);
        write(fd, parentwrite, sizeof(parentwrite));
        printf("parent has written\n");
    }
}