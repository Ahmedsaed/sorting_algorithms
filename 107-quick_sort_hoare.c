#include "sort.h"

/* helper functions */
void quick_sort_helper(int* array, int low, int high, size_t size);
int partition(int* array, int low, int high, size_t size);
void swap(int* a, int* b);

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

	quick_sort_helper(array, 0, size - 1, size);
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
void quick_sort_helper(int* array, int low, int high, size_t size)
{
	int pivot_index;

    if (low < high)
	{
        pivot_index = partition(array, low, high, size);

        quick_sort_helper(array, low, pivot_index - 1, size);
        quick_sort_helper(array, pivot_index + 1, high, size);
    }
}

/**
 * partition - partitions the array
 *
 * @array: the array to partition
 * @low: the low index
 * @high: the high index
*/
int partition(int* array, int low, int high, size_t size) {
    int pivot = array[high];
    int i = (low - 1);
    int j = high;

    while (1)
	{
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot && j > low);

        if (i >= j)
            break;

        swap(&array[i], &array[j]);
		print_array(array, size);
    }

    swap(&array[i], &array[high]);
    print_array(array, size);

    return (i);
}

/**
 * swap - swaps two integers
 *
 * @a: the first integer
 * @b: the second integer
*/
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
