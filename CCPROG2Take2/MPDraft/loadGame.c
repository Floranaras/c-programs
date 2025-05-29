#include "initDatabase.c"

void shuffleCardIndices(gameDatabaseType* pDb) 
{
    int j;
    int k;
    int nTemp;
    
    j = NUM_CARDS - 1;
    while (j > 0) {
        k = rand() % (j + 1);
        nTemp = pDb->arrCardIndices[j];
        pDb->arrCardIndices[j] = pDb->arrCardIndices[k];
        pDb->arrCardIndices[k] = nTemp;
        j = j - 1;
    }
}

void clearBoard(gameDatabaseType* pDb) 
{
    int j;
    int k;
    
    j = 0;
    while (j < BOARD_SIZE) {
        k = 0;
        while (k < BOARD_SIZE) {
            pDb->arrBoard[j][k] = EMPTY;
            k = k + 1;
        }
        j = j + 1;
    }
}

void placePieces(gameDatabaseType* pDb) 
{
    /* Red pieces (top) */
    pDb->arrBoard[0][0] = RED_PAWN;
    pDb->arrBoard[0][1] = RED_PAWN;
    pDb->arrBoard[0][2] = RED_MASTER;
    pDb->arrBoard[0][3] = RED_PAWN;
    pDb->arrBoard[0][4] = RED_PAWN;
    
    /* Blue pieces (bottom) */
    pDb->arrBoard[4][0] = BLUE_PAWN;
    pDb->arrBoard[4][1] = BLUE_PAWN;
    pDb->arrBoard[4][2] = BLUE_MASTER;
    pDb->arrBoard[4][3] = BLUE_PAWN;
    pDb->arrBoard[4][4] = BLUE_PAWN;
}

void setupCardIndices(gameDatabaseType* pDb) 
{
    int j;
    
    j = 0;
    while (j < NUM_CARDS) {
        pDb->arrCardIndices[j] = j;
        j = j + 1;
    }
}

void dealCards(gameDatabaseType* pDb) 
{
    int j;
    
    j = 0;
    while (j < CARDS_PER_PLAYER) {
        pDb->arrPlayerCards[RED][j] = pDb->arrAllCards[pDb->arrCardIndices[j]];
        pDb->arrPlayerCards[BLUE][j] = pDb->arrAllCards[pDb->arrCardIndices[j + 2]];
        j = j + 1;
    }
    pDb->neutralCard = pDb->arrAllCards[pDb->arrCardIndices[4]];
}

void initializeTempVariables(gameDatabaseType* pDb)
{
    pDb->nTempFromRow = 0;
    pDb->nTempFromCol = 0;
    pDb->nTempToRow = 0;
    pDb->nTempToCol = 0;
    pDb->nTempCardChoice = 0;
    pDb->bTempValidInput = FALSE;
    pDb->bTempValidMove = FALSE;
    pDb->bTempRedMasterFound = FALSE;
    pDb->bTempBlueMasterFound = FALSE;
}

void initializeGameDatabase(gameDatabaseType* pDb) 
{
    clearBoard(pDb);
    placePieces(pDb);
    initializeAllCards(pDb);
    setupCardIndices(pDb);
    shuffleCardIndices(pDb);
    dealCards(pDb);
    
    pDb->nCurrentPlayer = pDb->neutralCard.nColor;
    pDb->bGameOver = FALSE;
    pDb->nWinner = -1;
    
    initializeTempVariables(pDb);
}
