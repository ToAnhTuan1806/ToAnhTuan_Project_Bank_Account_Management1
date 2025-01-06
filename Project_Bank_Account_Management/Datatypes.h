#include<stdbool.h>

struct Date{
	int month, day, year;
};

struct User{
	char userId[11];
	char name[20];
	struct Date dateOfBirth;
	bool gender;
	char phone[11];
	char email[20];
	char userName[20];
	char password[15];
	char status[10];
};
struct User users[100];	
struct User temp;
