#include "sort.h"

/**
 * swap - swaps two integers
 *
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify - heaps a subtree rooted with idx in arr
 *
 * @arr: array to heapify
 * @size: size of the array
 * @i: index
 * @size_int: size of the array as int
 */
void heapify(int *arr, int size_int, int i, size_t size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size_int && arr[left] > arr[largest])
		largest = left;

	if (right < size_int && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		print_array(arr, size);
		heapify(arr, size_int, largest, size);
	}
}

/**
 * heap_sort - sorts an array of ints
 *
 * @array: array to sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int size_int = (int)size;

	for (i = size_int / 2 - 1; i >= 0; i--)
		heapify(array, size_int, i, size);

	for (i = size_int - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i != 0)
			print_array(array, size);
		heapify(array, i, 0, size);
	}
}
