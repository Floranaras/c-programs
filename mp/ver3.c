/*
Description: Onitama - A two-player turn-based strategy board game implementation
Programmed by: Student Name Section  
Last modified: June 10, 2025
Version: 1.0 - Optimized UI Experience
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/* Game Constants */
#define BOARD_SIZE 5
#define MAX_CARDS 16
#define MAX_MOVES 8
#define CARDS_PER_PLAYER 2
#define MAX_NAME_LENGTH 50
#define MAX_CARD_NAME_LENGTH 20
#define MAX_FILENAME_LENGTH 50
#define MAX_GAME_MOVES 200

/* Piece Types */
#define EMPTY 0
#define RED_STUDENT 1
#define RED_SENSEI 2
#define BLUE_STUDENT 3
#define BLUE_SENSEI 4

/* Player Colors - RED is now at bottom */
#define BLUE 0  /* Blue player (top of board) */
#define RED 1   /* Red player (bottom of board) */

/* Game States */
#define GAME_CONTINUE 0
#define RED_WINS 1
#define BLUE_WINS 2

/* Type Definitions */
typedef char String20[MAX_CARD_NAME_LENGTH + 1];
typedef char String50[MAX_NAME_LENGTH + 1];

/* Move structure for storing relative movements */
struct moveTag {
    int rowOffset;
    int colOffset;
};
typedef struct moveTag moveType;

/* Card structure containing all card information */
struct cardTag {
    String20 name;
    int startingPlayer;  /* BLUE or RED */
    moveType moves[MAX_MOVES];
    int moveCount;
};
typedef struct cardTag cardType;

/* Game move record for replay functionality */
struct gameMoveTag {
    int player;
    int fromRow;
    int fromCol;
    int toRow;
    int toCol;
    String20 cardUsed;
    int capturedPiece;
};
typedef struct gameMoveTag gameMoveType;

/* Main game state structure */
struct gameStateTag {
    /* Board and pieces */
    int board[BOARD_SIZE][BOARD_SIZE];
    
    /* Cards */
    cardType playerCards[2][CARDS_PER_PLAYER];
    cardType neutralCard;
    cardType allCards[MAX_CARDS];
    int totalCards;
    
    /* Game state */
    int currentPlayer;
    int gameStatus;
    
    /* Players */
    String50 playerNames[2];
    
    /* Move history for replay */
    gameMoveType moveHistory[MAX_GAME_MOVES];
    int moveCount;
    
    /* Shuffling support */
    int shuffledIndices[MAX_CARDS];
};
typedef struct gameStateTag gameStateType;

/* Function Prototypes */

/* Initialization Functions */
void initializeGame(gameStateType *game);
void setupBoard(gameStateType *game);
void placePieces(gameStateType *game);

/* Card Management */
int loadAllCards(gameStateType *game);
int loadCardFromFile(cardType *card, const char *filename);
void shuffleCards(gameStateType *game);
void dealCards(gameStateType *game);
void displayShuffleResult(gameStateType *game);

/* Display Functions */
void displayMainMenu(void);
void displayGameMenu(void);
void displayBoard(gameStateType *game);
void displayPlayerCards(gameStateType *game, int player);
void displayCard(cardType *card, int showNumbers, int player);
void displayOpponentCards(gameStateType *game);
void displayNeutralCard(gameStateType *game);
void displayGameResult(gameStateType *game);
void clearScreen(void);

/* Input Functions */
void getPlayerNames(gameStateType *game);
int getMenuChoice(void);
int getGameMenuChoice(void);
int parseCoordinate(const char *input, int *row, int *col);
int getPlayerMove(gameStateType *game);

/* Game Logic */
int makeMove(gameStateType *game, int fromRow, int fromCol, int toRow, int toCol, int cardIndex);
int isValidMove(gameStateType *game, int fromRow, int fromCol, int toRow, int toCol, int cardIndex);
int hasValidMoves(gameStateType *game, int player);
void executeMove(gameStateType *game, int fromRow, int fromCol, int toRow, int toCol, int cardIndex);
void swapCards(gameStateType *game, int cardIndex);
void switchPlayer(gameStateType *game);
int checkWinCondition(gameStateType *game);

/* Utility Functions */
char getPieceSymbol(int piece);
const char* getPlayerName(gameStateType *game, int player);
const char* getColorName(int player);
char getPlayerSymbol(int player);

/* Bonus Features */
void showReplay(gameStateType *game);

/*
This function initializes a new game state
Precondition: game points to a valid gameStateType
@param game pointer to the game state structure
@return none
*/
void initializeGame(gameStateType *game)
{
    int i, j;
    
    /* Initialize board */
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j] = EMPTY;
        }
    }
    
    /* Initialize game state */
    game->currentPlayer = BLUE;  /* Will be set by neutral card */
    game->gameStatus = GAME_CONTINUE;
    game->moveCount = 0;
    game->totalCards = 0;
    
    /* Initialize player names */
    strcpy(game->playerNames[BLUE], "Blue Player");
    strcpy(game->playerNames[RED], "Red Player");
    
    /* Initialize shuffled indices */
    for (i = 0; i < MAX_CARDS; i++) {
        game->shuffledIndices[i] = i;
    }
}

