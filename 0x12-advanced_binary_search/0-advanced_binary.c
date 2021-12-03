#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    if (array == NULL || size == 0)
        return (-1);
    return adv_bin(array, 0, size - 1, value);
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
    size_t middle, i;
    
    for (i = first; i <= last; i++)
    {
        printf("Searching in array: ");
        printf("%d", array[i]);
        if (i != last)
            printf(", ");
        else
            printf("\n");
    }
    middle = round((first + last) / 2);
    
    if (last > first)
    {
        if (value == array[first])
            return (first);
        else if (value > array[middle])
            return (adv_bin(array, middle + 1, last, value));
    
        else
            return (adv_bin(array,first, middle, value));
    }
        return (-1);
}
