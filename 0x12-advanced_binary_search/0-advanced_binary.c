#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: return the index where value is located, -1 otherwise
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array && size > 1)
		return (recursion_advanced_binary(array, 0, size - 1, value));

	return (-1);
}

/**
 * recursion_advanced_binary - search for a value in an array of integers
 * @array: is a pointer to the first element of the array to search in
 * @first: is the first element of the array
 * @last: is the last element of the array
 * @value: is the value to search for
 * Return: return the index where value is located, -1 otherwise
 */
int recursion_advanced_binary(int *array, int first, int last, int value)
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
		return (recursion_advanced_binary(array, middle + 1, last, value));

	return (recursion_advanced_binary(array, first, middle, value));
}