/*
This function loads a single card from a file
Precondition: card points to valid cardType, filename is valid
@param card pointer to card structure to fill
@param filename name of the file to load
@return 1 if successful, 0 if failed
*/
int loadCardFromFile(cardType *card, const char *filename)
{
    FILE *file;
    char colorStr[10];
    char grid[BOARD_SIZE][BOARD_SIZE + 1];
    int i, j, moveIndex;
    
    file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }
    
    /* Read starting player color */
    if (fscanf(file, "%s", colorStr) != 1) {
        fclose(file);
        return 0;
    }
    
    if (strcmp(colorStr, "red") == 0) {
        card->startingPlayer = RED;
    } else {
        card->startingPlayer = BLUE;
    }
    
    /* Read grid pattern */
    for (i = 0; i < BOARD_SIZE; i++) {
        if (fscanf(file, "%s", grid[i]) != 1) {
            fclose(file);
            return 0;
        }
    }
    
    /* Parse moves from grid */
    moveIndex = 0;
    for (i = 0; i < BOARD_SIZE && moveIndex < MAX_MOVES; i++) {
        for (j = 0; j < BOARD_SIZE && moveIndex < MAX_MOVES; j++) {
            if (grid[i][j] == 'x') {
                /* Store as offset from center position (2,2) */
                card->moves[moveIndex].rowOffset = i - 2;
                card->moves[moveIndex].colOffset = j - 2;
                moveIndex++;
            }
        }
    }
    
    card->moveCount = moveIndex;
    fclose(file);
    return 1;
}

/*
This function loads all available cards from files
Precondition: game points to valid gameStateType
@param game pointer to game state
@return 1 if successful, 0 if failed
*/
int loadAllCards(gameStateType *game)
{
    FILE *file;
    String20 cardName;
    String50 filename;
    int i;
    
    /* Try to load from movecards.txt first */
    file = fopen("movecards.txt", "r");
    if (file != NULL) {
        if (fscanf(file, "%d", &game->totalCards) == 1) {
            for (i = 0; i < game->totalCards && i < MAX_CARDS; i++) {
                if (fscanf(file, "%s", cardName) == 1) {
                    strcpy(game->allCards[i].name, cardName);
                    sprintf(filename, "%s.txt", cardName);
                    if (!loadCardFromFile(&game->allCards[i], filename)) {
                        /* Set default moves if file loading fails */
                        game->allCards[i].startingPlayer = (i % 2 == 0) ? RED : BLUE;
                        game->allCards[i].moveCount = 2;
                        game->allCards[i].moves[0].rowOffset = -1;
                        game->allCards[i].moves[0].colOffset = 0;
                        game->allCards[i].moves[1].rowOffset = 1;
                        game->allCards[i].moves[1].colOffset = 0;
                    }
                }
            }
        }
        fclose(file);
    } else {
        /* Use default card set if movecards.txt doesn't exist */
        const char *defaultCards[] = {
            "Boar", "Crab", "Crane", "Cobra", "Dragon", "Eel", "Elephant", "Frog",
            "Goose", "Horse", "Mantis", "Monkey", "Ox", "Rabbit", "Rooster", "Tiger"
        };
        
        game->totalCards = 16;
        for (i = 0; i < game->totalCards; i++) {
            strcpy(game->allCards[i].name, defaultCards[i]);
            sprintf(filename, "%s.txt", defaultCards[i]);
            if (!loadCardFromFile(&game->allCards[i], filename)) {
                /* Create simple default moves */
                game->allCards[i].startingPlayer = (i % 2 == 0) ? RED : BLUE;
                game->allCards[i].moveCount = 2;
                game->allCards[i].moves[0].rowOffset = -1;
                game->allCards[i].moves[0].colOffset = 0;
                game->allCards[i].moves[1].rowOffset = 1;
                game->allCards[i].moves[1].colOffset = 0;
            }
        }
    }
    
    return game->totalCards > 0;
}

/*
This function shuffles the cards using Fisher-Yates algorithm
Precondition: game has loaded cards
@param game pointer to game state
@return none
*/
void shuffleCards(gameStateType *game)
{
    int i, j, temp;
    
    /* Initialize indices */
    for (i = 0; i < game->totalCards; i++) {
        game->shuffledIndices[i] = i;
    }
    
    /* Fisher-Yates shuffle */
    for (i = game->totalCards - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = game->shuffledIndices[i];
        game->shuffledIndices[i] = game->shuffledIndices[j];
        game->shuffledIndices[j] = temp;
    }
}

