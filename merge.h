#pragma once
#include "functions.h"

void merge(int* arr, int l, int m, int r)
{
	//��������� ������ ����� � ������ ����� �������
	int nl = m - l + 1;
	int nr = r - m;

	//������� ��������� �������
	int* left = new int[nl];
	int* right = new int[nr];

	//�������� ������ �� ��������� �����
	for (int i = 0; i < nl; i++)
		left[i] = arr[l + i];

	for (int j = 0; j < nr; j++)
		right[j] = arr[m + j + 1];


	//�������������� �������
	int i = 0, j = 0;
	int k = l;//������ ����� �����

	//���������� ����������� �������� ������� �� ������� ������
	while (i < nl && j < nr)
	{
		if (left[i] < right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}

	//���������� ���������� �������� � ����� �����
	while (i < nl)
		arr[k++] = left[i++];

	//���������� ���������� �������� � ������ �����
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
