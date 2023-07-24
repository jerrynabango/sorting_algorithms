#include "sort.h"

/**
 * swap - Function to swap elements
 *
 * @a: Integer value to swap with element at index
 *
 * @b: Integer value to swap with element at index
 *
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int swap_element;

	swap_element = *b;
	*b = *a;
	*a = swap_element;
}

/**
 * shell_sort - Code implements Shell sort for int's asc,using Knuth sequence
 *
 * @array: Indicates the order of integers asc in the array passed in.
 *
 * @size: Indicates size of array passed in and size of the array passed in.
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t sort_1, sort_2, sort_3;

	if (array == NULL || size < 2)
		return;

	for (sort_1 = 1; sort_1 < (size / 3);)
		sort_1 = sort_1 * 3 + 1;

	for (; sort_1 >= 1; sort_1 /= 3)
	{
		for (sort_2 = sort_1; sort_2 < size; sort_2++)
		{
			sort_3 = sort_2;
			while (sort_3 >= sort_1 && array[sort_3 - sort_1] > array[sort_3])
			{
				swap(array + sort_3, array + (sort_3 - sort_1));
				sort_3 -= sort_1;
			}
		}
		print_array(array, size);
	}
}
