#include "vax.h"

void initDatabase (databaseType *db)
{
	int j;
	String10 A[MAX_BRAND] = {"Sinovac", "AstraZeneca", "Pfizer", 
							"Moderna", "Sputnik", "J&J", 
							"Novavax", "Sinopharm"};

	for (j = 0; j < MAX_BRAND; j++)
	{ 
		strcpy(db->vax[j], A[j]);
	}
}

void mainMenu (databaseType *db)
{
	char choice;
	
	initDatabase(db);
	db->userCount = 0;

	do 
	{
		printf("\n===MAIN MENU===\n");
		printf("1] Input New User\n");
		printf("2] Input Vax Information\n");
		printf("3] Search\n");
		printf("x] Exit\n");
		printf("Enter choice: ");
		scanf(" %c", &choice);
		
		switch (choice)
		{
			case '1': setUser(db); break;
			case '2': setVaxInfo(db); break;
			case '3': searchMenu(db); break;
			case 'x': 
			case 'X': printf("Exiting....\n"); break;
			default: printf("Invalid Input!\n");
		}

	} while (choice != 'x' && choice != 'X');
}
