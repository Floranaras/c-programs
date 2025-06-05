/******************************************************************************
 * Black box test program for checking the differences between two files (line by line)
 *
 * Adapted from Dr. Florante Salvador's bbtest.c
 *
 * Prepared by
 * - Email  : kristine.kalaw@dlsu.edu.ph
 * - @author: Kristine Kalaw
 *            Department of Software Technology
 *            College of Computer Studies
 *            De La Salle University
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLEN 80
#define PRINT

void stripLeadingWhitespace(char str[])
{
  int nonSpaceIdx = 0, i = 0;

  // Get idx of first non-whitespace character
  while (isspace(str[nonSpaceIdx]))
    nonSpaceIdx++;

  // Shift string
  while (str[i] != 0)
  {
    str[i] = str[nonSpaceIdx];
    i++;
    nonSpaceIdx++;
  }
}

void stripTrailingWhitespace(char str[])
{
  int i = strlen(str) - 1;

  // Starting from the last character, set to 0 if whitespace character
  while (isspace(str[i]))
  {
    str[i] = 0;
    i--;
  }
}

void stripWhitespace(char str[])
{
  // stripLeadingWhitespace(str);
  stripTrailingWhitespace(str);
}

int main(int argc, char *argv[])
{
  FILE *fp1, *fp2;
  int temp;
  int ctr = 0, diff_ctr = 0;
  // int retval;
  char expected[MAXLEN], actual[MAXLEN];

  if (argc != 3)
  {
    fprintf(stderr, "Usage: bbtest <sample file> <your file>\n");
    return 1;
  }

  /* open the text files */
  fp1 = fopen(argv[1], "r"); /* correct file (expected) */
  fp2 = fopen(argv[2], "r"); /* student's file (actual) */

  if (fp1 == NULL)
  {
    printf("\n");
    fprintf(stderr, "bbtest.exe: Fatal error, %s file NOT FOUND. Terminating...\n\n", argv[1]);
    exit(1);
  }

  if (fp2 == NULL)
  {
    printf("\n");
    fprintf(stderr, "bbtest.exe: Fatal error, %s file NOT FOUND. Terminating...\n\n", argv[2]);
    exit(1);
  }

  /* compare pairs of tokens */

#ifdef PRINT
  printf("+----------+----------------------------------+-----------------------------------+\n");
  printf("|          |  %-30s  |  %-30s   |\n", "EXPECTED", "ACTUAL");
  printf("+----------+----------------------------------+-----------------------------------+\n");
#endif

  while (!feof(fp1))
  {
    // retval = fscanf(fp1, "%s", expected);
    // fscanf(fp2, "%s", actual);

    // if (retval != 1) // no more value
    //   break;

    fgets(expected, sizeof(expected), fp1);
    fgets(actual, sizeof(actual), fp2);

    stripWhitespace(expected);
    stripWhitespace(actual);

    ctr++;

    temp = (strcmp(expected, actual) != 0);
    if (temp)
    {
      diff_ctr++;
#ifdef PRINT
      printf("| [%5d]  |  %-30s  |  %-30s   |  RED_FLAG!\n", ctr, expected, actual);
#endif
    }
    else
    {
#ifdef PRINT
      printf("| [%5d]  |  %-30s  |  %-30s   |\n", ctr, expected, actual);
#endif
    }
  }

#ifdef PRINT
  printf("+----------+----------------------------------+-----------------------------------+\n");
  printf("\nBLACK BOX TEST RESULT(S):\n");
#endif
  printf("           Differences = %d.\n", diff_ctr);
  // float score = (ctr - diff_ctr) / (float)ctr;
  // printf("           Score = %d / %d (%.2f)\n", ctr - diff_ctr, ctr, score);
  // printf("           Normalized = %.2f\n", score * 5);

  /*
      NOTE: if diff_ctr is 0, then it means that there is no difference.
            If diff_ctr > 0 then there is a difference between expected and actual results.
  */

  fclose(fp1);
  fclose(fp2);

  return 0;
}