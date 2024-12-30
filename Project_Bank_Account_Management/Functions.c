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
    struct User newUser;
    int i, j;
    int check;
        do {
            printf("\nEnter the User ID (at least 10 characters): ");
            scanf("%s", newUser.userId);
            getchar();
            check=(strlen(newUser.userId)>=10);
        	if(check==0){
        		printf("ID must be up to 10 characters. Try again!\n");	
				} else {
					check=1;
                    for (i=0; i<*length; i++) {
                        if (strcmp(users[i].userId, newUser.userId)==0) {
                            printf("Duplicate ID. Try again!\n");
                            check=0;
                            break;
                        }
                    }
                }
        } while (check==0);

        do {
            printf("Enter the name: ");  
	        fgets(newUser.name, sizeof(newUser.name), stdin);  
	        newUser.name[strcspn(newUser.name, "\n")] = 0; 
	        
	        check=(strlen(newUser.name)>0);  
	        if(check==0) {  
	            printf("Name cannot be empty. Try again!\n");  
	        }  
        } while(check==0);

        do {
            printf("Enter the email: ");  
	        fgets(newUser.email, sizeof(newUser.email), stdin);  
	        newUser.email[strcspn(newUser.email, "\n")] = 0;  
	        
	        check=(strlen(newUser.email)>0);  
	        if (check==0) {  
	            printf("Email cannot be empty. Try again!\n");  
	        } else {  
	            check= 1; 
	            for (i=0; i<*length; i++) {  
	                if (strcmp(users[i].email, newUser.email) == 0) {  
	                    printf("Duplicate email. Try again!\n");  
	                    check= 0;
	                    break;  
	                }  
	            }  
	        }  
        } while(check==0);

        do {
            printf("Enter the phone: ");  
	        fgets(newUser.phone, sizeof(newUser.phone), stdin);  
	        newUser.phone[strcspn(newUser.phone, "\n")] = 0;  
	        
	        check=(strlen(newUser.phone)>0);  
	        if(check==0) {  
	            printf("Phone cannot be empty. Try again!\n");  
	        }  
        } while(check==0);
    	
		do {
            printf("Enter the gender (1: Male, 0: Female): ");  
	        scanf("%d", &newUser.gender);  
	        getchar();
	        check=(newUser.gender==0 || newUser.gender==1);  
	        if(check==0) {  
	            printf("Gender must be 0 or 1. Try again!\n");  
	        }  
        } while(check==0);

		printf("Enter the date of birth:\n");  
	    do {  
	        printf("Enter the day: ");  
	        scanf("%d", &newUser.dateOfBirth.day);  
	        printf("Enter the month: ");  
	        scanf("%d", &newUser.dateOfBirth.month);  
	        printf("Enter the year: ");  
	        scanf("%d", &newUser.dateOfBirth.year);  
	        
	       	check=(newUser.dateOfBirth.day >= 1 && newUser.dateOfBirth.day <= 31 &&  
	                  newUser.dateOfBirth.month >= 1 && newUser.dateOfBirth.month <= 12 &&  
	                  newUser.dateOfBirth.year > 1900);  
	        if(check==0) {  
	            printf("Invalid date of birth. Try again!\n");  
	        }  
	    } while(check==0);  
	    
	    users[*length] = newUser;
        strcpy(users[*length].password, users[*length].phone);  
        strcpy(users[*length].status, "Open");

        (*length)++;
        printf("\nUser added successfully!\n");
    
}
//done
void showUsersData(struct User users[], int length) {
	if (length == 0) {  
        printf("No users available.\n");  
        return;  
    }  
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

void showUsersDetails(struct User users[], int length) {  
    printf("\n|=================|=================================|\n");  
/*	printf("| %-15s | %-33s |\n", "UserID", user.userId);  
    printf("|-----------------|---------------------------------|\n");  
    printf("| %-15s | %-33s |\n", "Name", user.name);  
    printf("|-----------------|---------------------------------|\n");  
    printf("| %-15s | %-33s |\n", "Email", user.email);  
    printf("|-----------------|---------------------------------|\n");  
    printf("| %-15s | %-33s |\n", "Phone", user.phone);  
    printf("|-----------------|---------------------------------|\n");  
    printf("| %-15s | %-33s |\n", "Gender", user.gender == 1 ? "Male" : "Female");  
    printf("|-----------------|---------------------------------|\n");  
    printf("| %-15s | %02d/%02d/%04d                    |\n", "Date of Birth", user.dateOfBirth.day, user.dateOfBirth.month, user.dateOfBirth.year);  
    printf("|-----------------|---------------------------------|\n");  
    printf("| %-15s | %-33s |\n", "Status", user.status);  
*/    printf("|=================|=================================|\n");  
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

void lockUnlockUsers(struct User users[], int length) {
	char id[11], choice;
	int found=0;
	printf("Enter the user ID to lock/unlock: ");
	scanf("%10s", id);
	int i;
	for(i=0; i<length; i++){
		if(strcmp(users[i].userId, id)==0){
			found=1;
			if(strcmp(users[i].status, "Open")==0){
				printf("");
			}
		}
	}
	
}
		
void saveUsersFromFile();
void loadUsersFromFile();

