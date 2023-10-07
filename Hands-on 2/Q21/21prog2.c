#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main(){
    int fd1=open("myfifo1",O_RDWR);
    int fd2=open("myfifo2",O_RDWR);
    if(fd2==-1){
        printf("error");
        return -1;
    }
    char buff1[1000];
    char buff2[1000];
    printf("enter something...\n");
    scanf("%[^\n]",buff2);
    write(fd2,buff2,sizeof(buff2));
    sleep(2);
    read(fd1,buff1,sizeof(buff1));
    printf("Text from fifo file is:   %s\n",buff1);

}