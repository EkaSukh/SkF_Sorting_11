#pragma once
#include "functions.h"

void merge(int* arr, int l, int m, int r)
{
	//Вычисляем размер левой и правой части массива
	int nl = m - l + 1;
	int nr = r - m;

	//создаем временные массивы
	int* left = new int[nl];
	int* right = new int[nr];

	//копируем данные во временные части
	for (int i = 0; i < nl; i++)
		left[i] = arr[l + i];

	for (int j = 0; j < nr; j++)
		right[j] = arr[m + j + 1];


	//инициализируем индексы
	int i = 0, j = 0;
	int k = l;//начало левой части

	//записываем минимальыне элементы обратно во входной массив
	while (i < nl && j < nr)
	{
		if (left[i] < right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}

	//записываем оставшиеся элементы в левой части
	while (i < nl)
		arr[k++] = left[i++];

	//записываем оставшиеся элементы в правой части
	while (j < nr)
		arr[k++] = right[j++];

	delete[] left;
	delete[] right;

}

void mergeSort(int* arr, int const begin, int const end)
{
	if (begin >= end)
		return;
	auto mid = begin + (end - begin) / 2;
	mergeSort(arr, begin, mid);
	mergeSort(arr, mid + 1, end);

	merge(arr, begin, mid, end);
}
