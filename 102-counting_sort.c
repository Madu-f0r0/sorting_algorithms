#include "sort.h"

/**
 * counting_sort - sorts an array usin the Counting sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, k = 0, *count_arr, *dup_array;

	if (array && size)
	{
		/* Find the largest number in the array and assign it to k */
		for (i = 0; i < (int)size; i++)
		{
			if (array[i] > k)
				k = array[i];
		}

		/* Allocate zero initialized memory for the counting array */
		count_arr = calloc(k + 1, sizeof(int));
		if (count_arr)
		{
			/* Populate count_arr with the frequency of the array elements */
			for (i = 0; i < (int)size; i++)
				count_arr[array[i]]++;

			/* Let count_arr contain the actual positions in array */
			for (i = 1; i < k + 1; i++)
				count_arr[i] += count_arr[i - 1];
			print_array(count_arr, k + 1);

			/* Allocate memory to duplicate input array */
			dup_array = malloc(sizeof(int) * size);
			if (dup_array)
			{
				for (i = size - 1; i >= 0; i--)
					dup_array[--count_arr[array[i]]] = array[i];

				for (i = 0; i < (int)size; i++)
					array[i] = dup_array[i];
				free(dup_array);
			}
			free(count_arr);
		}
	}
}
