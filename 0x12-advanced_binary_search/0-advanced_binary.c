#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * using the Binary search algorithm
 *
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: index of value or (-1) if value does not exist
*/
int advanced_binary(int *array, size_t size, int value)
{
	if (array && size > 1)
		return (recursion_advanced_binary(array, 0, size - 1, value));
}

/**
 * adv_bin - searches for a value in a sorted array of integers
 * using the Binary search algorithm
 *
 * @array: pointer to the first element of the array to search in
 * @first: first index of the array to search in
 * @last: last index of the array to search in
 * @value: value to search for
 *
 * Return: index of value or (-1) if value does not exist
*/
int adv_bin(int *array, size_t first, size_t last, int value)
{
	int middle = (first + last) / 2;
	int i;

	if (first > last)
		return (-1);

	printf("Searching in array: ");
	for (i = first; i <= last; i++)
	{
		printf("%d", array[i]);
		if (i < last)
			printf(", ");
		else
			printf("\n");
	}

	if (array[first] == value)
		return (first);

	if (array[middle] < value)
		return (adv_bin(array, middle + 1, last, value));

	return (adv_bin(array, first, middle, value));
}
