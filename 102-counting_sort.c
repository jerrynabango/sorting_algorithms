#include "sort.h"

/**
 * counting_sort - function that sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: An array of integers.
 * @size: The size of the array.
 * Return Nothing
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted_array, max, i;
	size_t j;

	if (array == NULL || size < 2)
		return;
	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
		return;
	for (max = array[0], j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted_array);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted_array[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];

	free(sorted_array);
	free(count);
}
