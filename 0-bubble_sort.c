#include "sort.h"

/**
 * bubble_sort - sort the array using bubble sort algorithm
 * @array: array to sort
 * @size: size of array
 * Return: void (no Return)
 */
void bubble_sort(int *array, size_t size)
{
	int last = size - 1, x, swapped = 1;

	if (size < 2)
		return;
	while (swapped)
	{
		swapped = 0;
		for (x = 0; x < last; x++)
		{
			if (array[x] > array[x + 1])
			{
				int temp = array[x];

				array[x] = array[x + 1];
				array[x + 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
		last--;
	}
}
