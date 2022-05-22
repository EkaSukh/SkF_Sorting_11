#pragma once
#include <iostream>

int getMax(int* arr, int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int getExp(int value) {
	int exp = 1;

	while (value > 10)
	{
		value /= 10;
		exp *= 10;
	}

	return exp;
}

void printArray(int* arr, int n)
{
	for (int j = 0; j < n; j++)
		std::cout << arr[j] << " ";
	std::cout << "\n";

}

