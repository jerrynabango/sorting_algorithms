#include "sort.h"

/**
  * insertion_sort_list - sorts array of integers in asc using Bubble sort
  *
  * @list: Indicates a pointer to an array of integers in ascending order
  *
  * Return: Nothing
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *next, *i, *j, *h;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	i = *list;
	j = (*list)->next;

	for ( ; j; j = next)
	{
		h = j->prev;
		next = j->next;
		while (h && j->n < h->n)
		{
			h->next = j->next;
			if (j->next)
			{
				j->next->prev = h;
			}
			j->next = h;
			j->prev = h->prev;
			if (h->prev)
			{
				h->prev->next = j;
			}
			else
			{
				i = j;
			}
			h->prev = j;
			h = j->prev;
			print_list(i);
		}
	}
	*list = i;
}
