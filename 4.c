#include "monty.h"

/**
 * create_node - Creates a node
 * @n: integer value
 * Return: pointer or NULL
 */

stack_t *create_node(int n)
{
	stack_t *temp;

	temp = malloc(sizeof(stack_t));
	if (!temp)
		error_func1(4);
	temp->next = NULL;
	temp->prev = NULL;
	temp->n = n;
	return (temp);
}

/**
 * free_node - frees node in the stack
 * Return: Nothing
 */

void free_node(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * push_in_stack - adds a node to the stack
 * @new_node: Pointer of a pointer
 * @line_num: interger
 * Return: Nothing
 */

void push_in_stack(stack_t **new_node, unsigned int line_num)
{
	stack_t *current;
	(void) line_num;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	current = head;
	head = *new_node;
	head->next = current;
	current->prev = head;
}



/**
 * print_stack - print the stack
 * @stack: Pointer of a pointer
 * @line_num: integer
 * Return: Nothing
 */

void print_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	(void) line_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * push_in_queue - adds a node to the queue
 * @new_node: pointer of a pointer
 * @line_num: integer
 * Return: Nothing
 */

void push_in_queue(stack_t **new_node, unsigned int line_num)
{
	stack_t *temp;
	(void) line_num;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *new_node;
	(*new_node)->prev = temp;
}
