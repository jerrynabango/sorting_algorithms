#include "sort.h"

/**
  * swap - Function to swap elements
  *
  * @list: Indicates a pointer to a list of pointers to elements
  *
  * @previous: Indicates prev ptr to elements in the list b4 being cock_sort
  *
  * @next: Indciates next pointer to elements in the list b4 being cock_sort
  *
  * Return: Nothing
  */
void swap(listint_t **list, listint_t *previous, listint_t *next)
{
	listint_t *swap_element;

	swap_element = previous->prev;
	if (swap_element)
	{
		swap_element->next = next;
	}
	else
	{
		*list = next;
	}
	next->prev = swap_element;

	previous->prev = next;
	previous->next = next->next;
	next->next = previous;
	if (previous->next != NULL)
	{
		previous->next->prev = previous;
	}
	previous = swap_element;
}

/**
  * cocktail_sort_list - doubly lnd ls of int's asc with Cocktail shaker sort
  *
  * @list: ls of int's asc from 1st to last element of list & viceversa
  *
  * Return: Nothing
  */
void cocktail_sort_list(listint_t **list)
{
	listint_t *next, *i;
	bool cock_sort = true;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	cock_sort = true;

	for (; cock_sort; )
	{
		cock_sort = false;
		i = *list;
		for ( ; i->next; i = next)
		{
			next = i->next;
			if (i->n > next->n)
			{
				swap(list, i, next);
				print_list(*list);
				cock_sort = true;
			}
		}
		if (!cock_sort)
			break;
		cock_sort = false;

		for ( ; i->prev; i = i->prev)
		{
			next = i->prev;
			if (i->n < next->n)
			{
				swap(list, next, i);
				print_list(*list);
				i = i->next;
				cock_sort = true;
			}
		}
	}
}
