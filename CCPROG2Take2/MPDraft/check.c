#include "game_engine.c"

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

