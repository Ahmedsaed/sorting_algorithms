#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm, using the Knuth sequence
 *
 * @array: the array of integers to be sorted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t h = 1, i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	while (h <= size / 3)
		h = 3 * h + 1;

	while (h >= 1)
	{
		for (i = h; i < size; i++)
		{
			tmp = array[i];
			j = i;

			while (j >= h && array[j - h] > tmp)
			{
				array[j] = array[j - h];
				j -= h;
			}

			array[j] = tmp;
		}

		h /= 3;
		print_array(array, size);
	}
}
