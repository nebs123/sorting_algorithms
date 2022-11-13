#include "sort.h"

/**
 * quick_sort - sorts array using quick sort algo
 * @array: array of integers
 * @size: size of the array
 *
 * Return: void (no return)
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || !array)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - helper that performs quick sort algo
 * @array: array of integers
 * @start: start index for sorting
 * @end: end index for sorting
 * @size: size of array used for printing
 *
 * Return: void (no return)
 */
void quick_sort_helper(int *array, int start, int end, size_t size)
{
	int pivot_ind;

	if (start >= end)
		return;
	pivot_ind = partition(array, start, end, size);

	quick_sort_helper(array, start, pivot_ind - 1, size);
	quick_sort_helper(array, pivot_ind + 1, end, size);
}

/**
 * partition - partitions the array between start and end with pivot in between
 * @array: array of integers
 * @start: start index of subset of array that is being partitioned
 * @end: end index of subset of array that is being partitioned
 * @size: size of the array for printing purposes
 *
 * Return: integer which is the index the pivot is positioned at
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end], x, p_index;

	p_index = start;
	for (x = start; x < end; x++)
	{
		if (array[x] <= pivot)
		{
			if (p_index != x)
			{
				int temp = array[p_index];

				array[p_index] = array[x];
				array[x] = temp;
				print_array(array, size);
			}
			p_index++;
		}
	}
	if (p_index != end)
	{
		int temp = array[p_index];

		array[p_index] = array[end];
		array[end] = temp;
		print_array(array, size);
	}

	return (p_index);
}
