#include "lists.h"

/**
 * delete_nodeint_at_index - deletes node at index number
 * @head: pointer to pointer to first node
 * @index: index integer
 * Return: 1 if success or -1 if not
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	/*declare variables to be used*/
	listint_t *current, *previous;
	unsigned int i = 0;
	/*set current to head*/
	current = *head;
	previous = NULL;
	/*check if index is 0 which is the first node spot*/
	if (index == 0 && *head != NULL)
	{
		/*move to next address*/
		current = current->next;
		free(*head);
		/*set head to new address after freeing*/
		*head = current;
		return (1);
	}
	/*traverse the list and get to the index position*/
	while (i != index)
	{
		previous = current;
		current = current->next;
		i++;
	}
	/*check if current and previous are NULL*/
	if (current == NULL && previous == NULL)
		return (-1);
	/*set previous->next to be the next address after current*/
	previous->next = current->next;
	/*free current*/
	free(current);
	return (1);/*success*/
}
