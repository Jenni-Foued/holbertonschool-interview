#include "sort.h"

/**
 * maxInt - Finds the maximum number in an array.
 *
 * @array: Array of integer.
 * @size: Size of the array.
 *
 * Return: The maximum number.
 */
int maxInt(int *array, size_t size)
{
	int max = array[0];
	size_t i = 1;

	for (; i < size; i++)
		if (max < array[i])
			max = array[i];
	
	return (max);
}

/**
 * radix - sort an array according to a place
 *
 * @array: array to be sorted.
 * @size: size of array.
 * @place: place of the sort.
 */
void radix(int *array, size_t size, size_t place)
{
	int max, *buckets, *output;
	size_t i = 1;
	int current;

	int output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		fprintf(stderr, "malloc failed\n");
		return (-1);
	}

	max = (array[0] / place) % 10;

	for (; i < size; i++)
	{
		current = (array[i] / place) % 10;
		if (current > max)
			max = array[i];
	}

	int buckets = malloc((max + 1) * sizeof(int));
	if (buckets == NULL)
	{
		fprintf(stderr, "malloc failed\n");
		return (-1);
	}

	for (i = 0; i < max; i++)
	{
		buckets[i] = 0;
	}

	for (i = 0; i < size; i++)
		buckets[(array[i] / place) % 10]++;
	
	for (i = 1; i < 10; i++)
		buckets[i] += buckets[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[buckets[(array[i] / place) % 10] - 1] = array[i];
		buckets[(array[i] / place) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
	free(buckets);
}

/**
 * radix_sort - sorts an array of integers in ascending
 * order using the Radix sort algorithm.
 *
 * @array: The array of integer to be sorted.
 * @size: Array size.
 */
void radix_sort(int *array, size_t size)
{
	int max;
	size_t i = 1;

	if (array == NULL || size < 2)
		return;

	max = maxInt(array, size);

	for (; i < max; i *= 10)
	{
		radix(array, size, i);
		print_array(array, size);
	}
}
