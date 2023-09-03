#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <unistd.h>
int main(){
    int fd;
    fd=open("input.txt",O_WRONLY|O_APPEND);
    fork();
    dprintf(fd,"\n");
    //write(fd, const void *__buf, size_t __n)
    dprintf(fd,"hello\n\n");
}