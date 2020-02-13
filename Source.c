/* Written by:
Matan Leizerovich 302674304
Doron Avramov     308140987 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include "functions.h"

/* Initialing the global variables */

int runID = 0;
int amountOfUsers = 0;
int amountOfitems = 0;
int itemsIdArraySize = 0;

/* Main Function */

int main() {
	int numberOfTries = 0, userChoice = 0, userLevel = 0;
	char username[SIZE], password[SIZE];
	char buffer;
	bool isLogoutPressed = FALSE;
	tree* root = NULL;

	/* Dynamic array for valid items */
	int* itemsId = (int*)calloc(sizeof(int));

	/* At the beginning of the program, the item file opens and a binary search tree is created from it */
	root = createTree(itemsId);

	//convertToBinaryFile(USER_FILE_NAME, USERS_BIN_FILE);


	/* Checks whether the log file exists or not, if not, produces the file */
	if (!isFileExists(LOG_FILE))
		createLogFile();

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nWelcome to Matan&Doron computer store!\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	// Check if there is user text file - if exist then give the login message to the user , otherwise create a file with one user
	if (isFileExists(USER_FILE_NAME))
		login(&userLevel);
	else {
		createUsersFile();
		strcpy(username, "admin");
		strcpy(password, "admin");
		userLevel = 3;
		printf("\n~ Your username is: | admin | and password is: | admin | for login ~\n");
		login(&userLevel);
	}

	amountOfUsers = usersAmount();

	while (TRUE) {  // menu function
		if (isLogoutPressed) {
			isLogoutPressed = FALSE;
			login(&userLevel);
		}

		switch (userLevel) {
		case 1: {
			userLevelOneMenu(root, &isLogoutPressed, itemsId);
			break;
		}

		case 2: {
			userLevelTwoMenu(root, &isLogoutPressed, itemsId);
			break;
		}
		case 3: {
			userLevelThreeMenu(root, &isLogoutPressed, itemsId);
			break;
		}
		default:
			break;
		}
	}

	free(root);
	return 0;
}