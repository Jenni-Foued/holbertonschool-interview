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
* countSort - counting sort according to the digit represented by exp
* @array: array to be sorted
* @n: size of array
* @exp: exponential
*/
void countSort(int *array, int n, int exp)
{
	int *output, i, count[10] = { 0 };

	output = malloc(sizeof(int) * n);
	if (output == NULL)
		return;

	for (i = 0; i < n; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		array[i] = output[i];
	free(output);
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

	for (; max / i > 0; i *= 10)
	{
		countSort(array, size, i);
		print_array(array, size);
	}
}
