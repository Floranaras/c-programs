#ifndef VAX_H
#define VAX_H 

#include <stdio.h>
#include <string.h>

#define MAX_VAX (4)
#define MAX_PEOPLE (15)
#define MAX_BRAND (8)
#define EXIT ("XXX")

typedef char String10[11];

struct nameTag 
{
	String10 first;
	String10 last;
	char middle;
};

typedef struct nameTag nameType;

struct dateTag
{
	int month;
	int day;
	int year;
};

typedef struct dateTag dateType;

struct vaxTag
{
	String10 brand;
	String10 city;
	dateType vaxDate;
};

typedef struct vaxTag vaxType;

struct userTag
{
	nameType name;
	dateType birthDate;
	int vaxCount;
	vaxType vaccines[MAX_VAX];
};

typedef struct userTag userType;

struct databaseTag
{
	userType users[MAX_PEOPLE];
	int userCount;
	String10 vax[MAX_BRAND]; 
}; 

typedef struct databaseTag databaseType;


// Prototype Functions
void mainMenu (databaseType *db);
void initDatabase (databaseType *db);
void searchMenu (databaseType *db);
void searchByBday (databaseType *db);
void searchByName (databaseType *db);
void displayUser (userType user);
void setVaxInfo(databaseType *db);
int verifyBrand(databaseType *db, String10 input);
void verifyUser (databaseType *db, int *idx);
void setUser (databaseType *db);
void setName (nameType *temp);
void setDate (dateType *temp);
int isValid (databaseType *db, userType *temp);
int getUser(databaseType *db, userType *temp);
int isNameFound(nameType temp, nameType db);
int isBdayFound(dateType temp, dateType db);

#endif