/*
This function deals cards to players and sets neutral card
Precondition: cards have been shuffled
@param game pointer to game state
@return none
*/
void dealCards(gameStateType *game)
{
    int i;
    
    /* Deal 2 cards to each player - Blue gets first 2, Red gets next 2 */
    for (i = 0; i < CARDS_PER_PLAYER; i++) {
        game->playerCards[BLUE][i] = game->allCards[game->shuffledIndices[i]];
        game->playerCards[RED][i] = game->allCards[game->shuffledIndices[i + 2]];
    }
    
    /* Set neutral card */
    game->neutralCard = game->allCards[game->shuffledIndices[4]];
    
    /* Set starting player based on neutral card */
    game->currentPlayer = game->neutralCard.startingPlayer;
    
    printf("DEBUG: Neutral card %s indicates starting player: %s\n", 
           game->neutralCard.name, getColorName(game->currentPlayer));
}

/*
This function displays the shuffle result
Precondition: cards have been shuffled and dealt
@param game pointer to game state
@return none
*/
void displayShuffleResult(gameStateType *game)
{
    printf("\n=== CARD SHUFFLING PROCESS ===\n");
    printf("Cards selected for this game:\n");
    
    printf("Blue Player: %s, %s\n", 
           game->playerCards[BLUE][0].name, 
           game->playerCards[BLUE][1].name);
    
    printf("Red Player: %s, %s\n", 
           game->playerCards[RED][0].name, 
           game->playerCards[RED][1].name);
    
    printf("Neutral Card: %s\n", game->neutralCard.name);
    
    printf("\nStarting player: %s (determined by neutral card)\n", 
           getColorName(game->currentPlayer));
    
    printf("==============================\n");
}

/*
This function sets up the board with pieces
Precondition: game is initialized
@param game pointer to game state
@return none
*/
void setupBoard(gameStateType *game)
{
    /* Load cards */
    if (!loadAllCards(game)) {
        printf("Error: Could not load cards!\n");
        return;
    }
    
    /* Shuffle and deal cards */
    shuffleCards(game);
    dealCards(game);
    
    /* Place pieces */
    placePieces(game);
    
    /* Display shuffle result */
    displayShuffleResult(game);
}

/*
This function places pieces on the board - Standard Onitama setup
Precondition: board is initialized
@param game pointer to game state
@return none
*/
void placePieces(gameStateType *game)
{
    /* Red pieces (top row - row 0) for internal board state */
    game->board[0][0] = RED_STUDENT;
    game->board[0][1] = RED_STUDENT;
    game->board[0][2] = RED_SENSEI;
    game->board[0][3] = RED_STUDENT;
    game->board[0][4] = RED_STUDENT;
    
    /* Blue pieces (bottom row - row 4) for internal board state */
    game->board[4][0] = BLUE_STUDENT;
    game->board[4][1] = BLUE_STUDENT;
    game->board[4][2] = BLUE_SENSEI;
    game->board[4][3] = BLUE_STUDENT;
    game->board[4][4] = BLUE_STUDENT;
}

/*
This function displays the main menu
Precondition: none
@param none
@return none
*/
void displayMainMenu(void)
{
    printf("\n================================\n");
    printf("         ONITAMA GAME\n");
    printf("================================\n");
    printf("1. Start New Game\n");
    printf("2. Exit\n");
    printf("================================\n");
    printf("Enter your choice: ");
}

/*
This function displays the game menu
Precondition: none
@param none
@return none
*/
void displayGameMenu(void)
{
    printf("--- GAME OPTIONS ---\n");
    printf("1. Make a move\n");
    printf("2. View opponent's cards\n");
    printf("3. View neutral card\n");
    printf("4. View my cards\n");
    printf("5. Clear screen and show board\n");
    printf("-------------------\n");
    printf("Enter choice: ");
}

/*
This function gets the symbol for a piece
Precondition: piece is a valid piece constant
@param piece the piece type
@return character symbol for the piece
*/
char getPieceSymbol(int piece)
{
    switch (piece) {
        case RED_STUDENT: return 'r';
        case RED_SENSEI: return 'R';
        case BLUE_STUDENT: return 'b';
        case BLUE_SENSEI: return 'B';
        default: return '.';
    }
}

/*
This function gets player symbol for display
Precondition: player is valid
@param player player index
@return character symbol for player
*/
char getPlayerSymbol(int player)
{
    return (player == RED) ? 'r' : 'b';
}

/*
This function gets player name
Precondition: game initialized, player is valid
@param game pointer to game state
@param player player index (RED or BLUE)
@return pointer to player name string
*/
const char* getPlayerName(gameStateType *game, int player)
{
    return game->playerNames[player];
}

/*
This function gets color name
Precondition: player is valid
@param player player index (RED or BLUE)
@return pointer to color name string
*/
const char* getColorName(int player)
{
    return (player == RED) ? "Red" : "Blue";
}

