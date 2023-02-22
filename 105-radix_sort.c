#include "sort.h"

/**
 * getMax - gets the max value in an array
 *
 * @array: given array
 * @size: size of array
 *
 * Return: largest value
 */

int getMax(int *array, size_t size)
{
	int i;
	int max = 0;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countSort - sorts array using countsort
 *
 * @array: given array
 * @size: size of array
 * @exp: digital positional value
 * @tmp: tmp array
 * @countArray: count array
 */

void countSort(int *array, size_t size, int exp, int *tmp, int *countArray)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = 0; i < 10; i++)
		countArray[i] = 0;

	for (i = 0; i < (int)size; i++)
		countArray[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		countArray[i] += countArray[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		tmp[countArray[(array[i] / exp) % 10] - 1] = array[i];
		countArray[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = tmp[i];
}

/**
 * radix_sort - sorts array using the radix algorithm
 *
 * @array: the array
 * @size: size of array
 */

void radix_sort(int *array, size_t size)
{
	int exp;
	int max = getMax(array, size);
	int *tmp = malloc(sizeof(int) * (int)size);
	int *countArray = malloc(sizeof(int) * (10));

	if (!array || size < 2 || !tmp || !countArray)
	{
		free(tmp);
		free(countArray);
		return;
	}

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp, tmp, countArray);
		print_array(array, size);
	}
	free(tmp);
	free(countArray);
}
