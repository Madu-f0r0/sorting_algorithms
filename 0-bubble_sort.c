#include "main.h"

/**
 * bubble_sort -  sorts an array of integers in ascending order
 * @array: array to sort
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int temp, swapped;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		swapped = 0;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped++;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}

