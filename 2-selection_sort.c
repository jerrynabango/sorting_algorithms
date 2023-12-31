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
	size_t i, j, h;
	int n;

	for (j = 0; j < size - 1; j++)
	{
		h = j;
		i = j + 1;
		while (i < size)
		{
			if (array[i] < array[h])
			{
				h = i;
			}
			i++;
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