/*
This function displays the current board state with current player always at bottom
Precondition: game is initialized
@param game pointer to game state
@return none
*/
void displayBoard(gameStateType *game)
{
    int i, j, displayRow, displayCol;
    
    printf("========= ONITAMA BOARD =========\n");
    printf("Current Player: %c (%s)\n", 
           getPlayerSymbol(game->currentPlayer),
           getColorName(game->currentPlayer));
    
    /* Column headers */
    printf("    1   2   3   4   5\n");
    printf("  +---+---+---+---+---+\n");
    
    /* Always display with current player at bottom (standard convention) */
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%c |", 'A' + i);
        
        for (j = 0; j < BOARD_SIZE; j++) {
            /* Calculate actual board position based on current player perspective */
            if (game->currentPlayer == BLUE) {
                /* Blue player at bottom: normal view (Blue pieces start at bottom) */
                displayRow = i;
                displayCol = j;
            } else {
                /* Red player at bottom: rotate 180 degrees so Red appears at bottom */
                displayRow = BOARD_SIZE - 1 - i;
                displayCol = BOARD_SIZE - 1 - j;
            }
            
            printf(" %c |", getPieceSymbol(game->board[displayRow][displayCol]));
        }
        printf("\n  +---+---+---+---+---+\n");
    }
    
    printf("================================\n");
}

/*
This function displays a card's move pattern with current player perspective
Precondition: card is valid
@param card pointer to card structure
@param showNumbers 1 to show move numbers, 0 for x marks
@param player player viewing the card (current player always at bottom)
@return none
*/
void displayCard(cardType *card, int showNumbers, int player)
{
    int i, j, k, moveNum;
    int found, rowOffset, colOffset;
    
    printf("Move pattern:\n");
    printf("  1 2 3 4 5\n");
    
    moveNum = 1;
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (i == 2 && j == 2) {
                printf("X ");  /* Center position */
            } else {
                found = 0;
                for (k = 0; k < card->moveCount && !found; k++) {
                    rowOffset = card->moves[k].rowOffset;
                    colOffset = card->moves[k].colOffset;
                    
                    /* Adjust pattern based on player perspective */
                    /* Current player always sees themselves at bottom */
                    if (player == RED) {
                        /* Red player at bottom: flip pattern to match their view */
                        rowOffset = -rowOffset;
                        colOffset = -colOffset;
                    }
                    /* Blue player at bottom: use normal pattern */
                    
                    if (rowOffset == (i - 2) && colOffset == (j - 2)) {
                        if (showNumbers) {
                            printf("%d ", moveNum++);
                        } else {
                            printf("x ");
                        }
                        found = 1;
                    }
                }
                if (!found) {
                    printf(". ");
                }
            }
        }
        printf("\n");
    }
    printf("X = Current position, %s = Valid moves\n", 
           showNumbers ? "Numbers" : "x");
}

/*
This function displays player's own cards
Precondition: game is initialized
@param game pointer to game state
@param player player whose cards to show
@return none
*/
void displayPlayerCards(gameStateType *game, int player)
{
    int i;
    
    printf("Your cards:\n");
    for (i = 0; i < CARDS_PER_PLAYER; i++) {
        printf("%d. %s\n", i + 1, game->playerCards[player][i].name);
        displayCard(&game->playerCards[player][i], 1, player);
    }
}

/*
This function displays opponent's cards
Precondition: game is initialized
@param game pointer to game state
@return none
*/
void displayOpponentCards(gameStateType *game)
{
    int opponent = (game->currentPlayer == RED) ? BLUE : RED;
    int i;
    
    printf("\n=== %s's Cards (Opponent) ===\n", getColorName(opponent));
    for (i = 0; i < CARDS_PER_PLAYER; i++) {
        printf("\nCard %d: %s\n", i + 1, game->playerCards[opponent][i].name);
        displayCard(&game->playerCards[opponent][i], 0, opponent);
    }
    printf("==============================\n");
}

/*
This function displays the neutral card
Precondition: game is initialized
@param game pointer to game state
@return none
*/
void displayNeutralCard(gameStateType *game)
{
    printf("\n=== NEUTRAL CARD ===\n");
    printf("Card: %s\n", game->neutralCard.name);
    displayCard(&game->neutralCard, 0, game->currentPlayer);
    printf("====================\n");
}

/*
This function gets player names
Precondition: game is initialized
@param game pointer to game state
@return none
*/
void getPlayerNames(gameStateType *game)
{
    printf("\n=== PLAYER SETUP ===\n");
    printf("Enter Blue player name: ");
    if (scanf("%49s", game->playerNames[BLUE]) != 1) {
        strcpy(game->playerNames[BLUE], "Blue Player");
    }
    
    printf("Enter Red player name: ");
    if (scanf("%49s", game->playerNames[RED]) != 1) {
        strcpy(game->playerNames[RED], "Red Player");
    }
    printf("====================\n");
}

