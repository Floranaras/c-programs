/*
Description: Onitama - A two-player turn-based strategy board game implementation
Programmed by: Student Name Section
Last modified: June 5, 2025
Version: 1.0
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define MAX_CARDS 16
#define MAX_MOVES 8
#define PLAYER_CARDS 2
#define STRING_SIZE 20
#define NAME_SIZE 50

/* String type definitions */
typedef char String20[STRING_SIZE + 1];
typedef char String50[NAME_SIZE + 1];

/* Game piece types */
#define EMPTY 0
#define RED_STUDENT 1
#define RED_SENSEI 2
#define BLUE_STUDENT 3
#define BLUE_SENSEI 4

/* Player colors */
#define RED_PLAYER 1
#define BLUE_PLAYER 2

/* Game states */
#define GAME_CONTINUE 0
#define RED_WINS 1
#define BLUE_WINS 2

/* Move card structure */
struct moveCardTag {
    String20 strName;
    int nFirstPlayer;
    int arrMoves[BOARD_SIZE][BOARD_SIZE];
    int nMoveCount;
    int arrValidMoves[MAX_MOVES][2];
};
typedef struct moveCardTag moveCardType;

/* Game state structure */
struct gameStateTag {
    int arrBoard[BOARD_SIZE][BOARD_SIZE];
    moveCardType arrPlayerCards[2][PLAYER_CARDS];
    moveCardType neutralCard;
    int nCurrentPlayer;
    String50 strPlayer1Name;
    String50 strPlayer2Name;
    int nMoveCount;
    int nGameStatus;
};
typedef struct gameStateTag gameStateType;

/* Move history structure */
struct moveHistoryTag {
    int nFromRow;
    int nFromCol;
    int nToRow;
    int nToCol;
    int nCardUsed;
    int nPlayer;
};
typedef struct moveHistoryTag moveHistoryType;

/* Function prototypes */
void initializeGame(gameStateType *pGame);
void loadMoveCards(moveCardType arrCards[], int *pnCardCount);
void shuffleCards(moveCardType arrCards[], int nCardCount);
void setupBoard(gameStateType *pGame);
void displayMainMenu();
void displayGameMenu();
void displayBoard(gameStateType *pGame);
void displayPlayerCards(gameStateType *pGame, int nPlayer);
void displayNeutralCard(gameStateType *pGame);
void displayOpponentCards(gameStateType *pGame, int nPlayer);
void clearScreen();
int makeMove(gameStateType *pGame);
int selectPiece(gameStateType *pGame, int *pnRow, int *pnCol);
int selectCard(gameStateType *pGame, int *pnCardIndex);
int selectDestination(gameStateType *pGame, int nPieceRow, int nPieceCol, 
                     int nCardIndex, int *pnDestRow, int *pnDestCol);
int isValidMove(gameStateType *pGame, int nFromRow, int nFromCol, 
               int nToRow, int nToCol, int nCardIndex);
void executeMove(gameStateType *pGame, int nFromRow, int nFromCol, 
                int nToRow, int nToCol, int nCardIndex);
void swapCards(gameStateType *pGame, int nCardIndex);
int checkWinCondition(gameStateType *pGame);
void switchPlayer(gameStateType *pGame);
int hasValidMoves(gameStateType *pGame, int nPlayer);
void getPlayerNames(gameStateType *pGame);
void loadCardFromFile(moveCardType *pCard, String20 strFileName);
void displayCardMoves(moveCardType *pCard, int nShowNumbers);
char getPieceSymbol(int nPiece);
void displayWinner(gameStateType *pGame);

/*
This function initializes the game state and sets up a new game
Precondition: pGame points to a valid gameStateType structure
@param pGame pointer to the game state structure
@return none
*/
void initializeGame(gameStateType *pGame)
{
    int i, j;
    
    /* Initialize board to empty */
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            pGame->arrBoard[i][j] = EMPTY;
        }
    }
    
    pGame->nCurrentPlayer = BLUE_PLAYER;
    pGame->nMoveCount = 0;
    pGame->nGameStatus = GAME_CONTINUE;
    strcpy(pGame->strPlayer1Name, "");
    strcpy(pGame->strPlayer2Name, "");
}

