/*
============================================================================
Name : 18.c
Author : Farman Ahmed
Description : Write a program to perform Record locking. a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access to avoid race condition.
Date: 10th September, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
struct {
	int train_num;
	int ticket_count;
} db;

int main() {
	int fd, input;
	fd = open("record.txt", O_RDWR);
	printf("Select train number (1,2,3): \n");
	scanf("%d", &input);
    if(input>3){
        printf("wrong choice\n");
        return 0;
    }
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = (input-1)*sizeof(db);
	lock.l_len = sizeof(db);
	lock.l_pid = getpid();

	lseek(fd, (input - 1)*sizeof(db), SEEK_SET);
	read(fd,&db, sizeof(db));
	printf("Before entering into critical section \n");
	
	fcntl(fd, F_SETLKW, &lock);
	printf("Ticket number: %d \n", db.ticket_count);
	db.ticket_count++;
	
	lseek(fd, -1*sizeof(db), SEEK_CUR);
	write(fd, &db, sizeof(db));;
	printf("To Book Ticket, press Enter: \n");
	getchar();
	lock.l_type=F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("Booked\n");

}


