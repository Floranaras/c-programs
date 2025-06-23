#include "head.h"

int isBdayFound(dateType temp, dateType db)
{
	return db.month == temp.month &&
			db.day == temp.day &&
			db.year == temp.year;
}

int isNameFound(nameType temp, nameType db)
{
	return !(strcmp(temp.first, db.first)) 
			&& !(strcmp(temp.last, db.last)) 
			&& temp.middle == db.middle;
}

int getUser(databaseType *db, userType *temp)
{
	int j;
	int flag = 0;
	int idx = -1;

	for (j = 0; j < db->userCount && !flag; j++)
	{
		if (isNameFound(temp->name, db->users[j].name))
		{
			if (isBdayFound(temp->birthDate, db->users[j].birthDate))	
			{
				idx = j;
				flag = 0;
			}
		}
	}

	return idx;
}

int isValid (databaseType *db, userType *temp)
{
	return getUser(db, temp) == -1;
}

void setDate (dateType *temp)
{
	printf("\n===Input Date===\n");
	printf("Enter month: ");
	scanf("%d", &temp->month);
	printf("Enter day: ");
	scanf("%d", &temp->day);
	printf("Enter year: ");
	scanf("%d", &temp->year);
	getMonthName(temp);
}

void setName (nameType *temp)
{
	printf("\n===Input Name===\n");
	printf("Enter firstname: ");
	scanf("%s", temp->first);
	printf("Enter middleinitial: ");
	scanf(" %c", &temp->middle);
	printf("Enter lastname: ");
	scanf("%s", temp->last);
}

void setUser (databaseType *db)
{
	userType temp;

	do 
	{
		setName(&temp.name);
		setDate(&temp.birthDate);

	} while (!isValid(db, &temp));

	printf("\nUser added successfully!\n");

	db->users[db->userCount] = temp;
	db->userCount++;
	db->users[db->userCount].vaxCount = 0;
}