/*
This function loads all move cards from files
Precondition: arrCards array can hold MAX_CARDS elements
@param arrCards array to store loaded cards
@param pnCardCount pointer to store the number of cards loaded
@return none
*/
void loadMoveCards(moveCardType arrCards[], int *pnCardCount)
{
    String20 strFileName;
    String20 strCardNames[MAX_CARDS] = {
        "Boar", "Crab", "Crane", "Cobra", "Dragon", "Eel", "Elephant", "Frog",
        "Goose", "Horse", "Mantis", "Monkey", "Ox", "Rabbit", "Rooster", "Tiger"
    };
    int i;
    
    *pnCardCount = MAX_CARDS;
    
    for (i = 0; i < MAX_CARDS; i++) {
        strcpy(arrCards[i].strName, strCardNames[i]);
        strcpy(strFileName, strCardNames[i]);
        strcat(strFileName, ".txt");
        loadCardFromFile(&arrCards[i], strFileName);
    }
}

/*
This function loads a single move card from a text file
Precondition: pCard points to a valid moveCardType, strFileName is valid
@param pCard pointer to the card structure to fill
@param strFileName name of the file to load
@return none
*/
void loadCardFromFile(moveCardType *pCard, String20 strFileName)
{
    FILE *pFile;
    String20 strColor;
    int i, j, nMoveIndex;
    char cChar;
    
    pFile = fopen(strFileName, "r");
    if (pFile != NULL) {
        /* Read first player color */
        fscanf(pFile, "%s", strColor);
        if (strcmp(strColor, "red") == 0) {
            pCard->nFirstPlayer = RED_PLAYER;
        } else {
            pCard->nFirstPlayer = BLUE_PLAYER;
        }
        
        /* Initialize moves array */
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                pCard->arrMoves[i][j] = 0;
            }
        }
        
        /* Read board pattern */
        nMoveIndex = 0;
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                fscanf(pFile, " %c", &cChar);
                if (cChar == 'X') {
                    pCard->arrMoves[i][j] = 2; /* Current position */
                } else if (cChar == 'x') {
                    pCard->arrMoves[i][j] = 1; /* Valid move */
                    pCard->arrValidMoves[nMoveIndex][0] = i;
                    pCard->arrValidMoves[nMoveIndex][1] = j;
                    nMoveIndex++;
                } else {
                    pCard->arrMoves[i][j] = 0; /* Empty */
                }
            }
        }
        pCard->nMoveCount = nMoveIndex;
        fclose(pFile);
    } else {
        /* Default card if file not found */
        pCard->nFirstPlayer = RED_PLAYER;
        pCard->nMoveCount = 0;
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                pCard->arrMoves[i][j] = 0;
            }
        }
        pCard->arrMoves[2][2] = 2; /* Center position */
    }
}

/*
This function shuffles the move cards array randomly
Precondition: arrCards contains nCardCount valid cards
@param arrCards array of cards to shuffle
@param nCardCount number of cards in the array
@return none
*/
void shuffleCards(moveCardType arrCards[], int nCardCount)
{
    int i, nRandomIndex;
    moveCardType tempCard;
    
    srand(time(NULL));
    
    for (i = 0; i < nCardCount; i++) {
        nRandomIndex = rand() % nCardCount;
        
        /* Swap cards */
        tempCard = arrCards[i];
        arrCards[i] = arrCards[nRandomIndex];
        arrCards[nRandomIndex] = tempCard;
    }
    
    printf("\n=== CARDS SHUFFLED ===\n");
    printf("Card distribution:\n");
    printf("Player 1 (Blue): %s, %s\n", arrCards[0].strName, arrCards[1].strName);
    printf("Player 2 (Red): %s, %s\n", arrCards[2].strName, arrCards[3].strName);
    printf("Neutral: %s\n", arrCards[4].strName);
    printf("======================\n\n");
}

