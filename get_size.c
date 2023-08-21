#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int curr_in = *i + 1;
	int s = 0;

	if (format[curr_in] == 'l')
		s = S_LONG;
	else if (format[curr_in] == 'h')
		s = S_SHORT;

	if (s == 0)
		*i = curr_in - 1;
	else
		*i = curr_in;

	return (s);
}