/*
This function gets menu choice from user
Precondition: none
@param none
@return menu choice number
*/
int getMenuChoice(void)
{
    int choice;
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 2) {
        printf("Invalid choice! Please enter 1 or 2: ");
        while (getchar() != '\n');
    }
    return choice;
}

/*
This function gets game menu choice from user
Precondition: none
@param none
@return game menu choice number
*/
int getGameMenuChoice(void)
{
    int choice;
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
        printf("Invalid choice! Please enter 1-5: ");
        while (getchar() != '\n');
    }
    return choice;
}

/*
This function parses coordinate input with current player always at bottom
Precondition: input is valid string
@param input coordinate string
@param row pointer to store row
@param col pointer to store column
@param player current player (always sees themselves at bottom)
@return 1 if successful, 0 if failed
*/
int parseCoordinateWithPerspective(const char *input, int *row, int *col, int player)
{
    if (strlen(input) < 2) return 0;
    
    char rowChar = toupper(input[0]);
    char colChar = input[1];
    
    if (rowChar < 'A' || rowChar > 'E') return 0;
    if (colChar < '1' || colChar > '5') return 0;
    
    int displayRow = rowChar - 'A';
    int displayCol = colChar - '1';
    
    /* Convert display coordinates to actual board coordinates */
    /* Current player always sees themselves at bottom (row E) */
    if (player == BLUE) {
        /* Blue player at bottom: normal coordinates */
        *row = displayRow;
        *col = displayCol;
    } else {
        /* Red player at bottom: flip coordinates to actual board position */
        *row = BOARD_SIZE - 1 - displayRow;
        *col = BOARD_SIZE - 1 - displayCol;
    }
    
    return 1;
}

/*
This function converts actual board coordinates to display coordinates
Precondition: coordinates are valid
@param actualRow actual board row
@param actualCol actual board column
@param player current player (always sees themselves at bottom)
@param displayRow pointer to store display row
@param displayCol pointer to store display column
@return none
*/
void convertToDisplayCoordinates(int actualRow, int actualCol, int player, 
                                int *displayRow, int *displayCol)
{
    if (player == BLUE) {
        /* Blue player at bottom: normal coordinates */
        *displayRow = actualRow;
        *displayCol = actualCol;
    } else {
        /* Red player at bottom: flip coordinates for display */
        *displayRow = BOARD_SIZE - 1 - actualRow;
        *displayCol = BOARD_SIZE - 1 - actualCol;
    }
}

/*
This function gets a move from the current player with standard perspective
Precondition: game is initialized
@param game pointer to game state
@return 1 if move successful, 0 if cancelled
*/
int getPlayerMove(gameStateType *game)
{
    char coordinate[10];
    int fromRow, fromCol, toRow, toCol, cardChoice, moveChoice;
    int player = game->currentPlayer;
    
    /* Get piece to move */
    printf("Select piece to move (e.g., A1, B3): ");
    scanf("%s", coordinate);
    
    if (!parseCoordinateWithPerspective(coordinate, &fromRow, &fromCol, player)) {
        printf("Invalid coordinate format!\n");
        return 0;
    }
    
    /* Check if piece belongs to player */
    int piece = game->board[fromRow][fromCol];
    if (player == RED && piece != RED_STUDENT && piece != RED_SENSEI) {
        printf("That's not your piece!\n");
        return 0;
    }
    if (player == BLUE && piece != BLUE_STUDENT && piece != BLUE_SENSEI) {
        printf("That's not your piece!\n");
        return 0;
    }
    
    /* Show player's cards */
    displayPlayerCards(game, player);
    
    /* Get card selection */
    printf("Select card (1 or 2): ");
    scanf("%d", &cardChoice);
    if (cardChoice < 1 || cardChoice > 2) {
        printf("Invalid card selection!\n");
        return 0;
    }
    cardChoice--; /* Convert to 0-based index */
    
    /* Show available moves for selected card */
    printf("Available moves for %s:\n", game->playerCards[player][cardChoice].name);
    displayCard(&game->playerCards[player][cardChoice], 1, player);
    
    /* Get move selection */
    printf("Select move number (1-%d): ", game->playerCards[player][cardChoice].moveCount);
    scanf("%d", &moveChoice);
    if (moveChoice < 1 || moveChoice > game->playerCards[player][cardChoice].moveCount) {
        printf("Invalid move number!\n");
        return 0;
    }
    moveChoice--; /* Convert to 0-based index */
    
    /* Calculate destination based on selected move and standard perspective */
    int rowOffset = game->playerCards[player][cardChoice].moves[moveChoice].rowOffset;
    int colOffset = game->playerCards[player][cardChoice].moves[moveChoice].colOffset;
    
    /* Apply standard perspective: current player always at bottom */
    if (player == BLUE) {
        /* Blue at bottom: normal pattern */
        toRow = fromRow + rowOffset;
        toCol = fromCol + colOffset;
    } else {
        /* Red at bottom: flipped pattern */
        toRow = fromRow - rowOffset;
        toCol = fromCol - colOffset;
    }
    
    /* Attempt the move */
    return makeMove(game, fromRow, fromCol, toRow, toCol, cardChoice);
}

