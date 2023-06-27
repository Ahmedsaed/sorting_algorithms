#include "sort.h"
#include <stdio.h>

#define UP 1
#define DOWN 0

/* function prototypes */
void bitonic_merge(int *array, size_t size,
					size_t start, size_t seq, char flow);
void bitonic_sort_recursive(int *array, size_t size,
							size_t start, size_t seq, char flow);

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

	bitonic_sort_recursive(array, size, 0, size, UP);
}

/**
 * bitonic_sort_recursive - sorts an array of integers in ascending
 * order using the Bitonic sort algorithm
 *
 * @array: array of integers to be sorted
 * @size: size of the array
 * @start: starting index
 * @seq: sequence
 * @flow: flow
 */
void bitonic_sort_recursive(int *array, size_t size,
							size_t start, size_t seq, char flow)
{
	size_t k = seq / 2;
	char *str = (flow == 1) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_sort_recursive(array, size, start, k, UP);
		bitonic_sort_recursive(array, size, start + k, k, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_merge - sorts an array of integers in ascending
 *
 * @array: array of integers to be sorted
 * @size: size of the array
 * @start: starting index
 * @seq: sequence
 * @flow: flow
 */
void bitonic_merge(int *array, size_t size,
					size_t start, size_t seq, char flow)
{
	size_t k = seq / 2, i, tmp;

	if (seq > 1)
	{
		for (i = start; i < start + k; i++)
		{
			if ((flow == UP && array[i] > array[i + k])
				|| (flow == DOWN && array[i] < array[i + k]))
			{
				tmp = array[i];
				array[i] = array[i + k];
				array[i + k] = tmp;
			}
		}
		bitonic_merge(array, size, start, k, flow);
		bitonic_merge(array, size, start + k, k, flow);
	}
}
