#include "sort.h"

/**
 * heapy - Function to sort a list of strings using the heapy algorithm
 *
 * @arr: Indciates ptrs to str's sorted by the given str length & asc of str
 *
 * @n: Indicates n.o of str's to sort by given str length & asc of str length
 *
 * @i: Indciates index of the first char in str to be sorted by the given str
 *
 * @size: Indicates size of array in bytes of given str length
 *
 * Return: Nothing
 */
void heapy(int *arr, size_t n, size_t i, size_t size)
{
	size_t a, j, h;
	int sort_heapy;

	a = i;
	j = 2 * i + 1;
	h = 2 * i + 2;

	if (j < n && arr[j] > arr[a])
	{
		a = j;
	}

	if (h < n && arr[h] > arr[a])
	{
		a = h;
	}

	if (a != i)
	{
		sort_heapy = arr[i];
		arr[i] = arr[a];
		arr[a] = sort_heapy;
		print_array(arr, size);
		heapy(arr, n, a, size);
	}
}

/**
 * heap_sort - sorts an array of integers ascusing the Heap sort
 *
 * @array: Indicates the ptrs to arrays to sort into asc & size respectively
 *
 * @size: size of array
 *
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	int heap;
	long sort;

	for (sort = size / 2 - 1; sort >= 0; sort--)
	{
		heapy(array, size, (size_t)sort, size);
	}

	sort = size - 1;
	while (sort >= 0)
	{
		heap = array[0];
		array[0] = array[sort];
		array[sort] = heap;

		if (sort != 0)
		{
			print_array(array, size);
		}

		heapy(array, (size_t)sort, 0, size);

		sort--;
	}
}
