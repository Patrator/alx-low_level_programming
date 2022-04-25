#include "lists.h"

/**
 * free_listint2 - frees lists and sets head to null
 * @head: pointer to pointer to head
 */

void free_listint2(listint_t **head)
{
	/*declare variables to be used*/
	listint_t *ptr;

	ptr = *head;
	/*traverse the list and free head*/
	while (ptr != NULL)
	{
		/*move to the next address*/
		ptr = ptr->next;
		/*after moving free head*/
		free(*head);
		/*then set head to the next address*/
		*head = ptr;
	}
	/*all the list have been freed set head to NULL*/
	head = NULL;
}
