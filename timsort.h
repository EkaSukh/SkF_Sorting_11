#pragma once
#include <iostream>
#include "insert.h"
#include "merge.h"

const int RUN = 32;

void timSort(int* arr, int n)
{
	for (int i = 0; i < n; i += RUN)
		InsertionSort(arr, i, std::min((i + RUN - 1), (n - 1)));

	for (int size = RUN; size < n; size = 2 * size)
	{
		for (int left = 0; left < n; left += 2 * size)
		{
			int mid = left + size - 1;
			int right = std::min((left + 2 * size), (n - 1));

			if (mid < right)
				merge(arr, left, mid, right);
		}
	}
}