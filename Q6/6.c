#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int fd, sz;
    char* c = (char*)calloc(100, sizeof(char));
    fd = open("foo.txt", O_RDONLY);
    if (fd < 0) {
        perror("r1");
        exit(1);
    }
    sz = read(fd, c, 10);
    printf("called read(% d, c, 10). returned that"
           " %d bytes were read.\n",
           fd, sz);
    c[sz] = '\0';
    printf("Those bytes are as follows: %s\n", c);
    int fd2 = open("bar.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 < 0) { 
        perror("r1"); 
        exit(1); 
    }
    int sz2 = write(fd, c, strlen(c)); 
    printf("called write"
    " It returned %d\n", fd2, strlen(c), sz); 
    close(fd); 
    return 0;
}