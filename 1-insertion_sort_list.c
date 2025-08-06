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
	listint_t *next; /* store correct unsortedpos during loop */
	listint_t *pos1, *pos4;/* store surrounding nodes */

	while (unsortedpos != NULL) /* iterate through unsorted part of list */
	{
		sortedpos = unsortedpos->prev; /* update sorted list position */
		next = unsortedpos->next;/* save correct unsortedpos */

		while (sortedpos != NULL) /* iterate through sorted list */
		{

			if (unsortedpos->n < sortedpos->n) /* compare values */
			{
				pos1 = sortedpos->prev; /* surrounding node */
				pos4 = unsortedpos->next; /* surrounding node */

				if (pos1 != NULL) /* if pos1 isn't head->prev */
				{
					pos1->next = unsortedpos; /* upd. ptr */
				}

				else /* if pos1 is at head->prev */
				{
					*list = unsortedpos; /* update head */
				}

				sortedpos->next = pos4; /* adjust pointers */
				sortedpos->prev = unsortedpos;
				unsortedpos->next = sortedpos;
				unsortedpos->prev = pos1;

				if (pos4 != NULL) /* if pos4 isn't tail->next */
				{
					pos4->prev = sortedpos; /* upd. ptr */
				}
			}
			sortedpos = sortedpos->prev;/*step back 1 in sortedpos*/
		}
		unsortedpos = next;/* move to next unsorted node */
	}
}
