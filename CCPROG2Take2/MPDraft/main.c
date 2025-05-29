#include "display.c"

int main() {
    gameDatabaseType gameDb;
    
    srand(time(NULL));
    initializeGameDatabase(&gameDb);
    runGameLoop(&gameDb);
    
    return 0;
}
