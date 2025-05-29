#include "head.h"

void setupRedCards(gameDatabaseType* pDb) 
{
    strcpy(pDb->arrAllCards[0].szName, "Tiger");
    pDb->arrAllCards[0].arrMoves[0].nDx = 0; pDb->arrAllCards[0].arrMoves[0].nDy = 2;
    pDb->arrAllCards[0].arrMoves[1].nDx = 0; pDb->arrAllCards[0].arrMoves[1].nDy = -1;
    pDb->arrAllCards[0].nNumMoves = 2;
    pDb->arrAllCards[0].nColor = RED;
    
    strcpy(pDb->arrAllCards[1].szName, "Dragon");
    pDb->arrAllCards[1].arrMoves[0].nDx = -2; pDb->arrAllCards[1].arrMoves[0].nDy = 1;
    pDb->arrAllCards[1].arrMoves[1].nDx = -1; pDb->arrAllCards[1].arrMoves[1].nDy = 1;
    pDb->arrAllCards[1].arrMoves[2].nDx = 1; pDb->arrAllCards[1].arrMoves[2].nDy = 1;
    pDb->arrAllCards[1].arrMoves[3].nDx = 2; pDb->arrAllCards[1].arrMoves[3].nDy = 1;
    pDb->arrAllCards[1].nNumMoves = 4;
    pDb->arrAllCards[1].nColor = RED;
    
    strcpy(pDb->arrAllCards[2].szName, "Frog");
    pDb->arrAllCards[2].arrMoves[0].nDx = -2; pDb->arrAllCards[2].arrMoves[0].nDy = 0;
    pDb->arrAllCards[2].arrMoves[1].nDx = -1; pDb->arrAllCards[2].arrMoves[1].nDy = 1;
    pDb->arrAllCards[2].arrMoves[2].nDx = 1; pDb->arrAllCards[2].arrMoves[2].nDy = -1;
    pDb->arrAllCards[2].nNumMoves = 3;
    pDb->arrAllCards[2].nColor = RED;
    
    strcpy(pDb->arrAllCards[3].szName, "Rabbit");
    pDb->arrAllCards[3].arrMoves[0].nDx = 2; pDb->arrAllCards[3].arrMoves[0].nDy = 0;
    pDb->arrAllCards[3].arrMoves[1].nDx = 1; pDb->arrAllCards[3].arrMoves[1].nDy = 1;
    pDb->arrAllCards[3].arrMoves[2].nDx = -1; pDb->arrAllCards[3].arrMoves[2].nDy = -1;
    pDb->arrAllCards[3].nNumMoves = 3;
    pDb->arrAllCards[3].nColor = RED;
    
    strcpy(pDb->arrAllCards[4].szName, "Crab");
    pDb->arrAllCards[4].arrMoves[0].nDx = 0; pDb->arrAllCards[4].arrMoves[0].nDy = 1;
    pDb->arrAllCards[4].arrMoves[1].nDx = -2; pDb->arrAllCards[4].arrMoves[1].nDy = 0;
    pDb->arrAllCards[4].arrMoves[2].nDx = 2; pDb->arrAllCards[4].arrMoves[2].nDy = 0;
    pDb->arrAllCards[4].nNumMoves = 3;
    pDb->arrAllCards[4].nColor = RED;
    
    strcpy(pDb->arrAllCards[5].szName, "Elephant");
    pDb->arrAllCards[5].arrMoves[0].nDx = -1; pDb->arrAllCards[5].arrMoves[0].nDy = 1;
    pDb->arrAllCards[5].arrMoves[1].nDx = -1; pDb->arrAllCards[5].arrMoves[1].nDy = 0;
    pDb->arrAllCards[5].arrMoves[2].nDx = 1; pDb->arrAllCards[5].arrMoves[2].nDy = 0;
    pDb->arrAllCards[5].arrMoves[3].nDx = 1; pDb->arrAllCards[5].arrMoves[3].nDy = 1;
    pDb->arrAllCards[5].nNumMoves = 4;
    pDb->arrAllCards[5].nColor = RED;
    
    strcpy(pDb->arrAllCards[6].szName, "Goose");
    pDb->arrAllCards[6].arrMoves[0].nDx = -1; pDb->arrAllCards[6].arrMoves[0].nDy = 0;
    pDb->arrAllCards[6].arrMoves[1].nDx = -1; pDb->arrAllCards[6].arrMoves[1].nDy = 1;
    pDb->arrAllCards[6].arrMoves[2].nDx = 1; pDb->arrAllCards[6].arrMoves[2].nDy = 0;
    pDb->arrAllCards[6].arrMoves[3].nDx = 1; pDb->arrAllCards[6].arrMoves[3].nDy = -1;
    pDb->arrAllCards[6].nNumMoves = 4;
    pDb->arrAllCards[6].nColor = RED;
    
    strcpy(pDb->arrAllCards[7].szName, "Rooster");
    pDb->arrAllCards[7].arrMoves[0].nDx = -1; pDb->arrAllCards[7].arrMoves[0].nDy = 0;
    pDb->arrAllCards[7].arrMoves[1].nDx = -1; pDb->arrAllCards[7].arrMoves[1].nDy = -1;
    pDb->arrAllCards[7].arrMoves[2].nDx = 1; pDb->arrAllCards[7].arrMoves[2].nDy = 0;
    pDb->arrAllCards[7].arrMoves[3].nDx = 1; pDb->arrAllCards[7].arrMoves[3].nDy = 1;
    pDb->arrAllCards[7].nNumMoves = 4;
    pDb->arrAllCards[7].nColor = RED;
}

