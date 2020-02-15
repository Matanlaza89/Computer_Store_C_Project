/* Written by: Matan Leizerovich 302674304 */


/******************************************************************************
*	==============================                                            *
*      Matan Product sales shop					    			              *
*	==============================                     						  *
*																		      *
*   Implemention include:												      *
*	---------------------													  *
*                          													  *
*		1. login															  *
*		2. menu															      *
*		3. userLevelOneMenu											       	  *
*		4. userLevelTwoMenu	        										  *
*		5. userLevelThreeMenu												  *
*		6. createTree													      *
*		7. isTreeEmpty													      *
*		8. isInputValid													      *
*		9. createUsersFile													  *
*	   10. isFileExists													      *
*	   11. writeToLogFile													  *
*	   12. createLogFile													  *
*	   13. updateItemsFile													  *
*	   14. convertToBinaryFile												  *
*	   15. checkIfUserValid													  *
*	   16. printUserInfo													  *
*	   17. createUser													      *
*	   18. displayUsers													      *
*	   19. deleteUser													      *
*	   20. isUserExists													      *
*	   21. usersAmount													      *
*	   22. updateUser													      *
*	   23. printDate													      *
*	   24. setToDateVar													      *
*	   25. isDateVaild													      *
*	   26. printItem													      *
*	   27. addItem					    								      *
*	   28. deleteItem													      *
*	   29. isItemIdExists												      *
*	   30. updateItem													      *
*	   31. isItemExists													      *
*	   32. searchItem													      *
*	   33. filterThenSearch													  *
*	   34. isItemExistsByStr												  *
*	   35. isItemExistsByBoolStr											  *
*	   36. create_node														  *
*	   37. insert_iterative													  *
*	   38. insert_recursive													  *
*	   39. print_preorder													  *
*	   40. print_inorder													  *
*	   41. print_postorder													  *
*	   42. deltree															  *
*	   43. search															  *
*	   44. min_value														  *
*	   45. max_value														  *
*	   46. delete_node														  *
*	   47. print_tree														  *
*	   48. clrscr															  *
*																		      *
*	The code was written by Matan leizerovich                   	          *
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
#define USER_LEVEL 1
#define SUPERUSER_LEVEL 2
#define ADMIN_LEVEL 3
#define FIRST_OPTION_ON_MENU 1
#define LAST_OPTION_ON_MENU_LEVEL_ONE 5
#define LAST_OPTION_ON_MENU_LEVEL_TWO 7
#define LAST_OPTION_ON_MENU_LEVEL_THREE 11
#define LAST_OPTION_ON_UPDATE_USER_MENU 5
#define LAST_OPTION_ON_UPDATE_ITEM_MENU 9
#define LAST_OPTION_ON_FILTER_AND_SEARCH_MENU 7
#define MIN_COUNTER 3
#define MAX_COUNTER 6
#define MIN_YEAR 1980
#define MAX_YEAR 2020
#define MIN_PRICE 1.0
#define MAX_PRICE 9999.99
#define MIN_ITEMS_AMOUNT 0
#define MAX_ITEMS_AMOUNT 100



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

char* login(int*);
void menu(tree*, int, int, int*);
void userLevelOneMenu(tree*, bool*, int itemsId[], char* );
void userLevelTwoMenu(tree*, bool*, int itemsId[], char* );
void userLevelThreeMenu(tree*, bool*, int itemsId[], char* );
tree* createTree(int itemsId[]);
bool isTreeEmpty(tree*);
bool isInputValid(char*, int, int);
bool isInputFloat(char* , float , float);
void clrscr(void);


/********************/
/* Files  functions */
/********************/

void createUsersFile(void);
bool isFileExists(FILE*);
void writeToLogFile(char* ,char*);
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