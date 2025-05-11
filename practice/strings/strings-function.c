#define WORD "POP"
#define SIZE (13) 
#define PASSWORD "password"
#define NUM_FRIENDS (5)

typedef char String7[8];
typedef char String10[11];
typedef char String30[31];


void problemOne()
{
    String7 subject1 = "COMPRO2";
    String7 subject2 = "FORMDEV";
    String30 sentence;

    printf("%lu\n", strlen("Hello World!"));
    printf("%lu\n", strlen("X"));
    printf("%lu\n", strlen("X\n"));
    printf("%lu\n", strlen(" "));
    printf("%lu\n", strlen(""));
    printf("%lu\n", strlen(strcpy(sentence,"Nanja kore???")));
    printf("%lu\n", strlen(strcat(strcpy(sentence,"A*B*"),"C*D*F")));
    printf("%d\n", strcmp(subject1,subject2));
    printf("%d\n", strcmp(subject2,subject1));
    printf("%d\n", strcmp("formdev",subject1));
    printf("%d\n", strcmp(subject2,"compro2"));
    printf("%d\n", strcmp(subject2,"formdev"));
}

void PrintReversed(char *str)
{
    int n = strlen(str);

    while (n >= 0)
    {
        printf("%c", str[n]);
        n--;
    }
    
    printf("\n");
}

int IsPalindrone(char* str)
{
    int i;
    int n = strlen(str);
    char rev[n+1];

    for (i = 0; i <= n; i++)
    {
        rev[i] = str[n - 1 - i];
    }

    rev[n] = '\0';
 
   return (strcmp(str,rev) == 0) ? 1 : 0;
}

char *Capitalize(char *str)
{
    int n = strlen(str);
    int i;

    for (i = 0; i < n + 1; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
    
    str[n] = '\0';

    return str;
}

int GetPassword(char *password)
{
    int flag = 0;
    int count = 0;

    do
    {
        printf("Input New Password: ");
        scanf("%s", password);

        if (strcmp(password, PASSWORD) == 0)
        {
            printf("You're in\n");
            flag = 1; 
        }

        else 
        {
            count++;
            if (count == 3)
            {
                printf("Too many failed attempts\n");
            }
            else
            {
                printf("Please try again\n");
            }
        }

    } while (!flag && count < 3);

    return flag;
}

void SortNicknames(String10 friends[], int n) 
{

    int i, j, min_idx;
    String10 temp;

    for (i = 0; i < n; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(friends[j], friends[i]) < 0)
            {
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            strcpy(temp, friends[i]);
            strcpy(friends[i], friends[min_idx]);
            strcpy(friends[min_idx], temp);
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%s ", friends[i]);
    }

    printf("\n");
}