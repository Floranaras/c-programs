#include "vaxFunc.c"

void displayUser (userType user)
{
	int j;

	printf("\nName: %s %c. %s\n", user.name.first, 
		   user.name.middle, user.name.last);
	printf("Date of Birth: %d/%d/%d\n", 
		   user.birthDate.month, user.birthDate.day, 
		   user.birthDate.year);
	printf("\n===VACCINES TAKEN===\n");

	for (j = 0; j < user.vaxCount; j++)
	{
		printf("Vaccine #%d:\n", j + 1);
		printf("Brand: %s\n", user.vaccines[j].brand);
		printf("City of Vaccination: %s\n", user.vaccines[j].city);
		printf("Date of Vaccination: %2d/%2d/%2d\n", user.vaccines[j].vaxDate.month,
			user.vaccines[j].vaxDate.day, user.vaccines[j].vaxDate.year);
	}
}

void searchByName (databaseType *db)
{
	int j;
	int ctr = 0;

	nameType temp;

	setName(&temp);
	
	for (j = 0; j < db->userCount; j++)
	{
		if (isNameFound(temp, db->users[j].name))	
		{
			displayUser(db->users[j]);
			ctr++;
		}
	}

	if (!ctr)
	{
		printf("User Not Found!\n");
	}
}

void searchByBday (databaseType *db)
{
	int j;
	dateType temp;

	setDate(&temp);
	
	for (j = 0; j < db->userCount; j++)
	{
		if (isBdayFound(temp, db->users[j].birthDate))	
		{
			displayUser(db->users[j]);
		}
	}
}
	
void searchMenu (databaseType *db)
{
	char choice;
	
	do 
	{
		printf("\n===Search Menu===\n");
		printf("1] Search by Name\n");
		printf("2] Search by Date of Birth\n");
		printf("x] Exit\n");
		printf("Enter choice: ");
		scanf(" %c", &choice);

		switch (choice)
		{
			case '1': searchByName(db); break;
			case '2': searchByBday(db); break;
			case 'X': 
			case 'x': printf("Exiting...\n"); break;
			default: printf("Invalid Input!\n");
		}


	} while (choice != 'x' && choice != 'X');
}
