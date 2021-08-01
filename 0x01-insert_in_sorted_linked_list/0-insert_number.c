#include "lists.h"
#include <stdlib.h>

/**
 * insert_node -  inserts a number into a sorted singly linked list.
 * @head: pointer to the head of the list.
 * @number: number to insert
 *
 * Return: pointer to the new node inserted
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *current;
	
	if (!head)
    	return (NULL);
	current = *head;
	new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);
	new_node->n = number;

	if ((*head) == NULL || (*head)->n > number)
	{
		new_node->next = (*head);
		new_node->n = number;
		(*head) = new_node;
	}
	else
	{
		while (current->next && current->next->n < number)
			current = current.next;
		if (current->next == NULL)
		{
			current->next = new_node;
			new_node->next = NULL;
		}
		else
		{
			new_node->next = current->next;
			current->next = new_node;
		}
	}
	return (new_node);
}
