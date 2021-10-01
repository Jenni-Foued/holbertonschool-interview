#include "slide_line.h"

/**
 * left_slide - slide numbers to the left
 *
 * @line: pointer to array of integers
 * @size: number of elements in array
 */

void left_slide(int *line, size_t size)
{
	size_t i = 0, j = 0, k = 0;

	while (i < size)
	{
		if (line[i] == 0)
			for (; line[i] == 0;)
				i++;
		if (i == (size - 1))
			break;
		j = i + 1;
		if (line[j] == 0)
			for (; line[j] == 0;)
				j++;
		if (line[i] == line[j])
		{
			line[i] = line[i] + line[j];
			line[j] = 0;
			i = j + 1;
		}
		else
			i++;
		j = 0;
	}
	for (i = 0, k = 0; i < size; i++)
		if (line[i] != 0)
			line[k++] = line[i];
	while (k < size)
		line[k++] = 0;
}


/**
 * right_slide - slide numbers to the left
 *
 * @line: pointer to array of integers
 * @size: number of elements in array
 */

void right_slide(int *line, size_t size)
{
	size_t i = 0, j = 0;

	for (i = size; i > 0; i--)
	{
		for (j = i - 1; j > 0; j--)
		{
			if (line[i - 1] != 0)
			{
				if (line[i - 1] == line[j - 1])
				{
					line[i - 1] = line[i - 1] + line[j - 1];
					line[j - 1] = 0;
					break;
				}
				if (line[i - 1] != line[j - 1] &&
					line[j - 1] != 0)
					break;
			}
			if (line[i - 1] == 0)
			{
				if (line[j - 1] != 0)
				{
					line[i - 1] = line[j - 1];
					line[j - 1] = 0;
					i++;
					break;
				}
			}
		}
	}
}


/**
 * slide_line - slides and merge the numbers
 *
 * @line: pointer to array of integers
 * @size: number of elements in array
 * @direction: where it will slide, left or right
 * Return: return 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	if ((direction != SLIDE_LEFT) && (direction != SLIDE_RIGHT))
		return (0);
	if (direction == 0)
		left_slide(line, size);
	if (direction == 1)
		right_slide(line, size);
	return (1);
}
