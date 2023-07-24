#include "sort.h"

/**
 * selection_sort - sorts an array of integers in asc using Selection sort
 *
 * @array: Indicates pointer to an array of integers
 *
 * @size: Indictes the size of the array in ascending order of the elements
 *
 * Return: Nothing
*/
void selection_sort(int *array, size_t size)
{
	int n;
	size_t i, j, h;

	for (j = 0; j < size - 1; j++)
	{
		h = j;
		for (i = j + 1; i < size; i++)
		{
			if (array[i] < array[h])
				h = i;
		}
		if (h != j)
		{
			n = array[h];
			array[h] = array[j];
			array[j] = n;
			print_array(array, size);
		}
	}
}
