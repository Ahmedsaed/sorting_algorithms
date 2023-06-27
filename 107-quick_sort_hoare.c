#include "sort.h"

/* helper functions */
void quick_sort_helper(int *array, size_t size, int low, int high);
int partition(int *array, size_t size, int low, int high);
void swap(int *a, int *b);

/**
 * quick_sort_hoare - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, size, 0, size - 1);
}

/**
 * quick_sort_helper - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 *
 * @array: the array to sort
 * @low: the low index
 * @high: the high index
 * @size: the size of the array
 */
void quick_sort_helper(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (high - low > 0)
	{
		pivot_index = partition(array, size, low, high);

		quick_sort_helper(array, size, low, pivot_index - 1);
		quick_sort_helper(array, size, pivot_index, high);
	}
}

/**
 * partition - partitions the array
 *
 * @array: the array to partition
 * @size: the size of the array
 * @low: the low index
 * @high: the high index
 *
 * Return: the pivot index
*/
int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high], i, j;

	for (i = low - 1, j = high + 1; i < j;)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	return (i);
}

/**
 * swap - swaps two integers
 *
 * @a: the first integer
 * @b: the second integer
*/
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