/*
This function sets up the initial board configuration
Precondition: pGame points to a valid gameStateType structure
@param pGame pointer to the game state
@return none
*/
void setupBoard(gameStateType *pGame)
{
    int i;
    moveCardType arrAllCards[MAX_CARDS];
    int nCardCount;
    
    /* Load and shuffle cards */
    loadMoveCards(arrAllCards, &nCardCount);
    shuffleCards(arrAllCards, nCardCount);
    
    /* Assign cards to players */
    pGame->arrPlayerCards[0][0] = arrAllCards[0]; /* Blue player card 1 */
    pGame->arrPlayerCards[0][1] = arrAllCards[1]; /* Blue player card 2 */
    pGame->arrPlayerCards[1][0] = arrAllCards[2]; /* Red player card 1 */
    pGame->arrPlayerCards[1][1] = arrAllCards[3]; /* Red player card 2 */
    pGame->neutralCard = arrAllCards[4]; /* Neutral card */
    
    /* Set first player based on neutral card */
    pGame->nCurrentPlayer = pGame->neutralCard.nFirstPlayer;
    
    /* Setup pieces on board */
    /* Red pieces (top row) */
    pGame->arrBoard[0][0] = RED_STUDENT;
    pGame->arrBoard[0][1] = RED_STUDENT;
    pGame->arrBoard[0][2] = RED_SENSEI;
    pGame->arrBoard[0][3] = RED_STUDENT;
    pGame->arrBoard[0][4] = RED_STUDENT;
    
    /* Blue pieces (bottom row) */
    pGame->arrBoard[4][0] = BLUE_STUDENT;
    pGame->arrBoard[4][1] = BLUE_STUDENT;
    pGame->arrBoard[4][2] = BLUE_SENSEI;
    pGame->arrBoard[4][3] = BLUE_STUDENT;
    pGame->arrBoard[4][4] = BLUE_STUDENT;
    
    /* Empty middle rows */
    for (i = 1; i < 4; i++) {
        pGame->arrBoard[i][0] = EMPTY;
        pGame->arrBoard[i][1] = EMPTY;
        pGame->arrBoard[i][2] = EMPTY;
        pGame->arrBoard[i][3] = EMPTY;
        pGame->arrBoard[i][4] = EMPTY;
    }
}

/*
This function displays the main menu options
Precondition: none
@param none
@return none
*/
void displayMainMenu()
{
    printf("\n================================\n");
    printf("         ONITAMA GAME\n");
    printf("================================\n");
    printf("1. Start New Game\n");
    printf("2. Exit\n");
    printf("================================\n");
    printf("Enter choice: ");
}

/*
This function displays the game menu options during gameplay
Precondition: none
@param none
@return none
*/
void displayGameMenu()
{
    printf("\n--- GAME OPTIONS ---\n");
    printf("1. Make a move\n");
    printf("2. View opponent's cards\n");
    printf("3. View neutral card\n");
    printf("4. View my cards\n");
    printf("5. Clear screen and show board\n");
    printf("-------------------\n");
    printf("Enter choice: ");
}

/*
This function returns the character symbol for a game piece
Precondition: nPiece is a valid piece type constant
@param nPiece the piece type to get symbol for
@return character representing the piece
*/
char getPieceSymbol(int nPiece)
{
    switch (nPiece) {
        case RED_STUDENT: return 'r';
        case RED_SENSEI: return 'R';
        case BLUE_STUDENT: return 'b';
        case BLUE_SENSEI: return 'B';
        default: return '.';
    }
}

/*
This function displays the current game board from current player's perspective
Precondition: pGame points to a valid gameStateType structure
@param pGame pointer to the game state
@return none
*/
void displayBoard(gameStateType *pGame)
{
    int i, j;
    
    printf("\n========= ONITAMA BOARD =========\n");
    printf("Current Player: ");
    if (pGame->nCurrentPlayer == BLUE_PLAYER) {
        printf("%s (Blue)\n", pGame->strPlayer1Name);
    } else {
        printf("%s (Red)\n", pGame->strPlayer2Name);
    }
    
    if (pGame->nCurrentPlayer == BLUE_PLAYER) {
        /* Blue player sees board normally (their pieces at bottom) */
        printf("    1   2   3   4   5\n");
        printf("  +---+---+---+---+---+\n");
        
        for (i = 0; i < BOARD_SIZE; i++) {
            printf("%c |", 'A' + i);
            for (j = 0; j < BOARD_SIZE; j++) {
                printf(" %c |", getPieceSymbol(pGame->arrBoard[i][j]));
            }
            printf("\n  +---+---+---+---+---+\n");
        }
    } else {
        /* Red player sees board flipped (their pieces at bottom) but same coordinates */
        printf("    1   2   3   4   5\n");
        printf("  +---+---+---+---+---+\n");
        
        for (i = BOARD_SIZE - 1; i >= 0; i--) {
            printf("%c |", 'A' + i);
            for (j = 0; j < BOARD_SIZE; j++) {
                printf(" %c |", getPieceSymbol(pGame->arrBoard[i][j]));
            }
            printf("\n  +---+---+---+---+---+\n");
        }
    }
    
    printf("\nLegend: R=Red Sensei, r=Red Student, B=Blue Sensei, b=Blue Student\n");
    printf("Your pieces are at the bottom of the board\n");
    printf("================================\n");
}

