#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_in;
	int width = 0;

	for (curr_in = *i + 1; format[curr_in] != '\0'; curr_in++)
	{
		if (is_digit(format[curr_in]))
		{
			width *= 10;
			width += format[curr_in] - '0';
		}
		else if (format[curr_in] == '*')
		{
			curr_in++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_in - 1;

	return (width);
}

