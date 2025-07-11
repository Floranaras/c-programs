#include <stdio.h>
#include <string.h>

#define MAX_VAX (4)
#define MAX_PEOPLE (15)
#define MAX_BRAND (8)
#define MAX_MONTHS (13)
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
	String10 mon;
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


void getMonthName (dateType *date);
