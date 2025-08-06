#include "sort.h"

/**
 * swap - swaps values of integers a and b
 * @a: pointer to integer a
 * @b: pointer to integer b
 *
 * Return: void
 */

void swap(int* a, int* b)
{
	int temp = *a; /* temp variable to store int a */
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
	int i = 0; /* outer loop counter */
	int j = 0; /* inner loop counter */
	int swapped; /* flag - 0 (false) 1 (true) */

	while (i < size) /* repeat passes through array */
	{
		swapped = 0; /* reset swapped to false for each pass */
		j = 0; /* reset inner loop to start for each pass */

		while (j < size - i - 1) /* compare adjacent ints */
		{
			if (array[j] > array[j + 1]) /* ints aren't in order */
			{
				swap(&array[j], &array[j + 1]); /* swap ints */
				swapped = 1; /* change swapped to true */
			}
			j = j + 1; /* move to next pair */
		}

		if (swapped == 0) /* if no swaps - array is sorted */
		break;

		i = i + 1; /* increment outer loop counter */
	}
}
