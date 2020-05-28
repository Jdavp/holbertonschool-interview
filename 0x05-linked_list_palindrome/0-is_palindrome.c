#include <stdlib.h>
#include <stdio.h>
#include "lists.h"
#include <stdbool.h>


/**
 * reverse_list - turn list backwards
 *@head: pointer to the list
 * Return: list reverse
 */

listint_t *reverse_list(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *curr = *head;
	listint_t *next;

	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return (prev);
}

/**
 * are_identical - checks if a singly linked list is a palindrome
 *@headA: pointer to list
 *@headB: pointer to list backwards
 * Return: Always 0 (Success)
 */

int are_identical(listint_t *headA, listint_t *headB)
{
	if (headA == NULL && headB == NULL)
		return (1);
	else if (headA != NULL && headB != NULL)
		return (headA->n == headB->n && are_identical(headA->next, headB->next));
	else
		return (0);
}


/**
 * is_palindrome - checks if a singly linked list is a palindrome
 *@head: first greed
 * Return: Always 0 (Success)
 */

int is_palindrome(listint_t **head)
{
	listint_t *first;
	listint_t *second;
	listint_t *f_ptr = *head;
	listint_t *s_ptr = *head;
	listint_t *prev = NULL;
	int ret = 0;

	if (head == NULL || *head == NULL)
		return (1);

	while (f_ptr && f_ptr->next && f_ptr->next->next)
	{
		prev = s_ptr;
		s_ptr = s_ptr->next;
		f_ptr = f_ptr->next->next;
	}
	if (!(f_ptr->next->next))
	{
		first = *head;
		second = s_ptr->next;
		s_ptr->next = NULL;
		second = reverse_list(&second);
		ret = are_identical(first, second);
	}
	if (!(f_ptr->next))
	{
		first = *head;
		second = s_ptr->next;
		prev->next = NULL;
		s_ptr->next = NULL;
		second = reverse_list(&second);
		ret = are_identical(first, second);
	}
	return (ret);
}
