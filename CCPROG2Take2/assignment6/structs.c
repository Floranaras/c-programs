#include <stdio.h>
#include <string.h>

#define STR25 (26)
#define STR9 (10) 
#define STR7 (8)
#define MAX_TEACHER (60)
#define MAX_SUB (5)
#define EXIT "XXX"

typedef char String25[STR25];
typedef char String7[STR7];
typedef char String9[STR9];

struct subjectTag
{
	String7 courseCode;
	String9 time;
	int section;
	float units;
};

typedef struct subjectTag subjectType;

struct teacherTag
{
	String25 name;
	String9 dept;
	subjectType subjects[MAX_SUB];
	int subjectCtr;
};

typedef struct teacherTag teacherType;

struct databaseTag
{
	teacherType teachers[MAX_TEACHER];
	int teacherCtr;
};

typedef struct databaseTag databaseType;

/* Helper Functions */
int isFound (databaseType *db, String25 input);
int isSubjectTaken (databaseType *db, int teachersIdx, String7 courseCode, int section);
void inputSection (databaseType *db, int *section, int teacherIdx, String7 courseCode);
void inputSubjects (databaseType *db, int teacherIdx);

/* Main Functions */
void initDatabase (databaseType *db);
void inputTeacher(databaseType *db);
void displayByCourse(databaseType *db);
void mainMenu (databaseType *db);


int main ()
{
	databaseType db;

	initDatabase(&db);
	mainMenu(&db);
	return 0;
}

int isFound (databaseType *db, String25 input)
{
	int j = 0;

	while (j < db->teacherCtr && strcmp(input, db->teachers[j].name) != 0)
		j++;

	if (j == db->teacherCtr)
		return 0;

	return 1;
}

int isSubjectTaken (databaseType *db, int teachersIdx, String7 courseCode, int section)
{
	int j;
	int found = 0;

	for (j = 0; j < db->teachers[teachersIdx].subjectCtr && !found; j++)
	{
		if (!strcmp(db->teachers[teachersIdx].subjects[j].courseCode, courseCode) && 
			db->teachers[teachersIdx].subjects[j].section == section)
		{
			found = 1;
		}
	}

	return found;
}

void inputSection (databaseType *db, int *section, int teacherIdx, String7 courseCode)
{
	do 
	{
		printf("Input Section: ");
		scanf("%d", section);
		if (isSubjectTaken(db, teacherIdx, courseCode, *section))
		{
			printf("Course %s with section %d is already in this teacher's load\n", 
				courseCode, *section);
		}
	} while (isSubjectTaken(db,teacherIdx, courseCode, *section));

}
void inputSubjects (databaseType *db, int teacherIdx)
{
	String7 courseCode;
	int section;
	int flag = 1;
	teacherType *teacher = &db->teachers[teacherIdx];
	int *subCtr = &db->teachers[teacherIdx].subjectCtr;

	printf("\n===Adding Subjects for %s===\n", teacher->name);

	do 
	{
		printf("Input Course Code (or %s to stop):", EXIT);
		scanf("%s", courseCode);

		if (strcmp(courseCode,EXIT) != 0) 
		{
			strcpy(teacher->subjects[*subCtr].courseCode, courseCode);
			printf("Input Time (HH:MM-HH:MM): ");
			scanf("%s", teacher->subjects[*subCtr].time);

			inputSection(db, &section, teacherIdx, courseCode);

			teacher->subjects[*subCtr].section = section;

			printf("Input Units: ");
			scanf("%f", &db->teachers[teacherIdx].subjects[*subCtr].units);

			(*subCtr)++;
		}

		else 
		{
			flag = 0;
		}

	} while (*subCtr < MAX_SUB && flag);

}

void initDatabase (databaseType *db)
{
	int j;

	db->teacherCtr = 0;

	for (j = 0; j < MAX_TEACHER; j++)
	{
		db->teachers[j].subjectCtr = 0;
	}
}

void inputTeacher(databaseType *db)
{
	String25 temp;
	int flag = 1;

	printf("\n===Adding New Teachers===\n"); 
	printf("Enter %s as name to stop adding teachers. \n\n", EXIT);

	do 
	{
		printf("Input Name: ");
		scanf("%s", temp);

		if (!strcmp(temp, EXIT))
		{
			flag = 0;
		}

		else if (!isFound(db, temp))
		{
			strcpy(db-> teachers[db->teacherCtr].name, temp);

			printf("Input Department: ");
			scanf("%s", db->teachers[db->teacherCtr].dept);

			db->teachers[db->teacherCtr].subjectCtr = 0;

			inputSubjects(db, db->teacherCtr);

			db->teacherCtr++;
			
			printf("Teachers added successfully!\n");
		}

		else 
		{
			printf("name already in the records. Please try a different name.\n");
		}

	} while (db->teacherCtr < MAX_TEACHER && flag);
}

void displayByCourse(databaseType *db)
{
	String7 courseCode;
	int j, k;
	int found = 0;

	printf("Input Course Code: ");
	scanf("%s", courseCode);

	printf("\n===%s Classes===\n", courseCode);
	printf("Teacher     Section     Units\n");

	for (j = 0; j < db->teacherCtr; j++)
	{
		for (k = 0; k < db->teachers[j].subjectCtr; k++)
		{
			if (!strcmp(db->teachers[j].subjects[k].courseCode, courseCode))
			{
				printf("%s     %d     %.1f\n", db->teachers[j].name,
					   						db->teachers[j].subjects[k].section,
					   						db->teachers[j].subjects[k].units);
				found = 1;
			}
		}
	}

	if (!found)
	{
		printf("No classes found for course code: %s\n", courseCode);
	}

	printf("\n");
}

void mainMenu (databaseType *db)
{
	char choice;

	printf("\n===Teacher Database Management System===\n");

	do 
	{
		printf("\n===  Teacher Database ===\n");
		printf("1] Input New Teacher\n");
		printf("2] Display Teachers by Course\n");
		printf("X] Exit\n");
		printf("Enter choice: ");
		scanf(" %c", &choice);

		switch (choice)
		{
			case '1': inputTeacher(db); break;
			case '2': displayByCourse(db); break;
			case 'x': 
			case 'X': printf("Exiting program....\n"); break;
			default: printf("Invalid Input! Please try again\n");
		}

	} while (choice != 'x' && choice != 'X');
}











