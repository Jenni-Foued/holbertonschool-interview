#include "lists.h"

/**
 * find_listint_loop - checks if a singly linked list has a cycle
 * @head: pointer to head of list
 * Return: The address of the node where the loop starts, or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *p1, *p2;

	if (head == NULL)
		return (0);
	p1 = head;
	p2 = head;
	while ((p1 != NULL) && (p2 != NULL) && (p2->next != NULL))
	{
		p1 = p1->next;
		p2 = p2->next->next;
		if (p1 == p2)
			break;
	}
	if (p1 != p2)
		return (NULL);
	p1 = head;

	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}

	return (p2);
}
