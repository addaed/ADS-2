int countPairs1(int *arr, int len, int value)
{
	int count = 0; 
	for (int i = 0; i < len-1; i++)
		for (int j =i+1; j < len; j++)
			if (arr[i] + arr[j] == value)
				count++;
	return count;
}

int countPairs2(int *arr,int len,int value)
{
	int count = 0;
	 for (int i = 0; i < len-1; i++)
	 	for (int j = len-1; j > i; j--)
			if (arr[i] + arr[j] == value)
		 		count++;
	 return count;
}

int countPairs3(int *arr, int len, int value)
{
	int count = 0;
	for (int i = 0; i < len - 1; i++)
	{
		int a = i, b = len;

		while (a < b-1)
		{
			int c = (a + b) / 2;
			if (arr[i] + arr[c] == value)
			{
				count++;
				int j = c+1;
				while (arr[i] + arr[j] == value && j <b)
				{
					count++;
					j++;
				}
				j = cc - 1;
				while (arr[i] + arr[j] == value && j>a)
				{
					count++;
					j--;
				}
				break;
			}
			if (arr[i] + arr[c] > value)
				b = c;
			else
				a = c;
		}
	}
	return count;
}
