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
	listint_t *sorted = NULL;
	listint_t *curr = *list;
	listint_t *next, *current_sorted;

	if (*list == NULL)
		return;

	while (curr != NULL)
	{
	next = curr->next;
		if (sorted == NULL || sorted->n >= curr->n)
		{
			curr->next = sorted;

		if (sorted != NULL)
		sorted->prev = curr;

		sorted = curr;
		sorted->prev = NULL;
		}

	else
	{
		current_sorted = sorted;
		while (current_sorted->next != NULL &&
			current_sorted->next->n < curr->n)
		{
			current_sorted = current_sorted->next;
		}

		curr->next = current_sorted->next;

		if (current_sorted->next != NULL)
			current_sorted->next->prev = curr;

		current_sorted->next = curr;
		curr->prev = current_sorted;
	}
		*list = sorted;
		print_list(*list);
		curr = next;
	}
}
