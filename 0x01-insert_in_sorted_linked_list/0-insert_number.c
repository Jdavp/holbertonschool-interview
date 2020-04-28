#include <stdlib.h>
#include "lists.h"
#include <stdio.h>

/**
 *insert_node - add a new node
 *@head: initial pointer
 *@number: number to insert
 *
 *Return: the address of the new node
 */


listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	current = *head;
	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	(*new).n = number;
	(*new).next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	if ((*current).n > number)
	{
		(*new).next = current;
		*head = new;
		return (new);
	}
	while ((current->next) != NULL)
	{
		if ((*current).n < number && (*current->next).n > number)
		{
			(*new).next = (*current).next;
			(*current).next = new;
		}
		current = current->next;
	}
	if ((*current).n < number)
	{
		(*current).next = new;
	}
	return (new);
}
