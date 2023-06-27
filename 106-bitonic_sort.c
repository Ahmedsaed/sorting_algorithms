#include "sort.h"
#include <stdio.h>

/* function prototypes */
void bitonic_merge(int *array, size_t low, size_t size, size_t size2, int dir);
void bitonic_sort_recursive(int *array, size_t low,
							size_t size, size_t size2, int dir);


/**
 * bitonic_sort - sorts an array of integers in ascending
 * order using the Bitonic sort algorithm
 *
 * @array: array of integers to be sorted
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, size, 1);
}

/**
 * bitonic_sort_recursive - sorts an array of integers in ascending
 * order using the Bitonic sort algorithm
 *
 * @array: array of integers to be sorted
 * @low: low index
 * @size: size of the array
 * @size2: size of the array
 * @dir: direction
 */
void bitonic_sort_recursive(int *array, size_t low,
							size_t size, size_t size2, int dir)
{
	size_t k = size / 2;

	if (size < 2)
		return;

	if (dir == 1)
		printf("Merging [%lu/%lu] (UP):\n", size, size2);
	else
		printf("Merging [%lu/%lu] (DOWN):\n", size, size2);

	print_array(array + low, size);

	bitonic_sort_recursive(array, low, k, size2, 1);
	bitonic_sort_recursive(array, low + k, k, size2, 0);
	bitonic_merge(array, low, size, size2, dir);
}

/**
 * bitonic_merge - sorts an array of integers in ascending
 * order using the Bitonic sort algorithm
 *
 * @array: array of integers to be sorted
 * @low: low index
 * @size: size of the array
 * @size2: size of the array
 * @dir: direction
 */
void bitonic_merge(int *array, size_t low, size_t size, size_t size2, int dir)
{
	size_t k = size / 2, i, temp;

	if (size < 2)
		return;

	for (i = low; i < low + k; i++)
	{
		if (dir == (array[i] > array[i + k]))
		{
			temp = array[i];
			array[i] = array[i + k];
			array[i + k] = temp;
		}
	}

	bitonic_merge(array, low, k, size2, dir);
	bitonic_merge(array, low + k, k, size2, dir);
}
