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
    return 1;
}

/*
This function executes a validated move
Precondition: move has been validated
@param pDatabase pointer to the game database
@param nFromRow source row
@param nFromCol source column
@param nToRow destination row
@param nToCol destination column
@param nCardIndex index of card used
@return none
*/
void executeMove(gameDatabaseType *pDatabase, int nFromRow, int nFromCol, 
                int nToRow, int nToCol, int nCardIndex)
{
    int nMovingPiece, nCapturedPiece;
    
    nMovingPiece = pDatabase->gameState.arrBoard[nFromRow][nFromCol];
    nCapturedPiece = pDatabase->gameState.arrBoard[nToRow][nToCol];
    
    /* Execute move */
    pDatabase->gameState.arrBoard[nToRow][nToCol] = nMovingPiece;
    pDatabase->gameState.arrBoard[nFromRow][nFromCol] = EMPTY;
    
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
@param pDatabase pointer to the game database
@param nCardIndex index of card to swap
@return none
*/
void swapCards(gameDatabaseType *pDatabase, int nCardIndex)
{
    moveCardType tempCard;
    int nPlayerIndex;
    
    nPlayerIndex = pDatabase->gameState.nCurrentPlayer - 1;
    
    /* Swap used card with neutral card */
    tempCard = pDatabase->gameState.arrPlayerCards[nPlayerIndex][nCardIndex];
    pDatabase->gameState.arrPlayerCards[nPlayerIndex][nCardIndex] = pDatabase->gameState.neutralCard;
    pDatabase->gameState.neutralCard = tempCard;
}

/*
This function checks for win conditions
Precondition: pDatabase points to a valid gameDatabaseType structure
@param pDatabase pointer to the game database
@return game status constant
*/
int checkWinCondition(gameDatabaseType *pDatabase)
{
    int i, j;
    int nRedSenseiFound, nBlueSenseiFound;
    
    /* Check for sensei capture or base occupation */
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            /* Check if blue sensei reached red base */
            if (pDatabase->gameState.arrBoard[0][2] == BLUE_SENSEI) {
                return BLUE_WINS;
            }
            /* Check if red sensei reached blue base */
            if (pDatabase->gameState.arrBoard[4][2] == RED_SENSEI) {
                return RED_WINS;
            }
        }
    }
    
    /* Check if any sensei was captured */
    nRedSenseiFound = 0;
    nBlueSenseiFound = 0;
    
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (pDatabase->gameState.arrBoard[i][j] == RED_SENSEI) {
                nRedSenseiFound = 1;
            }
            if (pDatabase->gameState.arrBoard[i][j] == BLUE_SENSEI) {
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
Precondition: pDatabase points to a valid gameDatabaseType structure
@param pDatabase pointer to the game database
@return none
*/
void switchPlayer(gameDatabaseType *pDatabase)
{
    if (pDatabase->gameState.nCurrentPlayer == BLUE_PLAYER) {
        pDatabase->gameState.nCurrentPlayer = RED_PLAYER;
    } else {
        pDatabase->gameState.nCurrentPlayer = BLUE_PLAYER;
    }
}

/*
This function checks if a player has any valid moves
Precondition: pDatabase points to valid game database, nPlayer is valid player number
@param pDatabase pointer to the game database
@param nPlayer player to check for valid moves
@return 1 if player has valid moves, 0 otherwise
*/
int hasValidMoves(gameDatabaseType *pDatabase, int nPlayer)
{
    int i, j, k, l, m;
    int nPlayerIndex, nPiece;
    int nDestRow, nDestCol;
    moveCardType *pCard;
    
    nPlayerIndex = nPlayer - 1;
    
    /* Check each piece */
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            nPiece = pDatabase->gameState.arrBoard[i][j];
            
            /* Check if piece belongs to current player */
            if ((nPlayer == BLUE_PLAYER && (nPiece == BLUE_STUDENT || nPiece == BLUE_SENSEI)) ||
                (nPlayer == RED_PLAYER && (nPiece == RED_STUDENT || nPiece == RED_SENSEI))) {
                
                /* Check each card */
                for (k = 0; k < PLAYER_CARDS; k++) {
                    pCard = &pDatabase->gameState.arrPlayerCards[nPlayerIndex][k];
                    
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
                        if (isValidMove(pDatabase, i, j, nDestRow, nDestCol, k) == 1) {
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
Precondition: pDatabase points to a valid gameDatabaseType structure
@param pDatabase pointer to the game database
@return none
*/
void displayWinner(gameDatabaseType *pDatabase)
{
    printf("\n================================\n");
    printf("           GAME OVER!\n");
    printf("================================\n");
    
    if (pDatabase->gameState.nGameStatus == BLUE_WINS) {
        printf("Winner: %s (Blue Player)\n", pDatabase->gameState.strPlayer1Name);
    } else if (pDatabase->gameState.nGameStatus == RED_WINS) {
        printf("Winner: %s (Red Player)\n", pDatabase->gameState.strPlayer2Name);
    }
    
    printf("Total moves: %d\n", pDatabase->gameState.nMoveCount);
    printf("================================\n");
}

/*
This function handles the main game loop
Precondition: pDatabase points to a valid gameDatabaseType structure
@param pDatabase pointer to the game database
@return none
*/
void playGame(gameDatabaseType *pDatabase)
{
    int nGameChoice;
    
    pDatabase->nGameRunning = 1;
    
    while (pDatabase->nGameRunning == 1) {
        clearScreen();
        displayBoard(pDatabase);
        
        if (pDatabase->gameState.nGameStatus != GAME_CONTINUE) {
            displayWinner(pDatabase);
            pDatabase->nGameRunning = 0;
        } else {
            displayGameMenu();
            scanf("%d", &nGameChoice);
            
            if (nGameChoice == 1) {
                /* Make a move */
                if (makeMove(pDatabase) == 0) {
                    printf("Move cancelled. Try again.\n");
                    waitForEnter();
                }
            } else if (nGameChoice == 2) {
                /* View opponent's cards */
                displayOpponentCards(pDatabase, pDatabase->gameState.nCurrentPlayer);
                waitForEnter();
            } else if (nGameChoice == 3) {
                /* View neutral card */
                displayNeutralCard(pDatabase);
                waitForEnter();
            } else if (nGameChoice == 4) {
                /* View my cards */
                displayPlayerCards(pDatabase, pDatabase->gameState.nCurrentPlayer);
                waitForEnter();
            } else if (nGameChoice == 5) {
                /* Clear screen and show board */
                clearScreen();
                displayBoard(pDatabase);
                waitForEnter();
            } else {
                printf("Invalid choice! Try again.\n");
                waitForEnter();
            }
        }
    }
}

/*
This is the main function that controls the application flow
Precondition: none
@param none
@return 0 on successful execution
*/
int main()
{
    gameDatabaseType database;
    int nMainChoice;
    
    database.nMainRunning = 1;
    
    printf("Welcome to Onitama!\n");
    
    while (database.nMainRunning == 1) {
        displayMainMenu();
        scanf("%d", &nMainChoice);
        
        if (nMainChoice == 1) {
            /* Start new game */
            initializeGame(&database);
            getPlayerNames(&database);
            setupBoard(&database);
            playGame(&database);
        } else if (nMainChoice == 2) {
            /* Exit */
            database.nMainRunning = 0;
            printf("Thank you for playing Onitama!\n");
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
    
    return 0;
}String20 strName;
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

/* Game database structure to hold all game data */
struct gameDatabaseTag {
    gameStateType gameState;
    moveCardType arrAllCards[MAX_CARDS];
    moveHistoryType arrMoveHistory[100];
    int nHistoryCount;
    int nGameRunning;
    int nMainRunning;
};
typedef struct gameDatabaseTag gameDatabaseType;

/* Function prototypes */
void initializeGame(gameDatabaseType *pDatabase);
void loadMoveCards(gameDatabaseType *pDatabase);
void shuffleCards(gameDatabaseType *pDatabase);
void setupBoard(gameDatabaseType *pDatabase);
void displayMainMenu();
void displayGameMenu();
void displayBoard(gameDatabaseType *pDatabase);
void displayPlayerCards(gameDatabaseType *pDatabase, int nPlayer);
void displayNeutralCard(gameDatabaseType *pDatabase);
void displayOpponentCards(gameDatabaseType *pDatabase, int nPlayer);
void clearScreen();
void playGame(gameDatabaseType *pDatabase);
int makeMove(gameDatabaseType *pDatabase);
int selectPiece(gameDatabaseType *pDatabase, int *pnRow, int *pnCol);
int selectCard(gameDatabaseType *pDatabase, int *pnCardIndex);
int selectDestination(gameDatabaseType *pDatabase, int nPieceRow, int nPieceCol, 
                     int nCardIndex, int *pnDestRow, int *pnDestCol);
int isValidMove(gameDatabaseType *pDatabase, int nFromRow, int nFromCol, 
               int nToRow, int nToCol, int nCardIndex);
void executeMove(gameDatabaseType *pDatabase, int nFromRow, int nFromCol, 
                int nToRow, int nToCol, int nCardIndex);
void swapCards(gameDatabaseType *pDatabase, int nCardIndex);
int checkWinCondition(gameDatabaseType *pDatabase);
void switchPlayer(gameDatabaseType *pDatabase);
int hasValidMoves(gameDatabaseType *pDatabase, int nPlayer);
void getPlayerNames(gameDatabaseType *pDatabase);
void loadCardFromFile(moveCardType *pCard, String20 strFileName);
void displayCardMoves(moveCardType *pCard, int nShowNumbers);
char getPieceSymbol(int nPiece);
void displayWinner(gameDatabaseType *pDatabase);
void waitForEnter();

/*
This function returns the character symbol for a game piece
Precondition: nPiece is a valid piece type constant
@param nPiece the piece type to get symbol for
@return character representing the piece
*/
char getPieceSymbol(int nPiece)
{
    char cResult;
    
    cResult = '.';
    switch (nPiece) {
        case RED_STUDENT: 
            cResult = 'r';
            break;
        case RED_SENSEI: 
            cResult = 'R';
            break;
        case BLUE_STUDENT: 
            cResult = 'b';
            break;
        case BLUE_SENSEI: 
            cResult = 'B';
            break;
        default: 
            cResult = '.';
            break;
    }
    
    return cResult;
}

/*
This function waits for user to press Enter
Precondition: none
@param none
@return none
*/
void waitForEnter()
{
    char cBuffer[100];
    printf("Press Enter to continue...");
    fgets(cBuffer, sizeof(cBuffer), stdin);
}

/*
This function initializes the game state and sets up a new game
Precondition: pDatabase points to a valid gameDatabaseType structure
@param pDatabase pointer to the game database structure
@return none
*/
void initializeGame(gameDatabaseType *pDatabase)
{
    int i, j;
    
    /* Initialize board to empty */
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            pDatabase->gameState.arrBoard[i][j] = EMPTY;
        }
    }
    
    pDatabase->gameState.nCurrentPlayer = BLUE_PLAYER;
    pDatabase->gameState.nMoveCount = 0;
    pDatabase->gameState.nGameStatus = GAME_CONTINUE;
    strcpy(pDatabase->gameState.strPlayer1Name, "");
    strcpy(pDatabase->gameState.strPlayer2Name, "");
    pDatabase->nHistoryCount = 0;
    pDatabase->nGameRunning = 1;
    pDatabase->nMainRunning = 1;
}

/*
This function loads all move cards from files
Precondition: pDatabase points to a valid gameDatabaseType structure
@param pDatabase pointer to the game database structure
@return none
*/
void loadMoveCards(gameDatabaseType *pDatabase)
{
    String20 strFileName;
    String20 strCardNames[MAX_CARDS] = {
        "Boar", "Crab", "Crane", "Cobra", "Dragon", "Eel", "Elephant", "Frog",
        "Goose", "Horse", "Mantis", "Monkey", "Ox", "Rabbit", "Rooster", "Tiger"
    };
    int i;
    
    for (i = 0; i < MAX_CARDS; i++) {
        strcpy(pDatabase->arrAllCards[i].strName, strCardNames[i]);
        strcpy(strFileName, strCardNames[i]);
        strcat(strFileName, ".txt");
        loadCardFromFile(&pDatabase->arrAllCards[i], strFileName);
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
Precondition: pDatabase contains valid loaded cards
@param pDatabase pointer to the game database structure
@return none
*/
void shuffleCards(gameDatabaseType *pDatabase)
{
    int i, nRandomIndex;
    moveCardType tempCard;
    
    srand(time(NULL));
    
    for (i = 0; i < MAX_CARDS; i++) {
        nRandomIndex = rand() % MAX_CARDS;
        
        /* Swap cards */
        tempCard = pDatabase->arrAllCards[i];
        pDatabase->arrAllCards[i] = pDatabase->arrAllCards[nRandomIndex];
        pDatabase->arrAllCards[nRandomIndex] = tempCard;
    }
    
    printf("\n=== CARDS SHUFFLED ===\n");
    printf("Card distribution:\n");
    printf("Player 1 (Blue): %s, %s\n", pDatabase->arrAllCards[0].strName, pDatabase->arrAllCards[1].strName);
    printf("Player 2 (Red): %s, %s\n", pDatabase->arrAllCards[2].strName, pDatabase->arrAllCards[3].strName);
    printf("Neutral: %s\n", pDatabase->arrAllCards[4].strName);
    printf("======================\n\n");
}

/*
This function sets up the initial board configuration
Precondition: pDatabase points to a valid gameDatabaseType structure
@param pDatabase pointer to the game database
@return none
*/
void setupBoard(gameDatabaseType *pDatabase)
{
    int i;
    
    /* Load and shuffle cards */
    loadMoveCards(pDatabase);
    shuffleCards(pDatabase);
    
    /* Assign cards to players */
    pDatabase->gameState.arrPlayerCards[0][0] = pDatabase->arrAllCards[0]; /* Blue player card 1 */
    pDatabase->gameState.arrPlayerCards[0][1] = pDatabase->arrAllCards[1]; /* Blue player card 2 */
    pDatabase->gameState.arrPlayerCards[1][0] = pDatabase->arrAllCards[2]; /* Red player card 1 */
    pDatabase->gameState.arrPlayerCards[1][1] = pDatabase->arrAllCards[3]; /* Red player card 2 */
    pDatabase->gameState.neutralCard = pDatabase->arrAllCards[4]; /* Neutral card */
    
    /* Set first player based on neutral card */
    pDatabase->gameState.nCurrentPlayer = pDatabase->gameState.neutralCard.nFirstPlayer;
    
    /* Setup pieces on board */
    /* Red pieces (top row) */
    pDatabase->gameState.arrBoard[0][0] = RED_STUDENT;
    pDatabase->gameState.arrBoard[0][1] = RED_STUDENT;
    pDatabase->gameState.arrBoard[0][2] = RED_SENSEI;
    pDatabase->gameState.arrBoard[0][3] = RED_STUDENT;
    pDatabase->gameState.arrBoard[0][4] = RED_STUDENT;
    
    /* Blue pieces (bottom row) */
    pDatabase->gameState.arrBoard[4][0] = BLUE_STUDENT;
    pDatabase->gameState.arrBoard[4][1] = BLUE_STUDENT;
    pDatabase->gameState.arrBoard[4][2] = BLUE_SENSEI;
    pDatabase->gameState.arrBoard[4][3] = BLUE_STUDENT;
    pDatabase->gameState.arrBoard[4][4] = BLUE_STUDENT;
    
    /* Empty middle rows */
    for (i = 1; i < 4; i++) {
        pDatabase->gameState.arrBoard[i][0] = EMPTY;
        pDatabase->gameState.arrBoard[i][1] = EMPTY;
        pDatabase->gameState.arrBoard[i][2] = EMPTY;
        pDatabase->gameState.arrBoard[i][3] = EMPTY;
        pDatabase->gameState.arrBoard[i][4] = EMPTY;
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
This function displays the current game board from current player's perspective
Precondition: pDatabase points to a valid gameDatabaseType structure
@param pDatabase pointer to the game database
@return none
*/
void displayBoard(gameDatabaseType *pDatabase)
{
    int i, j, nDisplayRow;
    
    printf("\n========= ONITAMA BOARD =========\n");
    printf("Current Player: %s (%s)\n", 
           pDatabase->gameState.nCurrentPlayer == BLUE_PLAYER ? pDatabase->gameState.strPlayer1Name : pDatabase->gameState.strPlayer2Name,
           pDatabase->gameState.nCurrentPlayer == BLUE_PLAYER ? "Blue" : "Red");
    
    if (pDatabase->gameState.nCurrentPlayer == BLUE_PLAYER) {
        /* Blue player sees board normally (their pieces at bottom) */
        printf("    1   2   3   4   5\n");
        printf("  +---+---+---+---+---+\n");
        
        for (i = 0; i < BOARD_SIZE; i++) {
            printf("%c |", 'A' + i);
            for (j = 0; j < BOARD_SIZE; j++) {
                printf(" %c |", getPieceSymbol(pDatabase->gameState.arrBoard[i][j]));
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
                printf(" %c |", getPieceSymbol(pDatabase->gameState.arrBoard[i][j]));
            }
            printf("\n  +---+---+---+---+---+\n");
        }
    }
    
    printf("\nLegend: R=Red Sensei, r=Red Student, B=Blue Sensei, b=Blue Student\n");
    printf("Your pieces are at the bottom of the board\n");
    printf("================================\n");
}

/*
This function gets player names at the start of the game
Precondition: pDatabase points to a valid gameDatabaseType structure
@param pDatabase pointer to the game database
@return none
*/
void getPlayerNames(gameDatabaseType *pDatabase)
{
    printf("\n=== PLAYER SETUP ===\n");
    printf("Enter Player 1 name (Blue): ");
    scanf("%49s", pDatabase->gameState.strPlayer1Name);
    printf("Enter Player 2 name (Red): ");
    scanf("%49s", pDatabase->gameState.strPlayer2Name);
    printf("====================\n");
}

/*
This function displays a player's cards with move patterns
Precondition: pDatabase points to valid game database, nPlayer is valid player number
@param pDatabase pointer to the game database
@param nPlayer player number (1 for blue, 2 for red)
@return none
*/
void displayPlayerCards(gameDatabaseType *pDatabase, int nPlayer)
{
    int nPlayerIndex, i;
    
    nPlayerIndex = nPlayer - 1;
    
    printf("\n=== %s's CARDS ===\n", 
           nPlayer == BLUE_PLAYER ? pDatabase->gameState.strPlayer1Name : pDatabase->gameState.strPlayer2Name);
    
    for (i = 0; i < PLAYER_CARDS; i++) {
        printf("\nCard %d: %s\n", i + 1, pDatabase->gameState.arrPlayerCards[nPlayerIndex][i].strName);
        displayCardMoves(&pDatabase->gameState.arrPlayerCards[nPlayerIndex][i], 1);
    }
    printf("===================\n");
}

/*
This function displays the neutral card
Precondition: pDatabase points to a valid gameDatabaseType structure
@param pDatabase pointer to the game database
@return none
*/
void displayNeutralCard(gameDatabaseType *pDatabase)
{
    printf("\n=== NEUTRAL CARD ===\n");
    printf("Card: %s\n", pDatabase->gameState.neutralCard.strName);
    displayCardMoves(&pDatabase->gameState.neutralCard, 0);
    printf("===================\n");
}

/*
This function displays the opponent's cards (names only)
Precondition: pDatabase points to valid game database, nPlayer is current player
@param pDatabase pointer to the game database
@param nPlayer current player number
@return none
*/
void displayOpponentCards(gameDatabaseType *pDatabase, int nPlayer)
{
    int nOpponentIndex, i;
    String50 strOpponentName;
    
    if (nPlayer == BLUE_PLAYER) {
        nOpponentIndex = 1;
        strcpy(strOpponentName, pDatabase->gameState.strPlayer2Name);
    } else {
        nOpponentIndex = 0;
        strcpy(strOpponentName, pDatabase->gameState.strPlayer1Name);
    }
    
    printf("\n=== %s's CARDS ===\n", strOpponentName);
    for (i = 0; i < PLAYER_CARDS; i++) {
        printf("Card %d: %s\n", i + 1, pDatabase->gameState.arrPlayerCards[nOpponentIndex][i].strName);
        displayCardMoves(&pDatabase->gameState.arrPlayerCards[nOpponentIndex][i], 0);
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
    printf("X = Current position, %s = Valid moves\n", 
           nShowNumbers == 1 ? "Numbers" : "x");
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
This function handles the complete move-making process
Precondition: pDatabase points to a valid gameDatabaseType structure
@param pDatabase pointer to the game database
@return 1 if move was made successfully, 0 otherwise
*/
int makeMove(gameDatabaseType *pDatabase)
{
    int nPieceRow, nPieceCol, nCardIndex, nDestRow, nDestCol;
    int nResult;
    
    /* Check if player has valid moves */
    if (hasValidMoves(pDatabase, pDatabase->gameState.nCurrentPlayer) == 0) {
        printf("No valid moves available! Skipping turn...\n");
        /* Still need to swap a card */
        if (selectCard(pDatabase, &nCardIndex) == 1) {
            swapCards(pDatabase, nCardIndex);
            switchPlayer(pDatabase);
            return 1;
        }
        return 0;
    }
    
    /* Select piece to move */
    nResult = selectPiece(pDatabase, &nPieceRow, &nPieceCol);
    if (nResult == 0) {
        return 0;
    }
    
    /* Select card to use */
    nResult = selectCard(pDatabase, &nCardIndex);
    if (nResult == 0) {
        return 0;
    }
    
    /* Select destination */
    nResult = selectDestination(pDatabase, nPieceRow, nPieceCol, nCardIndex, &nDestRow, &nDestCol);
    if (nResult == 0) {
        return 0;
    }
    
    /* Execute the move */
    executeMove(pDatabase, nPieceRow, nPieceCol, nDestRow, nDestCol, nCardIndex);
    
    /* Swap cards */
    swapCards(pDatabase, nCardIndex);
    
    /* Check win condition */
    pDatabase->gameState.nGameStatus = checkWinCondition(pDatabase);
    
    /* Switch player */
    switchPlayer(pDatabase);
    
    pDatabase->gameState.nMoveCount++;
    
    return 1;
}

/*
This function allows the player to select a piece to move
Precondition: pDatabase points to valid game database, pnRow and pnCol point to valid integers
@param pDatabase pointer to the game database
@param pnRow pointer to store selected row
@param pnCol pointer to store selected column
@return 1 if piece selected successfully, 0 otherwise
*/
int selectPiece(gameDatabaseType *pDatabase, int *pnRow, int *pnCol)
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
    
    nPiece = pDatabase->gameState.arrBoard[*pnRow][*pnCol];
    
    /* Check if piece belongs to current player */
    if (pDatabase->gameState.nCurrentPlayer == BLUE_PLAYER) {
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
Precondition: pDatabase points to valid game database, pnCardIndex points to valid integer
@param pDatabase pointer to the game database
@param pnCardIndex pointer to store selected card index
@return 1 if card selected successfully, 0 otherwise
*/
int selectCard(gameDatabaseType *pDatabase, int *pnCardIndex)
{
    int nChoice, nPlayerIndex;
    
    nPlayerIndex = pDatabase->gameState.nCurrentPlayer - 1;
    
    printf("\nYour cards:\n");
    printf("1. %s\n", pDatabase->gameState.arrPlayerCards[nPlayerIndex][0].strName);
    displayCardMoves(&pDatabase->gameState.arrPlayerCards[nPlayerIndex][0], 1);
    printf("2. %s\n", pDatabase->gameState.arrPlayerCards[nPlayerIndex][1].strName);
    displayCardMoves(&pDatabase->gameState.arrPlayerCards[nPlayerIndex][1], 1);
    
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
@param pDatabase pointer to the game database
@param nPieceRow source row
@param nPieceCol source column
@param nCardIndex index of selected card
@param pnDestRow pointer to store destination row
@param pnDestCol pointer to store destination column
@return 1 if destination selected successfully, 0 otherwise
*/
int selectDestination(gameDatabaseType *pDatabase, int nPieceRow, int nPieceCol, 
                     int nCardIndex, int *pnDestRow, int *pnDestCol)
{
    int nMoveNum, nPlayerIndex, i;
    moveCardType *pCard;
    int nRowOffset, nColOffset;
    
    nPlayerIndex = pDatabase->gameState.nCurrentPlayer - 1;
    pCard = &pDatabase->gameState.arrPlayerCards[nPlayerIndex][nCardIndex];
    
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
    if (pDatabase->gameState.nCurrentPlayer == BLUE_PLAYER) {
        /* Blue player moves normally */
        *pnDestRow = nPieceRow + nRowOffset;
        *pnDestCol = nPieceCol + nColOffset;
    } else {
        /* Red player moves are mirrored (cards are shown from red perspective) */
        *pnDestRow = nPieceRow - nRowOffset;
        *pnDestCol = nPieceCol - nColOffset;
    }
    
    /* Validate destination */
    if (isValidMove(pDatabase, nPieceRow, nPieceCol, *pnDestRow, *pnDestCol, nCardIndex) == 0) {
        printf("Invalid move! Destination: row %d, col %d\n", *pnDestRow, *pnDestCol);
        return 0;
    }
    
    return 1;
}

/*
This function checks if a move is valid
Precondition: all parameters are valid
@param pDatabase pointer to the game database
@param nFromRow source row
@param nFromCol source column
@param nToRow destination row
@param nToCol destination column
@param nCardIndex index of card being used
@return 1 if move is valid, 0 otherwise
*/
int isValidMove(gameDatabaseType *pDatabase, int nFromRow, int nFromCol, 
               int nToRow, int nToCol, int nCardIndex)
{
    int nDestPiece;
    
    /* Check bounds */
    if (nToRow < 0 || nToRow >= BOARD_SIZE || nToCol < 0 || nToCol >= BOARD_SIZE) {
        return 0;
    }
    
    nDestPiece = pDatabase->gameState.arrBoard[nToRow][nToCol];
    
    /* Check if destination is occupied by own piece */
    if (pDatabase->gameState.nCurrentPlayer == BLUE_PLAYER) {
        if (nDestPiece == BLUE_STUDENT || nDestPiece == BLUE_SENSEI) {
            return 0;
        }
    } else {
        if (nDestPiece == RED_STUDENT || nDestPiece == RED_SENSEI) {
            return 0;
        }
    }