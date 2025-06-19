#include "head.h"

void initDatabase (databaseType *db)
{
	db->teachers[db->teacherCtr].subjectsCtr = 0;	
}

int isTaken (databaseType *db, String7 section)
{
	int j, k;
	int flag = 0;
	
	for (j = 0; j < db->teacherCtr && flag; j++)
	{
		for (k = 0; k < db->teachers[j].subjectsCtr && flag; k++)
		{
			if (!strcmp(section, db->teachers[j].subjects[k].section))
			{
				flag = 1;
			}
		}
	}

	return flag;
}


void inputSubjects(databaseType *db, subjectType *subs, int *ctr)
{
	String7 input;
	int flag = 1;

	do 
	{
		printf("Input Course Code: ");
		scanf("%s", input);

		if (strcmp(input, "XXX") != 0)
		{

			strcpy(subs->courseCode, input);
			printf("Input Time (HH:MM): ");
			scanf("%s", subs->time);
			
			do 
			{
				printf("Input Section: ");	
				scanf("%s", input);	
			} while (isTaken(db, input));
					

			printf("Input Units: ");
			scanf("%d", &subs->units);

			(*ctr)++;
		}

		else 
			flag = 0;
	
	} while (*ctr < MAX_SUB && flag);
}

int isFound (databaseType *db, String25 input)
{
	int j = 0;

	while (j < db->teacherCtr && strcmp(input, db->teachers[j].name))
		   j++;
	
	if (j == db->teacherCtr)
		return 0;

	return 1;
}

void inputTeacher(databaseType *db)
{
	int *ctr = &db->teacherCtr;
	String25 temp;
	int flag = 1;

	do 
	{
		printf("Input Name: ");
		scanf("%s", temp);

		if (!strcmp(temp,"XXX"))
			flag = 0;

		else if (!isFound(db, temp))
		{
			strcpy(db->teachers[*ctr].name, temp);
			printf("Input Department: ");
			scanf("%s", db->teachers[*ctr].dept);

			inputSubjects(db, db->teachers[*ctr].subjects, ctr);
			(*ctr)++;
		}

		else 
		{
			printf("Name already in the records\n");	
		}
	} while (*ctr < MAX_TEACHER && flag);

}

void displayByCourse(databaseType *db)
{
	String7 courseCode;
	int j, k;

	printf("Input CourseCode: ");
	scanf("%s", courseCode);

	printf("\n===%s classes===\n", courseCode);

	for (j = 0; j < db->teacherCtr; j++)
	{
		for (k = 0; k < db->teachers[j].subjectsCtr; k++)
		{
			if (!strcmp(db->teachers[j].subjects[k].courseCode, courseCode))
			{
				printf("%s/t%s\n", db->teachers[j].name, 
					   	db->teachers[j].subjects[k].section);
			}
		}
	}
	
}
void mainMenu (databaseType *db)
{
	char choice;

	do 
	{
		printf("\n===Teacher Database===\n");
		printf("1] Input New Teacher\n");
		printf("2] Display Teachers by Course\n");
		printf("x] Exit\n");
		printf("\nEnter choice: ");
		scanf(" %c", &choice);

		switch (choice)
		{
			case '1': inputTeacher(db); break;
			case '2': displayByCourse(db); break;
			case 'x': printf("Exiting...\n");break;
			default: printf("Invalid Input!\n"); break;
		}

	} while (choice != 'x');

}