/*
This function checks if a move is valid with standard player-at-bottom perspective
Precondition: all parameters are valid
@param game pointer to game state
@param fromRow source row
@param fromCol source column
@param toRow destination row
@param toCol destination column
@param cardIndex card being used
@return 1 if valid, 0 if invalid
*/
int isValidMove(gameStateType *game, int fromRow, int fromCol, int toRow, int toCol, int cardIndex)
{
    int piece, destPiece, player, i;
    int rowDiff, colDiff;
    cardType *card;
    
    /* Check bounds */
    if (toRow < 0 || toRow >= BOARD_SIZE || toCol < 0 || toCol >= BOARD_SIZE) {
        return 0;
    }
    
    player = game->currentPlayer;
    piece = game->board[fromRow][fromCol];
    destPiece = game->board[toRow][toCol];
    card = &game->playerCards[player][cardIndex];
    
    /* Check if piece belongs to current player */
    if (player == RED && piece != RED_STUDENT && piece != RED_SENSEI) {
        return 0;
    }
    if (player == BLUE && piece != BLUE_STUDENT && piece != BLUE_SENSEI) {
        return 0;
    }
    
    /* Check if destination is not occupied by own piece */
    if (player == RED && (destPiece == RED_STUDENT || destPiece == RED_SENSEI)) {
        return 0;
    }
    if (player == BLUE && (destPiece == BLUE_STUDENT || destPiece == BLUE_SENSEI)) {
        return 0;
    }
    
    /* Check if move matches card pattern */
    rowDiff = toRow - fromRow;
    colDiff = toCol - fromCol;
    
    for (i = 0; i < card->moveCount; i++) {
        int expectedRowDiff, expectedColDiff;
        
        /* Standard perspective: current player always at bottom */
        if (player == BLUE) {
            /* Blue at bottom: use normal pattern */
            expectedRowDiff = card->moves[i].rowOffset;
            expectedColDiff = card->moves[i].colOffset;
        } else {
            /* Red at bottom: use flipped pattern */
            expectedRowDiff = -card->moves[i].rowOffset;
            expectedColDiff = -card->moves[i].colOffset;
        }
        
        if (rowDiff == expectedRowDiff && colDiff == expectedColDiff) {
            return 1;
        }
    }
    
    return 0;
}

/*
This function executes a validated move with proper coordinate display
Precondition: move has been validated
@param game pointer to game state
@param fromRow source row
@param fromCol source column
@param toRow destination row
@param toCol destination column
@param cardIndex card used
@return none
*/
void executeMove(gameStateType *game, int fromRow, int fromCol, int toRow, int toCol, int cardIndex)
{
    int movingPiece, capturedPiece;
    int displayFromRow, displayFromCol, displayToRow, displayToCol;
    
    movingPiece = game->board[fromRow][fromCol];
    capturedPiece = game->board[toRow][toCol];
    
    /* Record move for replay */
    if (game->moveCount < MAX_GAME_MOVES) {
        game->moveHistory[game->moveCount].player = game->currentPlayer;
        game->moveHistory[game->moveCount].fromRow = fromRow;
        game->moveHistory[game->moveCount].fromCol = fromCol;
        game->moveHistory[game->moveCount].toRow = toRow;
        game->moveHistory[game->moveCount].toCol = toCol;
        game->moveHistory[game->moveCount].capturedPiece = capturedPiece;
        strcpy(game->moveHistory[game->moveCount].cardUsed, 
               game->playerCards[game->currentPlayer][cardIndex].name);
    }
    
    /* Execute move */
    game->board[toRow][toCol] = movingPiece;
    game->board[fromRow][fromCol] = EMPTY;
    
    /* Convert to display coordinates for feedback */
    convertToDisplayCoordinates(fromRow, fromCol, game->currentPlayer, 
                               &displayFromRow, &displayFromCol);
    convertToDisplayCoordinates(toRow, toCol, game->currentPlayer, 
                               &displayToRow, &displayToCol);
    
    printf("\nMove executed: %c%d -> %c%d using %s", 
           'A' + displayFromRow, displayFromCol + 1, 
           'A' + displayToRow, displayToCol + 1,
           game->playerCards[game->currentPlayer][cardIndex].name);
    
    if (capturedPiece != EMPTY) {
        printf(" [Captured %c]", getPieceSymbol(capturedPiece));
    }
    printf("\n");
    
    game->moveCount++;
}

