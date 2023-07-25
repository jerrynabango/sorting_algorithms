#include "sort.h"

/**
 * bitonic_sort - sorts array of integers in asc using Bitonic sort
 *
 * @array: ptr to array sorted as in array & returns index of first element
 *
 * @size: size of array sorted as in array & returns index of first element
 *
 * Return: Nothing
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_recursion(array, 0, size - 1, 1, size);
}

/**
 * bitonic_merge - Function to merge two arrays to one array & return new array
 *
 * @array: Indicates array to merge into array passed in array
 *
 * @l: Indicates array to merge into array passed in array
 *
 * @r: Indicates array to be merged into array passed in array
 *
 * @dir: ascending or descending
 *
 * Return: Nothing
 */
void bitonic_merge(int *array, int l, int r, int dir)
{
	while (r - l >= 1)
	{
		int sort = (l + r) / 2;
		int mid = (r - l + 1) / 2;
		int merge, bitonic;

		for (bitonic = l; bitonic < l + mid; bitonic++)
		{
			if (dir == (array[bitonic] > array[bitonic + mid]))
			{
				merge = array[bitonic + mid];
				array[bitonic + mid] = array[bitonic];
				array[bitonic] = merge;
			}
		}

		bitonic_merge(array, l, sort, dir);
		l = sort + 1;
	}
}


/**
 * bitonic_recursion - Function to recurse through array & recurse each element
 *
 * @array: Indicates array sorted in asc of bitonic sort operations
 *
 * @l: Indicates whether the function is recursive or not
 *
 * @r: Indicates index of the right-most element in the array
 *
 * @dir: Indicates whether the sort is asc or desc order
 *
 * @size: Indicates number of elements in the array that should be sorted
 *
 * Return: void
 */
void bitonic_recursion(int *array, int l, int r, int dir, size_t size)
{
	int sort;

	if (r - l >= 1)
	{
		sort = (r + l) / 2;
		printf("Merging [%d/%lu] ", r - l + 1, size);
		if (dir)
		{
			printf("(UP):\n");
		}
		else
		{
			printf("(DOWN):\n");
		}
		print_array(array + l, r - l + 1);
		bitonic_recursion(array, l, sort, 1, size);
		bitonic_recursion(array, sort + 1, r, 0, size);
		bitonic_merge(array, l, r, dir);
		printf("Result [%d/%lu] ", r - l + 1, size);
		if (dir)
		{
			printf("(UP):\n");
		}
		else
		{
			printf("(DOWN):\n");
		}
	print_array(array + l, r - l + 1);
	}
}
