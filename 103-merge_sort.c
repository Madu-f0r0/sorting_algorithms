#include "sort.h"

void merge(int *arr, int *temp, size_t left, size_t mid, size_t right);


/**
 * merge_sort_recursive - Recursively apply merge sort to a subarray.
 * @arr: The original array to be sorted.
 * @temp: A temporary array used during merging.
 * @left: The left boundary of the subarray.
 * @right: The right boundary of the subarray.
 */
void merge_sort_recursive(int *arr, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (right - left <= 1)
		return;

	mid = left + (right - left) / 2;
	merge_sort_recursive(arr, temp, left, mid);
	merge_sort_recursive(arr, temp, mid, right);
	merge(arr, temp, left, mid, right);
}

/**
 * merge_sort - Sort an array of integers in ascending order
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size);

	free(temp);
}

/**
 * merge - Merge two sorted subarrays into a single sorted subarray.
 * @arr: The original array containing the subarrays.
 * @temp: A temporary array to store the merged subarray.
 * @left: The left boundary of the subarray.
 * @mid: The middle index of the subarray.
 * @right: The right boundary of the subarray.
 */
void merge(int *arr, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n[left]: ");
	print_array(arr + left, mid - left);

	printf("[right]: ");
	print_array(arr + mid, right - mid);

	while (i < mid && j < right)
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	while (i < mid)
		temp[k++] = arr[i++];

	while (j < right)
		temp[k++] = arr[j++];

	for (i = left; i < right; i++)
		arr[i] = temp[i];

	printf("[Done]: ");
	print_array(arr + left, right - left);
}
