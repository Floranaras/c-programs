#include "vax.h"

void verifyUser (databaseType *db, int *idx)
{
	userType temp;

	printf("\n===INPUT VACCINATION INFORMATION===\n");

	do 
	{
		printf("===Input Username===\n");
		setName(&temp.name);
		printf("===Input User Date of Birth===\n");
		setDate(&temp.birthDate);
		
		*idx = getUser(db, &temp);

	} while (*idx == -1);

}

int verifyBrand(databaseType *db, String10 input)
{
	int j = 0;

	while (j < MAX_BRAND && strcmp(input, db->vax[j]))
		j++;

	if (j == MAX_BRAND)
		return 0;

	return 1;
}

void setVaxInfo(databaseType *db)
{
	dateType temp;
	int idx;
	int j = 0;
	int flag = 1;
	String10 input;
	verifyUser(db, &idx);

	printf("\n===Vaccination records===\n");

	while (j < MAX_VAX && flag)
	{
		printf("Input brand: ");
		scanf("%s", input);

		if (!strcmp(input, EXIT))
		{
			flag = 0;
		}

		else if (verifyBrand(db, input))
		{
			strcpy(db->users[idx].vaccines[j].brand, input);

			printf("Input Date of Vaccination: ");
			setDate(&temp);
			db->users[idx].vaccines[j].vaxDate = temp;

			printf("Input City of Vaccination:");
			scanf("%s", db->users[idx].vaccines[j].city);

			j++;
			db->users[idx].vaxCount++;
		}

		else 
		{
			printf("Brand not found!\n");
		}

	}
}
