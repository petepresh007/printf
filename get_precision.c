#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int cur_in = *i + 1;
	int prec = -1;

	if (format[cur_in] != '.')
		return (prec);

	prec = 0;

	for (cur_in += 1; format[cur_in] != '\0'; cur_in++)
	{
		if (is_digit(format[cur_in]))
		{
			prec *= 10;
			prec += format[cur_in] - '0';
		}
		else if (format[cur_in] == '*')
		{
			cur_in++;
			prec = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*i = cur_in - 1;

	return (prec);
}