/*
This function displays a player's cards with move patterns
Precondition: pGame points to valid game state, nPlayer is valid player number
@param pGame pointer to the game state
@param nPlayer player number (1 for blue, 2 for red)
@return none
*/
void displayPlayerCards(gameStateType *pGame, int nPlayer)
{
    int nPlayerIndex, i;
    
    nPlayerIndex = nPlayer - 1;
    
    printf("\n=== ");
    if (nPlayer == BLUE_PLAYER) {
        printf("%s's CARDS ===\n", pGame->strPlayer1Name);
    } else {
        printf("%s's CARDS ===\n", pGame->strPlayer2Name);
    }
    
    for (i = 0; i < PLAYER_CARDS; i++) {
        printf("\nCard %d: %s\n", i + 1, pGame->arrPlayerCards[nPlayerIndex][i].strName);
        displayCardMoves(&pGame->arrPlayerCards[nPlayerIndex][i], 1);
    }
    printf("===================\n");
}

/*
This function displays the neutral card
Precondition: pGame points to a valid gameStateType structure
@param pGame pointer to the game state
@return none
*/
void displayNeutralCard(gameStateType *pGame)
{
    printf("\n=== NEUTRAL CARD ===\n");
    printf("Card: %s\n", pGame->neutralCard.strName);
    displayCardMoves(&pGame->neutralCard, 0);
    printf("===================\n");
}

/*
This function displays the opponent's cards (names only)
Precondition: pGame points to valid game state, nPlayer is current player
@param pGame pointer to the game state
@param nPlayer current player number
@return none
*/
void displayOpponentCards(gameStateType *pGame, int nPlayer)
{
    int nOpponentIndex, i;
    String50 strOpponentName;
    
    if (nPlayer == BLUE_PLAYER) {
        nOpponentIndex = 1;
        strcpy(strOpponentName, pGame->strPlayer2Name);
    } else {
        nOpponentIndex = 0;
        strcpy(strOpponentName, pGame->strPlayer1Name);
    }
    
    printf("\n=== %s's CARDS ===\n", strOpponentName);
    for (i = 0; i < PLAYER_CARDS; i++) {
        printf("Card %d: %s\n", i + 1, pGame->arrPlayerCards[nOpponentIndex][i].strName);
        displayCardMoves(&pGame->arrPlayerCards[nOpponentIndex][i], 0);
    }
    printf("===================\n");
}

