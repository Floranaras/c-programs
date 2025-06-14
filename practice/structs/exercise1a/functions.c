#include "head.h"

void initDatabase (databaseType *db)
{
	db->userCount = 0;
}
void inputNewUser (databaseType *db)
{
	int j;
	char choice = 'y';
	userType *currentUser = &db->users[db->userCount];
	int *vaxCtr = &currentUser->vaxCount;
	vaxType *vaxList = &currentUser->vaccines;

	if (db->userCount != MAX_PEOPLE)
	{
		scanf("%s", currentUser->name.first);
		scanf("%s", currentUser->name.last);
		scanf("%c", &currentUser->name.middle);

		scanf("%d", &currentUser->birthDate.month);
		scanf("%d", &currentUser->birthDate.day);
		scanf("%d", &currentUser->birthDate.year);
		
		*vaxCtr = 0;

		for (j = 0; j < MAX_VAX && choice == 'y'; j++)	
		{
			scanf("%s",vaxList[j].brand);
			scanf("%s",vaxList[j].city);

			scanf("%d",&vaxList[j].vaxDate.month);
			scanf("%d",&vaxList[j].vaxDate.day);
			scanf("%d",&vaxList[j].vaxDate.year);

			(*vaxCtr)++;

			scanf(" %c", choice);
		}

		db->userCount++;
	}

	else 
	{
		printf("Database is full ;-;");
	}

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