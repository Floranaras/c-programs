#include <stdio.h>
#include <string.h>
#define INPUT  "coord.txt"
#define MAX_COORDS (100)

struct pointTag
{
    int x;
    int y;
};

typedef struct pointTag pointType;

int main ()
{
    FILE* fp; 
    pointType coords[MAX_COORDS];
    int j = 0;
    int k = 0;

    fp = fopen (INPUT ,"r");

    if (fp == NULL)
    {
        printf("Error opening data\n");
    }

    else 
    {
        while (j < MAX_COORDS && fscanf(fp, "%d %d", &coords[j].x, &coords[j].y) == 2) 
            j++;
        fclose(fp);

        for (k = 0; k < j; k++)
            printf("%d %d\n", coords[k].x, coords[k].y);
    }
    return 0;
}
