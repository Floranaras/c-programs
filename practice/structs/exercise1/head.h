#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PEOPLE (15)

typedef char String25[26];

struct nameTag 
{
    String25 first;
    String25 last;
    String25 middle;
};

typedef struct nameTag nameType;

struct employeeTag 
{
   nameType name;
   int id;
   float salary; 
};

typedef struct employeeTag employeeType;

struct databaseTag
{
	employeeType employees[MAX_PEOPLE]; 
	int employeeCtr;
};

typedef struct databaseTag databaseType;
