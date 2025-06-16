#include "head.h"

void displayRecord (employeeType user)
{
	printf("\n===Employee Record===\n");
	printf("Name: %s %s %s\n", user.name.first,
		   					user.name.middle,
							user.name.last);	
	printf("ID: %d\n", user.id);
	printf("Salary: %.2f\n", user.salary);
}

int generateID ()
{
	return (rand() % 90000) + 10000;
}

int findIdx (databaseType* db, int key)
{
	int j = 0;

	while (j < MAX_PEOPLE && db->employees[j].id != key)
		j++;
	
	if (j == MAX_PEOPLE)
		return -1;

	return j;
}

void display(databaseType* db)
{
	int input;
	int idx;

	printf("Enter Employee ID: ");
	scanf("%d", &input);
	
	idx = findIdx(db, input);

	displayRecord(db->employees[idx]);
}
void inputName (databaseType* db, int idx)
{
	employeeType* currentEmployee = &db->employees[idx];	

	printf("Enter firstname: ");
	scanf("%s", currentEmployee->name.first);
	printf("Enter middle name: ");
	scanf("%s", currentEmployee->name.middle);
	printf("Enter lastname: ");
	scanf("%s", currentEmployee->name.last);
}

void inputSalary (databaseType* db, int idx)
{
	employeeType* currentEmployee = &db->employees[idx];	
	printf("Enter Salary: ");
	scanf("%f", &currentEmployee->salary);
}

void inputEmployee (databaseType* db)
{
	inputName(db, db->employeeCtr);
	inputSalary(db, db->employeeCtr);

	db->employees[db->employeeCtr].id = generateID();
	displayRecord(db->employees[db->employeeCtr]);
	db->employeeCtr++;

}

void editEmployee (databaseType* db)
{
	char choice;
	int target;
	int idx;

	printf("Enter Employee ID:");
	scanf("%d", &target);

	idx = findIdx(db, target);

	if (idx != -1)
	{
		do 
		{
			printf("\n===EDIT EMPLOYEE RECORDS===\n");	
			printf("1] Edit Name\n");
			printf("2] Edit Salary\n");
			printf("x] Exit\n");

			printf("Enter choice: ");
			scanf(" %c", &choice); 

			switch (choice)
			{
				case '1': inputName(db, idx); break;
				case '2': inputSalary(db, idx); break;
			}

		} while (choice != 'x');	
	}

	else 
	{
		printf("Employee not found");
	}

}

void mainMenu (databaseType* db)
{
	char choice;

	do 
	{	
		printf("\n===EMPLOYEE RECORDS===\n");	
		printf("1] Add New Employee\n");
		printf("2] Edit Employee Records\n");
		printf("3] Display Employee\n");
		printf("x] Exit\n");

		printf("Enter choice: ");
			scanf(" %c", &choice); 

		switch (choice)
		{
			case '1': inputEmployee(db); break;
			case '2': editEmployee(db); break;
			case '3': display(db); break;
		}

	} while (choice != 'x');
}
