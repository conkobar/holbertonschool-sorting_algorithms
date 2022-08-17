#include "sort.h"
/**
 * quick_sort - sorts an array in ascending order using the quick sort algo
 *
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	lickitysplit(array, 0, size - 1, size);
}

void lickitysplit(int *array, size_t lo, size_t hi, size_t size)
{
	int pie;

	if (lo < hi)
	{
		pie = partition(array, lo, hi, size);
		lickitysplit(array, lo, pie - 1, size);
		lickitysplit(array, pie + 1, hi, size);
	}
}

int partition(int *array, size_t lo, size_t hi, size_t size)
{
	int pivot = array[hi];
	size_t j, i = (lo - 1);

	for (j = lo; j <= hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, array[i], array[j], size);
		}
	}

	swap(array, array[i + 1], array[hi], size);
	return (i + 1);
}

void swap(int *array, size_t x, size_t y, size_t size)
{
	int tmp;

	tmp = array[x];
	array[x] = array[y];
	array[y] = tmp;
	print_array(array, size);
}
