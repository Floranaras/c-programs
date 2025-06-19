#ifndef HEAD_H
#define HEAD_H

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
    int subjectsCtr;
};
typedef struct teacherTag teacherType;

struct databaseTag
{
    teacherType teachers[MAX_TEACHER];
    int teacherCtr;
};
typedef struct databaseTag databaseType;

// Function declarations
void initDatabase(databaseType *db);
int isSubjectTaken(databaseType *db, int teacherIndex, String7 courseCode, int section);
void inputSubjects(databaseType *db, int teacherIndex);
int isFound(databaseType *db, String25 input);
void inputTeacher(databaseType *db);
void displayByCourse(databaseType *db);
void mainMenu(databaseType *db);

#endif
