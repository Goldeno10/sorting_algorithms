#include "sort.h"

/**
 *
 *
 *
 *
 */

void swap(listint_t *sort_l, listint_t *temp)
{
	sort_l->next = temp->next;
	if (temp->next)
		temp->next->prev = sort_l;
	temp->prev = sort_l->prev;
	if (sort_l->prev)
		sort_l->prev->next = temp;
	sort_l->prev = temp;
	temp->next = sort_l;
}


/**
 *
 *
 *
 *
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *sort_l, *h = *list;

	if (!h)
		return;
	/* Navigate to list begining */
	while (h->prev)
		h = h->prev;

	while (h && h->next)
	{
		temp = h->next;
		sort_l = h;
		while (sort_l && sort_l->n > temp->n)
		{
			swap(sort_l, temp);
			print_list(*list);
			sort_l = temp->prev;
		}
		h = h->next;
	}
}
