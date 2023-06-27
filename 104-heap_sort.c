#include "sort.h"

/* function prototypes */
void heapify(int *array, size_t size, size_t i, size_t orig_size);

/**
 * heap_sort - sorts an array of integers in ascending order
 *
 * @array: array of integers to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int temp;
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; (int)i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * heapify - heapifies a subtree
 *
 * @array: array to be sorted
 * @size: size of the array
 * @i: index of the subtree root
 * @orig_size: original size of the array
 */
void heapify(int *array, size_t size, size_t i, size_t orig_size)
{
	int temp;
	size_t largest, left, right;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;

		print_array(array, orig_size);
		heapify(array, size, largest, orig_size);
	}
}
