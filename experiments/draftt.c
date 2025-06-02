#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 5
#define NUM_CARDS 16
#define CARDS_PER_PLAYER 2
#define MAX_MOVES 8
#define NAME_LENGTH 20
#define TRUE 1
#define FALSE 0

/* Piece types */
#define EMPTY 0
#define RED_PAWN 1
#define RED_MASTER 2
#define BLUE_PAWN 3
#define BLUE_MASTER 4

/* Player colors */
#define RED 0
#define BLUE 1

/* Move structure */
struct moveTag {
    int nDx;
    int nDy;
};
typedef struct moveTag moveType;

/* Card structure */
struct cardTag {
    char szName[NAME_LENGTH];
    moveType arrMoves[MAX_MOVES];
    int nNumMoves;
    int nColor;
};
typedef struct cardTag cardType;

/* Complete game database structure */
struct gameDatabaseTag {
    /* Game state */
    int arrBoard[BOARD_SIZE][BOARD_SIZE];
    cardType arrPlayerCards[2][CARDS_PER_PLAYER];
    cardType neutralCard;
    int nCurrentPlayer;
    int bGameOver;
    int nWinner;
    
    /* All available cards */
    cardType arrAllCards[NUM_CARDS];
    
    /* Temporary variables for operations */
    int arrCardIndices[NUM_CARDS];
    int nTempFromRow;
    int nTempFromCol;
    int nTempToRow;
    int nTempToCol;
    int nTempCardChoice;
    int bTempValidInput;
    int bTempValidMove;
    int bTempRedMasterFound;
    int bTempBlueMasterFound;
    cardType tempCard;
};
typedef struct gameDatabaseTag gameDatabaseType;

// Initialization of database
void setupRedCards(gameDatabaseType* pDb);
void setupBlueCards(gameDatabaseType* pDb);
void initializeAllCards(gameDatabaseType* pDb);

// Loading Game
void shuffleCardIndices(gameDatabaseType* pDb);
void clearBoard(gameDatabaseType* pDb);
void placePieces(gameDatabaseType* pDb);
void setupCardIndices(gameDatabaseType* pDb);
void dealCards(gameDatabaseType* pDb);
void initializeTempVariables(gameDatabaseType* pDb);
void initializeGameDatabase(gameDatabaseType* pDb);

// Validation functions
void checkMoveInCard(cardType* pCard, int nPlayer, int nDx, int nDy, int* pbFound);
void checkValidPosition(gameDatabaseType* pDb, int nRow, int nCol);
void checkOwnPiece(gameDatabaseType* pDb, int nPiece, int nPlayer);
void checkMasterCapture(gameDatabaseType* pDb);
void checkTempleWin(gameDatabaseType* pDb, int j, int k);
void checkForVictory(gameDatabaseType* pDb);
void validatePositions(gameDatabaseType* pDb, int nFromRow, int nFromCol, int nToRow, int nToCol);
void validateDestination(gameDatabaseType* pDb, int nToRow, int nToCol);
void validateCardMove(gameDatabaseType* pDb, int nFromRow, int nFromCol, int nToRow, int nToCol, int nCardIndex);
void handlePlayerInput(gameDatabaseType* pDb);
void validatePieceOwnership(gameDatabaseType* pDb, int nFromRow, int nFromCol);

// Display functions
void printCardMoveRow(cardType* pCard, int nPlayer, int nRowOffset);
void displayCardMoves(gameDatabaseType* pDb, int nCardIndex);
void printBoardHeader(gameDatabaseType* pDb);
void printBoardRow(gameDatabaseType* pDb, int nRow);
void printGameInfo(gameDatabaseType* pDb);
void displayBoard(gameDatabaseType* pDb);
void printCardHeader(cardType* pCard);
void displayWelcomeMessage(gameDatabaseType* pDb);
void displayCurrentPlayer(gameDatabaseType* pDb);
void displayGameResult(gameDatabaseType* pDb);

// Game Engine
void executeMove(gameDatabaseType* pDb, int nFromRow, int nFromCol, int nToRow, int nToCol);
void rotateCards(gameDatabaseType* pDb, int nCardIndex);
void switchPlayer(gameDatabaseType* pDb);
void processMove(gameDatabaseType* pDb, int nFromRow, int nFromCol, int nToRow, int nToCol, int nCardIndex);
void getCardChoice(gameDatabaseType* pDb);
void getMoveInput(gameDatabaseType* pDb);
void runGameLoop(gameDatabaseType* pDb);

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

