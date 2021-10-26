#include "sort.h"
/**
 * insertion_sort_list - sort a list using insertion sort algorithm
 * @list: list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp;
	listint_t *current;
	listint_t *node;

	current = *list;

	if (!list)
		return;

	current = current->next;
	while (current)
	{
		if (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				temp = current->prev;
				node = current->next;
				current->prev = temp->prev;
				current->next = temp;
				if (current->prev != NULL)
					current->prev->next = current;

				temp->prev = current;
				temp->next = node;
				if (node != NULL)
					node->prev = temp;
				if (current->prev == NULL)
					*list = current;
				print_list(*list);
			}
			else
				current = current->next;
		}
		else
			current = current->next;
	}
}
