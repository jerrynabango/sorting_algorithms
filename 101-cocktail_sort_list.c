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
	bool swapped;
	listint_t *next, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	swapped = true;

	while (swapped)
	{
		swapped = false;
		current = *list;
		for ( ; current->next; current = next)
		{
			next = current->next;
			if (current->n > next->n)
			{
				swap(list, current, next);
				print_list(*list);
				swapped = true;
			}
		}
		if (!swapped)
			break;
		swapped = false;

		for ( ; current->prev; current = current->prev)
		{
			next = current->prev;
			if (current->n < next->n)
			{
				swap(list, next, current);
				print_list(*list);
				current = current->next;
				swapped = true;
			}
		}
	}
}