void setupBlueCards(gameDatabaseType* pDb) 
{
    strcpy(pDb->arrAllCards[8].szName, "Mantis");
    pDb->arrAllCards[8].arrMoves[0].nDx = -1; pDb->arrAllCards[8].arrMoves[0].nDy = 1;
    pDb->arrAllCards[8].arrMoves[1].nDx = 1; pDb->arrAllCards[8].arrMoves[1].nDy = 1;
    pDb->arrAllCards[8].arrMoves[2].nDx = 0; pDb->arrAllCards[8].arrMoves[2].nDy = -1;
    pDb->arrAllCards[8].nNumMoves = 3;
    pDb->arrAllCards[8].nColor = BLUE;
    
    strcpy(pDb->arrAllCards[9].szName, "Horse");
    pDb->arrAllCards[9].arrMoves[0].nDx = 0; pDb->arrAllCards[9].arrMoves[0].nDy = 1;
    pDb->arrAllCards[9].arrMoves[1].nDx = -1; pDb->arrAllCards[9].arrMoves[1].nDy = 0;
    pDb->arrAllCards[9].arrMoves[2].nDx = 0; pDb->arrAllCards[9].arrMoves[2].nDy = -1;
    pDb->arrAllCards[9].nNumMoves = 3;
    pDb->arrAllCards[9].nColor = BLUE;
    
    strcpy(pDb->arrAllCards[10].szName, "Ox");
    pDb->arrAllCards[10].arrMoves[0].nDx = 0; pDb->arrAllCards[10].arrMoves[0].nDy = 1;
    pDb->arrAllCards[10].arrMoves[1].nDx = 1; pDb->arrAllCards[10].arrMoves[1].nDy = 0;
    pDb->arrAllCards[10].arrMoves[2].nDx = 0; pDb->arrAllCards[10].arrMoves[2].nDy = -1;
    pDb->arrAllCards[10].nNumMoves = 3;
    pDb->arrAllCards[10].nColor = BLUE;
    
    strcpy(pDb->arrAllCards[11].szName, "Crane");
    pDb->arrAllCards[11].arrMoves[0].nDx = 0; pDb->arrAllCards[11].arrMoves[0].nDy = 1;
    pDb->arrAllCards[11].arrMoves[1].nDx = -1; pDb->arrAllCards[11].arrMoves[1].nDy = -1;
    pDb->arrAllCards[11].arrMoves[2].nDx = 1; pDb->arrAllCards[11].arrMoves[2].nDy = -1;
    pDb->arrAllCards[11].nNumMoves = 3;
    pDb->arrAllCards[11].nColor = BLUE;
    
    strcpy(pDb->arrAllCards[12].szName, "Boar");
    pDb->arrAllCards[12].arrMoves[0].nDx = 0; pDb->arrAllCards[12].arrMoves[0].nDy = 1;
    pDb->arrAllCards[12].arrMoves[1].nDx = -1; pDb->arrAllCards[12].arrMoves[1].nDy = 0;
    pDb->arrAllCards[12].arrMoves[2].nDx = 1; pDb->arrAllCards[12].arrMoves[2].nDy = 0;
    pDb->arrAllCards[12].nNumMoves = 3;
    pDb->arrAllCards[12].nColor = BLUE;
    
    strcpy(pDb->arrAllCards[13].szName, "Eel");
    pDb->arrAllCards[13].arrMoves[0].nDx = -1; pDb->arrAllCards[13].arrMoves[0].nDy = 1;
    pDb->arrAllCards[13].arrMoves[1].nDx = 1; pDb->arrAllCards[13].arrMoves[1].nDy = 0;
    pDb->arrAllCards[13].arrMoves[2].nDx = 1; pDb->arrAllCards[13].arrMoves[2].nDy = -1;
    pDb->arrAllCards[13].nNumMoves = 3;
    pDb->arrAllCards[13].nColor = BLUE;
    
    strcpy(pDb->arrAllCards[14].szName, "Cobra");
    pDb->arrAllCards[14].arrMoves[0].nDx = 1; pDb->arrAllCards[14].arrMoves[0].nDy = 1;
    pDb->arrAllCards[14].arrMoves[1].nDx = -1; pDb->arrAllCards[14].arrMoves[1].nDy = 0;
    pDb->arrAllCards[14].arrMoves[2].nDx = 1; pDb->arrAllCards[14].arrMoves[2].nDy = -1;
    pDb->arrAllCards[14].nNumMoves = 3;
    pDb->arrAllCards[14].nColor = BLUE;
    
    strcpy(pDb->arrAllCards[15].szName, "Monkey");
    pDb->arrAllCards[15].arrMoves[0].nDx = -1; pDb->arrAllCards[15].arrMoves[0].nDy = 1;
    pDb->arrAllCards[15].arrMoves[1].nDx = -1; pDb->arrAllCards[15].arrMoves[1].nDy = -1;
    pDb->arrAllCards[15].arrMoves[2].nDx = 1; pDb->arrAllCards[15].arrMoves[2].nDy = 1;
    pDb->arrAllCards[15].arrMoves[3].nDx = 1; pDb->arrAllCards[15].arrMoves[3].nDy = -1;
    pDb->arrAllCards[15].nNumMoves = 4;
    pDb->arrAllCards[15].nColor = BLUE;
}

void initializeAllCards(gameDatabaseType* pDb) 
{
    setupRedCards(pDb);
    setupBlueCards(pDb);
}


