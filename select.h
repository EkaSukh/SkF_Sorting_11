#pragma once
#include "functions.h"

void selectionSort(int arr[], int n)
{
	int  j, min_idx;

	for (int i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		swap(&arr[min_idx], &arr[i]);
	}
}