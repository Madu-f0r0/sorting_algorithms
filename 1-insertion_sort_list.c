#include "main.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order using
 *                       the insertion sort algorithm.
 * @list: Pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *inner_current, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		/*Store the current node in a variable for comparison*/
		inner_current = current;
		prev = current->prev;

		while (prev && prev->n > inner_current->n)
		{
			/*Adjust the next pointers to perform the swap*/
			prev->next = inner_current->next;
			if (inner_current->next != NULL)
				inner_current->next->prev = prev;

			/*Update the next and prev pointers for the current node*/
			inner_current->next = prev;
			inner_current->prev = prev->prev;

			/*Update the next and prev pointers for the adjacent nodes*/
			if (prev->prev != NULL)
				prev->prev->next = inner_current;
			else
				*list = inner_current; /*Update the head if needed*/

			prev->prev = inner_current;
			prev = inner_current->prev;

			/*Print the list after each swap (for visualization)*/
			print_list(*list);
		}

		/*Move to the next element in the list*/
		current = current->next;
	}
}


