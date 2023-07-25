#include "sort.h"

/**
 * swap - swap values
 * @j: parameter
 * @z: parameter
 * Return: Nothing
 */
void swap(int *j, int *z)
{
	int value;

	value = *j;
	*j = *z;
	*z = value;
}
/**
 * partition - Partition an array
 * @array: Array
 * @l: Parameter
 * @h: Parameter
 * @size: parameter
 * Return: Alway 0(success)
 */
int partition(int *array, int l, int h, size_t size)
{
	int pivot = array[h];
	int i = l, j = h;

	while (1)
	{
		for (; array[i] < pivot; i++)
			;
		for (; array[j] > pivot; j--)
			;

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
			i++;
			j--;
		}
		else
		{
			if (i != j)
				return (j);
			return (j - 1);
		}
	}
}
/**
 * _hoare - Sorting Recursively
 * @array: parameter
 * @l: parameter
 * @h: parameter
 * @size: parameter
 * Return: Nothing
 */
void _hoare(int *array, int l, int h, size_t size)
{
	int z;

	if (l < h)
	{
		z = partition(array, l, h, size);
		if (z > l)
			_hoare(array, l, z, size);
		_hoare(array, z + 1, h, size);
	}
}
/**
 * quick_sort_hoare - using the Quick sort algorithm
 * @array: Array of intergers
 * @size: Size of The Array
 * Return: Nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	_hoare(array, 0, size - 1, size);
}
