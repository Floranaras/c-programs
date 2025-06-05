/******************************************************************************
 * Topic   : 2D Array of Strings (Course List)
 * Name    : LastName, FirstName
 * Section : S##
 ******************************************************************************
 *
 * 1. Encode your name and section above, as well as rename this file in the
 *    following format: COURSELIST-LastName.c
 *     - Example: COURSELIST-DelaCruz.c
 *
 * 2. Edit the #include "COURSELIST-LastName.c" in main.c with the updated filename.
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
 *      prompt~> ./app < input.txt
 *
 *    Run in Windows:
 *      prompt~> app < input.txt
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
 * For this exercise, you are NOT ALLOWED to define any other convenience/helper
 * function.
 ******************************************************************************/

/**
 * <Provide complete function documentation>
 */
void populateStudentMatrix(StudentMatrix m, int *nStudents)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() in your final solution
    Do NOT modify/change the return type nor parameters
  */
  String temp;
  int j, k = 0;
  int flag = 1;

  for (j = 0; j < MAX_STUDENTS && flag; j++)
  {
    for (k = 0; k < MAX_COURSES + 1 && flag; k++)
    {

      scanf("%s", temp);

      if (!strcmp(temp,"END"))
      {
        flag = 0;
      }

      else
      {
        strcpy(m[j][k],temp);
      }
    }

    if (flag)
      (*nStudents)++;
  }
}
/**
 * <Provide complete function documentation>
 */
int searchStudent(StudentMatrix m, int nStudents, String searchStudentName)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */

  int j = 0;

  while (j < nStudents && strcmp(m[j][0], searchStudentName) != 0)
  {
    j++;
  }

  if (j == nStudents)
    return -1;

  return j; // replace with actual return value
}

int searchCourse(StudentMatrix m, int studentIdx)
{
  int j = 1;

  while (j <= MAX_COURSES && strcmp(m[studentIdx][j],"_") != 0) 
  {
    j++;
  }

  if (j == MAX_COURSES + 1)
    return -1;

  return j;
}
/**
 * <Provide complete function documentation>
 */
int addCourseToStudent(StudentMatrix m, int nStudents, String searchStudentName, String courseName)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */
  int studentIdx = searchStudent(m, nStudents, searchStudentName);
  int courseIdx = searchCourse(m,studentIdx);

  if (studentIdx != -1)
  {
    if (courseIdx != -1)
    {
      strcpy(m[studentIdx][courseIdx],courseName);
      return 1;
    }

    else 
    {
      return 0;
    }
  }

  return -1; // replace with actual return value
}

void swap(String a, String b)
{
  String t;
  strcpy(t, a);
  strcpy(a, b);
  strcpy(b, t);
}

int isUnderscore(String s)
{
  return strcmp(s, "_") == 0;
}

int shouldSwap(String a, String b)
{
  return (isUnderscore(a) && !isUnderscore(b)) ||
         (!isUnderscore(a) && !isUnderscore(b) && strcmp(a, b) > 0);
}
/**
 * <Provide complete function documentation>
 */
void sortCourses(StudentMatrix m, int nStudents)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */

 int j = 0, k, p;

  while (j < nStudents)
  {
    k = 0;
    while (k < MAX_COURSES)
    {
      p = 1;
      while (p < MAX_COURSES - k)
      {
        if (shouldSwap(m[j][p], m[j][p+1]))
          swap(m[j][p], m[j][p+1]);
        p++;
      }
      k++;
    }
    j++;
  }
}
