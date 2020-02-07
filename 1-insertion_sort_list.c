#include "sort.h"

/**
 * insertion_sort_list - Sorts doubly linked list of integers in acending order.
 * @list: double pointer
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *present, *owner, *node_owner;
	int tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	present = (*list)->next;
	while (present != NULL)
	{
		owner = present;
		while (owner->prev != NULL)
		{
			tmp = 0;
			if (owner->n < owner->prev->n)
			{
				if (owner->prev->prev != NULL)
				owner->prev->prev->next = owner;
				owner->prev->next = owner->next;
				node_owner = owner->prev->prev;
				owner->prev->prev = owner;
				if (owner->next != NULL)
				owner->next->prev = owner->prev;
				owner->next = owner->prev;
				owner->prev = node_owner;
				tmp = 1;
				if (owner->prev == NULL)
				*list = owner;
				print_list(*list);
			}
			if (tmp == 0)
				owner = owner->prev;
		}
		present = present->next;
	}
}
