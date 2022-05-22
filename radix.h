#pragma once
#include "functions.h"
#include "count.h"

void radixSort(int* arr, int n)
{
    int m = getMax(arr, n); // находим максимальное число
    // выполняем сортировку массива, пока не дойдем до старшего разряда наибольшего числа 

    int exp = 1;
    int orders = m / 10;
    for (int j = 0; j <= orders; ++j)
    {
        countSort(arr, n, exp);
        exp *= 10;
    }
}