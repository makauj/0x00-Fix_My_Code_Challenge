#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int p;

	if (!(*head))
	{
		return (-1);
	}
	tmp = *head;

	for (p = 0; tmp != NULL && p < index; p++)
	{
		tmp = tmp->next;
	}
	if (!tmp)
	{
		return (-1);
	}
	if (index == 0)
	{
		(*head) = (tmp)->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
	}
	else
	{
		if (tmp->prev != NULL)
			tmp->prev->next = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = tmp->prev;
	}
	free(tmp);
	return (1);
}
