#include <stdlib.h>
#include <stdio.h>
#include "lists.h"
#include <stdbool.h>

/**
 * isPalindromeUtil - checks if a singly linked list is a palindrome
 *@left: double pointer to list
 *@right: pointer to list
 * Return: Always 0 (Success)
 */

bool isPalindromeUtil(listint_t **left, listint_t  *right)
{
	if (right == NULL)
		return (1);

	bool isp = isPalindromeUtil(left, right->next);

	if (isp == 0)
		return (0);

	bool isp1 = (right->n == (*left)->n);
	*left = (*left)->next;
	return (isp1);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 *@head: first greed
 * Return: Always 0 (Success)
 */

int is_palindrome(listint_t **head)
{
	if (head == NULL)
		return (0);

	if (*head == NULL)
		return (1);

	return (isPalindromeUtil(head, *head));
}
