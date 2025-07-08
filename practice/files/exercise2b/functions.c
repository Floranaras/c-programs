#include "head.h"

void displayContacts (entryType entry)
{
    int j;

    for (j = 0; j < entry.contactCtr; j++)
    {
        printf("%s: %s\n", 
               entry.contactType[j],
               entry.contacts[j]);
    }
}

void displayEntry (entryType entry, int entryNum)
{
    printf("Entry: %d\n", entryNum);
    printf("Name: %s %s %s\n",
           entry.name.first,
           entry.name.middle,
           entry.name.last);
    printf("Birthday: %s %d, %d\n",
           entry.bday.month,
           entry.bday.day,
           entry.bday.year);
    
    displayContacts(entry);
    printf("\n");
}

void displayPhoneBook (entryType *phoneBook, int entryCtr)
{
    int j;

    printf("Phone Book Entries:\n");    
    printf("======================\n");

    for (j = 0; j < entryCtr; j++)
    {
        displayEntry(phoneBook[j], j + 1);
    }
}
void getName (FILE *fp, entryType *phoneBook, int *currentEntry, int *entryCtr)
{
    (*currentEntry)++;
    (*entryCtr)++;

    phoneBook[*currentEntry].contactCtr = 0;

    fscanf(fp,"%s %s %s",
           phoneBook[*currentEntry].name.first,
           phoneBook[*currentEntry].name.middle,
           phoneBook[*currentEntry].name.last);
}

void getBday (FILE *fp, entryType *phoneBook, int *currentEntry, int *entryCtr)
{
    char comma;

    fscanf(fp,"%s %d %c %d",
           phoneBook[*currentEntry].bday.month,
           &phoneBook[*currentEntry].bday.day,
           &comma,
           &phoneBook[*currentEntry].bday.year);
}

void getContact (FILE *fp, entryType *phoneBook, int *currentEntry, String keyword)
{
    if (phoneBook[*currentEntry].contactCtr >= MAX_CONTACT)
        printf("You have reached the maximum number of contacts\n");
    else
    {
        strcpy(phoneBook[*currentEntry].contactType[phoneBook[*currentEntry].contactCtr], keyword);
        fscanf(fp,"%s", phoneBook[*currentEntry].contacts[phoneBook[*currentEntry].contactCtr]);
        phoneBook[*currentEntry].contactCtr++;
    }

}

int getData (FILE *fp, entryType *phoneBook)
{

    String keyword;
    int entryCtr = 0;
    int currentEntry = -1;

    while (entryCtr < MAX_ENTRY && fscanf(fp, "%s", keyword) == 1)
    {
        if (!strcmp(keyword,"NAME")) 
            getName (fp, phoneBook, &currentEntry, &entryCtr);
        if (!strcmp(keyword,"BDAY"))
            getBday (fp, phoneBook, &currentEntry, &entryCtr);
        if (!strcmp(keyword,"MOBILE") || !strcmp(keyword,"LANDLINE") || !strcmp(keyword,"NUMBER"))
            getContact (fp, phoneBook, &currentEntry, keyword); 
    }
    
    return entryCtr;
}

int readPhoneBook (entryType *phoneBook)
{
    FILE *fp;
    int entryCtr = 0;

    fp = fopen (INPUT,"r");

    if (fp == NULL)
        printf("Error opening phone book failed\n");
    else 
        entryCtr = getData (fp, phoneBook);

    return entryCtr;
}
