/**
  * Problem: Sets
  *
  * Name: 
  * Section:
  *
  */

#include "sets.h"   // Do NOT edit or delete this line
  
/* To Do: (1) Implement Search() to return the index where
          key was first found in A.  If not found, return -1.
   @param key - string to search for in A 
   @param A - array of strings 
   @param nElem - number of elements in A
*/   
int
Search(String key, String A[], int nElem)
{
   int j = 0;

   while (j < nElem && strcmp(A[j], key) != 0)
   {
      j++;
   }

   if (j == nElem)
   {
      return -1;
   }

	return j;  //remember to update the return statement
}

/* To Do: (2) Implement setUnion() that will produce the
           union of unique values from the array A and array B.
           In math, union of sets will be the elements from both
		   sets. Do not assume that the arrays have same number 
		   of elements. The function returns the number of 
		   elements in C.
	
   Reminder: 1. Do NOT use array indexing notation for this function.
    
	         2. You are required to to meaningfully use Search()
  			    as part of the solution for this function.
			  
		Refer to pdf file for the details and complete 
		list of restrictions.	

   @param A first array of strings
   @param B second array of strings
   @param C resulting array to contain the union of A and B
   @param nElemA number of elements in array A
   @param nElemB number of elements in array B
*/
int 
setUnion(String *A, String *B, String *C, int nElemA, int nElemB)
{
   int j;
   int nElemC = 0;

   for (j = 0; j < nElemA; j++)
   {
      if (Search(*(A+j),C, nElemC) == -1)
      {
         strcpy(*(C+j), *(A+j));
         nElemC++;
      }      
   }

   for (j = 0; j < nElemB; j++)
   {
      if (Search(*(B+j), C, nElemC) == -1 && Search(*(B+j), A, nElemA) == -1)
      {
         strcpy(*(C+nElemC), *(B+j));
         nElemC++;
      }
   }
	return nElemC;  //remember to update the return statement
}

/* To Do: (3) Implement setDiff() that will generate contents of 
           array C to contain unique elements from array A that are not in
		   array B. The function returns the number of 
		   elements in C.

   Reminder: You are required to to meaningfully use Search()
  			 as part of the solution for this function.
			  
		Refer to pdf file for the details and complete 
		list of restrictions.	
		   
   @param A first array of strings
   @param B second array of strings
   @param C resulting array to contain elements in A but not in B
   @param nElemA number of elements in array A
   @param nElemB number of elements in array B
   @return number of elements in array C
*/
int
setDiff(String A[], String B[], String C[], int nElemA, int nElemB)
{
   int j;
   int nElemC = 0;

   for (j = 0; j < nElemA; j++)
   {
      if (Search(A[j], B, nElemB) == -1)
      {
        strcpy(C[nElemC], A[j]);
        nElemC++;
      }
   }
	return nElemC;  //remember to update the return statement
}

/* To Do: (4) Implement intersect() that will produce the
           intersection of unique values from the array A and array B.
           In math, intersection of sets will be the common elements only
		   from both sets. Do not assume that the arrays have same number 
		   of elements. The function returns the number of 
		   elements in C.

   Reminder: You are required to to meaningfully use Search()
  			 as part of the solution for this function.
			  
		Refer to pdf file for the details and complete 
		list of restrictions.	
		   
   @param A first array of strings
   @param B second array of strings
   @param C resulting array to contain the intersection of A and B
   @param nElemA number of elements in array A
   @param nElemB number of elements in array B
*/
int
intersect(String A[], String B[], String C[], int nElemA, int nElemB)
{
   int j;
   int nElemC = 0;

   for (j = 0; j < nElemA; j++)
   {
      if (Search(A[j], B, nElemB) != -1 && Search(A[j], C, nElemC) == - 1)
      {
         strcpy(C[nElemC], A[j]);
         nElemC++;
      }
   }
	return nElemC;  //remember to update the return statement
}

/* To Do: (5) Implement substringList() that will produce the collection
           of words from the 1D array B that has substrings equivalent to
		   the string key. The function returns the number of 
		   elements in C.
		   
	Reminder: You are only allowed to use strlen(), strcmp(), strcat(),
  	          and strcpy() from string.h.  No other functions from 
			  string.h can be used.
			  
			  Refer to pdf file for the details and complete 
			  list of restrictions.
		   
   @param key - string to search for within strings in B 
   @param B array of strings
   @param C resulting array to contain strings that have key as substrings
   @param nElemB number of elements in array B
   @return number of elements in array C
*/
int
substringList(String key, String B[], String C[], int nElemB)
{
   int j;
   int k;
   int m;
   int nElemC = 0;
   int keyLen;
   int wordLen;
   int match;
   int nextStr;

   keyLen = strlen(key);

   for (j = 0; j < nElemB; j++)
   {
      wordLen = strlen(B[j]);

      nextStr = 1;
      for (k = 0; k < wordLen && nextStr; k++)
      {
         match = 1;
         for (m = 0; m < keyLen && match; m++)
         {
            if (B[j][k+m] != key[m])
            {
               match = 0;
            }
         }

         if (match && Search(B[j], C, nElemC) == -1)
         {
            strcpy(C[nElemC], B[j]);
            nElemC++;
            nextStr = 0;
         }
      }
   }
   
	return nElemC;  //remember to update the return statement
}