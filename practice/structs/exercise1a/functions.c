#include "head.h"

void initDatabase (databaseType *db)
{
	db->userCount = 0;
}

int isNameFound()
{
	
}

int isUnique(databaseType *db)
{
	int foundCtr = 0;
	int foundIdx[MAX_PEOPLE];

}

void inputUser(userType *user)
{
	printf("\n===Enter name of user===\n");
	printf("Enter firstname: ");
	scanf("%s", user->name.first);
	printf("Enter lastname: ");
	scanf("%s", user->name.last);
	printf("Enter middle initial: ");
	scanf(" %c", &user->name.middle);

	printf("\n===Enter day of birth===\n");
	printf("Enter month: ");
	scanf("%d", &user->birthDate.month);
	printf("Enter day: ");
	scanf("%d", &user->birthDate.day);
	printf("Enter year: ");
	scanf("%d", &user->birthDate.year);
}

int compName (databaseType *db, userType user, int idx)
{
	nameType *currentUserName = &db->users[idx].name;
	return !strcmp(currentUserName->first, user.name.first) && 
			!strcmp(currentUserName->last, user.name.last) &&
			currentUserName->middle == user.name.middle;
}
int isUserFound(databaseType *db, userType user)
{
	int j = 0;

	while (j < db->userCount && !compName(db, user, j))
		j++;

	if (j == db->userCount)
		return -1;

	return j;	
}
void inputVaxInfo(databaseType *db)
{
	int j;
	int idx = -1;
	char choice = 'y';
	userType *currentUser; 
	int *vaxCtr; 
	vaxType *vaxList; 
	userType temp;	

	*vaxCtr = 0;

	do 
	{
		inputUser(&temp);
		idx = isUserFound(db, temp);

			*currentUser = db->users[idx];
			*vaxCtr = currentUser->vaxCount;

		if (idx != -1)
		{
			for (j = 0; j < MAX_VAX && choice == 'y'; j++)	
			{
				printf("\n===Enter vaccine information===\n");
				printf("Enter brand: ");
				scanf("%s",currentUser->vaccines[j].brand);
				printf("Enter city where vaccination was administered: ");
				scanf("%s",currentUser->vaccines[j].city);
						
				printf("\n===Enter date of when vaccination was administered===\n");
				printf("Enter month: ");
				scanf("%d",&currentUser->vaccines[j].vaxDate.month);
				printf("Enter day: ");	
				scanf("%d",&currentUser->vaccines[j].vaxDate.day);
				printf("Enter year: ");
				scanf("%d",&currentUser->vaccines[j].vaxDate.year);

				(*vaxCtr)++;
				printf("Do you want to enter another vaccine? (y/n): ");
				scanf(" %c", &choice);
			}			
		}
	} while (idx == -1);
	
}

void inputNewUser (databaseType *db)
{
	int j;
	userType *currentUser = &db->users[db->userCount];
	
	if (db->userCount != MAX_PEOPLE)
	{
		printf("\n===Enter name of user===\n");
		printf("Enter firstname: ");
		scanf("%s", currentUser->name.first);
		printf("Enter lastname: ");
		scanf("%s", currentUser->name.last);
		printf("Enter middle initial: ");
		scanf(" %c", &currentUser->name.middle);

		printf("\n===Enter day of birth===\n");
		printf("Enter month: ");
		scanf("%d", &currentUser->birthDate.month);
		printf("Enter day: ");
		scanf("%d", &currentUser->birthDate.day);
		printf("Enter year: ");
		scanf("%d", &currentUser->birthDate.year);
		
		db->userCount++;
	}

	else 
	{
		printf("Database is full ;-;");
	}

}

void displayUserData (databaseType *db, int idx)
{
	int j;
	userType *user = &db->users[idx];
	vaxType *vax = db->users[idx].vaccines;

	printf("\nName: %s %c. %s\n", user->name.first, 
								user->name.middle, 
								user->name.last);
	printf("Birth Date: %2d/%2d/%2d\n", user->birthDate.month,
									user->birthDate.day,
									user->birthDate.year);

	for (j = 0; j < user->vaxCount; j++)
	{
		printf("\n===Vaccine #%d===\n", j + 1);
		printf("Vaccine Brand: %s\n", vax[j].brand);
		printf("City of Vaccination: %s\n", vax[j].city);
		printf("Date of Vaccination: %2d/%2d/%2d\n", vax[j].vaxDate.month,
													vax[j].vaxDate.day,
													vax[j].vaxDate.year);
	}	
}

void searchByName (databaseType *db)
{
	nameType input;
	int j;
	int isFound = 0;

	printf("\n===Search User by Name===\n");
	printf("\n===Enter name of user===\n");
	printf("Enter firstname: ");	
	scanf("%s", input.first);
	printf("Enter lastname: ");	
	scanf("%s", input.last);
	printf("Enter middle initial: ");	
	scanf(" %c", &input.middle);

	for (j = 0; j < db->userCount && !isFound; j++)	
	{
		if (strcmp(input.first, db->users[j].name.first) == 0 && 
			strcmp(input.last, db->users[j].name.last) == 0 &&
			input.middle == db->users[j].name.middle)
		{
			isFound = 1;
		}
	}

	if (isFound)
		displayUserData(db, j-1);
	else 
		printf("User not found!\n");

}

void searchByDate (databaseType *db)
{
	dateType input;
	int j;
	int isFound = 0;
	int ctr = 0;

	printf("\n===Search User by Birthdate===\n");
	printf("\n===Enter birthdate of user===\n");
	printf("Enter month: ");	
	scanf("%d", &input.month);
	printf("Enter day: ");	
	scanf("%d", &input.day);
	printf("Enter year: ");	
	scanf("%d", &input.year);

	for (j = 0; j < db->userCount; j++)	
	{
		if (input.month == db->users[j].birthDate.month &&
			input.day == db->users[j].birthDate.day &&
			input.year == db->users[j].birthDate.year)
		{
			displayUserData(db, j);
			ctr++;
		}
	}

	if (!ctr)
	{
		printf("User Not Found!\n");
	}
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
