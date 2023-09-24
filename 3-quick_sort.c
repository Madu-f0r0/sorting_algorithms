#include "sort.h"
#include <stdio.h>

void lomuto(int *arr, size_t low, size_t high, size_t size);

/**
 * quick_sort - implements the quick sort algorithm on an array of ints
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array && size)
		lomuto(array, 0, size - 1, size);
}

/**
 * lomuto - implements the lomuto partition scheme for quick sort
 * @arr: the array to be partitioned
 * @low: the lower bound of the partition
 * @high: the upper bound of the partition
 * @size: the size of the array
 */
void lomuto(int *arr, size_t low, size_t high, size_t size)
{
	size_t i, j, pivot, temp;

	if (low >= high)
	{
		return;
	}

	pivot = arr[high];
	j = low;

	for (i = low; i < high; i++)
	{
		if (arr[i] <= (int)pivot)
		{
			if (j != i)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				print_array(arr, size);
			}
			j++;
		}
	}
	if (high != j)
	{
		temp = arr[high];
		arr[high] = arr[j];
		arr[j] = temp;
		print_array(arr, size);
	}

	if (j - low > 1)
		lomuto(arr, low, j - 1, size);
	if (high - j > 1)
		lomuto(arr, j + 1, high, size);
}