/*
This function displays a card's move pattern
Precondition: pCard points to a valid moveCardType
@param pCard pointer to the card to display
@param nShowNumbers 1 to show move numbers, 0 otherwise
@return none
*/
void displayCardMoves(moveCardType *pCard, int nShowNumbers)
{
    int i, j, nMoveNum;
    
    printf("Move pattern:\n");
    printf("  1 2 3 4 5\n");
    
    nMoveNum = 1;
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (pCard->arrMoves[i][j] == 2) {
                printf("X ");
            } else if (pCard->arrMoves[i][j] == 1) {
                if (nShowNumbers == 1) {
                    printf("%d ", nMoveNum);
                    nMoveNum++;
                } else {
                    printf("x ");
                }
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    if (nShowNumbers == 1) {
        printf("X = Current position, Numbers = Valid moves\n");
    } else {
        printf("X = Current position, x = Valid moves\n");
    }
}

/*
This function clears the screen
Precondition: none
@param none
@return none
*/
void clearScreen()
{
    int i;
    for (i = 0; i < 50; i++) {
        printf("\n");
    }
}

/*
This function gets player names at the start of the game
Precondition: pGame points to a valid gameStateType structure
@param pGame pointer to the game state
@return none
*/
void getPlayerNames(gameStateType *pGame)
{
    printf("\n=== PLAYER SETUP ===\n");
    printf("Enter Player 1 name (Blue): ");
    scanf("%49s", pGame->strPlayer1Name);
    printf("Enter Player 2 name (Red): ");
    scanf("%49s", pGame->strPlayer2Name);
    printf("====================\n");
}

/*
This function handles the complete move-making process
Precondition: pGame points to a valid gameStateType structure
@param pGame pointer to the game state
@return 1 if move was made successfully, 0 otherwise
*/
int makeMove(gameStateType *pGame)
{
    int nPieceRow, nPieceCol, nCardIndex, nDestRow, nDestCol;
    int nResult;
    
    /* Check if player has valid moves */
    if (hasValidMoves(pGame, pGame->nCurrentPlayer) == 0) {
        printf("No valid moves available! Skipping turn...\n");
        /* Still need to swap a card */
        if (selectCard(pGame, &nCardIndex) == 1) {
            swapCards(pGame, nCardIndex);
            switchPlayer(pGame);
            return 1;
        }
        return 0;
    }
    
    /* Select piece to move */
    nResult = selectPiece(pGame, &nPieceRow, &nPieceCol);
    if (nResult == 0) {
        return 0;
    }
    
    /* Select card to use */
    nResult = selectCard(pGame, &nCardIndex);
    if (nResult == 0) {
        return 0;
    }
    
    /* Select destination */
    nResult = selectDestination(pGame, nPieceRow, nPieceCol, nCardIndex, &nDestRow, &nDestCol);
    if (nResult == 0) {
        return 0;
    }
    
    /* Execute the move */
    executeMove(pGame, nPieceRow, nPieceCol, nDestRow, nDestCol, nCardIndex);
    
    /* Swap cards */
    swapCards(pGame, nCardIndex);
    
    /* Check win condition */
    pGame->nGameStatus = checkWinCondition(pGame);
    
    /* Switch player */
    switchPlayer(pGame);
    
    pGame->nMoveCount++;
    
    return 1;
}

/*
This function allows the player to select a piece to move
Precondition: pGame points to valid game state, pnRow and pnCol point to valid integers
@param pGame pointer to the game state
@param pnRow pointer to store selected row
@param pnCol pointer to store selected column
@return 1 if piece selected successfully, 0 otherwise
*/
int selectPiece(gameStateType *pGame, int *pnRow, int *pnCol)
{
    char cRow;
    int nCol, nPiece;
    
    printf("\nSelect piece to move (e.g., A1, B3): ");
    scanf(" %c%d", &cRow, &nCol);
    
    /* Convert coordinates - same system for both players */
    *pnRow = cRow - 'A';
    *pnCol = nCol - 1;
    
    /* Validate coordinates */
    if (*pnRow < 0 || *pnRow >= BOARD_SIZE || *pnCol < 0 || *pnCol >= BOARD_SIZE) {
        printf("Invalid coordinates!\n");
        return 0;
    }
    
    nPiece = pGame->arrBoard[*pnRow][*pnCol];
    
    /* Check if piece belongs to current player */
    if (pGame->nCurrentPlayer == BLUE_PLAYER) {
        if (nPiece != BLUE_STUDENT && nPiece != BLUE_SENSEI) {
            printf("That's not your piece!\n");
            return 0;
        }
    } else {
        if (nPiece != RED_STUDENT && nPiece != RED_SENSEI) {
            printf("That's not your piece!\n");
            return 0;
        }
    }
    
    return 1;
}

/*
This function allows the player to select a card to use
Precondition: pGame points to valid game state, pnCardIndex points to valid integer
@param pGame pointer to the game state
@param pnCardIndex pointer to store selected card index
@return 1 if card selected successfully, 0 otherwise
*/
int selectCard(gameStateType *pGame, int *pnCardIndex)
{
    int nChoice, nPlayerIndex;
    
    nPlayerIndex = pGame->nCurrentPlayer - 1;
    
    printf("\nYour cards:\n");
    printf("1. %s\n", pGame->arrPlayerCards[nPlayerIndex][0].strName);
    displayCardMoves(&pGame->arrPlayerCards[nPlayerIndex][0], 1);
    printf("2. %s\n", pGame->arrPlayerCards[nPlayerIndex][1].strName);
    displayCardMoves(&pGame->arrPlayerCards[nPlayerIndex][1], 1);
    
    printf("Select card (1 or 2): ");
    scanf("%d", &nChoice);
    
    if (nChoice < 1 || nChoice > 2) {
        printf("Invalid card selection!\n");
        return 0;
    }
    
    *pnCardIndex = nChoice - 1;
    return 1;
}

/*
This function allows the player to select a destination for the move
Precondition: all parameters are valid
@param pGame pointer to the game state
@param nPieceRow source row
@param nPieceCol source column
@param nCardIndex index of selected card
@param pnDestRow pointer to store destination row
@param pnDestCol pointer to store destination column
@return 1 if destination selected successfully, 0 otherwise
*/
int selectDestination(gameStateType *pGame, int nPieceRow, int nPieceCol, 
                     int nCardIndex, int *pnDestRow, int *pnDestCol)
{
    int nMoveNum, nPlayerIndex;
    moveCardType *pCard;
    int nRowOffset, nColOffset;
    
    nPlayerIndex = pGame->nCurrentPlayer - 1;
    pCard = &pGame->arrPlayerCards[nPlayerIndex][nCardIndex];
    
    printf("\nAvailable moves for %s:\n", pCard->strName);
    displayCardMoves(pCard, 1);
    
    printf("Select move number (1-%d): ", pCard->nMoveCount);
    scanf("%d", &nMoveNum);
    
    if (nMoveNum < 1 || nMoveNum > pCard->nMoveCount) {
        printf("Invalid move number!\n");
        return 0;
    }
    
    /* Calculate destination based on piece position and card pattern */
    nRowOffset = pCard->arrValidMoves[nMoveNum - 1][0] - 2;
    nColOffset = pCard->arrValidMoves[nMoveNum - 1][1] - 2;
    
    /* Apply moves based on player orientation */
    if (pGame->nCurrentPlayer == BLUE_PLAYER) {
        /* Blue player moves normally */
        *pnDestRow = nPieceRow + nRowOffset;
        *pnDestCol = nPieceCol + nColOffset;
    } else {
        /* Red player moves are mirrored (cards are shown from red perspective) */
        *pnDestRow = nPieceRow - nRowOffset;
        *pnDestCol = nPieceCol - nColOffset;
    }
    
    /* Validate destination */
    if (isValidMove(pGame, nPieceRow, nPieceCol, *pnDestRow, *pnDestCol, nCardIndex) == 0) {
        printf("Invalid move! Destination: row %d, col %d\n", *pnDestRow, *pnDestCol);
        return 0;
    }
    
    return 1;
}

/*
This function checks if a move is valid
Precondition: all parameters are valid
@param pGame pointer to the game state
@param nFromRow source row
@param nFromCol source column
@param nToRow destination row
@param nToCol destination column
@param nCardIndex index of card being used
@return 1 if move is valid, 0 otherwise
*/
int isValidMove(gameStateType *pGame, int nFromRow, int nFromCol, 
               int nToRow, int nToCol, int nCardIndex)
{
    int nDestPiece;
    
    /* Check bounds */
    if (nToRow < 0 || nToRow >= BOARD_SIZE || nToCol < 0 || nToCol >= BOARD_SIZE) {
        return 0;
    }
    
    nDestPiece = pGame->arrBoard[nToRow][nToCol];
    
    /* Check if destination is occupied by own piece */
    if (pGame->nCurrentPlayer == BLUE_PLAYER) {
        if (nDestPiece == BLUE_STUDENT || nDestPiece == BLUE_SENSEI) {
            return 0;
        }
    } else {
        if (nDestPiece == RED_STUDENT || nDestPiece == RED_SENSEI) {
            return 0;
        }
    }
    
    return 1;
}

/*
This function executes a validated move
Precondition: move has been validated
@param pGame pointer to the game state
@param nFromRow source row
@param nFromCol source column
@param nToRow destination row
@param nToCol destination column
@param nCardIndex index of card used
@return none
*/
void executeMove(gameStateType *pGame, int nFromRow, int nFromCol, 
                int nToRow, int nToCol, int nCardIndex)
{
    int nMovingPiece, nCapturedPiece;
    
    nMovingPiece = pGame->arrBoard[nFromRow][nFromCol];
    nCapturedPiece = pGame->arrBoard[nToRow][nToCol];
    
    /* Execute move */
    pGame->arrBoard[nToRow][nToCol] = nMovingPiece;
    pGame->arrBoard[nFromRow][nFromCol] = EMPTY;
    
    printf("\nMove executed: %c%d -> %c%d", 
           'A' + nFromRow, nFromCol + 1, 'A' + nToRow, nToCol + 1);
    
    if (nCapturedPiece != EMPTY) {
        printf(" (Captured %c)", getPieceSymbol(nCapturedPiece));
    }
    printf("\n");
}

/*
This function swaps the used card with the neutral card
Precondition: nCardIndex is valid
@param pGame pointer to the game state
@param nCardIndex index of card to swap
@return none
*/
void swapCards(gameStateType *pGame, int nCardIndex)
{
    moveCardType tempCard;
    int nPlayerIndex;
    
    nPlayerIndex = pGame->nCurrentPlayer - 1;
    
    /* Swap used card with neutral card */
    tempCard = pGame->arrPlayerCards[nPlayerIndex][nCardIndex];
    pGame->arrPlayerCards[nPlayerIndex][nCardIndex] = pGame->neutralCard;
    pGame->neutralCard = tempCard;
}

/*
This function checks for win conditions
Precondition: pGame points to a valid gameStateType structure
@param pGame pointer to the game state
@return game status constant
*/
int checkWinCondition(gameStateType *pGame)
{
    int i, j;
    
    /* Check for sensei capture or base occupation */
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            /* Check if blue sensei reached red base */
            if (pGame->arrBoard[0][2] == BLUE_SENSEI) {
                return BLUE_WINS;
            }
            /* Check if red sensei reached blue base */
            if (pGame->arrBoard[4][2] == RED_SENSEI) {
                return RED_WINS;
            }
        }
    }
    
    /* Check if any sensei was captured */
    int nRedSenseiFound = 0;
    int nBlueSenseiFound = 0;
    
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (pGame->arrBoard[i][j] == RED_SENSEI) {
                nRedSenseiFound = 1;
            }
            if (pGame->arrBoard[i][j] == BLUE_SENSEI) {
                nBlueSenseiFound = 1;
            }
        }
    }
    
    if (nRedSenseiFound == 0) {
        return BLUE_WINS;
    }
    if (nBlueSenseiFound == 0) {
        return RED_WINS;
    }
    
    return GAME_CONTINUE;
}