void checkMoveInCard(cardType* pCard, int nPlayer, int nDx, int nDy, int* pbFound) 
{
	int j;
	int nCardDx;
	int nCardDy;

	*pbFound = FALSE;
	j = 0;
	while (j < pCard->nNumMoves && *pbFound == FALSE) {
		nCardDx = pCard->arrMoves[j].nDx;
		nCardDy = pCard->arrMoves[j].nDy;

		/* Flip moves for blue player */
		if (nPlayer == BLUE) {
			nCardDx = -nCardDx;
			nCardDy = -nCardDy;
		}

		if (nCardDx == nDx && nCardDy == nDy) {
			*pbFound = TRUE;
		}
		j = j + 1;
	}
}

void checkValidPosition(gameDatabaseType* pDb, int nRow, int nCol) 
{
	if (nRow >= 0 && nRow < BOARD_SIZE && nCol >= 0 && nCol < BOARD_SIZE) {
		pDb->bTempValidMove = TRUE;
	} else {
		pDb->bTempValidMove = FALSE;
	}
}

void checkOwnPiece(gameDatabaseType* pDb, int nPiece, int nPlayer) 
{
	pDb->bTempValidMove = FALSE;
	if (nPlayer == RED) {
		if (nPiece == RED_PAWN || nPiece == RED_MASTER) {
			pDb->bTempValidMove = TRUE;
		}
	} else {
		if (nPiece == BLUE_PAWN || nPiece == BLUE_MASTER) {
			pDb->bTempValidMove = TRUE;
		}
	}
}

void checkMasterCapture(gameDatabaseType* pDb) 
{
	if (pDb->bTempRedMasterFound == FALSE) {
		pDb->nWinner = BLUE;
		pDb->bGameOver = TRUE;
	}
	if (pDb->bTempBlueMasterFound == FALSE) {
		pDb->nWinner = RED;
		pDb->bGameOver = TRUE;
	}
}

void checkTempleWin(gameDatabaseType* pDb, int j, int k) 
{
	if (pDb->arrBoard[j][k] == RED_MASTER) {
		pDb->bTempRedMasterFound = TRUE;
		/* Check if red master reached blue temple */
		if (j == 4 && k == 2) {
			pDb->nWinner = RED;
			pDb->bGameOver = TRUE;
		}
	}
	if (pDb->arrBoard[j][k] == BLUE_MASTER) {
		pDb->bTempBlueMasterFound = TRUE;
		/* Check if blue master reached red temple */
		if (j == 0 && k == 2) {
			pDb->nWinner = BLUE;
			pDb->bGameOver = TRUE;
		}
	}
}

void checkForVictory(gameDatabaseType* pDb) 
{
	int j;
	int k;

	pDb->bTempRedMasterFound = FALSE;
	pDb->bTempBlueMasterFound = FALSE;

	/* Check if masters are captured or reached temples */
	j = 0;
	while (j < BOARD_SIZE) {
		k = 0;
		while (k < BOARD_SIZE) {
			checkTempleWin(pDb, j, k);
			k = k + 1;
		}
		j = j + 1;
	}

	checkMasterCapture(pDb);
}

void validatePositions(gameDatabaseType* pDb, int nFromRow, int nFromCol, int nToRow, int nToCol) 
{
	checkValidPosition(pDb, nFromRow, nFromCol);
	if (pDb->bTempValidMove == TRUE) {
		checkValidPosition(pDb, nToRow, nToCol);
	}
}

void validatePieceOwnership(gameDatabaseType* pDb, int nFromRow, int nFromCol) 
{
	if (pDb->bTempValidMove == TRUE) {
		checkOwnPiece(pDb, pDb->arrBoard[nFromRow][nFromCol], pDb->nCurrentPlayer);
	}
}

void validateDestination(gameDatabaseType* pDb, int nToRow, int nToCol) 
{
	if (pDb->bTempValidMove == TRUE) {
		checkOwnPiece(pDb, pDb->arrBoard[nToRow][nToCol], pDb->nCurrentPlayer);
		if (pDb->bTempValidMove == TRUE) {
			pDb->bTempValidMove = FALSE;
		} else {
			pDb->bTempValidMove = TRUE;
		}
	}
}

