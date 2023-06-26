#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int flag = 1;
	size_t i = 0;

	while (flag)
	{
		flag = 0;

		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				int tmp = array[i - 1];

				array[i - 1] = array[i];
				array[i] = tmp;
				flag = 1;
				print_array(array, size);
			}
		}

		if (flag == 0)
			break;
	}
}
