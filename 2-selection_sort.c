#include "sort.h"
/**
 * selection_sort - sorts array in ascending order using selection sort algo
 *
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx;
	int tmp;

	for (i = 0; i < size; i++)
	{
		idx = i;
		for (j = idx; j < size; j++)
		{
			if (array[j] < array[idx])
				idx = j;
		}


		if (idx != i)
		{
			tmp = array[i];
			array[i] = array[idx];
			array[idx] = tmp;
			print_array(array, size);
		}
	}
}
