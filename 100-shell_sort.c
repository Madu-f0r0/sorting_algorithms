#include "sort.h"

/**
 * shell_sort - sorts an array using the shell sort algorithm
 * @array: the array to be sorted
 * @size : the size of the array
 */
void shell_sort(int *array, size_t size)
{
	int i, j, temp, gap = 1;

	if (array && size > 1)
	{
		/* Calculate the starting gap (using Knuth's Sequence) */
		while (gap < (int)size)
		{
			if (gap * 3 + 1 > (int)size)
				break;
			gap = gap * 3 + 1;
		}

		/* Initiate gap interval (using Knuth's Sequence) */
		for (; gap >= 1; gap = (gap - 1) / 3)
		{
			for (j = gap; j < (int)size; j++)
			{
				for (i = j - gap; i >= 0; i -= gap)
				{
					if (array[i + gap] < array[i])
					{
						temp = array[i];
						array[i] = array[i + gap];
						array[i + gap] = temp;
					}
					else
					{
						break;
					}
				}
			}
			print_array(array, size);

		}
	}
}
