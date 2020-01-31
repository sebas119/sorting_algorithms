#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Doubly linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *actual, *last;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	actual = (*list)->next;
	while (actual != NULL)
	{
		last = actual->next;
		while (actual->prev != NULL && actual->n < actual->prev->n)
			swapl(actual->prev, actual, list);
		actual = last;
	}
}


/**
 *	swapl - Swap two elements of an doubly linked list
 *	@first: First element to swap.
 *	@second: Second element to swap.
 *	@head: Head of the list
 */
void swapl(listint_t *first, listint_t *second, listint_t **head)
{
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	if (first->prev != NULL)
		first->prev->next = second;
	first->prev = second;

	if (second->prev == NULL)
		*head = second;
	print_list(*head);
}
