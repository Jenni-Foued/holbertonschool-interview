#include "search.h"
/**
 * linear_skip - Search for a value in a skip list.
 * @list: Pointer to the head of the skip list.
 * @value: Value to search for.
 * Return: Pointer to the first node where value is located.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp = list;

	if (!list)
		return (NULL);

	while (list->n < value && list->express)
	{
		tmp = list;
		list = list->express;
		printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
	}

	if (value <= list->n)
		printf("Value found between indexes [%ld] and [%ld]\n",
				tmp->index, list->index);
	else
	{
		tmp = tmp->express;
		while (list->next)
			list = list->next;
		printf("Value found between indexes [%ld] and [%ld]\n",
				tmp->index, list->index);
	}

	while (tmp)
	{
		printf("Value checked at index [%ld] = [%d]\n", tmp->index, tmp->n);
		if (tmp->n == value)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
