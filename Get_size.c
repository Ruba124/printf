#include "main.h"

/**
 * g_size - a function that calculates the size to cast the argument
 * @format: the formatted string in which to print the arguments
 * @i: the list of arguments to be printed.
 *
 * Return: Precision.
 */
int g_size(const char *format, int *i)
{
	int c_i = *i + 1;
	int the_size = 0;

	if (format[c_i] == 'l')
		the_size = S_LONG;
	else if (format[c_i] == 'h')
		the_size = S_SHORT;

	if (the_size == 0)
		*i = c_i - 1;
	else
		*i = c_i;

	return (the_size);
}
