#include "check.c"

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


