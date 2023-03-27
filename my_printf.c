#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * print_char - Prints a character to stdout
 * @args: A va_list containing a single character to print
 *
 * Return: The number of characters printed
 */
int print_char(va_list args)
{
char c = va_arg(args, int);
return (_putchar(c));
}

/**
 * print_string - Prints a string to stdout
 * @args: A va_list containing a string to print
 *
 * Return: The number of characters printed
 */
int print_string(va_list args)
{
char *str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
int i = 0;
while (str[i] != '\0')
_putchar(str[i++]);
return (i);
}

/**
 * print_percent - Prints a percent sign to stdout
 * @args: A va_list containing no arguments
 *
 * Return: The number of characters printed
 */
int print_percent(va_list args)
{
(void) args;
return (_putchar('%'));
}

/**
 * _printf - prints output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
count += print_char(args);
break;
case 's':
count += print_string(args);
break;
case '%':
count += print_percent(args);
break;
default:
count += _putchar('%');
count += _putchar(*format);
break;
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
