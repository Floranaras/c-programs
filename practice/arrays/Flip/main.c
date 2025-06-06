/******************************************************************************
 * DO NOT MODIFY THIS FILE (except for #include "FLIP7-LastName.c")
 *
 * This contains the main() function for testing your solution. This file will
 * show you the result of each function that you need to implement.
 ******************************************************************************/

/******************************************************************************
 * TODO: Modify the line below with the updated filename
 ******************************************************************************/
#include "FLIP7-LastName.c"

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
  printf("+------------------------------+\n");
  printf("| TASK #1: Draw Card from Deck |\n");
  printf("+------------------------------+\n");
  displayTask1();

  printf("\n\n");
  printf("+----------------------------------+\n");
  printf("| TASK #2: Check If Exists in Hand |\n");
  printf("+----------------------------------+\n");
  displayTask2();

  printf("\n\n");
  printf("+---------------------------+\n");
  printf("| TASK #3: Add Card to Hand |\n");
  printf("+---------------------------+\n");
  displayTask3();

  printf("\n\n");
  printf("+--------------------+\n");
  printf("| TASK #4: Get Score |\n");
  printf("+--------------------+\n");
  displayTask4();

  printf("\n\n");
  printf("+----------------------------------+\n");
  printf("| TASK #5: Putting It All Together |\n");
  printf("+----------------------------------+\n");
  displayTask5();

  printf("\n\n");
  printf("+------------------+\n");
  printf("| Round Simulation |\n");
  printf("+------------------+\n");
  displayRoundSimulation();

  return 0;
}