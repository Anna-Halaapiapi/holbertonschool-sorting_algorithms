#include "sort.h"
#include <stddef.h>

/**
 * swap - swaps values of int a and int b
 * @a: integer a
 * @b: integer b
 *
 * Return: void
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - sets last element as pivot and partitions array
 * @array: the array to partition
 * @low: starting index of array
 * @high:ending index of array
 *
 * Return: void
 */

int partition(int array[], int low, int high)
{
	int pivot = arr[high]; /* set pivot to last array element */
	int i = (low - 1); /* set i to index of smaller element */
	int j; /* loop counter */

	for (int j = low; j <= high - 1; j++)
	{
		/* if current element is <= pivot */
		if (array[j] <= pivot)
		{
			i++; /* increment index of smaller element */
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * quick_sort - sorts array of ints in ascending order using quick sort
 * with the Lomuto partition scheme
 * @array: array of integers
 * @size: size of array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	int low, high, partindex;

	if (low < high)
	{
	partindex = partition(array, low, high);

	quick_sort(array, size);
	quicksort(array, size);
	}
}
