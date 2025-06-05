/******************************************************************************
 * DO NOT MODIFY THIS FILE (except for #include "COURSELIST-LastName.c")
 *
 * This contains the main() function for testing your solution. This file will
 * show you the result of each function that you need to implement.
 ******************************************************************************/

/******************************************************************************
 * TODO: Modify the line below with the updated filename
 ******************************************************************************/
#include "COURSELIST-LastName.c"

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
  StudentMatrix students = {
      {"Alice", "CCPROG2", "CSMATH1", "CCDSTRU", "_", "_"},
      {"Bob", "CCPROG2", "GEUSELF", "_", "_", "_"},
      {"Charlie", "CCDSTRU", "GEARTAP", "LASARE1", "NSTP-01", "GEMATMW"},
      {"Darwin", "_", "_", "_", "_", "_"},
      {"Evan", "CCPROG3", "_", "_", "_", "_"},
      {"Faye", "CSMATH2", "GEFIL1", "LCFAITH", "_", "_"},
      {"George", "SAS1000", "CCPROG3", "_", "_", "_"},
      {"Henry", "CCICOMP", "STT101A", "NSTP101", "CCPROG1", "_"},
      {"Ina", "CCDSALG", "LCLSONE", "_", "_", "_"},
  };

  printf("+----------------------------------+\n");
  printf("| TASK #1: Populate Student Matrix |\n");
  printf("+----------------------------------+\n");
  displayTask1();

  printf("\n\n");
  printf("+-----------------------------------+\n");
  printf("| TASK #2: Search Student In Matrix |\n");
  printf("+-----------------------------------+\n");
  displayTask2(students);

  printf("\n\n");
  printf("+---------------------------------------+\n");
  printf("| TASK #3: Add Course To Student Record |\n");
  printf("+---------------------------------------+\n");
  displayTask3(students);

  printf("\n\n");
  printf("+-----------------------+\n");
  printf("| TASK #4: Sort Courses |\n");
  printf("+-----------------------+\n");
  displayTask4(students);

  return 0;
}