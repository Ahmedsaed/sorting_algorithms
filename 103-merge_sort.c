#include "sort.h"
#include <stdio.h>

/* function prototypes */
void merge(int *array, int *left, int *right,
			size_t left_size, size_t right_size);

/**
 * merge_sort - sorts an array of integers in ascending order
 *
 * @array: array of integers to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *left, *right;
	size_t i, mid;

	if (array == NULL || size < 2)
		return;

	mid = size / 2;

	left = malloc(sizeof(int) * mid);
	if (left == NULL)
		return;

	right = malloc(sizeof(int) * (size - mid));
	if (right == NULL)
	{
		free(left);
		return;
	}

	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);

	merge(array, left, right, mid, size - mid);

	free(left);
	free(right);
}

/**
 * merge - merges two subarrays into one
 *
 * @array: array to be sorted
 * @left: left subarray
 * @right: right subarray
 * @left_size: size of the left subarray
 * @right_size: size of the right subarray
 */
void merge(int *array, int *left, int *right,
			size_t left_size, size_t right_size)
{
	size_t i, j, k;

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	i = j = 0;
	k = 0;
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];
	while (j < right_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, left_size + right_size);
}
