/* Written by:
Matan Leizerovich 302674304
Doron Avramov     308140987 */

#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


/*********************/
/* General functions */
/*********************/

/* This function let the user to login to the store , also , it checks whether the user exists or not */
void login(int* userLevel) {
	int numberOfTries = 0;
	char inputUsername[SIZE] = { 0 }, inputPassword[SIZE] = { 0 };

	printf("\n========================\n         Login\n========================\n");

	do {
		do {
			printf("\nPlease enter your username: > ");
			gets(inputUsername);
			if (strlen(inputUsername) == 0)
				printf("You entered empty input!\n");
		} while (strlen(inputUsername) == 0);
		do {
			printf("\nPlease enter your password: > ");
			gets(inputPassword);
			if (strlen(inputPassword) == 0)
				printf("You entered empty input!\n");
		} while (strlen(inputPassword) == 0);
		if (checkIfUserValid(inputUsername, inputPassword, &userLevel))
			break;
		else {
			numberOfTries++;
		}
	} while (numberOfTries < NUM_OF_ATTEMPTS);

	/* The user has passed the number of attempts */
	if (numberOfTries == 3) {
		printf("You have passed the number of attempts to login , BYE BYE!\n");
		exit(0);
	}

	writeToLogFile("User login to system");
}

/* This function display menu for user level one */
void userLevelOneMenu(tree* root, bool* isLogoutPressed, int itemsId[]) {
	int userChoice = 0;
	char  userInput[SIZE] = { 0 }, buffer[1] = { 0 };

	printf("\n===================\n     Main Menu\n===================\n");
	printf("\n1.Show items\n2.Search item\n3.Add item\n4.Log out\n5.Quit\nEnter your choice : > ");

	do {
		scanf_s("%s", &userInput, SIZE);
		if (!isInputValid(userInput, 1, 5))
			printf("Wrong input!\nEnter your choice: > ");
	} while (!isInputValid(userInput, 1, 5));

	userChoice = atoi(userInput);

	switch (userChoice) {
	case 1: {
		printf("\n========================\n     Items On Store\n========================\n\n");
		print_inorder(root);
		writeToLogFile("Item display function enabled");
		break;
	}
	case 2: {
		filterThenSearch(root, 1);
		break;
	}
	case 3: {
		addItem(root, NULL, itemsId);
		break;
	}
	case 4: {
		*isLogoutPressed = TRUE;
		scanf_s("%c", &buffer); // temp statement to clear buffer
		writeToLogFile("User has signed out from system");
		printf("\n~ You have logged out of the system ~\n");
		break;
	}
	case 5: {
		printf("\n*****************************************************\nThanks for choosing us, see you at the next purchase!\n*****************************************************\n");
		free(itemsId);
		free(root);
		exit(0);
		break;
	}
	default: {
		break;
	}
	}
}

/* This function display menu for user level two */
void userLevelTwoMenu(tree* root, bool* isLogoutPressed, int itemsId[]) {
	int userChoice = 0;
	char  userInput[SIZE] = { 0 }, buffer[1] = { 0 };

	printf("\n===================\n     Main Menu\n===================\n");
	printf("\n1.Show items\n2.Search item\n3.Add item\n4.Update item\n5.Delete item\n6.Log out\n7.Quit\nEnter your choice: > ");

	do {
		scanf_s("%s", userInput, SIZE);
		if (!isInputValid(userInput, 1, 7))
			printf("Wrong input!\nEnter your choice: > ");
	} while (!isInputValid(userInput, 1, 7));

	userChoice = atoi(userInput);

	switch (userChoice) {
	case 1: {
		printf("\n========================\n     Items On Store\n========================\n\n");
		print_inorder(root);
		writeToLogFile("Item display function enabled");
		break;
	}
	case 2: {
		filterThenSearch(root, 2);
		break;
	}
	case 3: {
		addItem(root, NULL, itemsId);
		break;
	}
	case 4: {
		updateItem(root, 0);
		break;
	}
	case 5: {
		root = deleteItem(root, itemsId);
		break;
	}
	case 6: {
		*isLogoutPressed = TRUE;
		scanf_s("%c", &buffer); // temp statement to clear buffer
		writeToLogFile("User has signed out from system");
		printf("\n~ You have logged out of the system ~\n");
		break;
	}
	case 7: {
		printf("\n*****************************************************\nThanks for choosing us, see you at the next purchase!\n*****************************************************\n");
		free(itemsId);
		free(root);
		exit(0);
		break;
	}
	default: {
		printf("Wrong choise! try again...\n");
		break;
	}
	}
}

/* This function display menu for user level three */
void userLevelThreeMenu(tree* root, bool* isLogoutPressed, int itemsId[]) {
	int userChoice = 0;
	char  userInput[SIZE] = { 0 }, buffer[1] = { 0 };

	printf("\n===================\n     Main Menu\n===================\n");
	printf("\n1.Show items\n2.Search item\n3.Add item\n4.Update item\n5.Delete item\n6.Display users\n7.Add user\n8.Update user\n9.Delete user\n10.Log out\n11.Quit\n\nEnter your choice: > ");

	do {
		scanf_s("%s", userInput, SIZE);
		if (!isInputValid(userInput, 1, 11))
			printf("Wrong input!\nEnter your choice: > ");
	} while (!isInputValid(userInput, 1, 11));

	userChoice = atoi(userInput);

	switch (userChoice) {
	case 1: {
		printf("\n========================\n     Items On Store\n========================\n\n");
		print_inorder(root);
		writeToLogFile("Item display function enabled");
		break;
	}
	case 2: {
		filterThenSearch(root, 3);
		break;
	}
	case 3: {
		addItem(root, NULL, itemsId);
		break;
	}
	case 4: {
		updateItem(root, 0);
		break;
	}
	case 5: {
		root = deleteItem(root, itemsId);
		break;
	}
	case 6: {
		displayUsers();
		break;
	}
	case 7: {
		createUser();
		break;
	}
	case 8: {
		updateUser();
		break;
	}
	case 9: {
		deleteUser();
		break;
	}
	case 10: {
		*isLogoutPressed = TRUE;
		scanf_s("%c", &buffer, 1); // temp statement to clear buffer
		writeToLogFile("User has signed out from system");
		printf("\n~ You have logged out of the system ~\n");
		break;
	}
	case 11: {
		printf("\n*****************************************************\nThanks for choosing us, see you at the next purchase!\n*****************************************************\n");
		free(itemsId);
		free(root);
		exit(0);
		break;
	}
	default: {
		printf("Wrong choise! try again...\n");
		break;
	}
	}
}

/* This function opens the item file and produces a binary search tree from it */
tree* createTree(int itemsId[]) {
	int ch = 0;
	char boolean[SIZE] = { 0 }, date[SIZE] = { 0 };
	FILE* fp;
	Item item;
	tree* root = NULL;

	fp = fopen(ITEMS_FILE, "r");

	while ((ch = fgetc(fp)) != EOF) {
		if (ch == '\n') { // looking for the next line
			fscanf(fp, "%4d %12s %13s %11s %7f %11s %15d %10s", &item.id, item.manufactor, item.model, item.processor, &item.price, boolean, &item.amountInStock, date);
			//printf("id is: %d , man is: %s , mod is: %s, pro is: %s, price is: %.2f, bool is: %s , amount is: %d, date: %s\n", item.id, item.manufactor, item.model, item.processor, item.price, boolean, item.amountInStock, date);

			if (strcmp(boolean, "TRUE") == 0)
				item.isInStock = TRUE;
			else
				item.isInStock = FALSE;

			item.manufacturingDate = setToDateVar(date);

			// insert to the tree
			amountOfitems++;
			itemsId = (int*)realloc(itemsId, sizeof(int) * (item.id + 1));
			itemsId[item.id] = item.id;

			insert_recursive(&root, NULL, item);
		}
	}
	runID = item.id;

	itemsIdArraySize = item.id + 1;

	fclose(fp);
	return root;
}

/*  This function checks if the tree is empty  */
bool isTreeEmpty(tree* root)
{
	if (!root)
		return TRUE;
	return FALSE;

}

