#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int solution(int A[], int N, int B[], int M);
int Minchanges(int SumBig, int SumSmall, int countSmall[], int countBig[]);


//int Minchanges(int SumBig, int SumSmall, int countSmall[], int countBig[]);


int solution(int A[], int N, int B[], int M)
{
	int sumA = 0;
	int sumB = 0;
	int res, gap, i, j;
	int countA[6] = { 0,0,0,0,0,0 };
	int countB[6] = { 0,0,0,0,0,0 };

	for (i = 0; i < N; i++)
	{
		sumA += A[i];
		countA[A[i] - 1]++;
	}
	for (j = 0; j < M; j++)
	{
		sumB += B[j];
		countB[B[j] - 1]++;
	}
	if (sumA > sumB)
	{
		gap = sumA - sumB;
		res = Minchanges(sumA, sumB, countB, countA);
		return res;
	}
	else if (sumB > sumA)
	{
		gap = sumB - sumA;
		res = Minchanges(sumB, sumA, countA, countB);
		return res;
	}
	return -1;
}

	int Minchanges(int SumBig, int SumSmall, int countSmall[], int countBig[])
{
	int i = 5;
	int j;
	int NumOfChanges = 0;
	while (SumBig > SumSmall)
	{
		for (j = 0; j < countBig[i]; j++)
		{
			SumBig = SumBig - i;
			NumOfChanges++;
		}
		i--;
		if (i == 0)
		{
			break;
		}
	}
	i = 5;
	while (SumBig > SumSmall)
	{

		for (j = 0; j < countSmall[i]; j++)
		{
			SumSmall = SumSmall + i;
			NumOfChanges++;
		}
		i--;
		if (i == 0)
		{
			break;
		}
	}
	if (SumBig <= SumSmall)
	{
		return NumOfChanges;
	}
	if (SumSmall < SumBig)
	{
		return -1;
	}
	return NumOfChanges;
}

