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
	size_t i, j, min_index; /* loop counters & min element index */
	int temp; /* temp var used in swap */

	if (array == NULL || size < 2) /* array is NULL or size < 2 */
		return;

	for (i = 0; i < size - 1; i++) /*loop through each element except last*/
	{
		min_index = i; /* start with current position as min index */

		/* loop through unsorted list portion & find actual min */
		for (j = i + 1; j < size; j++)
		{
			/* if smaller number is found */
			if (array[j] < array[min_index])
			{
				min_index = j; /* update min index */
			}
		}

		if (min_index != i) /* if smaller number was found */
		{
			temp = array[i]; /* perform swap & print list */
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
