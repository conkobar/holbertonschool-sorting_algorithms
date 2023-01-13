#include "sort.h"

/**
 * merge_sort - Implementation of top-down merge sort algorithm
 * @array: pointer to array of integers to be sorted
 * @size: size of given array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *tmp_arr = malloc(sizeof(array[0]) * size);

	copy_array(array, 0, size, tmp_arr);
	recur_split(tmp_arr, 0, size, array);
	free(tmp_arr);
}

/**
 * print_my_array - Prints an array between two indices
 * @array: Array to print
 * @start: Starting index of array to print
 * @end: Ending index of array to print
 *
 * Return: void
 */
void print_my_array(int *array, int start, int end)
{
	int i;

	for (i = start; i < end; i++)
	{
		printf("%d", array[i]);
		if (i < end - 1)
			printf(", ");
		else
			printf("\n");
	}
}

/**
 * copy_array - Copies from array to tmp_arr
 * @array: Original Array
 * @start: Starting index to copy
 * @end: End index to copy
 * @tmp_arr: Holds the copied array
 *
 * Return: void
 */
void copy_array(int *array, int start, int end, int *tmp_arr)
{
	int i;

	for (i = start; i < end; i++)
		tmp_arr[i] = array[i];
}

/**
 * recur_split - Splits the array recursively until it is of size 1
 * @tmp_arr: Temporary array, copy of given array
 * @array: Given array to sort
 * @start: Starting index of array to split
 * @end: End index of array to split
 *
 * Return: Void
 */
void recur_split(int *tmp_arr, int start, int end, int *array)
{
	int mid = (end + start) / 2;

	if (end - start <= 1)
		return;

	recur_split(array, start, mid, tmp_arr);
	recur_split(array, mid, end, tmp_arr);
	time_to_merge(tmp_arr, start, mid, end, array);
}

/**
 * time_to_merge - Takes all of the split arrays, compares and merges
 * @array: Given array, one element long to start
 * @start: starting index of array
 * @mid: middle index of array
 * @end: ending index of array
 * @tmp_arr: Array to be returned to print
 *
 * Return: Void
 */
void time_to_merge(int *array, int start, int mid, int end, int *tmp_arr)
{
	int i = start;
	int j = mid;
	int k = start;

	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || array[i] <= array[j]))
		{
			tmp_arr[k] = array[i];
			i++;
		}
		else
		{
			tmp_arr[k] = array[j];
			j++;
		}
	}

	printf("Merging...\n[left]: ");
	print_my_array(array, start, mid);
	printf("[right]: ");
	print_my_array(array, mid, end);
	printf("[Done]: ");
	print_my_array(tmp_arr, start, end);
}