/* This function check if the input is valid */
bool isInputValid(char* checkInput, int lowerLimit, int topLimit) {
	int userChoice = 0, i = 0;
	bool notDigitFlag = FALSE, isValid = TRUE;

	while (checkInput[i] != '\0') {
		if (!isdigit(checkInput[i])) {
			notDigitFlag = 1;
			break;
		}
		i++;
	}

	if (notDigitFlag) {
		isValid = FALSE;
	}
	else {
		userChoice = atoi(checkInput);
		if (!(userChoice >= lowerLimit && userChoice <= topLimit)) {
			isValid = FALSE;
		}
		else
			isValid = TRUE;
	}
	return isValid;
}

/* This function check if the float input is valid */
bool isInputFloat(char* checkInput, float lowerLimit, float topLimit) {
	float userChoice = 0.0;
	int i = 0, pointCounter = 0, digitCounter = 0;
	bool isValid = TRUE, isFloatNumber = TRUE;
	char point = '.';

	while (checkInput[i] != '\0') {
		if (!isdigit(checkInput[i])) {
			if (checkInput[i] == point && digitCounter > 0) {
				isFloatNumber = TRUE;
				pointCounter++;
				if (pointCounter != 1) {
					isFloatNumber = FALSE;
					break;
				}
			}
			else {
				isFloatNumber = FALSE;
				break;
			}
			isFloatNumber = TRUE;
		}
		i++;
		digitCounter++;
	}

	if (!isFloatNumber) {
		isValid = FALSE;
	}
	else {
		userChoice = strtod(checkInput, NULL);
		if (!(userChoice >= lowerLimit && userChoice <= topLimit)) {
			isValid = FALSE;
		}
		else
			isValid = TRUE;
	}
	return isValid;
}



/********************/
/* Files  functions */
/********************/

/*
This function creates new users file with default data
username: admin
password: admin
level: 3
fullname: System_Manager
*/
void createUsersFile(void) {
	FILE* fp;

	fp = fopen(USER_FILE_NAME, "w");
	fprintf(fp, "%s", "============================ Users File ============================\n");
	fprintf(fp, "%-15s %-15s %-3d %-20s", "admin", "admin", 3, "System_Manager");
	amountOfUsers++;
	fclose(fp);

	writeToLogFile("New user was added to the system");
}

/*  This function check whether file exists or not */
bool isFileExists(char* filename) {
	FILE* fp;

	fp = fopen(filename, "r");

	if (fp != NULL) {
		fclose(fp);
		return TRUE;
	}
	else
		return FALSE;
}

/* This function write every operation to the log file */
void writeToLogFile(char* str) {
	FILE* fp;
	time_t t;
	time(&t);

	fp = fopen(LOG_FILE, "a"); // append mode
	fprintf(fp, "%s at %s", str, ctime(&t));

	fclose(fp);
}

/* This function create a new log file */
void createLogFile(void) {
	FILE* fp;

	fp = fopen(LOG_FILE, "w");
	fprintf(fp, "%s", "=====================\nLog File - Operations\n=====================\n");
	fclose(fp);
}

/* This function updates the items file */
void updateItemsFile(Item item, char* filename) {
	FILE* fp;
	char day[SIZE] = { 0 }, month[SIZE] = { 0 }, year[SIZE] = { 0 };

	sprintf(day, "%d", item.manufacturingDate.day);
	sprintf(month, "%d", item.manufacturingDate.month);
	sprintf(year, "%d", item.manufacturingDate.year);

	strcat(strcat(strcat(strcat(day, "/"), month), "/"), year);

	fp = fopen(filename, "a");
	fprintf(fp, "\n%-4d %-12s %-13s %-11s %-7.2f %-11s %-15d %-10s", item.id, item.manufactor, item.model, item.processor, item.price, "TRUE", item.amountInStock, day);

	fclose(fp);
}

/* This function convert text file to binary file
void convertToBinaryFile(char* textFileName, char* binaryFileName) {
	FILE* in;
	FILE* out;
	int ch = 0;
	char buf[1000];

	/* Write
	/* open both files

	in = fopen(textFileName, "r");
	out = fopen(binaryFileName, "wb");

	/* write to a file
	//size_t elements_written = fwrite(&p1, sizeof(Point), 1, out); // size_t is size of object

	fprintf(out, "%s", "============================ Users File ============================\n");

	while (fgets(buf, 1000, in) != NULL)
		fputs(buf, out);		//copy line into Output.txt
	/*
	while ((ch = fgetc(fp)) != EOF) {
		if (ch == '\n') {
			fscanf(fp, "%s",userLevel, fullnameFromFile);
			fgets(fullnameFromFile, SIZE, fp); // Special string handling with space

			if (!strcmp(inputUsername, usernameFromFile) == 0) {
				//copy to the new file!!
				fprintf(temp, "\n%-15s %-15s %-3d %-20s", usernameFromFile, passwordFromFile, userLevel, fullnameFromFile);
			}


	fclose(in);
	fclose(out);

	//if (elements_written == 0) {
	//	return 2; // error code

	/* READ
	in = fopen(USERS_BIN_FILE, "rb");
	if (in == NULL) {
		return 3; // error code
	}

	char* line = NULL;
	size_t len = 0;
	size_t read;

	// wrong command with get line - need to read the file and check if its good after it copied
	while ((read = getline(&line, &len, in)) != -1) {
		printf("Retrieved line of length %zu:\n", read);
		printf("%s", line);
	}

	fclose(in);
	if (line)
		free(line);

}
*/

/*********************/
/*  Users  functions */
/*********************/

/* This function checks whether the user exists or not */
bool checkIfUserValid(char* inputUsername, char* inputPassword, int** userLevel) {
	int ch = 0;
	char usernameFromFile[SIZE] = { 0 }, passwordFromFile[SIZE] = { 0 };
	FILE* fp;
	bool wrongUserFlag = FALSE;  // this flag raised when there is wrong username

	fp = fopen(USER_FILE_NAME, "r");

	while ((ch = fgetc(fp)) != EOF) {
		if (ch == '\n') { // looking for the next line
			fscanf(fp, "%15s %15s %3d", usernameFromFile, passwordFromFile, &(**userLevel));
			//printUserInfo(usernameFromFile, passwordFromFile, userLevel); // optional
			if (strcmp(inputUsername, usernameFromFile) == 0) {
				wrongUserFlag = FALSE;
				if (strcmp(inputPassword, passwordFromFile) == 0) {
					//printf("user is exists!\n");
					fclose(fp);
					return TRUE;
				}
				else {
					printf("Wrong password!\n");
					fclose(fp);
					return FALSE;
				}
			}
			else
				wrongUserFlag = TRUE;
		}
	}

	if (wrongUserFlag)
		printf("Wrong username!\n");

	fclose(fp);

	return FALSE;
}

/* This function prints user's information */
void printUserInfo(char* username, char* password, int level, char* fullname) {
	printf("username is: %s\tpassword is: %s\tuser_level is: %d\tfull name is:%s\n", username, password, level, fullname);
}

/* This function creates a new user */
void createUser(void) {
	FILE* fp;
	int userLevel = 0;
	char temp;
	char inputUsername[SIZE] = { 0 }, inputPassword[SIZE] = { 0 }, inputFullName[SIZE] = { 0 }, inputUserLevel[SIZE] = { 0 };

	printf("\n===============\nCreate new user\n===============\n");
	scanf_s("%c", &temp, 1); // temp statement to clear buffer
	do {
		printf("\nPlease enter new username: > ");
		gets(inputUsername);
		if (strlen(inputUsername) == 0)
			printf("You entered empty input!\n");
		else if (isUserExists(inputUsername))
			printf("\nThe inserted username already exists in the system, select another username!\n\n");
	} while (strlen(inputUsername) == 0 || isUserExists(inputUsername));

	do {
		printf("Please enter new password: > ");
		gets(inputPassword);
		if (strlen(inputPassword) == 0)
			printf("You entered empty input!\n");
		else if (isUserExists(inputPassword))
			printf("\nThe inserted username already exists in the system, select another username!\n\n");
	} while (strlen(inputPassword) == 0 || isUserExists(inputPassword));

	do {
		printf("Please enter new user level(1, 2, 3): > ");
		scanf_s("%s", &inputUserLevel, SIZE);
		if ((!isInputValid(inputUserLevel, 1, 3)))
			printf("Wrong input!\n");
	} while (!isInputValid(inputUserLevel, 1, 3));

	userLevel = atoi(inputUserLevel);

	printf("Please enter new full name: > ");
	scanf_s("%c", &temp, 1); // temp statement to clear buffer
	scanf_s("%[^\n]", inputFullName, SIZE);


	fp = fopen(USER_FILE_NAME, "a");
	fprintf(fp, "\n%-15s %-15s %-3d %-20s", inputUsername, inputPassword, userLevel, inputFullName);

	amountOfUsers++;

	fclose(fp);

	writeToLogFile("New user was added to the system");
}

