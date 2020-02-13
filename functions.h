/* Written by:
Matan Leizerovich 302674304
Doron Avramov     308140987 */


/******************************************************************************
*	==============================                                            *
*   Matan&Doron Product sales shop					    			          *
*	==============================                     						  *
*																		      *
*   Implemention include:												      *
*	---------------------													  *
*                          													  *
*		1. login                                                              *
*		2. userLevelOneMenu											       	  *
*		3. userLevelTwoMenu	        										  *
*		4. userLevelThreeMenu												  *
*		5. createTree													      *
*		6. isTreeEmpty													      *
*		7. isInputValid													      *
*		8. createUsersFile													  *
*		9. isFileExists													      *
*	   10. writeToLogFile													  *
*	   11. createLogFile													  *
*	   12. updateItemsFile													  *
*	   13. convertToBinaryFile												  *
*	   14. checkIfUserValid													  *
*	   15. printUserInfo													  *
*	   16. createUser													      *
*	   17. displayUsers													      *
*	   18. deleteUser													      *
*	   19. isUserExists													      *
*	   20. usersAmount													      *
*	   21. updateUser													      *
*	   22. printDate													      *
*	   23. setToDateVar													      *
*	   24. isDateVaild													      *
*	   25. printItem													      *
*	   26. addItem					    								      *
*	   27. deleteItem													      *
*	   28. isItemIdExists												      *
*	   29. updateItem													      *
*	   30. isItemExists													      *
*	   31. searchItem													      *
*	   32. filterThenSearch													  *
*	   33. isItemExistsByStr												  *
*	   34. isItemExistsByBoolStr											  *
*	   35. create_node														  *
*	   36. insert_iterative													  *
*	   37. insert_recursive													  *
*	   38. print_preorder													  *
*	   39. print_inorder													  *
*	   40. print_postorder													  *
*	   41. deltree															  *
*	   42. search															  *
*	   43. min_value														  *
*	   44. max_value														  *
*	   45. delete_node														  *
*	   46. print_tree														  *
*																		      *
*	The code was written by Matan leizerovich and Doron Avramov,	          *
*	Based on the following references:		                                  *
*  	https://www.google.co.il/                                                 *
*	http://md.hit.ac.il/pluginfile.php/411379/mod_resource/content/1/tree.c   *
******************************************************************************/

#include <stdio.h>
#ifndef _FUNCTIONS_H  // if not define then do the following procedure
#define _FUNCTIONS_H

/* Constant Variables*/
#define COUNT 10
#define SIZE 20
#define TRUE 1
#define FALSE 0
#define NUM_OF_ATTEMPTS 3
#define USER_FILE_NAME "users.txt"
#define LOG_FILE "logfile.txt"
#define ITEMS_FILE "items.txt"
#define TEMP_FILE "temp.txt"
#define USERS_BIN_FILE "users.bin"
#define ITEMS_BIN_FILE "items.bin"

/* Global variables */

extern int runID;
extern int amountOfUsers;
extern int amountOfitems;
extern int itemsIdArraySize;

/* creates new variable type - boolean */

typedef int bool;

/* Date Struct */
typedef struct Date {
	int day, month, year;
}Date;

/* Item Struct */

typedef struct Item {
	int id;
	char manufactor[SIZE];
	char model[SIZE];
	char processor[SIZE];
	float price;
	bool isInStock;
	int amountInStock;
	Date manufacturingDate;
}Item;

typedef Item tree_type;

/* Tree struct */

typedef struct tree {

	struct tree* right, * left, * parent;
	tree_type data;
}tree;


/*~*~*~*~*~*~*~*~*~*~*~*~*/
/* Function declarations */
/*~*~*~*~*~*~*~*~*~*~*~*~*/


   /*********************/
  /* General functions */
 /*********************/

void login(int*);
void userLevelOneMenu(tree*, bool*, int itemsId[]);
void userLevelTwoMenu(tree*, bool*, int itemsId[]);
void userLevelThreeMenu(tree*, bool*, int itemsId[]);
tree* createTree(int itemsId[]);
bool isTreeEmpty(tree*);
bool isInputValid(char*, int, int);
bool isInputFloat(char* , float , float);


/********************/
/* Files  functions */
/********************/

void createUsersFile(void);
bool isFileExists(FILE*);
void writeToLogFile(char*);
void createLogFile(void);
void updateItemsFile(Item, char*);
//void convertToBinaryFile(char* textFileName, char* binaryFileName);


  /*********************/
 /*  Users  functions */
/*********************/

bool checkIfUserValid(char*, char*, int**);
void printUserInfo(char*, char*, int, char*);
void createUser(void);
void displayUsers(void);
void deleteUser(void);
bool isUserExists(char*);
int usersAmount(void);
void updateUser(void);

/******************/
/* Date functions */
/******************/

void printDate(Date);
Date setToDateVar(char*);
bool isDateVaild(char*);


/********************/
/*  Items functions */
/********************/

void printItem(Item);
void addItem(tree**, tree*, int itemsId[]);
tree* deleteItem(tree*, int itemsId[]);
bool isItemIdExists(tree*, int);
void updateItem(tree*, int);
bool isItemExists(tree*, Item);
tree* searchItem(tree*, int);
void filterThenSearch(tree*, int);
bool isItemExistsByStr(tree*, char*, int);
bool isItemExistsByBoolStr(tree*, char*);



/* Aviram's tree functions */

tree* create_node(tree*, tree_type);
void insert_iterative(tree**, tree_type);
void insert_recursive(tree**, tree*, tree_type);
void print_preorder(tree*);
void print_inorder(tree*);
void print_postorder(tree*);
void deltree(tree**);
tree* search(tree*, tree_type);
tree* min_value(tree*, int*);
tree* max_value(tree*, int*);
tree* delete_node(tree*, tree_type);
void print_tree(tree*, int);


#endif