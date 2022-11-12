#include "sort.h"

/**
 * selection_sort - sorts array using selection sort algo
 * @array: array of integers
 * @size: size of array
 *
 * Return: void (no return)
 */
void selection_sort(int *array, size_t size)
{
	size_t min, pos, x;

	if (size < 2)
		return;

	for (pos = 0; pos < size - 1; pos++)
	{
		min = pos;
		for (x = pos + 1; x < size; x++)
		{
			if (array[x] < array[min])
				min = x;
		}
		if (min != pos)
		{
			int temp = array[pos];

			array[pos] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
