#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 *
 * @list: linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *tmp, *next_node;

	if (list == NULL || *list == NULL)
		return;

	current_node = *list;

	while (current_node != NULL)
	{
		next_node = current_node->next;
		tmp = current_node;
		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;
			if (tmp->prev == NULL)
				*list = tmp;
			else
				tmp->prev->next = tmp;
			print_list(*list);
		}
		current_node = next_node;
	}
}
