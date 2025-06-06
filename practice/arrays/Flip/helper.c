/******************************************************************************
 * DO NOT MODIFY THIS FILE.
 *
 * This file contains helper functions for completing the exercise
 ******************************************************************************/

#ifndef HELPER_C // Do not remove this line
#define HELPER_C // Do not remove this line

#include <stdio.h>

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] CONSTANTS
 ******************************************************************************/

#define DECK_SIZE 15 // Max number deck cards
#define HAND_SIZE 7  // Max number of hand cards

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] FUNCTION PROTOTYPES
 *
 * These are the function prototypes for the functions that you need to
 * implement in the file FLIP7-LastName.c
 *
 * You are not allowed to modify/change the return type nor parameters.
 ******************************************************************************/

int drawCard(int deck[]);
int checkExists(int playerHand[], int drawnCard);
void addToHand(int playerHand[], int drawnCard);
void getScore(int playerHand[], int *score);
int takeTurn(int deck[], int playerHand[]);

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] Display helper functions
 ******************************************************************************/

/**
 * Copies the content of the source array to the destination array
 * @param dst The destination array where the contents will be copied to
 * @param src The source array where the contents will be copied from
 * @param arrSize The size of the array
 */
void copyCards(int dst[], int src[], int arrSize)
{
  int i;
  for (i = 0; i < arrSize; i++)
    dst[i] = src[i];
}

/**
 * Displays the array of cards
 * @param cards The array of cards
 * @param arrSize The size of the array of cards
 */
void displayCards(int cards[], int arrSize)
{
  int i;
  for (i = 0; i < arrSize; i++)
    printf("%d ", cards[i]);
}

/**
 * Displays a single test case for Task #1
 * @param deck The array of cards to draw from
 */
void displayTask1TestCase(int deck[])
{
  int drawnCard = 999;

  printf("\n  Deck (before): ");
  displayCards(deck, DECK_SIZE);

  // Call student function
  drawnCard = drawCard(deck);

  // Display results
  printf("\n   Deck (after): ");
  displayCards(deck, DECK_SIZE);
  printf("\n     Drawn Card: %d\n\n", drawnCard);
}

/**
 * Displays a single test case for Task #2
 * @param playerHand The player's array of cards
 * @param drawnCard The drawn card
 */
void displayTask2TestCase(int playerHand[], int drawnCard)
{
  int result = 999;

  // Call student function
  result = checkExists(playerHand, drawnCard);

  // Display results
  printf("\n  Is '%d' already in { ", drawnCard);
  displayCards(playerHand, HAND_SIZE);
  printf("} ?");
  printf("\n  Result: %d\n\n", result);
}

/**
 * Displays a single test case for Task #3
 * @param playerHand The player's array of cards
 */
void displayTask3TestCase(int playerHand[])
{
  int drawnCard = 9;

  printf("\n  Player Hand (before): ");
  displayCards(playerHand, HAND_SIZE);

  // Call student function
  addToHand(playerHand, drawnCard);

  // Display results
  printf("\n   Player Hand (after): ");
  displayCards(playerHand, HAND_SIZE);
  printf("\n\n");
}

/**
 * Displays a single test case for Task #4
 * @param playerHand The player's array of cards
 */
void displayTask4TestCase(int playerHand[])
{
  int score = 999;

  // Call student function
  getScore(playerHand, &score);

  // Display results
  printf("\n  Player Hand: ");
  displayCards(playerHand, HAND_SIZE);
  printf("\n        Score: %d\n\n", score);
}

void displayTask5TestCase(int deck[], int playerHand[])
{
  int deckCopy[DECK_SIZE], handCopy[HAND_SIZE];
  int score = 999;

  // Copy arrays for to preserve original input
  copyCards(deckCopy, deck, DECK_SIZE);
  copyCards(handCopy, playerHand, HAND_SIZE);

  // Call student function
  score = takeTurn(deckCopy, handCopy);

  // Display results
  printf("\n  Deck (before): ");
  displayCards(deck, DECK_SIZE);
  printf("\n   Deck (after): ");
  displayCards(deckCopy, DECK_SIZE);

  printf("\n\n  Player Hand (before): ");
  displayCards(playerHand, HAND_SIZE);
  printf("\n   Player Hand (after): ");
  displayCards(handCopy, HAND_SIZE);

  printf("\n\n  Score: %d\n\n", score);
}

/******************************************************************************
 * [DO NOT MODIFY] Main display functions
 ******************************************************************************/

/**
 * Display Task #1 test cases
 */
void displayTask1()
{
  int fullDeck[DECK_SIZE] = {9, 4, 7, 5, 4, 3, 7, 7, 9, 4, 8, 7, 6, 1, 6};
  int partialDeck[DECK_SIZE] = {5, 7, 9, 9, 3, 8, 8, 9};
  int lastCardDeck[DECK_SIZE] = {3};

  printf("\n  TEST CASE #1: Full Deck");
  printf("\n  -----------------------\n");
  displayTask1TestCase(fullDeck);

  printf("\n  TEST CASE #2: Partial Deck");
  printf("\n  --------------------------\n");
  displayTask1TestCase(partialDeck);

  printf("\n  TEST CASE #3: Last Card In Deck");
  printf("\n  -------------------------------\n");
  displayTask1TestCase(lastCardDeck);
}

/**
 * Display Task #2 test cases
 */
