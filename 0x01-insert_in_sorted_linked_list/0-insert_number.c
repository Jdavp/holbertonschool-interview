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

	if (*head != NULL)
	{
		while ((*current->next).n < number)
		{
			current = current->next;
		}
		(*new).next = (*current).next;
		(*current).next = new;
	}
	else
	{
		*head = new;
	}
	return (new);
}
