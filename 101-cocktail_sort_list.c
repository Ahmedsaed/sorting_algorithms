#include "sort.h"


/**
 * swap_nodes - swaps two nodes
 *
 * @node1: first node
 * @node2: second node
 * @list: doubly linked list
 */
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
	listint_t *tmp = NULL;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next)
		node2->next->prev = node1;
	tmp = node2->next;
	node2->next = node1;
	node2->prev = node1->prev;
	node1->next = tmp;
	node1->prev = node2;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 *
 * @list: doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp = NULL;
	int swapped = 1;

	if (!list || !(*list) || !(*list)->next)
		return;

	tmp = *list;
	while (swapped)
	{
		swapped = 0;
		while (tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				swap_nodes(tmp, tmp->next, list);
				swapped = 1;
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (tmp->prev)
		{
			if (tmp->n < tmp->prev->n)
			{
				swap_nodes(tmp->prev, tmp, list);
				swapped = 1;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
	}
}
