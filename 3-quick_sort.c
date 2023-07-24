#include "sort.h"

/**
 * swap - swap
 * @l: parameter
 * @z: parameter
 * Return: Nothing
 */
void swap(int *l, int *z)
{
	int temp = *l;
	*l = *z;
	*z = temp;
}

/**
 * lomuto_qsort - Quick Sort Algorithm using Lomuto partition
 * @array: Pramater array to be sorted
 * @low: The lowest valuey
 * @high: highest value
 * @size: Size of The Array
 * Return: Nothing
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int piv = array[high];
		int l = low - 1, z;

		for (z = low; z <= high; z++)
		{
			if (array[z] <= piv)
			{
				l++;
				if (l != z)
				{
					swap(&array[l], &array[z]);
					print_array(array, size);
				}
			}
		}

		lomuto_qsort(array, low, l - 1, size);
		lomuto_qsort(array, l + 1, high, size);
	}
}

/**
 * quick_sort - function that sorts an array of integers in ascending
 * @array: Parameter Array
 * @size: Size of The Array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size - 1, size);
}