void validateCardMove(gameDatabaseType* pDb, int nFromRow, int nFromCol, int nToRow, int nToCol, int nCardIndex) {
	cardType* pCard;
	int nDx;
	int nDy;
	int j;

	if (pDb->bTempValidMove == TRUE) {
		pCard = &pDb->arrPlayerCards[pDb->nCurrentPlayer][nCardIndex];
		nDx = nToCol - nFromCol;
		nDy = nToRow - nFromRow;

		/* Flip moves for blue player */
		if (pDb->nCurrentPlayer == BLUE) {
			nDx = -nDx;
			nDy = -nDy;
		}

		pDb->bTempValidMove = FALSE;
		j = 0;
		while (j < pCard->nNumMoves && pDb->bTempValidMove == FALSE) {
			if (pCard->arrMoves[j].nDx == nDx && pCard->arrMoves[j].nDy == nDy) {
				pDb->bTempValidMove = TRUE;
			}
			j = j + 1;
		}
	}
}

void handlePlayerInput(gameDatabaseType* pDb) 
{
	getCardChoice(pDb);
	displayCardMoves(pDb, pDb->nTempCardChoice);
	getMoveInput(pDb);
}

void printCardHeader(cardType* pCard) 
{
	printf("\n%s card moves:\n", pCard->szName);
	printf("  +---+---+---+\n");
}

void displayWelcomeMessage(gameDatabaseType* pDb) {
	printf("Welcome to Onitama!\n");
	printf("Pieces: R/r = Red Master/Pawn, B/b = Blue Master/Pawn\n");
	printf("Goal: Capture enemy master or reach their temple (middle of opposite side)\n");
}

void displayCurrentPlayer(gameDatabaseType* pDb) {
	if (pDb->nCurrentPlayer == RED) {
		printf("\nRED player's turn\n");
	} else {
		printf("\nBLUE player's turn\n");
	}
}


void displayCardMoves(gameDatabaseType* pDb, int nCardIndex) 
{
	cardType* pCard;
	int j;

	pCard = &pDb->arrPlayerCards[pDb->nCurrentPlayer][nCardIndex];

	printCardHeader(pCard);

	j = -1;
	while (j <= 1) {
		printCardMoveRow(pCard, pDb->nCurrentPlayer, j);
		j = j + 1;
	}
}
void displayGameResult(gameDatabaseType* pDb) {
	displayBoard(pDb);
	if (pDb->nWinner == RED) {
		printf("\nGame Over! RED wins!\n");
	} else {
		printf("\nGame Over! BLUE wins!\n");
	}
}


void printCardMoveRow(cardType* pCard, int nPlayer, int nRowOffset) {
	int j;
	int bFound;

	printf("  |");
	j = -1;
	while (j <= 1) {
		checkMoveInCard(pCard, nPlayer, j, nRowOffset, &bFound);
		if (nRowOffset == 0 && j == 0) {
			printf(" S |"); /* Starting position */
		} else if (bFound == TRUE) {
			printf(" X |"); /* Valid move */
		} else {
			printf("   |"); /* Empty */
		}
		j = j + 1;
	}
	printf("\n  +---+---+---+\n");
}

void printBoardHeader(gameDatabaseType* pDb) 
{
	printf("\n    0   1   2   3   4\n");
	printf("  +---+---+---+---+---+\n");
}

void printBoardRow(gameDatabaseType* pDb, int nRow) 
{
	int j;
	char cPiece;

	printf("%d |", nRow);
	j = 0;
	while (j < BOARD_SIZE) {
		cPiece = ' ';
		if (pDb->arrBoard[nRow][j] == RED_PAWN) {
			cPiece = 'r';
		}
		if (pDb->arrBoard[nRow][j] == RED_MASTER) {
			cPiece = 'R';
		}
		if (pDb->arrBoard[nRow][j] == BLUE_PAWN) {
			cPiece = 'b';
		}
		if (pDb->arrBoard[nRow][j] == BLUE_MASTER) {
			cPiece = 'B';
		}
		printf(" %c |", cPiece);
		j = j + 1;
	}
	printf("\n  +---+---+---+---+---+\n");
}

void printGameInfo(gameDatabaseType* pDb) 
{
	printf("\nCards:\n");
	printf("RED: %s, %s\n", 
		   pDb->arrPlayerCards[RED][0].szName, 
		   pDb->arrPlayerCards[RED][1].szName);
	printf("BLUE: %s, %s\n", 
		   pDb->arrPlayerCards[BLUE][0].szName, 
		   pDb->arrPlayerCards[BLUE][1].szName);
	printf("Neutral: %s\n", pDb->neutralCard.szName);

	if (pDb->nCurrentPlayer == RED) {
		printf("\nCurrent player: RED\n");
	} else {
		printf("\nCurrent player: BLUE\n");
	}
}