/* This function display the users from users file */
void displayUsers(void) {
	FILE* fp;
	char usernameFromFile[SIZE] = { 0 }, passwordFromFile[SIZE] = { 0 }, fullnameFromFile[SIZE] = { 0 };
	int ch = 0, userLevel;

	printf("\n==========================================\n    Display users - Total users: | %d |\n==========================================\n\n", amountOfUsers);
	fp = fopen(USER_FILE_NAME, "r");

	while ((ch = fgetc(fp)) != EOF) {
		if (ch == '\n') {
			fscanf(fp, "%15s %15s %3d", usernameFromFile, passwordFromFile, &userLevel);
			fgets(fullnameFromFile, SIZE, fp); // Special string handling with space
			puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			printUserInfo(usernameFromFile, passwordFromFile, userLevel, fullnameFromFile);
			puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		}
	}

	fclose(fp);

	writeToLogFile("User view function program has been activated");
}

/* This function delete a user and updates the user.txt file */
void deleteUser(void) {
	FILE* fp, * temp;
	char inputUsername[SIZE] = { 0 }, usernameFromFile[SIZE] = { 0 }, passwordFromFile[SIZE] = { 0 }, fullnameFromFile[SIZE] = { 0 };
	int counter = 0, userLevel = 0, ch = 0;

	printf("\n===================\n    Delete user\n===================\n");

	do {
		printf("\nPlease enter the username you want to delete: > ");
		scanf_s("%s", inputUsername, SIZE);
		if (!isUserExists(inputUsername)) {
			printf("\nInvalid username entered!\n");
			counter++;
		}
		if (counter == 3 || counter == 6)
			displayUsers();
		else if (counter > 6)
			return;
	} while (!isUserExists(inputUsername));


	fp = fopen(USER_FILE_NAME, "r");
	temp = fopen("temp.txt", "w");

	fprintf(temp, "%s", "============================ Users File ============================");

	while ((ch = fgetc(fp)) != EOF) {
		if (ch == '\n') {
			fscanf(fp, "%15s %15s %3d %20", usernameFromFile, passwordFromFile, &userLevel, fullnameFromFile);
			fgets(fullnameFromFile, SIZE, fp); // Special string handling with space
			if (!strcmp(inputUsername, usernameFromFile) == 0) {
				//copy to the new file!!
				fprintf(temp, "\n%-15s %-15s %-3d %-20s", usernameFromFile, passwordFromFile, userLevel, fullnameFromFile);
			}
		}
	}

	amountOfUsers--;

	// close the original file and remove it
	fclose(fp);
	remove("users.txt");

	// close the new file and rename it
	fclose(temp);
	rename("temp.txt", USER_FILE_NAME);

	writeToLogFile("User deleted from system");
}

/* This function check if the user is exists in the users file */
bool isUserExists(char* inputUsername) {
	int ch = 0;
	char usernameFromFile[SIZE] = { 0 };
	FILE* fp;

	fp = fopen(USER_FILE_NAME, "r");

	while ((ch = fgetc(fp)) != EOF) {
		if (ch == '\n') { // looking for the next line
			fscanf(fp, "%15s ", usernameFromFile);
			if (strcmp(inputUsername, usernameFromFile) == 0) {
				fclose(fp);
				return TRUE;
			}
		}
	}

	fclose(fp);
	return FALSE;
}

/* This function counts the amount of users on the users file */
int usersAmount(void) {
	FILE* fp, * temp;
	int counter = 0, ch = 0;

	fp = fopen(USER_FILE_NAME, "r");

	while ((ch = fgetc(fp)) != EOF) {
		if (ch == '\n')
			counter++;
	}

	fclose(fp);

	return counter;
}

/* This function updates the user */
void updateUser(void) {
	FILE* fp, * temp;
	char buffer;
	char inputUsername[SIZE] = { 0 }, usernameFromFile[SIZE] = { 0 }, passwordFromFile[SIZE] = { 0 }, fullnameFromFile[SIZE] = { 0 }, inputUserLevel[SIZE] = { 0 }, userChoise[SIZE] = { 0 };
	int userLevel = 0, ch = 0, choise = 0, counter = 0;
	printf("counter is: %d\n", counter);
	printf("\n===================\n    Update user\n===================\n");

	do {
		printf("\nPlease enter the username you want to update: > ");
		scanf_s("%s", inputUsername, SIZE);
		if (!isUserExists(inputUsername)) {
			printf("\nInvalid username entered!\n");
			counter++;
		}
		if (counter == 3 || counter == 6)
			displayUsers();
		else if (counter > 6)
			return;
	} while (!isUserExists(inputUsername));


	fp = fopen(USER_FILE_NAME, "r");
	temp = fopen("temp.txt", "w");

	fprintf(temp, "%s", "============================ Users File ============================");

	while ((ch = fgetc(fp)) != EOF) {
		if (ch == '\n') {
			fscanf(fp, "%15s %15s %3d %20", usernameFromFile, passwordFromFile, &userLevel, fullnameFromFile);
			fgets(fullnameFromFile, SIZE, fp); // Special string handling with space

			if (!strcmp(inputUsername, usernameFromFile) == 0) {
				//copy to the new file!!
				fprintf(temp, "\n%-15s %-15s %-3d %-20s", usernameFromFile, passwordFromFile, userLevel, fullnameFromFile);
			}
			else
			{
				printf("\n1.Change password\n2.Change user level\n3.Change user full name\n4.Change all\n5.Back\nEnter your choice: > ");

				do {
					scanf_s("%s", userChoise, SIZE);
					if (!isInputValid(userChoise, 1, 5))
						printf("Wrong input!\nEnter your choice: > ");
				} while (!isInputValid(userChoise, 1, 5));

				choise = atoi(userChoise);

				switch (choise) {
				case 1: {
					printf("\nEnter the new password: > ");
					scanf_s("%s", passwordFromFile, SIZE);
					break;
				}
				case 2: {
					do {
						printf("Please enter new user level(1, 2, 3): > ");
						scanf_s("%s", &inputUserLevel, SIZE);
						if ((!isInputValid(inputUserLevel, 1, 3)))
							printf("Wrong input!\n");
					} while (!isInputValid(inputUserLevel, 1, 3));

					userLevel = atoi(inputUserLevel);
					break;
				}
				case 3: {
					printf("Enter new full name: > ");
					scanf_s("%c", &buffer, 1); // temp statement to clear buffer
					scanf_s("%[^\n]", fullnameFromFile, SIZE);
					break;
				}
				case 4: {
					printf("\nEnter the new password: > ");
					scanf_s("%s", passwordFromFile, SIZE);

					do {
						printf("Please enter new user level(1, 2, 3): > ");
						scanf_s("%s", &inputUserLevel, SIZE);
						if ((!isInputValid(inputUserLevel, 1, 3)))
							printf("Wrong input!\n");
					} while (!isInputValid(inputUserLevel, 1, 3));

					userLevel = atoi(inputUserLevel);

					printf("Enter new full name: > ");
					scanf_s("%c", &buffer, 1); // temp statement to clear buffer
					scanf_s("%[^\n]", fullnameFromFile, SIZE);
					break;
				}
				case 5: {
					return;
					break;
				}
				default: {
					break;
				}
				}

				fprintf(temp, "\n%-15s %-15s %-3d %-20s", usernameFromFile, passwordFromFile, userLevel, fullnameFromFile);

			}
		}
	}



	// close the original file and remove it
	fclose(fp);
	remove("users.txt");

	// close the new file and rename it
	fclose(temp);
	rename("temp.txt", USER_FILE_NAME);

	writeToLogFile("An update was made for a system user");

}



/******************/
/* Date functions */
/******************/

/* This function prints the date */
void printDate(Date date) {
	printf("the date is: %d\\%d\\%d\n", date.day, date.month, date.year);
}

