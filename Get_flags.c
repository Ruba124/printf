#include "main.h"

/**
 * g_flags -function that calculates the active flags
 * @format: the formatted string in which to print the arguments
 * @i:parameter.
 * Return: the flags:
 */
int g_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int r, c_i;
	int the_flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[6] = {N_MINUS, N_PLUS, N_ZERO, N_HASH, N_SPACE, 0};

	for (c_i = *i + 1; format[c_i] != '\0'; c_i++)
	{
		for (r = 0; FLAGS_CH[r] != '\0'; r++)
			if (format[c_i] == FLAGS_CH[r])
			{
				the_flags |= FLAGS_ARR[r];
				break;
			}

		if (FLAGS_CH[r] == 0)
			break;
	}

	*i = c_i - 1;

	return (the_flags);
}