void displayBoard(gameDatabaseType* pDb) 
{
	int j;

	printBoardHeader(pDb);

	j = 0;
	while (j < BOARD_SIZE) {
		printBoardRow(pDb, j);
		j = j + 1;
	}

	printGameInfo(pDb);
}

void executeMove(gameDatabaseType* pDb, int nFromRow, int nFromCol, int nToRow, int nToCol) 
{
	pDb->arrBoard[nToRow][nToCol] = pDb->arrBoard[nFromRow][nFromCol];
	pDb->arrBoard[nFromRow][nFromCol] = EMPTY;
}

void rotateCards(gameDatabaseType* pDb, int nCardIndex) 
{
	cardType* pCard;

	pCard = &pDb->arrPlayerCards[pDb->nCurrentPlayer][nCardIndex];
	pDb->tempCard = *pCard;
	*pCard = pDb->neutralCard;
	pDb->neutralCard = pDb->tempCard;
}

void switchPlayer(gameDatabaseType* pDb) 
{
	if (pDb->nCurrentPlayer == RED) {
		pDb->nCurrentPlayer = BLUE;
	} else {
		pDb->nCurrentPlayer = RED;
	}
}

void processMove(gameDatabaseType* pDb, int nFromRow, int nFromCol, int nToRow, int nToCol, int nCardIndex) 
{
	pDb->bTempValidMove = TRUE;

	validatePositions(pDb, nFromRow, nFromCol, nToRow, nToCol);
	validatePieceOwnership(pDb, nFromRow, nFromCol);
	validateDestination(pDb, nToRow, nToCol);
	validateCardMove(pDb, nFromRow, nFromCol, nToRow, nToCol, nCardIndex);

	if (pDb->bTempValidMove == TRUE) {
		executeMove(pDb, nFromRow, nFromCol, nToRow, nToCol);
		rotateCards(pDb, nCardIndex);
		switchPlayer(pDb);
		checkForVictory(pDb);
	}
}

void getCardChoice(gameDatabaseType* pDb) 
{
	int nScanResult;

	pDb->bTempValidInput = FALSE;
	while (pDb->bTempValidInput == FALSE) {
		printf("Choose a card (0 or 1): ");
		nScanResult = scanf("%d", &pDb->nTempCardChoice);
		if (nScanResult == 1) {
			if (pDb->nTempCardChoice >= 0 && pDb->nTempCardChoice < CARDS_PER_PLAYER) {
				pDb->bTempValidInput = TRUE;
			} else {
				printf("Invalid card choice!\n");
			}
		} else {
			printf("Invalid input!\n");
			scanf("%*[^\n]");
			scanf("%*c");
		}
	}
}

void getMoveInput(gameDatabaseType* pDb) 
{
	int nScanResult;

	pDb->bTempValidInput = FALSE;
	while (pDb->bTempValidInput == FALSE) {
		printf("Enter move (from_row from_col to_row to_col): ");
		nScanResult = scanf("%d %d %d %d", &pDb->nTempFromRow, &pDb->nTempFromCol, 
							&pDb->nTempToRow, &pDb->nTempToCol);
		if (nScanResult == 4) {
			processMove(pDb, pDb->nTempFromRow, pDb->nTempFromCol, 
						pDb->nTempToRow, pDb->nTempToCol, pDb->nTempCardChoice);
			if (pDb->bTempValidMove == TRUE) {
				pDb->bTempValidInput = TRUE;
			} else {
				printf("Invalid move! Try again.\n");
			}
		} else {
			printf("Invalid input! Please enter 4 numbers.\n");
			scanf("%*[^\n]");
			scanf("%*c");
		}
	}
}

void runGameLoop(gameDatabaseType* pDb) {
	displayWelcomeMessage(pDb);

	while (pDb->bGameOver == FALSE) {
		displayBoard(pDb);
		displayCurrentPlayer(pDb);
		handlePlayerInput(pDb);
	}

	displayGameResult(pDb);
}

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

int main() {
    gameDatabaseType gameDb;
    
    srand(time(NULL));
    initializeGameDatabase(&gameDb);
    runGameLoop(&gameDb);
    
    return 0;
}