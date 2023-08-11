#include <stdio.h>
#include <stdlib.h> // For exit()
int main(){
    FILE *fl1,*fl2;
    char inpFile[100],c;
    printf("enter file name:\n");
    scanf("%s",inpFile);
    fl1=fopen(inpFile, "r");
    if(fl1==NULL){
        printf("cannot open %s",fl1);
        exit(0);
    }
    printf("enter file name to write to:\n");
    scanf("%s",inpFile);
    fl2=fopen(inpFile, "w");
    if(fl2==NULL){
        printf("cannot open %s",fl2);
        exit(0);
    }
    c=fgetc(fl1);
    while (c!=EOF) {
        fputc(c, fl2);
        c=fgetc(fl1);
    }
    printf("contents gor copied\n");
    fclose(fl1);
    fclose(fl2);
    return 0;
    
}