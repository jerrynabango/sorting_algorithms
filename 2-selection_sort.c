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
	size_t j = 0;

    while (j < size - 1)
    {
        size_t h = j + 1;
        size_t i = j + 2;

        while (i < size)
        {
            if (array[i] < array[h])
            {
                h = i;
            }
            i++;
        }

        if (array[j] > array[h])
        {
            int n = array[h];
            array[h] = array[j];
            array[j] = n;
            print_array(array, size);
        }

        j++;
    }
}
