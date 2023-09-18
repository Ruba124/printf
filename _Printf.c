#include "main.h"

void p_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Prints anything
 * @format: the format string
 *
 * Return: number of bytes printe
 */
int _printf(const char *format, ...)
{
	int j, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				p_buffer(buffer, &buff_ind);
			/* write(1, &format[j], 1);*/
			printed_chars++;
		}
		else
		{
			p_buffer(buffer, &buff_ind);
			flags = g_flags(format, &j);
			width = g_width(format, &j, list);
			precision = g_precision(format, &j, list);
			size = g_size(format, &j);
			++j;
			printed = handle_print(format, &j, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	p_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * p_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at Which to add next char, represents the length.
 */
void p_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
