#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flag at the end 
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int xy;
	int current_k;
	int flags = 0;
	const char FLAGS_CHARACTER[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_k = *i + 1; format[current_k] != '\0'; current_k++)
	{
		for (xy = 0; FLAGS_CHARACTER[xy] != '\0'; xy++)
			if (format[current_k] == FLAGS_CHARACTER[xy])
			{
				flags |= FLAGS_ARRAY[xy];
				break;
			}

		if (FLAGS_CHARACTER[xy] == 0)
			break;
	}

	*i = current_k - 1;

	return (flags);
}