/* This function splits a string into day , month and year in order to set them into Data variable */
Date setToDateVar(char* str) {
	Date date = { 0,0,0 };
	int temp = 0, counter = 0;

	// Extract the first token
	char* token = strtok(str, "/");

	// loop through the string to extract all other tokens
	while (token != NULL) {
		counter++;
		temp = atoi(token);
		token = strtok(NULL, "/");

		switch (counter) {
		case 1: { date.day = temp; break; }
		case 2: { date.month = temp; break; }
		case 3: { date.year = temp; break; }
		default: { break; }
		}
	}

	return date;
}

/* This function checks if the date is valid */
bool isDateVaild(char* str) {
	int day = 0, month = 0, year = 0, checkDay = 0, temp = 0, counter = 0;

	// Extract the first token
	char* token = strtok(str, "/");

	// loop through the string to extract all other tokens
	while (token != NULL) {
		counter++;
		temp = atoi(token);
		token = strtok(NULL, "/");

		switch (counter) {
		case 1: { day = temp; break; }
		case 2: { month = temp; break; }
		case 3: { year = temp; break; }
		default: { break; }
		}
	}

	/* Check year */
	if (!(year >= 1980 && year <= 2020))
		return FALSE;

	/* Check month */
	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: {
		checkDay = 31;
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11: {
		checkDay = 30;
		break;
	}
	case 2: {
		if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) // leap year
			checkDay = 29;
		else
			checkDay = 28;
		break;
	}
	default: { // wrong month was entered
		return FALSE;
		break;
	}
	}

	if (day >= 1 && day <= checkDay)
		return TRUE;
	else
		return FALSE;
}


/********************/
/*  Items functions */
/********************/

/* This function prints the item's data */
void printItem(Item item) {
	char* str = NULL;

	str = item.isInStock ? "TRUE" : "FALSE";

	printf("id: %-3d manufactor: %-10s model: %-16s processor: %-3s  price: %-7.2f  isInStock: %-6s amountInStock: %-3d manufcatoringDate:  %d/%d/%-4d\n",
		item.id, item.manufactor, item.model, item.processor, item.price, str, item.amountInStock,
		item.manufacturingDate.day, item.manufacturingDate.month, item.manufacturingDate.year);
}

/*  This function adds a new item to the BST and updates the items file */
void addItem(tree** root, tree* parent, int itemsId[]) {
	char buffer, inputDate[SIZE] = { 0 }, inputAmount[SIZE] = { 0 }, strTemp[SIZE] = { 0 }, inputPrice[SIZE] = { 0 };
	bool validInput = FALSE;
	Item item;

	item.id = ++runID;

	itemsId[item.id] = item.id;

	printf("\nPlease enter manufactor name: > ");
	scanf_s("%s", item.manufactor, SIZE);

	printf("Please enter model name: > ");
	scanf_s("%s", item.model, SIZE);

	do {
		printf("Please enter processor name (i3/i5/i7): > ");
		scanf_s("%s", item.processor, SIZE);
		if (!(strcmp(item.processor, "i3") == 0 || strcmp(item.processor, "i5") == 0 || strcmp(item.processor, "i7") == 0))
			printf("Wrong input!\n");
	} while (!(strcmp(item.processor, "i3") == 0 || strcmp(item.processor, "i5") == 0 || strcmp(item.processor, "i7") == 0));


	do {
		printf("Please enter the price: > ");
		scanf_s("%s", inputPrice, SIZE);
		if (!isInputFloat(inputPrice, 1.0, 9999.99))
			printf("Wrong input!\n");
	} while (!isInputFloat(inputPrice, 1.0, 9999.99));

	item.price = strtod(inputPrice, NULL);

	item.isInStock = TRUE;

	do {
		printf("Please enter amount of items: > ");
		scanf_s("%s", &inputAmount, SIZE);

		if (!isInputValid(inputAmount, 1, 100))
			printf("Wrong input!\n");
	} while (!isInputValid(inputAmount, 1, 100));

	item.amountInStock = atoi(inputAmount);

	do {
		printf("Please enter the date ( XX/XX/XXXX ): > ");
		scanf_s("%s", inputDate, SIZE);
		scanf_s("%c", &buffer, 1); // temp statement to clear buffer
		strcpy(strTemp, inputDate);
		if (isDateVaild(strTemp))
			validInput = TRUE;
		else
			printf("Wrong input!\n");

	} while (!isDateVaild(strTemp) && !validInput);

	item.manufacturingDate = setToDateVar(inputDate);

	/* insert item to the BST */
	insert_recursive(&root, NULL, item);

	amountOfitems++;

	/* Update items file */
	updateItemsFile(item, ITEMS_FILE);

	/* Update log file */
	writeToLogFile("New item was added to the system");
}

/* This function deletes an item from the BST and updates the items file*/
tree* deleteItem(tree* root, int itemsId[]) {
	int inputId = 0, choice = 0, isInStock = 0, counter = 0;
	char buffer;
	char dateHelper[SIZE], userInput[SIZE], day[SIZE], month[SIZE], year[SIZE];
	bool wrongInput = FALSE;
	FILE* fp, * tempFile;

	tree* cursor = root;
	tree* temp = root;


	// check if there are any item on the store
	if (isTreeEmpty(root))
		puts("There are no items to delete");
	else {
		// Open the original file and Create a new file
		fp = fopen(ITEMS_FILE, "r");
		tempFile = fopen(TEMP_FILE, "w");

		// headline for the new file
		fprintf(tempFile, "%-4s %-12s %-13s %-11s %-7s %-11s %-15s %-10s", "id", "manufactor", "model", "processor", "price", "isInStock", "amountInStock", "manufactoringDate");

		printf("\n===================\n    Delete item\n===================\n\n");

		//  input & checks if the input is valid  
		do {
			printf("Please enter the item's ID you want to delete: > ");
			scanf_s("%s", userInput, SIZE);
			scanf_s("%c", &buffer, 1); // temp statement to clear buffer - itemsId[atoi(userInput)] > 0
			if (atoi(userInput) == 0 || (!(atoi(userInput) <= runID) || (!isInputValid(userInput, 1, runID) || itemsId[atoi(userInput)] == 0))) {
				printf("Wrong input!\n");
				counter++;
			}

			if (counter == 3 || counter == 6) {
				printf("\n========================\n     Items On Store\n========================\n\n");
				print_inorder(root);
				printf("\n");
				writeToLogFile("Item display function enabled");
			}
			else if (counter > 6)
				return;
		} while (atoi(userInput) == 0 || (!(atoi(userInput) <= runID) || (!isInputValid(userInput, 1, runID) || itemsId[atoi(userInput)] == 0)));

		inputId = atoi(userInput);

		// Move over the tree and copy the original items and the updated item to the new file
		while (cursor != NULL) {
			if (cursor->data.id == inputId) {  // the organ that need to be deleted
				if (cursor == root) { // the first organ in the tree
					*root = *root->right;
					itemsId[inputId] = 0;
				}
				else if (cursor->right == NULL) { // the last organ in the tree
					root = delete_node(root, cursor->data);
					itemsId[inputId] = 0;
					cursor = NULL;
				}
				else {
					itemsId[inputId] = 0;
					cursor = cursor->right;
					root = delete_node(root, cursor->parent->data);
				}
			}
			else {
				sprintf(day, "%d", cursor->data.manufacturingDate.day);
				sprintf(month, "%d", cursor->data.manufacturingDate.month);
				sprintf(year, "%d", cursor->data.manufacturingDate.year);
				fprintf(tempFile, "\n%-4d %-12s %-13s %-11s %-7.2f %-11s %-15d %-10s", cursor->data.id, cursor->data.manufactor, cursor->data.model, cursor->data.processor, cursor->data.price, "TRUE", cursor->data.amountInStock, strcat(strcat(strcat(strcat(day, "/"), month), "/"), year));

				cursor = cursor->right;
			}
		}

		amountOfitems--;

		// close the original file and remove it
		fclose(fp);
		remove(ITEMS_FILE);

		// close the new file and rename it
		fclose(tempFile);
		rename(TEMP_FILE, ITEMS_FILE);


		// Update log file
		writeToLogFile("Item was deleted");
	}

	return root;
}

