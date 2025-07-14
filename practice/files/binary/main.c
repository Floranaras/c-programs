#include <stdio.h>
#include <string.h>

#define MAX (5)

typedef char String7[8];
typedef char String4[5];

struct courseTag
{
    char strCourse[8];
    float fUnit;
    char strSection[5];
};

typedef struct courseTag courseType;

void readFromFile (courseType *courses, int size)
{
    FILE *fp;
//    int j;
    fp = fopen ("course.dat", "rb");
    fread (courses, sizeof(courseType), size, fp);
    fseek(fp, 0, SEEK_SET);
    fclose (fp);

}

void saveToFile (courseType *courses, int size)
{
    FILE *fp;
    fp = fopen ("course.dat", "wb");
    fwrite (courses, sizeof(courseType), size, fp);
    fclose (fp);

}

void displayCourse (courseType *courses)
{
    printf("%s (%s) %.1f\n", courses->strCourse, courses->strSection, courses->fUnit);
}

void displayAll (courseType *courses, int size)
{
    int j;
    printf("\nCourse Section Units\n");
    for (j = 0; j < size; j++)
    {
        displayCourse(courses + j);
    }
}

int main ()
{
    int j;
    courseType courses[5];
    courseType out_courses[5];
    String7 courselist[MAX] = {"CCPROG1", "CCPROG2","CCPROG3", "CCINFOM", "CSINTSY"};
    String4 sectionlist[MAX] = {"S11", "S12","S13","S14","S15"};

    for (j = 0; j < 5; j++)
    {
        strcpy(courses[j].strCourse, courselist[j]);
        strcpy(courses[j].strSection, sectionlist[j]);
		courses[j].fUnit = 3.0;
    }

    saveToFile(courses, MAX);
    for (j = 0; j < 5; j++)
    {
        out_courses[j].fUnit = 1.0;
    }
    readFromFile(out_courses, MAX);
    displayAll(out_courses, MAX);
    return 0;
}
