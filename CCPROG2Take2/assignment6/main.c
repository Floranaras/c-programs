#include "head.h"

int main()
{
    databaseType db;
    
    // Initialize the database
    initDatabase(&db);
    
    // Start the main menu
    mainMenu(&db);
    
    return 0;
}
