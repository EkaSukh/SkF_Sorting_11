#pragma once

#include "functions.h"


void countSort(int* arr, int n)
{
	//шаг 0(опционально): Находим максимальный элемент массива, если нам не известно m
	int max = getMax(arr, n);
	//шаг 1: создаем массив частот размером m
	int* count = new int[max + 1];
	int* output = new int[n];

	for (size_t i = 0; i < max + 1; i++)
		count[i] = 0;

	//шаг 2: подсчитываем частоты
	for (size_t i = 0; i < n; i++)
		count[arr[i]]++;

	//шаг 3: подсчитываем накопленные частоты
	for (size_t i = 1; i < max + 1; i++)
		count[i] += count[i - 1];

	//шаг 4: записываем во временный массив занчения входного
	//использую как индекс значение частоты
	for (size_t i = 0; i < n;i++)
	{
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	for (size_t i = 0; i < n;i++)
		arr[i] = output[i];

	delete[] count;
	delete[] output;
}

void countSort(int* arr, int n, int exp)
{
	int* output = new int[n];
	int count[10] = { 0 }; // выделяем память под массив частот размером 10, так как используем 10-чную систему счисления

	// вычисление разряда элемента arr[i] выполняет выражение 
	// (arr[i] / exp) % 10
	for (int i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;  // вычисляем значение разряда и считаем его частоту

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (int i = 0; i < n; i++)
		arr[i] = output[i];
}
