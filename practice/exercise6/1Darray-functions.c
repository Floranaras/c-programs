
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

void removeDuplicates()
{

}

void addUnique(int* src, int* dst, int* size)
{
	int i, j, found = 0;

	for (i = 0; i < *size; i++)
	{
		found = 0;

		for (j = 0; j < *size; j++)
		{
			if (src[i] == dst[j])
			{
				found = 1;
			}
		}
		
		if (!found)
		{
			dst[*size - 1] = src[i];
			*(size)++;
		}

	}
}
