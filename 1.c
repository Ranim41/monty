#include "monty.h"


/**
 * esra_pop - remove a node from the stack
 * @stack: pointer to pointer
 * @line_num: integer
 * Return: Nothing
 */

void esra_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!stack || !*stack)
		error_func2(7, line_num);
	temp = *stack;
	*stack = temp->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * atika_print - Prints the top node of the stack
 * @stack: pointer to a pointer
 * @line_num: interger
 */

void atika_print(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		error_func2(6, line_num);
	printf("%d\n", (*stack)->n);
}

/**
 * ranim_swap - swaps the top two elements
 * @stack: Pointer to pointer
 * @line_number: Interger
 */

void ranim_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_func2(8, line_number, "swap");

	temp = (*stack)->next;
	(*stack)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *stack;

	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * fuad_add - adds the top two elements of the stack
 * @stack: Pointer of a pointer
 * @line_number: Interger
 */

void fuad_add(stack_t **stack, unsigned int line_number)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_func2(8, line_number, "add");

	(*stack) = (*stack)->next;
	add = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * aseel_nop - does nothing
 * @stack: Pointer of pointer
 * @line_number: Interger
 */

void aseel_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
