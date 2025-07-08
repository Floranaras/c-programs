#include "functions.c"

int main ()
{
    entryType phoneBook[MAX_ENTRY];
    int entryCtr;

    entryCtr = readPhoneBook(phoneBook);
    
    if (entryCtr <= 0)
    {
        printf("No entries found or error file handling\n");
    }

    displayPhoneBook(phoneBook, entryCtr);

    return 0;
}