/* This function checks if the items's ID exsits */
bool isItemIdExists(tree* root, int id) {
	tree* cursor = root;
	bool returnValue = TRUE;

	while (cursor != NULL) {
		if (cursor->data.id == id)
			return TRUE;
		else
			cursor = cursor->right;
	}
	return FALSE;
}

/* This function updates item on the tree and updates the items file - need to fix!!! */
void updateItem(tree* root, int validId) {
	int id = 0, choise = 0, isInStock = 0, numberOfAttempts = 0;
	char buffer;
	char inputDate[SIZE] = { 0 }, day[SIZE] = { 0 }, month[SIZE] = { 0 }, year[SIZE] = { 0 }, strTemp[SIZE] = { 0 };
	char inputAmount[SIZE] = { 0 }, inputId[SIZE] = { 0 }, inputIsInStock[SIZE] = { 0 }, inputPrice[SIZE] = { 0 }, choiseStr[SIZE] = { 0 };
	bool wrongInput = FALSE, validInput = FALSE;
	FILE* fp, * tempFile;

	tree* cursor = root;

	// check if there are any item on the store
	if (isTreeEmpty(root))
		puts("There are no items to update");
	else {
		// Open the original file and Create a new file
		fp = fopen(ITEMS_FILE, "r");
		tempFile = fopen(TEMP_FILE, "w");

		// headline for the new file
		fprintf(tempFile, "%-4s %-12s %-13s %-11s %-7s %-11s %-15s %-10s", "id", "manufactor", "model", "processor", "price", "isInStock", "amountInStock", "manufactoringDate");

		printf("\n===================\n    Update item\n===================\n");

		//  input & checks if the input is valid  -   && isInputValid(inputId, 1, runID))
		do {
			if (validId == 0) {
				printf("\nPlease enter the item's ID you want to update: > ");
				scanf_s("%s", inputId, SIZE);
				numberOfAttempts++;
				if (!isItemIdExists(root, atoi(inputId)))
					printf("Wrong input!\n");
			}
			else if (validId > 0)
				break;
			else
				printf("\nWrong choise! try again...\n");

			if (numberOfAttempts == 3 || numberOfAttempts == 6 || numberOfAttempts == 9) {
				puts("");
				print_inorder(root);
			}
			else if (numberOfAttempts > 9)
				return;

		} while (!isInputValid(inputId, 1, runID) || !isItemIdExists(root, atoi(inputId)));

		if (validId == 0)
			id = atoi(inputId);
		else
			id = validId;

		// Move over the tree and copy the original items and the updated item to the new file
		while (cursor != NULL) {
			if (cursor->data.id == id) { // the organ that need to be updated
				// operations to update the updated organ to the items file
				puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				printItem(cursor->data); // Prints the found organ
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

				printf("1.Change manufacor\n2.Change model\n3.Change processor\n4.Change price\n5.Change item in stock\n6.Change amount in stock\n7.Change manufacturing date\n8.Change all\n9.Back\nEnter your choice: > ");


				do {
					scanf_s("%s", choiseStr, SIZE);
					if (!isInputValid(choiseStr, 1, 9))
						printf("Wrong input!\nEnter your choice: > ");
				} while (!isInputValid(choiseStr, 1, 9));

				choise = atoi(choiseStr);

				switch (choise) {
				case 1: {
					printf("\nEnter the new manufacor: > ");
					scanf_s("%s", cursor->data.manufactor, SIZE);
					break;
				}
				case 2: {
					printf("Enter the new model name: > ");
					scanf_s("%s", cursor->data.model, SIZE);
					break;
				}
				case 3: {
					do {
						printf("Enter the new processor name (i3/i5/i7): > ");
						scanf_s("%s", cursor->data.processor, SIZE);
						if (!(strcmp(cursor->data.processor, "i3") == 0 || strcmp(cursor->data.processor, "i5") == 0 || strcmp(cursor->data.processor, "i7") == 0))
							printf("Wrong input!\n");
					} while (!(strcmp(cursor->data.processor, "i3") == 0 || strcmp(cursor->data.processor, "i5") == 0 || strcmp(cursor->data.processor, "i7") == 0));
					break;
				}
				case 4: {
					do {
						printf("\nPlease enter the new price: > ");
						scanf_s("%s", inputPrice, SIZE);
						if (!isInputFloat(inputPrice, 1.0, 9999.99))
							printf("Wrong input!");
					} while (!isInputFloat(inputPrice, 1.0, 9999.99));

					cursor->data.price = strtod(inputPrice, NULL);

					break;
				}
				case 5: {
					do {
						printf("Enter whether the product is in stock (1 - TRUE , 0 - FALSE) : > ");
						scanf_s("%s", inputIsInStock, SIZE);

						if (!(isInputValid(inputIsInStock, 0, 1)))
							printf("Wrong input!\n");
					} while (!(isInputValid(inputIsInStock, 0, 1)));

					isInStock = atoi(inputIsInStock);

					if (isInStock == 1) {
						if (cursor->data.isInStock == FALSE) {
							cursor->data.isInStock = TRUE;

							do {
								printf("Enter amount of items: > ");
								scanf_s("%s", &inputAmount, SIZE);
							} while (!isInputValid(inputAmount, 1, 100));

							cursor->data.amountInStock = atoi(inputAmount);
						}
					}
					else if (isInStock == 0) {
						cursor->data.isInStock = FALSE;
						cursor->data.amountInStock = 0;
					}

					break;
				}
				case 6: {
					do {
						printf("Enter amount of items: > ");
						scanf_s("%s", &inputAmount, SIZE);
					} while (!isInputValid(inputAmount, 0, 100));

					if (atoi(inputAmount) != 0)
						cursor->data.isInStock = TRUE;
					else
						cursor->data.isInStock = FALSE;
					cursor->data.amountInStock = atoi(inputAmount);
					break;
				}
				case 7: {
					do {
						printf("Please enter the date ( XX/XX/XXXX ): > ");
						scanf_s("%s", inputDate, SIZE);
						scanf_s("%c", &buffer, 1); // temp statement to clear buffer
						strcpy(strTemp, inputDate);
						if (isDateVaild(strTemp))
							validInput = TRUE;
						else
							printf("Wrong input!\n");

					} while (!isDateVaild(strTemp) && !validInput);

					cursor->data.manufacturingDate = setToDateVar(inputDate);
					break;
				}
				case 8: { // change all
					printf("\nEnter the new manufacor: > ");
					scanf_s("%s", cursor->data.manufactor, SIZE);

					printf("Enter the new model name: > ");
					scanf_s("%s", cursor->data.model, SIZE);

					do {
						printf("Enter the new processor name (i3/i5/i7): > ");
						scanf_s("%s", cursor->data.processor, SIZE);
						if (!(strcmp(cursor->data.processor, "i3") == 0 || strcmp(cursor->data.processor, "i5") == 0 || strcmp(cursor->data.processor, "i7") == 0))
							printf("Wrong input!\n");
					} while (!(strcmp(cursor->data.processor, "i3") == 0 || strcmp(cursor->data.processor, "i5") == 0 || strcmp(cursor->data.processor, "i7") == 0));

					do {
						printf("Please enter the new price: > ");
						scanf_s("%s", inputPrice, SIZE);
						if (!isInputFloat(inputPrice, 1.0, 9999.99))
							printf("Wrong input!\n");
					} while (!isInputFloat(inputPrice, 1.0, 9999.99));

					cursor->data.price = strtod(inputPrice, NULL);

					do {
						printf("Enter whether the product is in stock (1 - TRUE , 0 - FALSE) : > ");
						scanf_s("%s", inputIsInStock, SIZE);

						if (!(isInputValid(inputIsInStock, 0, 1)))
							printf("Wrong input!\n");
					} while (!(isInputValid(inputIsInStock, 0, 1)));

					isInStock = atoi(inputIsInStock);

					if (isInStock == 1) {
						if (cursor->data.isInStock == FALSE) {
							cursor->data.amountInStock = 1;
							cursor->data.isInStock = TRUE;
						}
						else {
							do {
								printf("Enter the new amount of items: > ");
								scanf_s("%s", &inputAmount, SIZE);
								if (!isInputValid(inputAmount, 0, 100))
									printf("Wrong input!\n");
							} while (!isInputValid(inputAmount, 0, 100));
							cursor->data.amountInStock = atoi(inputAmount);
						}
					}
					else if (isInStock == 0) {
						cursor->data.isInStock = FALSE;
						cursor->data.amountInStock = 0;
					}

					do {
						printf("Please enter the date ( XX/XX/XXXX ): > ");
						scanf_s("%s", inputDate, SIZE);
						scanf_s("%c", &buffer, 1); // temp statement to clear buffer
						strcpy(strTemp, inputDate);
						if (isDateVaild(strTemp))
							validInput = TRUE;
						else
							printf("Wrong input!\n");

					} while (!isDateVaild(strTemp) && !validInput);

					cursor->data.manufacturingDate = setToDateVar(inputDate);
					break;
				}
				case 9: {return; break;}
				default: {
					printf("Wrong input!\n");
					break;
				}
				}

				// copy the current organ to the items file
				sprintf(day, "%d", cursor->data.manufacturingDate.day);
				sprintf(month, "%d", cursor->data.manufacturingDate.month);
				sprintf(year, "%d", cursor->data.manufacturingDate.year);
				fprintf(tempFile, "\n%-4d %-12s %-13s %-11s %-7.2f %-11s %-15d %-10s", cursor->data.id, cursor->data.manufactor, cursor->data.model, cursor->data.processor, cursor->data.price, "TRUE", cursor->data.amountInStock, strcat(strcat(strcat(strcat(day, "/"), month), "/"), year));

				cursor = cursor->right;
			}
			else {

				sprintf(day, "%d", cursor->data.manufacturingDate.day);
				sprintf(month, "%d", cursor->data.manufacturingDate.month);
				sprintf(year, "%d", cursor->data.manufacturingDate.year);
				fprintf(tempFile, "\n%-4d %-12s %-13s %-11s %-7.2f %-11s %-15d %-10s", cursor->data.id, cursor->data.manufactor, cursor->data.model, cursor->data.processor, cursor->data.price, "TRUE", cursor->data.amountInStock, strcat(strcat(strcat(strcat(day, "/"), month), "/"), year));

				cursor = cursor->right;
			}
		}


		// close the original file and remove it
		fclose(fp);
		remove(ITEMS_FILE);

		// close the new file and rename it
		fclose(tempFile);
		rename(TEMP_FILE, ITEMS_FILE);


		/* Update log file*/
		writeToLogFile("Item was updated");
	}
}

