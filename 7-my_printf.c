#include "main.h"
#include <stdarg.h>

/**
 * print_plus_space - prints either a plus sign or a space
 * depending on the given flag and number
 * @flag: the flag character ('+' or ' ')
 * @num: the number to check
 *
 * Return: the number of characters printed
 */
int print_plus_space(char flag, int num)
{
int count = 0;
if (flag == '+' && num >= 0)
{
count += _putchar('+');
}
else if (flag == ' ' && num >= 0)
{
count += _putchar(' ');
}
return (count);
}

/**
 * print_hash - prints a prefix depending on the conversion specifier
 * and the given flag
 * @flag: the flag character ('#')
 * @specifier: the conversion specifier character
 *
 * Return: the number of characters printed
 */
int print_hash(char flag, char specifier)
{
int count = 0;
if (flag == '#')
{
if (specifier == 'o')
{
count += _putchar('0');
}
else if (specifier == 'x' || specifier == 'X')
{
count += _puts("0x");
}
}
return (count);
}

/**
 * _printf - custom implementation of printf
 * @format: a string of characters that specifies the output format
 *          (see printf documentation for details)
 * @...: optional arguments to print according to the format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
char flag = '\0';
va_start(args, format);
while (*format)
{
if (*format == '%')
{
flag = '\0';
format++;
while (*format == '+' || *format == ' ' || *format == '#')
{
flag = *format;
format++;
}
if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
count += print_plus_space(flag, num);
count += print_number(num);
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
if (!str)
{
str = "(null)";
}
count += _puts(str);
}
else if (*format == 'c')
{
char c = (char) va_arg(args, int);
count += _putchar(c);
}
else if (*format == 'x' || *format == 'X' || *format == 'o')
{
int num = va_arg(args, int);
count += print_hash(flag, *format);
count += print_number_base(num, *format);
}
else if (*format == 'p')
{
void *ptr = va_arg(args, void *);
count += _puts("0x");
count += print_address(ptr);
}
else if (*format == '%')
{
count += _putchar('%');
}
}
else
{
count += _putchar(*format);
}
format++;
}
va_end(args);
return (count);
}
