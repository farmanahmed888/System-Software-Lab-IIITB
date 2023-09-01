#include <stdio.h>
#include <stdlib.h> // For exit()
int main(){
    FILE *f1;
    f1=fopen("abc.txt", "r");
    if(f1==NULL){
        printf("error");
        exit(0);
    }
    do{
        char c=fgetc(f1);
        if(feof(f1)) break;
        printf("%c",c);
    }while(1);
    return 0;
}