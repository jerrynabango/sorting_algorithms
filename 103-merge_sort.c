#include "sort.h"

/**
 * _subarr - Sort a subarray.
 * @arr: parameter.
 * @temp: parameter.
 * @head: parameter.
 * @cen: parameter.
 * @tail: parameter.
 * Return: Nothing
 */
void _subarr(int *arr, int *temp, size_t head, size_t cen, size_t tail)
{
	size_t j, k, z = 0;

	printf("Merging...\n[left]: ");
	print_array(arr + head, cen - head);

	printf("[right]: ");
	print_array(arr + cen, tail - cen);

	j = head;
	k = cen;
	while (j < cen && k < tail)
	{
		temp[z] = (arr[j] < arr[k]) ? arr[j++] : arr[k++];
		z++;
	}
	while (j < cen)
	{
		temp[z++] = arr[j];
		j++;
	}
	while (k < tail)
	{
		temp[z++] = arr[k];
		k++;
	}
	j = head;
	z = 0;
	while (j < tail)
	{
		arr[j] = temp[z++];
		j++;
	}

	printf("[Done]: ");
	print_array(arr + head, tail - head);
}

/**
 * _recursive - merge sort through recursion.
 * @arr: parameter.
 * @temp: parameter.
 * @head: parameter.
 * @tail: parameter.
 * Return: Nothing
 */
void _recursive(int *arr, int *temp, size_t head, size_t tail)
{
	size_t cen;

	if (tail - head > 1)
	{
		cen = head + (tail - head) / 2;
		_recursive(arr, temp, head, cen);
		_recursive(arr, temp, cen, tail);
		_subarr(arr, temp, head, cen, tail);
	}
}

/**
 * merge_sort - using the Merge sort algorithm
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	_recursive(array, temp, 0, size);

	free(temp);
}
