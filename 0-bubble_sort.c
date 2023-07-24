#include "sort.h"

/**
  * bubble_sort - function that sorts an array of integers
  * @array: Parameter
  * @size: size of array
  * Return: Nothing
  */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int n;
	int swapped;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				n = array[j];
				array[j] = array[j + 1];
				array[j + 1] = n;
				print_array(array, size);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
}
