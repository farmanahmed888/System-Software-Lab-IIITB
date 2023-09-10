/*
============================================================================
Name : 11a.c
Author : Farman Ahmed
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
a. use dup
Date: 10th September, 2023.
============================================================================
*/
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int file_desc = open("dup.txt", O_WRONLY | O_APPEND);
	
	if(file_desc < 0) printf("Error opening the file\n");
	int copy_desc = dup(file_desc);
	write(copy_desc,"This will be output to the file named dup.txt\n", 46);
	write(file_desc,"This will also be output to the file named dup.txt\n", 51);
	return 0;
}
