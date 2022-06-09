#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of linked list
 *
 * @head: first node in the list
 * @index: index to delete node from
 * Return: 1 if succeeds or -1 if it fails
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *future;
	unsigned int i = 0;

	if (!*head || !head)
		return (-1);

	future = *head;
	if (index == 0)
	{
		future = future->next, free(*head), *head = future;
		return (1);
	}
	for (i = 0; i < index && future; i++)
		future = future->next;

	if (i != index || !future) /* invalid index */
		return (-1);

	future->prev->next = future->next;
	future->next->prev = future->prev;
	free(future);
	return (1);
}
