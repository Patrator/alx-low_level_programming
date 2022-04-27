#include "lists.h"
/**
 * free_listint_safe - freeing the list
 * @h: pointer to pointer to list
 * Return: size of the freed list
 */

size_t free_listint_safe(listint_t **h)
{
	/*declare variables*/
	listint_t *current;
	listnode_t *node;
	size_t count = 0;

	if (h == NULL)
		return (0);
	/*check if there's loop or NULL*/
	while (!in_node(*h, node))
	{
		/*adding address to node and checking if it returns NULL*/
		if (!add_node(&node, *h))
		{
			free_nodes(node);
			exit(98);
		}
		current = *h;
		/*move to the next address*/
		*h = (*h)->next;
		/*after moving free current*/
		free(current);
		count++;
	}
	/*check if it was a loop*/
	if (*h != NULL)
		*h = NULL;
	free_nodes(node);
	return (count);
}
