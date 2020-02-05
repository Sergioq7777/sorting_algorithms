#include "sort.h"
/**
 * selection_sort - Sort an array using selection.
 *
 * @array: Array - Pointer
 * @size: Size - array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min, temporal;

	for (i = 0; i < size - 1; i++)
	{
		temporal = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[temporal])
			{
				temporal = j;
			}
		}
		if (temporal != i)
		{
			min = array[i];
			array[i] = array[temporal];
			array[temporal] = min;
			print_array(array, size);
		}
	}
}