/*  This function checks if the item exists by Item argument */
bool isItemExists(tree* root, Item item) {
	tree* cursor = root;
	bool returnValue = TRUE;
	while (cursor != NULL) {
		if (cursor->data.id == item.id && (strcmp(cursor->data.manufactor, item.manufactor) == 0) &&
			(strcmp(cursor->data.model, item.model) == 0) && strcmp(cursor->data.processor, item.processor) == 0 &&
			cursor->data.price == item.price && cursor->data.isInStock == item.isInStock && cursor->data.amountInStock == item.amountInStock &&
			cursor->data.manufacturingDate.day == item.manufacturingDate.day && cursor->data.manufacturingDate.month == item.manufacturingDate.month &&
			cursor->data.manufacturingDate.year == item.manufacturingDate.year)
		{
			return TRUE;
		}
		else
			cursor = cursor->right;
	}

	return FALSE;
}

/* This function search an item on the tree */
tree* searchItem(tree* root, int id) {
	{
		if (!root)
			return NULL;

		if (id < root->data.id)
		{
			searchItem(root->left, id);
		}
		else if (id > root->data.id)
		{
			searchItem(root->right, id);
		}
		else if (id == root->data.id)
		{
			return root;
		}
	}
}

/* This function do somehting - need to continue */
void filterThenSearch(tree* root, int userLevel) {
	tree* cursor = root;

	// check if there are any item on the store
	if (isTreeEmpty(root))
		puts("There are no items to show!");
	else {
		int id = 0, userChoice = 0, counter = 0, currentPrice = 0, isInStock = 0, trueCounter = 0, falseCounter = 0;
		float price = 0.0;
		char  userInput1[SIZE] = { 0 }, userInput2[SIZE] = { 0 }, inputId[SIZE] = { 0 }, strTemp[SIZE] = { 0 }, buffer;
		bool validInput = FALSE;
		int* validId = (int*)calloc(runID, sizeof(int)); // dynamic array for maintain the valid item's id
		Date tempDate = { 0,0,0 };

		printf("\n========================\n  Search Item On Store\n========================\n\n");

		printf("Please choose how you would like to filter your search:\n\n");
		printf("1.Filter by manufacturer\n2.Filter by model\n3.Filter by manufacturer&model\n4.Filter by price\n5.Filter by stock availability\n6.Filter by date\n7.Back\nEnter your choice : > ");


		do {
			scanf_s("%s", &userInput1, SIZE);
			if (!isInputValid(userInput1, 1, 7))
				printf("Wrong input!\nEnter your choice: > ");
		} while (!isInputValid(userInput1, 1, 7));

		userChoice = atoi(userInput1);

		switch (userChoice) {
		case 1: { // manufactor
			do {
				printf("\nEnter manufactor name: > ");
				scanf_s("%s", &userInput1, SIZE);
				scanf_s("%c", &buffer, 1); // temp statement to clear buffer

				if (!isItemExistsByStr(root, userInput1, 1))
					printf("Wrong manufactor!\n");
			} while (!isItemExistsByStr(root, userInput1, 1));

			puts("");

			tree* cursor = root;

			while (cursor != NULL) {
				if (strcmp(cursor->data.manufactor, userInput1) == 0) {
					printItem(cursor->data);
					validId[cursor->data.id] = cursor->data.id;
					cursor = cursor->right;
				}
				else
					cursor = cursor->right;
			}

			/* Update log file */
			writeToLogFile("Search by manufacturer was activated");
			if (userLevel != 1) {
				do {
					printf("\nDo you want to update an item? [y/n]: > ");
					scanf_s("%s", &userInput1, SIZE);

					if (strlen(userInput1) == 1 && isalpha(userInput1[0])) {
						userInput1[0] = tolower(userInput1[0]);
						if (userInput1[0] == 'y' || userInput1[0] == 'n')
							break;
						else
							puts("Wrong input!");
					}
					else
						puts("Wrong input!");

				} while (!(strlen(userInput1) == 1 && isalpha(userInput1[0]) && (userInput1[0] == 'y' || userInput1[0] == 'n')));

				if (userInput1[0] == 'y') {
					do {
						printf("\nPlease enter one of the following item's ID you want to update: > ");
						scanf_s("%s", inputId, SIZE);
						if (atoi(inputId) == 0 || !(validId[atoi(inputId)] == atoi(inputId)))
							printf("Invalid ID\n");
					} while ((atoi(inputId) == 0) || !(validId[atoi(inputId)] == atoi(inputId)));

					id = atoi(inputId);
					updateItem(root, id);
				}
				else if (userInput1[0] == 'n')
					return;
			}



			break;
		}
		case 2: { // model
			do {
				printf("\nEnter model name: > ");
				scanf_s("%s", &userInput1, SIZE);
				scanf_s("%c", &buffer); // temp statement to clear buffer

				if (!isItemExistsByStr(root, userInput1, 2))
					printf("Wrong model!\n");
			} while (!isItemExistsByStr(root, userInput1, 2));

			puts("");

			tree* cursor = root;

			while (cursor != NULL) {
				if (strcmp(cursor->data.model, userInput1) == 0) {
					printItem(cursor->data);
					validId[cursor->data.id] = cursor->data.id;
					cursor = cursor->right;
				}
				else
					cursor = cursor->right;
			}

			/* Update log file */
			writeToLogFile("Search by model was activated");
			if (userLevel != 1) {
				do {
					printf("\nDo you want to update an item? [y/n]: > ");
					scanf_s("%s", &userInput1, SIZE);

					if (strlen(userInput1) == 1 && isalpha(userInput1[0])) {
						userInput1[0] = tolower(userInput1[0]);
						if (userInput1[0] == 'y' || userInput1[0] == 'n')
							break;
						else
							puts("Wrong input!");
					}
					else
						puts("Wrong input!");

				} while (!(strlen(userInput1) == 1 && isalpha(userInput1[0]) && (userInput1[0] == 'y' || userInput1[0] == 'n')));

				if (userInput1[0] == 'y') {
					do {
						printf("\nPlease enter one of the following item's ID you want to update: > ");
						scanf_s("%s", inputId, SIZE);
						if (atoi(inputId) == 0 || !(validId[atoi(inputId)] == atoi(inputId)))
							printf("Invalid ID\n");
					} while ((atoi(inputId) == 0) || !(validId[atoi(inputId)] == atoi(inputId)));

					id = atoi(inputId);
					updateItem(root, id);
				}
				else if (userInput1[0] == 'n')
					return;
			}

			break;
		}
		case 3: { // manufactor & model
			do {
				printf("\nEnter manufactor name: > ");
				scanf_s("%s", &userInput1, SIZE);
				scanf_s("%c", &buffer, 1); // temp statement to clear buffer

				if (!isItemExistsByStr(root, userInput1, 1))
					printf("Wrong manufactor!\n");
			} while (!isItemExistsByStr(root, userInput1, 1));

			do {
				printf("\nEnter model name: > ");
				scanf_s("%s", &userInput2, SIZE);
				scanf_s("%c", &buffer); // temp statement to clear buffer

				if (!isItemExistsByStr(root, userInput2, 2))
					printf("Wrong model!\n");
			} while (!isItemExistsByStr(root, userInput2, 2));

			puts("");

			tree* cursor = root;

			while (cursor != NULL) {
				if (strcmp(cursor->data.manufactor, userInput1) == 0 && strcmp(cursor->data.model, userInput2) == 0) {
					printItem(cursor->data);
					validId[cursor->data.id] = cursor->data.id;
					cursor = cursor->right;
				}
				else
					cursor = cursor->right;
			}

			/* Update log file */
			writeToLogFile("Search by manufacturer & model was activated");

			if (userLevel != 1) {
				do {
					printf("\nDo you want to update an item? [y/n]: > ");
					scanf_s("%s", &userInput1, SIZE);

					if (strlen(userInput1) == 1 && isalpha(userInput1[0])) {
						userInput1[0] = tolower(userInput1[0]);
						if (userInput1[0] == 'y' || userInput1[0] == 'n')
							break;
						else
							puts("Wrong input!");
					}
					else
						puts("Wrong input!");

				} while (!(strlen(userInput1) == 1 && isalpha(userInput1[0]) && (userInput1[0] == 'y' || userInput1[0] == 'n')));

				if (userInput1[0] == 'y') {
					do {
						printf("\nPlease enter one of the following item's ID you want to update: > ");
						scanf_s("%s", inputId, SIZE);
						if (atoi(inputId) == 0 || !(validId[atoi(inputId)] == atoi(inputId)))
							printf("Invalid ID\n");
					} while ((atoi(inputId) == 0) || !(validId[atoi(inputId)] == atoi(inputId)));

					id = atoi(inputId);
					updateItem(root, id);
				}
				else if (userInput1[0] == 'n')
					return;
			}
			break;
		}
		case 4: {
			do {   // price
				printf("\nPlease enter the price: > ");
				scanf_s("%s", userInput1, SIZE);
				scanf_s("%c", &buffer, 1); // temp statement to clear buffer
				if (!isInputFloat(userInput1, 0.0, 9999.99))
					printf("\nWrong input!\n");
			} while (!isInputFloat(userInput1, 0.0, 9999.99));

			currentPrice = atoi(userInput1);

			do {
				printf("\nDo you want to get higer(h) or lower(l) price than you entered? [h/l]: > ");
				scanf_s("%s", &userInput1, SIZE);

				if (strlen(userInput1) == 1 && isalpha(userInput1[0])) {
					userInput1[0] = tolower(userInput1[0]);
					if (userInput1[0] == 'h' || userInput1[0] == 'l')
						break;
					else
						puts("Wrong input!");
				}
				else
					puts("Wrong input!");

			} while (!(strlen(userInput1) == 1 && isalpha(userInput1[0]) && (userInput1[0] == 'h' || userInput1[0] == 'l')));

			if (userInput1[0] == 'h') { // higher price

				while (cursor != NULL) {
					if (cursor->data.price > currentPrice) {
						printItem(cursor->data);
						validId[cursor->data.id] = cursor->data.id;
						cursor = cursor->right;
					}
					else
						cursor = cursor->right;
				}
			}
			else if (userInput1[0] == 'l') {

				while (cursor != NULL) {
					if (cursor->data.price < currentPrice) {
						printItem(cursor->data);
						validId[cursor->data.id] = cursor->data.id;
						cursor = cursor->right;
					}
					else
						cursor = cursor->right;
				}
			}

			/* Update log file */
			writeToLogFile("Search by price was activated");

			if (userLevel != 1) {
				do {
					printf("\nDo you want to update an item? [y/n]: > ");
					scanf_s("%s", &userInput1, SIZE);

					if (strlen(userInput1) == 1 && isalpha(userInput1[0])) {
						userInput1[0] = tolower(userInput1[0]);
						if (userInput1[0] == 'y' || userInput1[0] == 'n')
							break;
						else
							puts("Wrong input!");
					}
					else
						puts("Wrong input!");

				} while (!(strlen(userInput1) == 1 && isalpha(userInput1[0]) && (userInput1[0] == 'y' || userInput1[0] == 'n')));

				if (userInput1[0] == 'y') {
					do {
						printf("\nPlease enter one of the following item's ID you want to update: > ");
						scanf_s("%s", inputId, SIZE);
						if (atoi(inputId) == 0 || !(validId[atoi(inputId)] == atoi(inputId)))
							printf("Invalid ID\n");
					} while ((atoi(inputId) == 0) || !(validId[atoi(inputId)] == atoi(inputId)));

					id = atoi(inputId);
					updateItem(root, id);
				}
				else if (userInput1[0] == 'n')
					return;
			}
			break;
		}
		case 5: {
			do { // isInStock-> TRUE/FALSE
				printf("\nEnter value to see products that are in stock or not (1 - TRUE , 0 - FALSE) : > ");
				scanf_s("%s", userInput1, SIZE);

				if (!(isInputValid(userInput1, 0, 1)))
					printf("Wrong input!\n");
			} while (!(isInputValid(userInput1, 0, 1)));

			isInStock = atoi(userInput1);
			printf("\n");

			while (cursor != NULL) {
				if (isInStock == 1 && isItemExistsByBoolStr(cursor, "TRUE")) {
					trueCounter++;
					printItem(cursor->data);
					validId[cursor->data.id] = cursor->data.id;
					cursor = cursor->right;
				}
				else if (isInStock == 0 && isItemExistsByBoolStr(cursor, "FALSE")) {
					falseCounter++;
					printItem(cursor->data);
					validId[cursor->data.id] = cursor->data.id;
					cursor = cursor->right;
				}
				else
					cursor = cursor->right;
			}

			/* Update log file */
			writeToLogFile("Search by availability was activated");
			if (userLevel != 1) {
				if ((falseCounter > 0 && trueCounter > 0) || (falseCounter == 0 && trueCounter > 0) || (falseCounter > 0 && trueCounter == 0)) {
					do {
						printf("\nDo you want to update an item? [y/n]: > ");
						scanf_s("%s", &userInput1, SIZE);

						if (strlen(userInput1) == 1 && isalpha(userInput1[0])) {
							userInput1[0] = tolower(userInput1[0]);
							if (userInput1[0] == 'y' || userInput1[0] == 'n')
								break;
							else
								puts("Wrong input!");
						}
						else
							puts("Wrong input!");

					} while (!(strlen(userInput1) == 1 && isalpha(userInput1[0]) && (userInput1[0] == 'y' || userInput1[0] == 'n')));

					if (userInput1[0] == 'y') {
						do {
							printf("\nPlease enter one of the following item's ID you want to update: > ");
							scanf_s("%s", inputId, SIZE);
							if (atoi(inputId) == 0 || !(validId[atoi(inputId)] == atoi(inputId)))
								printf("\nInvalid ID!\n");
						} while ((atoi(inputId) == 0) || !(validId[atoi(inputId)] == atoi(inputId)));

						id = atoi(inputId);
						updateItem(root, id);
					}
					else if (userInput1[0] == 'n')
						return;
				}
				else if (falseCounter == 0 || trueCounter == 0)
					printf("No such items!\n");
			}
			if (userLevel == 1 && (falseCounter == 0 || trueCounter == 0))
				printf("No such items!\n");

			break;
		}
		case 6: {  // date
			do {

				printf("Please enter the date ( XX/XX/XXXX ): > ");
				scanf_s("%s", userInput1, SIZE);
				scanf_s("%c", &buffer, 1); // temp statement to clear buffer
				strcpy(strTemp, userInput1);
				if (isDateVaild(strTemp))
					validInput = TRUE;
				else
					printf("Wrong input!\n");

			} while (!isDateVaild(strTemp) && !validInput);

			tempDate = setToDateVar(userInput1); // input date

			do {
				printf("\nWould you like to view an item with an earlier(e) or later(l) date? [e/l]: > ");
				scanf_s("%s", &userInput1, SIZE);

				if (strlen(userInput1) == 1 && isalpha(userInput1[0])) {
					userInput1[0] = tolower(userInput1[0]);
					if (userInput1[0] == 'e' || userInput1[0] == 'l')
						break;
					else
						puts("Wrong input!");
				}
				else
					puts("Wrong input!");

			} while (!(strlen(userInput1) == 1 && isalpha(userInput1[0]) && (userInput1[0] == 'e' || userInput1[0] == 'l')));

			if (userInput1[0] == 'e') { // earlier date
				while (cursor != NULL) {
					if (cursor->data.manufacturingDate.year <= tempDate.year && cursor->data.manufacturingDate.month <= tempDate.month && cursor->data.manufacturingDate.day < tempDate.day) {
						printItem(cursor->data);
						validId[cursor->data.id] = cursor->data.id;
						cursor = cursor->right;
					}
					else
						cursor = cursor->right;
				}
			}
			else if (userInput1[0] == 'l') { // later date

				while (cursor != NULL) {
					if (cursor->data.manufacturingDate.year >= tempDate.year && (cursor->data.manufacturingDate.month >= tempDate.month || cursor->data.manufacturingDate.day >= tempDate.day)) {
						printItem(cursor->data);
						validId[cursor->data.id] = cursor->data.id;
						cursor = cursor->right;
					}
					else
						cursor = cursor->right;
				}
			}

			/* Update log file */
			writeToLogFile("Search by date was activated");

			if (userLevel != 1) {
				do {
					printf("\nDo you want to update an item? [y/n]: > ");
					scanf_s("%s", &userInput1, SIZE);

					if (strlen(userInput1) == 1 && isalpha(userInput1[0])) {
						userInput1[0] = tolower(userInput1[0]);
						if (userInput1[0] == 'y' || userInput1[0] == 'n')
							break;
						else
							puts("Wrong input!");
					}
					else
						puts("Wrong input!");

				} while (!(strlen(userInput1) == 1 && isalpha(userInput1[0]) && (userInput1[0] == 'y' || userInput1[0] == 'n')));

				if (userInput1[0] == 'y') {
					do {
						printf("\nPlease enter one of the following item's ID you want to update: > ");
						scanf_s("%s", inputId, SIZE);
						if (atoi(inputId) == 0 || !(validId[atoi(inputId)] == atoi(inputId)))
							printf("Invalid ID\n");
					} while ((atoi(inputId) == 0) || !(validId[atoi(inputId)] == atoi(inputId)));

					id = atoi(inputId);
					updateItem(root, id);
				}
				else if (userInput1[0] == 'n')
					return;
			}
			break;
		}
		case 7: { return; break; }
		default: { break; }
		}
	}
}

