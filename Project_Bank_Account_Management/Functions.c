#include <stdio.h>
#include "Functions.h"
#include <string.h>
#include <stdbool.h>

void menuStart() {
	printf("\n***Bank Management System Using C***\n");
	printf("\n    CHOOSE YOUR ROLE\n");
	printf("========================\n");
	printf("[1] Admin.\n");
	printf("[2] User.\n");
	printf("[0] Exit the Program.\n");
	printf("========================\n");
}

void menuAdmin() {
	printf("\n***Bank Management System Using C***\n");
	printf("\n    MENU");
	printf("\n========================\n");
	printf("[1] Add A New user.\n");
	printf("[2] Show All users.\n");
	printf("[3] Show detail an user.\n");
	printf("[4] Lock (Unkock) an user.\n");
	printf("[5] User Guideline.\n");
	printf("[6] About Us.\n");
	printf("[0] Exit the program.\n");
	printf("\n========================\n");				
}

void addUsers(struct User users[], int *length) {
	printf("*** Add a new user ***\n");
	int numUsers;
	printf("Add number of User: ");
	scanf("%d", &numUsers);
	getchar();
	int i;
	for(i=0; i<numUsers; i++){
		int check=0;
		while(check==0){
			printf("Enter the ID: ");
			fgets(users[*length].userId, sizeof(users[*length].userId), stdin);
			users[*length].userId[strcspn(users[*length].userId, "\n")]=0;
			if (strlen(users[*length].userId) > 10 || strlen(users[*length].userId) == 0) {
    			printf("\nError: ID must be at most 10 characters. Try again!\n");
			} else {
    			check = 1;
			}
		}
		
		printf("Enter the name: ");
        fgets(users[*length].name, sizeof(users[*length].name), stdin);
        users[*length].name[strcspn(users[*length].name, "\n")] = 0;

        printf("Enter the gender (1 is male, 0 is female): ");
        char genderInput[2];
        fgets(genderInput, sizeof(genderInput), stdin);
        if(genderInput[0] == '1') {
            users[*length].gender = true;
        } else if (genderInput[0] == '0') {
            users[*length].gender = false;
        }
		while (getchar() != '\n');	
        printf("Enter the email: ");
        fgets(users[*length].email, sizeof(users[*length].email), stdin);
        users[*length].email[strcspn(users[*length].email, "\n")] = 0;
		while (getchar() != '\n');
        printf("Enter the phone: ");
        fgets(users[*length].phone, sizeof(users[*length].phone), stdin);
        users[*length].phone[strcspn(users[*length].phone, "\n")] = 0;
		
		strcpy(users[*length].password, users[*length].phone);
		strcpy(users[*length].status, "Open");
        (*length)++;
    }
}
//done
void showUsersData(struct User users[], int length) {
	printf("|============|=================|======================|============|========|\n");
	printf("| %-10s | %-15s | %-20s | %-10s | %-6s |\n", "ID", "Name", "Email", "Phone", "Status");  
    printf("|============|=================|======================|============|========|\n");
 
  	int i;
    for (i=0; i<length; i++) {  
        printf("| %-10s | %-15s | %-20s | %-10s | %-6s |\n",   
                users[i].userId, users[i].name, users[i].email, users[i].phone, users[i].status);  
        printf("|------------|-----------------|----------------------|------------|--------|\n"); 
    }  
}
//done
void softUsersByName(struct User users[], int length) {
	printf("\n***Sort Order***\n");
    printf("====================\n");
    printf("[1] Ascending.\n");
    printf("[2] Descending.\n");
    printf("[0] Exit Sorting.\n");
    printf("====================\n");
	int choice;
	printf("Enter the choice: ");
	scanf("%d", &choice);
	getchar();
	
	if(choice==1 || choice==2) {
		int i, j;
		for(i=0; i<length-1; i++){
			for(j=i+1; j<length; j++){
				int comparison=strcmp(users[i].name, users[j].name);
				if((choice==1&&comparison>0) || (choice==2&&comparison<0)) {
					temp=users[i];
					users[i]=users[j];
					users[j]=temp;
				}
			}
		}
		printf("\nSoft successfully.\n");
		showUsersData(users, length);
	} else if(choice==0) {
		printf("\nExit sort menu\n");
	} else {
		printf("Invalid choice.");
	}
} 
//done
void searchUsersByName(struct User users[], int length) { 
	char searchName[50];
	int found=-1;
	printf("Enter the name to search: ");
	fgets(searchName, sizeof(searchName), stdin);
	searchName[strcspn(searchName, "\n")]=0;
	int i;
	for(i=0; i<length; i++){
		if(strstr(users[i].name, searchName)!=NULL) {
			if(found==-1) {
				printf("|============|=================|======================|============|========|\n");
			    printf("| %-10s | %-15s | %-20s | %-10s | %-6s |\n", "ID", "Name", "Email", "Phone", "Status");  
			    printf("|============|=================|======================|============|========|\n");
			}
		printf("| %-10s | %-15s | %-20s | %-10s | %-6s |\n", users[i].userId, users[i].name, users[i].email, users[i].phone, users[i].status);  
        printf("|------------|-----------------|----------------------|------------|--------|\n");
        found = 1;
        }
    }
        if(found ==-1){
		printf("\nNo users found with the name containing \"%s\".\n", searchName);
		
	}
}	

		


