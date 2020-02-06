#include "sort.h"


/**
 * quick_sort - Sort an array of integers in sort way
 * @array: pointer
 * @size: size
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	int low = 0, high = 0;

	if (size <= 1 || array == NULL || size == 0)
		return;

	low = 0;
	high = size - 1;

	recur_lom(array, low, high, size);
}

/**
 * lomutos - lomuto partition scheme.
 * @arr: pointer.
 * @lo: the lower
 * @hi: the higher
 * @size: size
 * Return: No
 */

int lomutos(int *arr, int lo, int hi, size_t size)
{
	int jump = 0;
	int i = 0, j = 0;
	size_t tmp;

	jump = arr[hi];
	i = lo - 1;

	for (j = lo; j <= hi; j++)
	{
		if (arr[j] <= jump)
		{
			i += 1;
			if (i != j)
			{

				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				print_array(arr, size);
			}
		}
	}
	return (i);
}

/**
 * recur_lom - recursive function
 * @arr: pointer
 * @low: lower
 * @high: higher
 * @size: array
 * Return: nothing
 */

void recur_lom(int *arr, int low, int high, size_t size)
{

	int pi = 0;

	if (low < high)
	{
		pi = lomutos(arr, low, high, size);

		recur_lom(arr, low, pi - 1, size);
		recur_lom(arr, pi + 1, high, size);
	}
}
