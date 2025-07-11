
int mystrlen(char *str)
{
    int i = 0;
    
    while (str[i] != '\0')
    {
        i++;
    }

    return i;
}

char *mystrcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    
    return dest;
}

char *mystrcat(char *dest, char *src)
{
    int start = mystrlen(dest);
    int i = 0;

    while (src[i] != '\0')
    {
        dest[start + i] = src[i];
        i++;
    }

    return dest;
}

int mystrcmp(char *str1, char *str2)
{

    int i = 0, flag = 0;
	int result;
	int num;


    while (str1[i] != '\0' && str2[i] != '\0' && !flag)
    {
        if (str1[i] != str2[i])
        {
            flag = 1;
        }

        i++; 
    }

	if (flag == 1)
	{
		result = str1[i] - str2[i];

		if (result > 0)
		{
			num = 1;
		}

		else if (result < 0)
		{
			num = -1;
		}
	}

	else if (flag == 0)
	{
		num = 0;	
	}

	return num;
    //return flag = 1 ? str1[i] - str2[i] : 0;
}

#include "mystring-test.c"
