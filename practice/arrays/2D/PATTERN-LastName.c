/******************************************************************************
 * Topic   : Practice 2D Arrays (Pattern Printing)
 * Name    : LastName, FirstName
 * Section : S##
 ******************************************************************************
 *
 * 1. Encode your name and section above, as well as rename this file in the
 *    following format: PATTERN-LastName.c
 *     - Example: PATTERN-DelaCruz.c
 *
 * 2. Read and understand the problem specs.
 *
 * 3. Compile and run the skeleton code. Observe, trace, and understand what the
 *    skeleton code does before doing any changes.
 *
 * 4. Implement your solution in this file. This is the C source file that you
 *    should submit/upload in AnimoSpace. Follow all the instructions in the
 *    accompanying specifications file and the instructions written (as function
 *    comments) in this file.
 *
 *    Compile:
 *      prompt~> gcc -Wall -std=c99 PATTERN-DelaCruz.c -o app
 *
 *    Run in Mac/Linux:
 *      prompt~> ./app < input1.txt
 *
 *    Run in Windows:
 *      prompt~> app < input1.txt
 *
 * 5. Your program must be able to reproduce the same expected output. If
 *    applicable, you may use the included bbtest.c file to streamline the
 *    testing of your program.
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
 * For this exercise, you are NOT ALLOWED to define any other convenience/helper
 * function.
 ******************************************************************************/

/**
 * [GIVEN] Builds a filled box pattern
 * @param arr2D The 2D array to populate with the pattern
 * @param n The size of the box
 */
void filledBox(char arr2D[][MAX_SIZE], int n)
{
  /*  Given `n = 3`, the expected output is:
        x x x
        x x x
        x x x
   */
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      arr2D[i][j] = 'x';
}

/**
 * Builds a number grid pattern #1 pattern
 * @param arr2D The 2D array to populate with the pattern
 * @param n The size of the grid
 */
void numberGrid1(int arr2D[][MAX_SIZE], int n)
{
  /*  Given `n = 3`, the expected output is:
        1 1 1
        2 2 2
        3 3 3
   */

  int j, k;

  for (j = 0; j < n; j++)
  {
    for (k = 0; k < n; k++)
    {
      arr2D[j][k] = j + 1;
    }
  }
}

/**
 * Builds a number grid pattern #2 pattern
 * @param arr2D The 2D array to populate with the pattern
 * @param n The size of the grid
 */
void numberGrid2(int arr2D[][MAX_SIZE], int n)
{
  /*  Given `n = 3`, the expected output is:
        1 2 3
        1 2 3
        1 2 3
   */

  int j, k;

  for (j = 0; j < n; j++)
  {
    for (k = 0; k < n; k++)
    {
      arr2D[j][k] = k + 1;
    }
  }
}

/**
 * Builds the multiplication table up to `n`
 * @param arr2D The 2D array to populate with the pattern
 * @param n The size of the table
 */
void multiplicationTable(int arr2D[][MAX_SIZE], int n)
{
  /*  Given `n = 3`, the expected output is:
        1 2 3
        2 4 6
        3 6 9
   */

   int j, k;

    for (j = 0; j < n; j++)
    { 
      for (k = 0; k < n; k++)
      {
        arr2D[j][k] = (j + 1) * (k + 1);
      }
    }
}

/**
 * Builds a hollow box pattern
 * @param arr2D The 2D array to populate with the pattern
 * @param n The size of the box
 */
void hollowBox(char arr2D[][MAX_SIZE], int n)
{
  /*  Given `n = 3`, the expected output is:
        x x x
        x   x
        x x x
   */

   int j, k;

    for (j = 0; j < n; j++)
    {
      for (k = 0; k < n; k++)
      {
        if (j == n/2 && k == n/2 )
        {
          arr2D[j][k] = ' ';
        }

        else
        {
          arr2D[j][k] = 'x';
        }
      }
    }
}

/**
 * Builds a left pyramid pattern
 * @param arr2D The 2D array to populate with the pattern
 * @param n The size of the pyramid
 */
void leftPyramid(char arr2D[][MAX_SIZE], int n)
{
  /*  Given `n = 3`, the expected output is:
        x
        x x
        x x x
   */

   int j, k;

   for (j = 0; j < n; j++)
   {
      for (k = 0; k < j + 1; k++)
      {
        arr2D[j][k] = 'x';
      }
   }
}

/**
 * Builds an inverted left pyramid pattern
 * @param arr2D The 2D array to populate with the pattern
 * @param n The size of the pyramid
 */
