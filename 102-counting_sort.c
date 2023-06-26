#include "sort.h"

/**
 * counting_sort - sorts an array of integers in
 * ascending order using the Counting sort algorithm
 *
 * @array: array of integers to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *freq, *output, curr;
	size_t i, max;

	if (array == NULL)
		return;

	max = 0;
	for (i = 1; i < size; i++)
		if (array[i] > array[max])
			max = i;

	freq = malloc(sizeof(int) * (array[max] + 1));
	if (freq == NULL)
		return;

	for (i = 0; (int)i < array[max] + 1; i++)
		freq[i] = 0;

	for (i = 0; i < size; i++)
		freq[array[i]]++;

	for (i = 1; (int)i < array[max] + 1; i++)
		freq[i] += freq[i - 1];

	print_array(freq, array[max] + 1);

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(freq);
		return;
	}

	for (curr = size - 1; curr >= 0; curr--)
	{
		output[freq[array[curr] - 1]] = array[curr];
		output[array[curr]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(freq);
	free(output);
}
