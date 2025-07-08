#include <stdio.h>
#include <string.h>

#define MAX_MONTH (4)
#define MAX_CONTACT (3)
#define MAX_ENTRY (15)
#define STR_MAX (30)
#define STR_MID (3)
#define INPUT "phonebook.txt"

typedef char String[STR_MAX];
typedef char String_Mid[STR_MID]; 
typedef char String_Month[MAX_MONTH];

struct nameTag
{
    String first;
    String last;
    String_Month middle;
};

typedef struct nameTag nameType;

struct dateTag
{
    String_Month month;
    int day;
    int year;
};

typedef struct dateTag dateType;

struct entryTag
{
    nameType name;
    dateType bday;
    String contacts[MAX_CONTACT];        
    String contactType[MAX_CONTACT];        
    int contactCtr;

};

typedef struct entryTag entryType;


