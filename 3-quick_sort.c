#include "sort.h"
/**
 * quick_sort - sorts an array in ascending order using the quick sort algo
 *
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	lickity_split(array, 0, (size - 1), size);
}

/**
 * lickity_split - recursively quicksort with Lomuto partition
 *
 * @array: array to sort
 * @lo: starting index
 * @hi: ending index
 * @size: size of array
 *
 * Return: sorted array
 */
int *lickity_split(int *array, int lo, int hi, int size)
{
	int i, j, pie;

	if (lo <= hi)
	{
		j = lo;
		pie = array[hi];

		for (i = lo; i < hi; i++)
		{
			if (array[i] <= pie)
			{
				if (i != j)
				{
					freaky_friday(array, i, j);
					print_array(array, size);
				}
				j++;
			}
		}

		if (j != hi)
		{
			freaky_friday(array, hi, j);
			print_array(array, size);
		}

		lickity_split(array, lo, j - 1, size);
		lickity_split(array, j + 1, hi, size);
	}

	return (array);
}

/**
 * freaky_friday - swaps elements of an array
 *
 * @array: array
 * @jamie: thing 1
 * @lindsay: thing 2
 */
void freaky_friday(int *array, int jamie, int lindsay)
{
	int tmp;

	tmp = array[jamie];
	array[jamie] = array[lindsay];
	array[lindsay] = tmp;
}
