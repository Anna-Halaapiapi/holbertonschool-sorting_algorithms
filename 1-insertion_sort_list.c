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

	/* if no pointer given or list empty */
	if (list == NULL || *list == NULL)
		return;

	while (unsortedpos != NULL) /* iterate through unsorted part of list */
	{
		sortedpos = unsortedpos->prev; /* update sorted list position */
		next = unsortedpos->next;/* save correct unsortedpos */

		/* iterate through sorted list */
		while (sortedpos != NULL && unsortedpos->n < sortedpos->n)
		{
				pos1 = sortedpos->prev; /* surrounding node */
				pos4 = unsortedpos->next; /* surrounding node */

				/* remove unsortedpos */
				if (unsortedpos->prev != NULL)
				{
				unsortedpos->prev->next = unsortedpos->next;
				}
				if (unsortedpos->next != NULL)
				unsortedpos->next->prev = unsortedpos->prev;

				/* insert unsortedpos in correct pos */
				unsortedpos->prev = pos1;
				unsortedpos->next = sortedpos;
				sortedpos->prev = unsortedpos;

				if (pos1 != NULL) /* if pos1 isn't head->prev */
				{
					pos1->next = unsortedpos; /* upd. ptr */
				}

				else /* if pos1 is at head->prev */
				{
					*list = unsortedpos; /* update head */
				}
				print_list(*list);/* print list after each swap*/
				break;
		}
		unsortedpos = next;/* move to next unsorted node */
	}
}
