#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a node at index position
 * @head: pointer to pointer to first node in list
 * @idx: index position to add node
 * @n: the value to be added
 * Return: the first node of list
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	/*declare variables to be used*/
	unsigned int i = 1;/*i is 1 to enable to insert at exactly idx*/
	listint_t *ptr, *new;
	/*set ptr to address of first node*/
	ptr = *head;
	/*malloc space for new node*/
	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	/*put values in new node*/
	new->n = n;
	new->next = NULL;
	/*traverse the list till index is reached*/
	while (i < idx)
	{
		ptr = ptr->next;
		i++;
	}
	/* check if ptr is empty*/
	if (ptr == NULL)
	{
		free(new);
		return (NULL);
	}
	/*insert the list*/
	new->next = ptr->next;
	ptr->next = new;
	return (*head);
}
