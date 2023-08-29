#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>

#define RECORD_SIZE 100
int lock_record(int fd, int record_number, int lock_type) {
    struct flock fl;
    fl.l_type = lock_type;
    fl.l_whence = SEEK_SET;
    fl.l_start = record_number * RECORD_SIZE;
    fl.l_len = RECORD_SIZE;
    return fcntl(fd, F_SETLKW, &fl);
}

int main() {
    int fd = open("record_file.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Failed to open the file");
        return 1;
    }
    char records[3][RECORD_SIZE] = {"Record 1", "Record 2", "Record 3"};
    for (int i = 0; i < 3; i++) {
        if (lock_record(fd, i, F_WRLCK) == -1) {
            perror("Failed to lock the record for writing");
            return 1;
        }
        lseek(fd, i * RECORD_SIZE, SEEK_SET);
        write(fd, records[i], RECORD_SIZE);
        printf("Record %d written.\n", i);
        sleep(2); 
        lock_record(fd, i, F_UNLCK); 
    }
    for (int i = 0; i < 3; i++) {
        if (lock_record(fd, i, F_RDLCK) == -1) {
            perror("Failed to lock the record for reading");
            return 1;
        }
        lseek(fd, i * RECORD_SIZE, SEEK_SET);
        char buffer[RECORD_SIZE];
        read(fd, buffer, RECORD_SIZE);
        printf("Record %d: %s\n", i, buffer);
        sleep(1); 
        lock_record(fd, i, F_UNLCK); 
    }

    close(fd);
    
    return 0;
}
