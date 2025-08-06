#include "sort.h"
#include <stddef.h>

/**
 * swap - swaps values of integers a and b
 * @a: pointer to integer a
 * @b: pointer to integer b
 *
 * Return: void
 */

void swap(int *a, int *b)
{
	int temp = *a; /* temp var to store int a */
	*a = *b; /* store b in a */
	*b = temp; /* store a in b */
}

/**
 * bubble_sort - sorts array of ints in ascending order using bubble sort
 * @array: pointer to array of integers
 * @size: size of array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0; /* counter for full passes through array */
	size_t j = 0; /* counter for inner loop comparison in each pass */

	if (size < 2) /* if array < 2 - do not sort */
		return;

	while (i < size) /* perform full pass through array */
	{
		j = 0; /* reset inner loop counter */

		while (j < size - i - 1) /* compare adjacent ints */
		{
			if (array[j] > array[j + 1]) /* if int a > int b */
			{
				swap(&array[j], &array[j + 1]); /* swap ints */
				print_array(array, size); /* print array */
			}
			j = j + 1;
		}
		i = i + 1;
	}
}