void invertedLeftPyramid(char arr2D[][MAX_SIZE], int n)
{
  /*  Given `n = 3`, the expected output is:
        x x x
        x x
        x
   */

   int j, k;

   for (j = 0; j < n; j++)
   {
      for (k = 0; k < n - j; k++)
      {
        arr2D[j][k] = 'x';
      }
   }
}

/**
 * Builds a right pyramid pattern
 * @param arr2D The 2D array to populate with the pattern
 * @param n The size of the pyramid
 */
void rightPyramid(char arr2D[][MAX_SIZE], int n)
{
  /*  Given `n = 3`, the expected output is:
            x
          x x
        x x x
   */

   int j, k;

   for (j = 0; j < n; j++)
   {
    for(k = n - j - 1; k < n; k++)
    {
      arr2D[j][k] = 'x';
    }
   }
}

/**
 * Builds a inverted right pyramid pattern
 * @param arr2D The 2D array to populate with the pattern
 * @param n The size of the pyramid
 */
void invertedRightPyramid(char arr2D[][MAX_SIZE], int n)
{
  /*  Given `n = 3`, the expected output is:
        x x x
          x x
            x
   */
   int j, k;

   for (j = 0; j < n; j++)
   {
    for(k = j; k < n; k++)
    {
      arr2D[j][k] = 'x';
    }
   }

}

/******************************************************************************
 * [GIVEN / DO NOT MODIFY]
 *
 * This is the main() function for displaying your final solution. You are not
 * supposed to modify the contents and the logic of this function.
 *
 * If you need to experiment, i.e. you'd like to edit/introduce new codes, then
 * it is suggested that you copy this file, and make changes on your copy.
 *
 * Your functions should work correctly even with a different set of input data
 * and a different main() function.
 *
 *******************************************************************************/
int main()
{
  int numGrid1[MAX_SIZE][MAX_SIZE];   // for number grid 1
  int numGrid2[MAX_SIZE][MAX_SIZE];   // for number grid 2
  int numGrid3[MAX_SIZE][MAX_SIZE];   // for multiplication table
  char charGrid1[MAX_SIZE][MAX_SIZE]; // for filled box
  char charGrid2[MAX_SIZE][MAX_SIZE]; // for hollow box
  char charGrid3[MAX_SIZE][MAX_SIZE]; // for left pyramid
  char charGrid4[MAX_SIZE][MAX_SIZE]; // for inverted left pyramid
  char charGrid5[MAX_SIZE][MAX_SIZE]; // for right pyramid
  char charGrid6[MAX_SIZE][MAX_SIZE]; // for inverted right pyramid

  // This part gets the input; You can streamline it with input redirection
  int patternSize;
  scanf("%d", &patternSize);

  // Initializes all elements of the number grids to 0
  initializeNumberGrid(numGrid1, patternSize);
  initializeNumberGrid(numGrid2, patternSize);
  initializeNumberGrid(numGrid3, patternSize);
  // Initializes all elements of the number grids to '_'
  initializeCharacterGrid(charGrid1, patternSize);
  initializeCharacterGrid(charGrid2, patternSize);
  initializeCharacterGrid(charGrid3, patternSize);
  initializeCharacterGrid(charGrid4, patternSize);
  initializeCharacterGrid(charGrid5, patternSize);
  initializeCharacterGrid(charGrid6, patternSize);

  // Display
  printf("Filled Box:\n");
  filledBox(charGrid1, patternSize);
  displayCharacterGrid(charGrid1, patternSize);

  printf("\nNumber Grid #1:\n");
  numberGrid1(numGrid1, patternSize);
  displayNumberGrid(numGrid1, patternSize);

  printf("\nNumber Grid #2:\n");
  numberGrid2(numGrid2, patternSize);
  displayNumberGrid(numGrid2, patternSize);

  printf("\nMultiplication Table:\n");
  multiplicationTable(numGrid3, patternSize);
  displayNumberGrid(numGrid3, patternSize);

  printf("\nHollow Box:\n");
  hollowBox(charGrid2, patternSize);
  displayCharacterGrid(charGrid2, patternSize);

  printf("\nLeft Pyramid:\n");
  leftPyramid(charGrid3, patternSize);
  displayCharacterGrid(charGrid3, patternSize);

  printf("\nInverted Left Pyramid:\n");
  invertedLeftPyramid(charGrid4, patternSize);
  displayCharacterGrid(charGrid4, patternSize);

  printf("\nRight Pyramid:\n");
  rightPyramid(charGrid5, patternSize);
  displayCharacterGrid(charGrid5, patternSize);

  printf("\nInverted Right Pyramid:\n");
  invertedRightPyramid(charGrid6, patternSize);
  displayCharacterGrid(charGrid6, patternSize);

  return 0;
}