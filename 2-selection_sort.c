#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - implements the selection sort algorithm on an array of ints
 * @array: the array to sort
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	int i, j, smallest_el, idx;

	if (array && size)
	{
		for (i = 0; i < (int)size; i++)
		{
			smallest_el = array[i];
			idx = i;

			for (j = i + 1; j < (int)size; j++)
			{
				if (array[j] < smallest_el)
				{
					smallest_el = array[j];
					idx = j;
				}
			}
			if (i != idx)
			{
				array[idx] = array[i];
				array[i] = smallest_el;
				print_array(array, size);
			}
		}
	}
}
