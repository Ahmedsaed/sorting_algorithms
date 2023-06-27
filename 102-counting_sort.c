#include "sort.h"

/**
 * get_max - gets the maximum value in an array
 *
 * @array: array of integers
 * @size: size of the array
 *
 * Return: maximum value in the array
 */
size_t get_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = 0;
	for (i = 1; i < size; i++)
		if (array[i] > array[max])
			max = i;

	return (array[max]);
}

/**
 * counting_sort - sorts an array of integers in
 * ascending order using the Counting sort algorithm
 *
 * @array: array of integers to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *freq, *output;
	size_t i, max;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	freq = malloc(sizeof(int) * (max + 1));
	if (freq == NULL)
		return;

	for (i = 0; i < max + 1; i++)
		freq[i] = 0;
	for (i = 0; i < size; i++)
		freq[array[i]]++;
	for (i = 1; i < max + 1; i++)
		freq[i] += freq[i - 1];

	print_array(freq, max + 1);

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(freq);
		return;
	}

	for (i = 0; i < size; i++)
	{
		output[freq[array[i]] - 1] = array[i];
		freq[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(freq);
	free(output);
}
