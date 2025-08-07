#include "sort.h"
#include <stddef.h>

/**
 * selection_sort - sorts array of ints in ascending order using selection sort
 * @array: array of integers
 * @size: size of array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int min_index, temp;

	while (i < size)
	{
		min_index = i;

		while (j < size)
		{
			j = i + 1;
			j = j + 1;
		if (array[j] < array[min_index])
			{
				min_index = j;
				print_array(*array, size);
			}
		}
		i = i + 1;
	}

		temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
}
