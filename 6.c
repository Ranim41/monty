#include "monty.h"

/**
 * error_func1 - prints error massege
 * @err: The error codes are the following:
 * error(1): user does not give any file or more than one file to the program
 * error(2): the file provided is not a file that can be opened or read
 * error(3): the file provided contains an invalid instruction
 * error(4): when the program is unable to malloc more memory
 * error(5): when the parameter passed to the instruction "push" is not an int
 * error(6): when the stack it empty for pint
 * error(7): when the stack it empty for pop
 * error(8): when stack is too short for operation
 */

void error_func1(int err, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, err);

switch (err)
{
	case 1:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 2:
		fprintf(stderr, "Error: Can't open file %s\n",
		va_arg(ag, char *));
		break;
	case 3:
		l_num = va_arg(ag, int);
		op = va_arg(ag, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
		break;
	case 4:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case 5:
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
		break;
	default:
		break;
}
free_node();
exit(EXIT_FAILURE);
}

/**
 * error_func2 - handles errors
 * @err: The error codes are the following:
 * error(6): When the stack it empty for pint
 * error(7): When the stack it empty for pop
 * error(8): When stack is too short for operation
 * error(9): Division by zero
 */
void error_func2(int err, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, err);
	switch (err)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}

/**
 * string_error - handles errors
 * @err: The error codes are the following:
 * error(10): The number inside a node is outside ASCII bounds
 * error(11): The stack is empty
 */
void string_error(int err, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, err);
	l_num = va_arg(ag, int);
	switch (err)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}
