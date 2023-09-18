#include "main.h"

/**
 * g_width - a function that Calculates the width
 * @format: the formatted string in which to print the arguments.
 * @i:the list of arguments to be printed.
 * @list: the list of arguments.
 *
 * Return: width.
 */
int g_width(const char *format, int *i, va_list list)
{
	int c_i;
	int Width = 0;

	for (c_i = *i + 1; format[c_i] != '\0'; c_i++)
	{
		if (is_digit(format[c_i]))

			Width *= 10;
			Width += format[c_i] - '0';
		}
		else if (format[c_i] == '*')
		{
			c_i++;
			Width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = c_i - 1;
	return (Width);
}
