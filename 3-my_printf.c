#include "holberton.h"
#include <stdlib.h>

/**
 * print_unsigned_int - prints an unsigned integer
 *
 * @n: the unsigned integer to print
 * @base: the base to print in (10 for decimal, 8 for octal, 16 for hex)
 * @spec: the conversion specifier ('u', 'o', 'x', or 'X')
 * @printed: the number of characters printed so far
 *
 * Return: the number of characters printed
 */
static int print_unsigned_int(unsigned int n, int base, char spec, int printed)
{
	char *digits = "0123456789abcdef";
	int rem, len = 0;
	char buf[32];

	do {
		rem = n % base;
		buf[len++] = digits[rem];
		n /= base;
	} while (n > 0);

	if (spec == 'X')
		digits = "0123456789ABCDEF";

	while (len--)
	{
		_putchar(buf[len]);
		printed++;
	}

	return (printed);
}

/**
 * print_u - prints an unsigned integer in decimal notation
 *
 * @args: the va_list containing the unsigned integer to print
 *
 * Return: the number of characters printed
 */
int print_u(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	return (print_unsigned_int(n, 10, 'u', 0));
}

/**
 * print_o - prints an unsigned integer in octal notation
 *
 * @args: the va_list containing the unsigned integer to print
 *
 * Return: the number of characters printed
 */
int print_o(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	return (print_unsigned_int(n, 8, 'o', 0));
}

/**
 * print_x - prints an unsigned integer in lowercase hex notation
 *
 * @args: the va_list containing the unsigned integer to print
 *
 * Return: the number of characters printed
 */
int print_x(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	return (print_unsigned_int(n, 16, 'x', 0));
}

/**
 * print_X - prints an unsigned integer in uppercase hex notation
 *
 * @args: the va_list containing the unsigned integer to print
 *
 * Return: the number of characters printed
 */
int print_X(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	return (print_unsigned_int(n, 16, 'X', 0));
}
