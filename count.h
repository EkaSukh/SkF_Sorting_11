#pragma once

#include "functions.h"


void countSort(int* arr, int n)
{
	//��� 0(�����������): ������� ������������ ������� �������, ���� ��� �� �������� m
	int max = getMax(arr, n);
	//��� 1: ������� ������ ������ �������� m
	int* count = new int[max + 1];
	int* output = new int[n];

	for (size_t i = 0; i < max + 1; i++)
		count[i] = 0;

	//��� 2: ������������ �������
	for (size_t i = 0; i < n; i++)
		count[arr[i]]++;

	//��� 3: ������������ ����������� �������
	for (size_t i = 1; i < max + 1; i++)
		count[i] += count[i - 1];

	//��� 4: ���������� �� ��������� ������ �������� ��������
	//��������� ��� ������ �������� �������
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
	int count[10] = { 0 }; // �������� ������ ��� ������ ������ �������� 10, ��� ��� ���������� 10-���� ������� ���������

	// ���������� ������� �������� arr[i] ��������� ��������� 
	// (arr[i] / exp) % 10
	for (int i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;  // ��������� �������� ������� � ������� ��� �������

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (int i = 0; i < n; i++)
		arr[i] = output[i];
}