/*
This function swaps the used card with neutral card
Precondition: cardIndex is valid
@param game pointer to game state
@param cardIndex index of card to swap
@return none
*/
void swapCards(gameStateType *game, int cardIndex)
{
    cardType temp;
    
    temp = game->playerCards[game->currentPlayer][cardIndex];
    game->playerCards[game->currentPlayer][cardIndex] = game->neutralCard;
    game->neutralCard = temp;
}

/*
This function switches to the next player
Precondition: game is initialized
@param game pointer to game state
@return none
*/
void switchPlayer(gameStateType *game)
{
    game->currentPlayer = (game->currentPlayer == RED) ? BLUE : RED;
}

/*
This function checks for win conditions
Precondition: game is initialized
@param game pointer to game state
@return game status constant
*/
int checkWinCondition(gameStateType *game)
{
    int i, j;
    int redSenseiFound = 0, blueSenseiFound = 0;
    
    /* Check for sensei capture and base occupation */
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == RED_SENSEI) {
                redSenseiFound = 1;
                /* Check if red sensei reached blue base (row 0, col 2) */
                if (i == 0 && j == 2) {
                    return RED_WINS;
                }
            }
            if (game->board[i][j] == BLUE_SENSEI) {
                blueSenseiFound = 1;
                /* Check if blue sensei reached red base (row 4, col 2) */
                if (i == 4 && j == 2) {
                    return BLUE_WINS;
                }
            }
        }
    }
    
    /* Check for sensei capture */
    if (!redSenseiFound) {
        return BLUE_WINS;
    }
    if (!blueSenseiFound) {
        return RED_WINS;
    }
    
    return GAME_CONTINUE;
}

/*
This function checks if player has valid moves
Precondition: game is initialized
@param game pointer to game state
@param player player to check
@return 1 if has valid moves, 0 otherwise
*/
int hasValidMoves(gameStateType *game, int player)
{
    int i, j, k, l;
    int destRow, destCol;
    
    /* Check each piece */
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            int piece = game->board[i][j];
            
            /* Skip if not player's piece */
            if (player == RED && piece != RED_STUDENT && piece != RED_SENSEI) continue;
            if (player == BLUE && piece != BLUE_STUDENT && piece != BLUE_SENSEI) continue;
            
            /* Check each card */
            for (k = 0; k < CARDS_PER_PLAYER; k++) {
                cardType *card = &game->playerCards[player][k];
                
                /* Check each move */
                for (l = 0; l < card->moveCount; l++) {
                    if (player == BLUE) {
                        /* Blue player sees flipped pattern */
                        destRow = i - card->moves[l].rowOffset;
                        destCol = j - card->moves[l].colOffset;
                    } else {
                        /* Red player sees normal pattern */
                        destRow = i + card->moves[l].rowOffset;
                        destCol = j + card->moves[l].colOffset;
                    }
                    
                    /* Check if this move is valid */
                    int tempPlayer = game->currentPlayer;
                    game->currentPlayer = player;
                    if (isValidMove(game, i, j, destRow, destCol, k)) {
                        game->currentPlayer = tempPlayer;
                        return 1;
                    }
                    game->currentPlayer = tempPlayer;
                }
            }
        }
    }
    
    return 0;
}

/*
This function makes a move
Precondition: game is initialized
@param game pointer to game state
@param fromRow source row
@param fromCol source column
@param toRow destination row
@param toCol destination column
@param cardIndex card index
@return 1 if move successful, 0 otherwise
*/
int makeMove(gameStateType *game, int fromRow, int fromCol, int toRow, int toCol, int cardIndex)
{
    if (!isValidMove(game, fromRow, fromCol, toRow, toCol, cardIndex)) {
        printf("Invalid move!\n");
        return 0;
    }
    
    /* Execute the move */
    executeMove(game, fromRow, fromCol, toRow, toCol, cardIndex);
    
    /* Swap cards */
    swapCards(game, cardIndex);
    
    /* Check win condition */
    game->gameStatus = checkWinCondition(game);
    
    /* Switch player if game continues */
    if (game->gameStatus == GAME_CONTINUE) {
        switchPlayer(game);
    }
    
    return 1;
}

/*
This function clears the screen
Precondition: none
@param none
@return none
*/
void clearScreen(void)
{
    int i;
    for (i = 0; i < 50; i++) {
        printf("\n");
    }
}

/*
This function displays the game result
Precondition: game has ended
@param game pointer to game state
@return none
*/
void displayGameResult(gameStateType *game)
{
    printf("\n========================================\n");
    printf("              GAME OVER!                \n");
    printf("========================================\n");
    
    if (game->gameStatus == RED_WINS) {
        printf("🏆 Winner: %s (Red)\n", getPlayerName(game, RED));
    } else if (game->gameStatus == BLUE_WINS) {
        printf("🏆 Winner: %s (Blue)\n", getPlayerName(game, BLUE));
    }
    
    printf("Total moves: %d\n", game->moveCount);
    printf("========================================\n");
}

