#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int x, curr_in;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_in = *i + 1; format[curr_in] != '\0'; curr_in++)
	{
		for (x = 0; FLAGS_CH[i] != '\0'; x++)
			if (format[curr_in] == FLAGS_CH[x])
			{
				flags |= FLAGS_ARR[x];
				break;
			}

		if (FLAGS_CH[x] == 0)
			break;
	}

	*i = curr_in - 1;

	return (flags);
}

