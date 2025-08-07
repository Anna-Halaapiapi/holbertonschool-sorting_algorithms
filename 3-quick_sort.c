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
 * Return: index of pivot after partitioning
 */

int partition(int array[], int low, int high)
{
	int pivot = array[high]; /* set pivot to last array element */
	int i = (low - 1); /* set i to index of smaller element */
	int j; /* loop counter */

	for (j = low; j <= high - 1; j++)
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
 * quick_sort_recur - recursive quicksort
 * @array: array of integers
 * @low: starting index
 * @high: end index
 *
 * Return: void
 */

void quick_sort_recur(int *array, int low, int high)
{
	int part_index;

	if (low < high)
	{
		part_index = partition(array, low, high);
		quick_sort_recur(array, low, part_index - 1);
		quick_sort_recur(array, part_index + 1, high);
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
	if (array == NULL || size < 2)
		return;

	quick_sort_recur(array, 0, size - 1);

}