/*  This function checks if the item exists by ID and string argument */
bool isItemExistsByBoolStr(tree* root, char* strInput) {
	char temp[SIZE] = { 0 };
	tree* cursor = root;

	if (cursor->data.isInStock == 1)
		strcpy(temp, "TRUE");
	else
		strcpy(temp, "FALSE");

	if (strcmp(temp, strInput) == 0)
		return TRUE;
	else
		return FALSE;
}

/*  This function checks if the item exists by string argument */
bool isItemExistsByStr(tree* root, char* strInput, int field) {
	tree* cursor = root;
	bool returnValue = TRUE;

	if (!root) // empty tree
		return FALSE;

	while (cursor != NULL) {
		switch (field) {
		case 1: { // manufactor
			if (strcmp(cursor->data.manufactor, strInput) == 0)
				return TRUE;
			else
				cursor = cursor->right;
			break;
		}
		case 2: {  // model
			if (strcmp(cursor->data.model, strInput) == 0)
				return TRUE;
			else
				cursor = cursor->right;
			break;
		}
		default: { break; }
		}
	}
	return FALSE;
}



/***************************/
/* Aviram's tree functions */
/***************************/

/*create a new node*/
tree* create_node(tree* parent, tree_type data)
{
	tree* node = (tree*)malloc(sizeof(tree));
	if (!node)
	{
		printf("Not enough system memory is available for allocation!\n");
		exit(1);
	}
	node->data = data;
	node->parent = parent;
	node->left = node->right = NULL;
	return node;
}

