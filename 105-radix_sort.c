#include "sort.h"

/**
 * _LSD - count sort
 * @arr: parameter
 * @size: parameter
 * @radix: parameter
 * Return: Nothing
 */
void _LSD(int *arr, size_t size, size_t radix)
{
	int count_arr[10] = {0};
	int *out_arr;
	int i = 1, m;
	size_t j = 0;
	size_t z = 0;

	out_arr = malloc(sizeof(int) * size);

	while (j < size)
	{
		count_arr[(arr[j] / radix) % 10]++;
		j++;
	}
	while (i < 10)
	{
		count_arr[i] += count_arr[i - 1];
		i++;
	}

	m = size - 1;
	while (m >= 0)
	{
		out_arr[count_arr[(arr[m] / radix) % 10] - 1] = arr[m];
		count_arr[(arr[m] / radix) % 10]--;
		m--;
	}

	while (z < size)
	{
		arr[z] = out_arr[z];
		z++;
	}

	free(out_arr);
}

/**
 * radix_sort -	using the Radix sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int high = 0;
	size_t z = 0, radix = 1;

	if (!array || size < 2)
		return;

	while (z < size)
	{
		if (array[z] > high)
			high = array[z];
	z++;
	}

	while (high / radix > 0)
	{
		_LSD(array, size, radix);
		print_array(array, size);
	radix *= 10;
	}
}