/*
This function switches to the next player
Precondition: pGame points to a valid gameStateType structure
@param pGame pointer to the game state
@return none
*/
void switchPlayer(gameStateType *pGame)
{
    if (pGame->nCurrentPlayer == BLUE_PLAYER) {
        pGame->nCurrentPlayer = RED_PLAYER;
    } else {
        pGame->nCurrentPlayer = BLUE_PLAYER;
    }
}

/*
This function checks if a player has any valid moves
Precondition: pGame points to valid game state, nPlayer is valid player number
@param pGame pointer to the game state
@param nPlayer player to check for valid moves
@return 1 if player has valid moves, 0 otherwise
*/
int hasValidMoves(gameStateType *pGame, int nPlayer)
{
    int i, j, k, l;
    int nPlayerIndex, nPiece;
    int nDestRow, nDestCol;
    moveCardType *pCard;
    
    nPlayerIndex = nPlayer - 1;
    
    /* Check each piece */
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            nPiece = pGame->arrBoard[i][j];
            
            /* Check if piece belongs to current player */
            if ((nPlayer == BLUE_PLAYER && (nPiece == BLUE_STUDENT || nPiece == BLUE_SENSEI)) ||
                (nPlayer == RED_PLAYER && (nPiece == RED_STUDENT || nPiece == RED_SENSEI))) {
                
                /* Check each card */
                for (k = 0; k < PLAYER_CARDS; k++) {
                    pCard = &pGame->arrPlayerCards[nPlayerIndex][k];
                    
                    /* Check each possible move */
                    for (l = 0; l < pCard->nMoveCount; l++) {
                        /* Calculate destination */
                        nDestRow = i + (pCard->arrValidMoves[l][0] - 2);
                        nDestCol = j + (pCard->arrValidMoves[l][1] - 2);
                        
                        /* Adjust for red player */
                        if (nPlayer == RED_PLAYER) {
                            nDestRow = i - (pCard->arrValidMoves[l][0] - 2);
                            nDestCol = j - (pCard->arrValidMoves[l][1] - 2);
                        }
                        
                        /* Check if this move is valid */
                        if (isValidMove(pGame, i, j, nDestRow, nDestCol, k) == 1) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}

/*
This function displays the winner and game statistics
Precondition: pGame points to a valid gameStateType structure
@param pGame pointer to the game state
@return none
*/
void displayWinner(gameStateType *pGame)
{
    printf("\n================================\n");
    printf("           GAME OVER!\n");
    printf("================================\n");
    
    if (pGame->nGameStatus == BLUE_WINS) {
        printf("Winner: %s (Blue Player)\n", pGame->strPlayer1Name);
    } else if (pGame->nGameStatus == RED_WINS) {
        printf("Winner: %s (Red Player)\n", pGame->strPlayer2Name);
    }
    
    printf("Total moves: %d\n", pGame->nMoveCount);
    printf("================================\n");
}

/*
This is the main function that controls the game flow
Precondition: none
@param none
@return 0 on successful execution
*/
int main()
{
    gameStateType game;
    int nMainChoice, nGameChoice;
    int nGameRunning, nMainRunning;
    
    nMainRunning = 1;
    
    printf("Welcome to Onitama!\n");
    
    while (nMainRunning == 1) {
        displayMainMenu();
        scanf("%d", &nMainChoice);
        
        if (nMainChoice == 1) {
            /* Start new game */
            initializeGame(&game);
            getPlayerNames(&game);
            setupBoard(&game);
            
            nGameRunning = 1;
            
            while (nGameRunning == 1) {
                clearScreen();
                displayBoard(&game);
                
                if (game.nGameStatus != GAME_CONTINUE) {
                    displayWinner(&game);
                    nGameRunning = 0;
                } else {
                    displayGameMenu();
                    scanf("%d", &nGameChoice);
                    
                    if (nGameChoice == 1) {
                        /* Make a move */
                        if (makeMove(&game) == 0) {
                            printf("Move cancelled. Try again.\n");
                            printf("Press Enter to continue...");
                            getchar();
                            getchar();
                        }
                    } else if (nGameChoice == 2) {
                        /* View opponent's cards */
                        displayOpponentCards(&game, game.nCurrentPlayer);
                        printf("Press Enter to continue...");
                        getchar();
                        getchar();
                    } else if (nGameChoice == 3) {
                        /* View neutral card */
                        displayNeutralCard(&game);
                        printf("Press Enter to continue...");
                        getchar();
                        getchar();
                    } else if (nGameChoice == 4) {
                        /* View my cards */
                        displayPlayerCards(&game, game.nCurrentPlayer);
                        printf("Press Enter to continue...");
                        getchar();
                        getchar();
                    } else if (nGameChoice == 5) {
                        /* Clear screen and show board */
                        clearScreen();
                        displayBoard(&game);
                        printf("Press Enter to continue...");
                        getchar();
                        getchar();
                    } else {
                        printf("Invalid choice! Try again.\n");
                        printf("Press Enter to continue...");
                        getchar();
                        getchar();
                    }
                }
            }
        } else if (nMainChoice == 2) {
            /* Exit */
            nMainRunning = 0;
            printf("Thank you for playing Onitama!\n");
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
    
    return 0;
}
