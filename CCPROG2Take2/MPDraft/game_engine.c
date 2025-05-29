#include "loadGame.c"

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
