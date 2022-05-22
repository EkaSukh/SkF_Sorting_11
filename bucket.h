#pragma once
#include "functions.h"
#include "count.h"
#include <vector>

struct bucket {
    int count; // количество элементов в корзине
    int* data; // массив элементов корзины
};

/*
void bucketSort(int* arr, int n)
{
    std::vector<int> b[10];

    int exp = getExp(getMax(arr, n));

    for (int i = 0; i < n; i++)
    {
        int bi = arr[i] / exp;
        b[bi].push_back(arr[i]);

    }

    for (int i = 0; i < 10; i++)
        countSort(&b[i][0], b[i].size());

    int index = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}
*/

void bucketSort(int* arr, const int n)
{
    struct bucket buckets[10];
    // вычисляем значение экспоненты
    int exp = getExp(getMax(arr, n));

    for (int i = 0; i < 10; i++)
    {
        buckets[i].count = 0;
        buckets[i].data = new int[n];
    }
    for (int i = 0; i < n; i++) {
        int bi = arr[i] / exp; // вычисляем индекс корзины
        buckets[bi].data[buckets[bi].count++] = arr[i]; // добавляем элемент в корзину
    }

    int index = 0;
    for (int i = 0; i < 10; i++)
    {
        countSort(buckets[i].data, buckets[i].count);
        for (int j = 0; j < buckets[i].count; j++)
            arr[index++] = buckets[i].data[j];
    }

}
