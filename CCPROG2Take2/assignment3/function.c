int findIdx(int arr[], int size)
{
	int j = 0;

	while(j < size && arr[j] != 0)
	{
		j++;
	}
		
	return j;
}

int isFound(int arr[], int val, int idx)
{
	int j = 0;

	while (j < idx && val != arr[j])
	{
		j++;
	}

	if (j == idx)
	{
		return 0;
	}

	return 1;
}

void getUnion(int setA[], int setB[], int size)
{
	int j, aIdx, bIdx;

	aIdx = findIdx(setA, size);
	bIdx = findIdx(setB, size);

	for (j = 0; j < bIdx && aIdx < size; j++)
	{
		if (!isFound(setA, setB[j], aIdx))
		{
			setA[aIdx] = setB[j];
			aIdx++;
		}
	}
}

