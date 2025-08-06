#include "sort.h"
#include <stddef.h>

/**
 * insertion_sort_list - sorts list in ascending order using insertion sort
 * @list: double pointer to head of doubly linked list
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *unsortedpos = *list;/*store unsorted list pos start at head*/
	listint_t *sortedpos; /* store sorted list position */
	listint_t *pos1, *pos2, *pos3, *pos4;/* store node positions for swap */

	while (unsortedpos != NULL) /* iterate through unsorted part of list */
	{
		sortedpos = unsortedpos->prev; /* update sorted list position */

		while (sortedpos != NULL) /* iterate through sorted list */
		{

			if (unsortedpos->n < sortedpos->n) /* compare values */
			{
				pos1 = sortedpos->prev; /* surrounding node */
				pos2 = sortedpos; /* node to be swapped */
				pos3 = unsortedpos; /* node to be swapped */
				pos4 = unsortedpos->next; /* surrounding node */

				pos1->next = unsortedpos; /* adjust pointers */
				sortedpos->next = pos4;
				sortedpos->prev = unsortedpos;
				unsortedpos->next = sortedpos;
				unsortedpos->prev = pos1;
				pos4->prev = sortedpos;
			}
			sortedpos = sortedpos->prev;/*step back 1 in sortedpos*/
		}
		unsortedpos = unsortedpos->next;/* move to next unsorted node */
	}
}
