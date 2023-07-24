#include "sort.h"

/**
 * selection_sort - sorts an array of integers in asc using Selection sort
 *
 * @array: Indicates pointer to an array of integers
 *
 * @size: Indictes the size of the array in ascending order of the elements
 *
 * Return: Nothing
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
    int n;

    for (j = 0; j < size - 1; j++)
    {
        size_t min_index = j;

        for (i = j + 1; i < size; i++)
        {
            if (array[i] < array[min_index])
            {
                min_index = i;
            }
        }

        if (min_index != j)
        {
            n = array[min_index];
            array[min_index] = array[j];
            array[j] = n;
            print_array(array, size);
        }
    }
}
