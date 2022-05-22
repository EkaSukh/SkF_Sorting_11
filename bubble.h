#pragma once
#include "functions.h"

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n - 1 - i; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