/*
This function shows a replay of the game
Precondition: game has move history
@param game pointer to game state
@return none
*/
void showReplay(gameStateType *game)
{
    int i;
    char input;
    
    printf("\n=== GAME REPLAY ===\n");
    printf("Press Enter to see each move...\n");
    
    for (i = 0; i < game->moveCount; i++) {
        printf("\nMove %d: %s (%s)\n", 
               i + 1, 
               getPlayerName(game, game->moveHistory[i].player),
               getColorName(game->moveHistory[i].player));
        
        printf("Moved from %c%d to %c%d using %s\n",
               'A' + game->moveHistory[i].fromRow,
               game->moveHistory[i].fromCol + 1,
               'A' + game->moveHistory[i].toRow,
               game->moveHistory[i].toCol + 1,
               game->moveHistory[i].cardUsed);
        
        if (game->moveHistory[i].capturedPiece != EMPTY) {
            printf("Captured: %c\n", getPieceSymbol(game->moveHistory[i].capturedPiece));
        }
        
        printf("Press Enter for next move...");
        while (getchar() != '\n');
        getchar();
    }
    
    printf("\n=== END OF REPLAY ===\n");
}

/*
This function runs the main game loop with optimized UI
Precondition: game is initialized and set up
@param game pointer to game state
@return none
*/
void runGameLoop(gameStateType *game)
{
    int choice, cardChoice;
    char replayChoice;
    
    while (game->gameStatus == GAME_CONTINUE) {
        clearScreen();
        displayBoard(game);
        
        /* Check if current player has valid moves */
        if (!hasValidMoves(game, game->currentPlayer)) {
            printf("\n%s has no valid moves! Must pass turn.\n", 
                   getPlayerName(game, game->currentPlayer));
            
            /* Player must still swap a card */
            displayPlayerCards(game, game->currentPlayer);
            printf("Select a card to swap (1 or 2): ");
            scanf("%d", &cardChoice);
            while (cardChoice < 1 || cardChoice > 2) {
                printf("Invalid selection. Enter 1 or 2: ");
                scanf("%d", &cardChoice);
            }
            cardChoice--; /* Convert to 0-based index */
            
            swapCards(game, cardChoice);
            switchPlayer(game);
            
            printf("Turn passed. Press Enter to continue...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        
        /* Display game menu */
        displayGameMenu();
        choice = getGameMenuChoice();
        
        switch (choice) {
            case 1:
                /* Make a move */
                if (!getPlayerMove(game)) {
                    printf("Move failed. Press Enter to continue...");
                    while (getchar() != '\n');
                    getchar();
                }
                break;
                
            case 2:
                /* View opponent's cards */
                displayOpponentCards(game);
                printf("Press Enter to continue...");
                while (getchar() != '\n');
                getchar();
                break;
                
            case 3:
                /* View neutral card */
                displayNeutralCard(game);
                printf("Press Enter to continue...");
                while (getchar() != '\n');
                getchar();
                break;
                
            case 4:
                /* View my cards */
                printf("\n=== Your Cards ===\n");
                displayPlayerCards(game, game->currentPlayer);
                printf("==================\n");
                printf("Press Enter to continue...");
                while (getchar() != '\n');
                getchar();
                break;
                
            case 5:
                /* Clear screen and show board - just continue loop */
                break;
                
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    
    /* Display final result */
    clearScreen();
    displayBoard(game);
    displayGameResult(game);
    
    /* Offer replay */
    printf("\nWould you like to see a replay? (y/n): ");
    scanf(" %c", &replayChoice);
    if (replayChoice == 'y' || replayChoice == 'Y') {
        showReplay(game);
    }
}

/*
This function runs the main program
Precondition: none
@param none
@return none
*/
void runMainProgram(void)
{
    gameStateType game;
    int choice;
    int running = 1;
    
    /* Initialize random seed */
    srand((unsigned int)time(NULL));
    
    printf("Welcome to Onitama!\n");
    printf("A two-player strategy board game.\n");
    
    while (running) {
        displayMainMenu();
        choice = getMenuChoice();
        
        switch (choice) {
            case 1:
                /* Start new game */
                initializeGame(&game);
                getPlayerNames(&game);
                setupBoard(&game);
                
                printf("\nPress Enter to start the game...");
                while (getchar() != '\n');
                getchar();
                
                runGameLoop(&game);
                break;
                
            case 2:
                /* Exit */
                printf("Thank you for playing Onitama!\n");
                running = 0;
                break;
                
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}

/*
Main function - entry point of the program
Precondition: none
@param none
@return 0 on successful execution
*/
int main(void)
{
    runMainProgram();
    return 0;
}