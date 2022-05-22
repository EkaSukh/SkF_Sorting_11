#include <iostream>
#include "functions.h"
#include "bubble.h"
#include "bucket.h"
#include "count.h"
#include "Insert.h"
#include "merge.h"
#include "quick.h"
#include "radix.h"
#include "select.h"
#include "timsort.h"
#include <vector>



int main()
{
	int arr[] = { 3, 5, 1, 2, 1, 0, 5, 4, 6, 7, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	/*
		std::cout << "bubbleSort:\n";
		bubbleSort(arr, n);
		printArray(arr, n);
	*/
	


	
	

	std::cout << "bucketSort:\n";
	bucketSort(arr, n);
	printArray(arr, n);
/*
	std::cout << "countSort:\n";
	countSort(arr, n);
	printArray(arr, n);


	std::cout << "insertSort:\n";
	InsertionSort(arr, n);
	printArray(arr, n);

	std::cout << "mergeSort:\n";
	mergeSort(arr, 0, n-1);
	printArray(arr, n);

	std::cout << "quickSort:\n";
	quickSort(arr, 0, n - 1);
	printArray(arr, n);

	std::cout << "radixSort:\n";
	radixSort(arr, n);
	printArray(arr, n);

	std::cout << "selectionSort:\n";
	selectionSort(arr, n);
	printArray(arr, n);

	std::cout << "TimSort:\n";
	timSort(arr, n);
	printArray(arr, n);
*/
	return 0;
}