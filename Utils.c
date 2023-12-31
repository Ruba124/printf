#include "main.h"

/**
 * is_printable - runs if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
	{   return (1); }

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char m_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
	{   ascii_code *= -1; }

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = m_to[ascii_code / 16];
	buffer[i] = m_to[ascii_code % 16];

	return (3);
}
/**
 * is_digit - checks if a char is a digit
 * @c: Char to be cheaked
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
/**
 * convert_size_number - Function that Casts a number to the specified size
 * @num: Number .
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == SZ_LONG)
		return (num);
	else if (size == SZ_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Function that casts a number to the specified size
 * @num: the Number to be casted
 * @size:the Number indicating the type to be casted
 *
 * Return:the casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == SZ_LONG)
		return (num);
	else if (size == SZ_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
