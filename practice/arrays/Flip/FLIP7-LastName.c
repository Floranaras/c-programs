/******************************************************************************
 * Topic   : 1D Arrays (Flip 7)
 * Name    : LastName, FirstName
 * Section : S##
 ******************************************************************************
 *
 * 1. Encode your name and section above, as well as rename this file in the
 *    following format: FLIP7-LastName.c
 *     - Example: FLIP7-DelaCruz.c
 *
 * 2. Edit the #include "FLIP7-LastName.c" in main.c with the updated filename.
 *
 * 3. Read and understand the problem specs.
 *
 * 4. Compile and run the skeleton code. Observe, trace, and understand what the
 *    skeleton code does before doing any changes.
 *
 * 4. Implement your solution in this file. This is the C source file that you
 *    should submit/upload in AnimoSpace. Follow all the instructions in the
 *    accompanying specifications file and the instructions written (as function
 *    comments) in this file.
 *
 *    Compile:
 *      prompt~> gcc -Wall -std=c99 main.c -o app
 *
 *    Run in Mac/Linux:
 *      prompt~> ./app
 *
 *    Run in Windows:
 *      prompt~> app
 *
 * 5. Your program must be able to reproduce the same expected output.
 *    Take note that the functionality for output formatting is already
 *    implemented for you.
 *
 * Prepared by
 * - Email  : kristine.kalaw@dlsu.edu.ph
 * - @author: Kristine Kalaw
 *            Department of Software Technology
 *            College of Computer Studies
 *            De La Salle University
 *
 * Kindly inform me if there are any corrections needed for this template
 ******************************************************************************/

#include "helper.c"

/******************************************************************************
 * [TODO] FUNCTION IMPLEMENTATIONS
 *
 * The section area below is where you will complete the functions as described
 * in the problem specs.
 *
 * Ideally, all functions must observe proper and complete function
 * documentation. This means it has a function description, a list of parameters
 * with description, and if it returns something, a description of the return
 * value.
 *
 * For this exercise, you are NOT ALLOWED to define any other convenience/helper
 * function.
 ******************************************************************************/

/**
 * <Provide complete function documentation>
 */

void shiftIdx(int idx, int *A)
{
  int j;

  for (j = idx; j < DECK_SIZE - 1; j++)
  {
    A[j] = A[j + 1];
  }

  A[DECK_SIZE - 1] = 0;
}
int drawCard(int deck[])
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */
  int nVal = deck[0];
  shiftIdx(0, deck);


  return nVal; // replace with actual return value
}

/**
 * <Provide complete function documentation>
 */

int searchFor(int *A, int key)
{
  int j = 0;

  while (j < HAND_SIZE && A[j] != key)
  {
    j++;
  }

  if (j == HAND_SIZE)
    return -1;

  return j;
}
int checkExists(int playerHand[], int drawnCard)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */

  if (searchFor(playerHand, drawnCard) == -1)
    return 0;

  return 1; // replace with actual return value
}

/**
 * <Provide complete function documentation>
 */
void addToHand(int playerHand[], int drawnCard)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */
  int idx = searchFor(playerHand, 0);

  if (idx != -1)
  {
    playerHand[idx] = drawnCard;
  }

}

/**
 * <Provide complete function documentation>
 */
void getScore(int playerHand[], int *score)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */

  int j;
  *score = 0;

  for (j = 0; j < HAND_SIZE; j++)
  {
    *score += playerHand[j];
  }

}

/**
 * <Provide complete function documentation>
 */
int takeTurn(int deck[], int playerHand[])
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */
  int score;
  int drawnCard = drawCard(deck);

  if (checkExists(playerHand, drawnCard))
  {
    addToHand(playerHand, drawnCard);
    score = 0;
  }

  else 
  {
    addToHand(playerHand, drawnCard);
    getScore(playerHand, &score);
  }


  return score; // replace with actual return value
}