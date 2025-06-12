#include "head.h"

void initDatabase (databaseType *db)
{
	db->userCount = 0;
}
void inputNewUser (databaseType *db)
{

}

void displayUserData (databaseType *db)
{

}

void searchByName (databaseType *db)
{

}

void searchByDate (databaseType *db)
{

}

void mainMenu (databaseType *db)
{

	char choice;
	
	initDatabase(db);
	
	do 
	{
		printf("\n===MAIN MENU===\n");
		printf("1] Input New User\n");
		printf("2] Search by Name\n");
		printf("3] Search by Date of birth\n");
		printf("x] Exit\n");

		scanf(" %c", &choice);

		switch (choice)
		{
			case '1': inputNewUser(db); break;
			case '2': searchByName(db); break;
			case '3': searchByDate(db); break;
		}
	
	} while (choice != 'x');
}
