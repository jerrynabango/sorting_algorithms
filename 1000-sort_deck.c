#include "deck.h"

/**
 * sort_deck - function that sorts a deck of cards.
 *
 * @deck: Indicates the deck to be sorted by cards
 *
 * Return: nothing
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *a, *j, *h, *b, *sort;
	size_t len;

	len = list_len_deck(*deck);

	if (!deck || !*deck || len < 2)
		return;

	sort = *deck;
	while (sort)
	{
		if (sort->prev && card_value(sort) < card_value(sort->prev))
		{
			a = sort->prev->prev;
			j = sort->prev;
			h = sort;
			b = sort->next;

			j->next = b;
			if (b)
			{
				b->prev = j;
			}
			h->next = j;
			h->prev = a;
			if (a)
			{
				a->next = h;
			}
			else
			{
				*deck = h;
			}
			j->prev = h;
			sort = *deck;
			continue;
		}
		else
			sort = sort->next;
	}
}

/**
 * card_value - Function to return the value of a card
 *
 * @node: Indicates the card type and the card number
 *
 * Return: value of the card type and the card number
 */
int card_value(deck_node_t *node)
{
	int a, kind_val = 0;
	char *val[13] = {"Ace", "2", "3", "4", "5", "6",
	"7", "8", "9", "10", "Jack", "Queen", "King"};
	char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};

	a = 1;
	while (a <= 13)
	{
		if (!_strcmp(node->card->value, val[a - 1]))
		{
			kind_val = a;
		}
		a++;
	}

	for (a = 1; a <= 4; a++)
	{
		if (!_strcmp(kinds[node->card->kind], kinds[a - 1]))
		{
			kind_val = kind_val + (13 * a);
		}
	}

	return (kind_val);
}

/**
 * _strcmp - Function to compare two strings for equality
 *
 * @s1: Indicates the first str to compare against the second str
 *
 * @s2: Indicates the second str to compare against the first str
 *
 * Return: value of the comparison
 */
int _strcmp(const char *s1, const char *s2)
{
	for (; *s1 == *s2; s1++, s2++)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
	}
	return (*s1 - *s2);
}

/**
 * list_len_deck - function returns length of list
 *
 * @list: head of list
 *
 * Return: length
 */
size_t list_len_deck(deck_node_t *list)
{
	size_t len;

	for (len = 0; list; len++)
	{
		list = list->next;
	}
	return (len);
}
