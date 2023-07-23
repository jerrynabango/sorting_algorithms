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

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				n = array[j];
				array[j] = array[j + 1];
				array[j + 1] = n;
				print_array(array, size);
			}
		}
	}
}
