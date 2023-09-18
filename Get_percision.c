#include "main.h"


/**
 * g_precision - a function that calculates the precision for printing
 * @format: the formatted string in which to print the arguments
 * @i: the list of arguments to be printed.
 * @list: the list of arguments.
 *
 * Return: Precision.
 */
int g_precision(const char *format, int *i, va_list list)
{
	int c_i = *i + 1;
	int Precision = -1;

	if (format[c_i] != '.')
		return (Precision);

	Precision = 0;

	for (c_i += 1; format[c_i] != '\0'; c_i++)
	{
		if (is_digit(format[c_i]))
		{
			Precision *= 10;
			Precision += format[c_i] - '0';
		}
		else if (format[c_i] == '*')
		{
			c_i++;
			Precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = c_i - 1;

	return (Precision);
}
