#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *tortoise;
	listint_t *hear;

	tortoise = list;
	hear = list->next;
	while (hear->next != NULL)
	{
		if (hear == tortoise)
		{
			return (1);
		}
		tortoise = tortoise->next;
		hear = hear->next->next;
	}
	return (0);
}
