#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdio.h>

# define MAX_TEXT 50

struct my_msg{
long int msg_type;
char some_text[MAX_TEXT];
};

int main(){
    int start=1;
    int msgid;
    struct my_msg some_data;
    char buffer[20];
    msgid=msgget((key_t)12345,0666|IPC_CREAT);
    if(msgid==-1){printf("error");}
    while(start){
        printf("enter the text\n");
        fgets(buffer,20,stdin);
        some_data.msg_type=1;
        strcpy(some_data.some_text,buffer);

        if(msgsnd(msgid,(void *)&some_data,MAX_TEXT,0)==-1){printf("msg not send\n");}

        if(strncmp(buffer,"end", 3)==0){start=0;}
    }
}
