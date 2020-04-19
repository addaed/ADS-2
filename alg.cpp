#include "stdafx.h"
#include "iostream"
using namespace std;

int countPairs1(int *arr, int len, int value)
{

int k = 0;
int i, j;
for (i = 0; i< len - 1; i++){
    for (j = i + 1; j<len; j++){
    if ((arr[i] + arr[j]) == value) k++;
    }
}
return k;
}



int countPairs2(int *arr, int len, int value)
{
    int k = 0;
    int lt, rt;
    for (lt = 0; lt < len-2; lt++){
        for (rt = len-1; rt > lt; rt--){
            if ((arr[rt] + arr[lt]) == value)k++;
            else if ((arr[rt] + arr[lt]) < value) break;
        }
    }
    return k;
}

int countPairs3(int arr, int len, int value)
{
        int k = 0;
        for (int i = 0; i < len - 1; i++)
        {
            int a = i, b = len;

            while (a < b - 1)
            {
                int c = (a + b) / 2;
                if (arr[i] + arr[c] == value)
                {    k++;
                    int j = c + 1;
                    while (arr[i] + arr[j] == value && j <b)
                    {
                        k++;
                        j++;
                    }
                    j = c - 1;
                    while (arr[i] + arr[j] == value && j>a)
                    {
                    k++;
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
        return k;
    }

int _tmain(int argc, _TCHAR argv[])
{
    const int SIZE = 6;
    int arr1[SIZE] = { 20, 20,30, 30, 40, 40 };
    int var = 60;

    cout << countPairs3(arr1, SIZE, var) << endl;
    return 0;
}