void displayTask2()
{
  int emptyHand[HAND_SIZE] = {0};
  int partialHand[HAND_SIZE] = {1, 8, 7, 6, 3};

  printf("\n  TEST CASE #1: Empty Hand");
  printf("\n  ------------------------\n");
  displayTask2TestCase(emptyHand, 4);

  printf("\n  TEST CASE #2: Card Exists at 1st Element");
  printf("\n  ----------------------------------------\n");
  displayTask2TestCase(partialHand, 1);

  printf("\n  TEST CASE #3: Card Exists at Middle Element");
  printf("\n  -------------------------------------------\n");
  displayTask2TestCase(partialHand, 7);

  printf("\n  TEST CASE #4: Card Exists at 'Last' Element");
  printf("\n  -------------------------------------------\n");
  displayTask2TestCase(partialHand, 3);

  printf("\n  TEST CASE #5: Card Does Not Exist");
  printf("\n  ---------------------------------\n");
  displayTask2TestCase(partialHand, 5);
}

/**
 * Display Task #3 test cases
 */
void displayTask3()
{
  int emptyHand[HAND_SIZE] = {0};
  int partialHand[HAND_SIZE] = {1, 7, 6, 3};
  int almostFullHand[HAND_SIZE] = {8, 2, 5, 4, 3, 6};

  printf("\n  Adding '9' to the player hand...\n\n");

  printf("\n  TEST CASE #1: Empty Hand");
  printf("\n  ------------------------\n");
  displayTask3TestCase(emptyHand);

  printf("\n  TEST CASE #2: Partial Hand");
  printf("\n  --------------------------\n");
  displayTask3TestCase(partialHand);

  printf("\n  TEST CASE #3: Almost Full Hand");
  printf("\n  ------------------------------\n");
  displayTask3TestCase(almostFullHand);
}

/**
 * Display Task #4 test cases
 */
void displayTask4()
{
  int emptyHand[HAND_SIZE] = {0};
  int partialHand[HAND_SIZE] = {1, 7, 6, 3};
  int fullHand[HAND_SIZE] = {8, 2, 5, 4, 3, 6, 1};

  printf("\n  TEST CASE #1: Empty Hand");
  printf("\n  ------------------------\n");
  displayTask4TestCase(emptyHand);

  printf("\n  TEST CASE #2: Partial Hand");
  printf("\n  --------------------------\n");
  displayTask4TestCase(partialHand);

  printf("\n  TEST CASE #3: Full Hand");
  printf("\n  -----------------------\n");
  displayTask4TestCase(fullHand);
}

/**
 * Display Task #5 test cases
 */
void displayTask5()
{
  int deck1[DECK_SIZE] = {9, 4, 7, 3, 5};
  int deck2[DECK_SIZE] = {6, 2, 4, 4, 7};

  int emptyHand[HAND_SIZE] = {0};
  int partialHand[HAND_SIZE] = {1, 7, 6, 3};
  int almostFullHand[HAND_SIZE] = {8, 2, 5, 4, 3, 6};

  printf("\n  For the following test cases, assume that they are independent of each other\n\n");

  printf("\n  TEST CASE #1: Empty Hand");
  printf("\n  ------------------------\n");
  displayTask5TestCase(deck1, emptyHand);

  printf("\n  TEST CASE #2: Partial Hand, Can Continue");
  printf("\n  ----------------------------------------\n");
  displayTask5TestCase(deck1, partialHand);

  printf("\n  TEST CASE #3: Partial Hand, Out of the Game");
  printf("\n  -------------------------------------------\n");
  displayTask5TestCase(deck2, partialHand);

  printf("\n  TEST CASE #4: Full Hand, Can Continue");
  printf("\n  -------------------------------------\n");
  displayTask5TestCase(deck1, almostFullHand);

  printf("\n  TEST CASE #5: Full Hand, Out of the Game");
  printf("\n  ----------------------------------------\n");
  displayTask5TestCase(deck2, almostFullHand);
}

/**
 * Display round simulation
 */
void displayRoundSimulation()
{
  int deck[DECK_SIZE] = {2, 5, 9, 6, 6, 7, 4, 2, 5, 7};
  int scoreP1 = 999, handP1[HAND_SIZE] = {6, 4, 9};
  int scoreP2 = 999, handP2[HAND_SIZE] = {8, 5, 7};
  int scoreP3 = 999, handP3[HAND_SIZE] = {7, 4, 8};

  printf("\n  - This is just an extra display to show how your solution"
         "\n      would be used in a text-based version of Flip 7"
         "\n  - This simulates a full round consisting of 3 players,"
         "\n      wherein they would all be drawing from 1 deck"
         "\n  - In the real game, the deck is hidden; we're just displaying it"
         "\n      to show the transfer of the card from deck to hand"
         "\n  - At the end of the round, their running total score is displayed"
         "\n  - Player #2 is expected to be out of the game after the round\n\n");

  printf("\n  Deck: ");
  displayCards(deck, DECK_SIZE);
  printf("\n\n  Player #1: ");
  displayCards(handP1, HAND_SIZE);
  printf("\n  Player #2: ");
  displayCards(handP2, HAND_SIZE);
  printf("\n  Player #3: ");
  displayCards(handP3, HAND_SIZE);

  printf("\n"
         "\n  Player 1 takes a turn..."
         "\n  Player 2 takes a turn..."
         "\n  Player 3 takes a turn...\n");

  scoreP1 = takeTurn(deck, handP1);
  scoreP2 = takeTurn(deck, handP2);
  scoreP3 = takeTurn(deck, handP3);

  printf("\n  Player #1: ");
  displayCards(handP1, HAND_SIZE);
  printf("// Score: %d", scoreP1);
  printf("\n  Player #2: ");
  displayCards(handP2, HAND_SIZE);
  printf("// Score: %d", scoreP2);
  printf("\n  Player #3: ");
  displayCards(handP3, HAND_SIZE);
  printf("// Score: %d", scoreP3);
}

#endif // HELPER_C // Do not remove this line