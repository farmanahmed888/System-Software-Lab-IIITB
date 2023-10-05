struct Course{
    char course_code[5];
	char course_name[100];
};
struct Admin{
	char name[100];
	char emailId[100];
	char password[100];
};
struct Student{
	char name[100];
	char rollno[100];
	char emailId[100];
	char password[100];
	int status;
	struct Course course_enrolled[6];
};
struct Faculty{
	char name[100];
	char emailId[100];
	char password[100];
	struct Course course_offered[6];
};
