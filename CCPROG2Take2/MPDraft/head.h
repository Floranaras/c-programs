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
}; typedef struct moveTag moveType;

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