/*insert a new node into the BST using recursive method*/
void insert_recursive(tree** root, tree* parent, tree_type data)
{
	if (!(*root))
	{
		tree* temp = create_node(parent, data);
		*root = temp;
		return;
	}

	if (data.id < (*root)->data.id)
	{
		insert_recursive(&(*root)->left, *root, data);
	}
	else if (data.id > (*root)->data.id)
	{
		insert_recursive(&(*root)->right, *root, data);
	}
}

void print_preorder(tree* root)
{
	if (root)
	{
		printItem(root->data);
		print_preorder(root->left);
		print_preorder(root->right);
	}
}

void print_inorder(tree* root)
{
	if (root)
	{
		print_inorder(root->left);
		//printf("%d ", root->data);
		printItem(root->data);
		print_inorder(root->right);
	}
}

void print_postorder(tree* root)
{
	if (root)
	{
		print_postorder(root->left);
		print_postorder(root->right);
		//printf("%d ", root->data);
		printItem(root->data);
	}
}

void deltree(tree** root)
{
	if (*root)
	{
		deltree(&((*root)->left));
		deltree(&((*root)->right));
		free(*root);
		*root = NULL;
	}
}

tree* search(tree* root, tree_type data)
{
	if (!root)
		return NULL;

	if (data.id < root->data.id)
	{
		search(root->left, data);
	}
	else if (data.id > root->data.id)
	{
		search(root->right, data);
	}
	else if (data.id == root->data.id)
	{
		return root;
	}
}

tree* min_value(tree* node, int* height)
{
	*height = 0;

	/* loop down to find the leftmost leaf */
	while (node->left != NULL)
	{
		node = node->left;
		(*height)++;
	}

	return node;
}

tree* max_value(tree* node, int* height)
{
	*height = 0;

	/* loop down to find the rightmost leaf */
	while (node->right != NULL)
	{
		node = node->right;
		(*height)++;
	}

	return node;
}

/*delete a node in the BST*/
tree* delete_node(tree* root, tree_type data)
{
	if (!root)
		return NULL;

	if (data.id < root->data.id)
		root->left = delete_node(root->left, data);
	else if (data.id > root->data.id)
		root->right = delete_node(root->right, data);
	else
	{
		tree* temp = NULL;

		if ((root->left) && (root->right)) //2 children
		{
			int left, right;
			tree* parent = NULL;
			tree* cursorLeft = min_value(root->right, &left);
			tree* cursorRight = max_value(root->left, &right);

			temp = (left > right) ? cursorLeft : cursorRight;
			parent = temp->parent;
			root->data = temp->data;

			if (parent->left == temp)
				parent->left = delete_node(parent->left, temp->data);
			else
				parent->right = delete_node(parent->right, temp->data);
		}
		else
		{
			if (root->left)	//only left child
			{
				temp = root->left;
				temp->parent = root->parent;
			}
			else if (root->right) //only right child
			{
				temp = root->right;
				temp->parent = root->parent;
			}
			free(root);
			root = temp;
		}
	}

	return root;
}

// Function to print binary tree in 2D , It does reverse inorder
void print_tree(tree* root, int space)
{
	int i;

	// Base case
	if (!root)
		return;

	// Process right child first
	print_tree(root->right, space + COUNT);

	// Print current node after space
	// count
	printf("\n");
	for (i = 0; i < space; i++)
		printf(" ");
	printf("%d\n", root->data);

	// Process left child
	print_tree(root->left, space + COUNT);
}