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
 * @high: ending index of array
 *
 * Return: index of pivot after partitioning
 */

int partition(int array[], int low, int high, size_t size)
{
	int pivot = array[high]; /* set pivot to last array element */
	int i = (low - 1); /* track positions for swapping smaller elements */
	int j; /* loop counter */

	for (j = low; j <= high - 1; j++) /* loop through elements */
	{
		/* if current element is <= pivot */
		if (array[j] <= pivot)
		{
			i++; /* increment index of smaller element */
			swap(&array[i], &array[j]); /* perform swap */
			print_array(array, size); /* print array */

		}
	}
	swap(&array[i + 1], &array[high]); /* put pivot in correct position */
	print_array(array, size); /* print array */
	return (i + 1); /* return index of pivot */
}

/**
 * quick_sort_recur - recursive quicksort for subarrays
 * @array: array of integers
 * @low: starting index
 * @high: ending index
 *
 * Return: void
 */

void quick_sort_recur(int *array, int low, int high, size_t size)
{
	int part_index;

	if (low < high)
	{
		/* partition array, get pivot index */
		part_index = partition(array, low, high, size);
		/* recursive quicksort on left subarray */
		quick_sort_recur(array, low, part_index - 1, size);
		/* recursive quicksort on right subarray */
		quick_sort_recur(array, part_index + 1, high, size);
	}
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
	/* check if array is NULL or size < 2 */
	if (array == NULL || size < 2)
		return;

	/* start recursive quicksort on original array */
	quick_sort_recur(array, 0, size - 1);
}
