#include "sort.h"

/**
 * insertion_sort_list - sorts doubly linked list using insertion sort algo
 * @list: pointer to a doubly linked list pointer
 *
 * Return: void (no Return)
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *prev;

	if (!list || !(*list) || !((*list)->next))
		return;

	head = *list;
	while (head)
	{
		if (head->prev)
		{
			prev = head->prev;
			if (head->n < prev->n)
			{
				prev->next = head->next;
				if (prev->next)
					prev->next->prev = prev;
				head->next = prev;
				head->prev = prev->prev;
				prev->prev = head;
				if (head->prev)
					head->prev->next = head;
				else
					*list = head;
				print_list(*list);
				continue;
			}
		}
		head = head->next;
	}
}
