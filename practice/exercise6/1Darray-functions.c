
int isEqual(int *src, int *dst, int size)
{
    int i = 0, flag = 1;

    while (i < size && flag)
    {
        if (src[i] != dst[i])
            flag = 0;

        i++;
    }

    return flag;
}

