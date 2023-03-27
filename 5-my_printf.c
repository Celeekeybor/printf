#include "main.h"

/**
 * _printf - prints formatted output to stdout
 * @format: the format string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0, i = 0, j = 0;
char buffer[1024];
char *str;
if (format == NULL)
return (-1);
va_start(args, format);
while (format[i])
{
if (format[i] != '%')
{
buffer[j++] = format[i++];
if (j == 1024)
{
count += write(1, buffer, j);
j = 0;
}
}
else
{
str = get_specifier_func(&format[i + 1])(args);
if (str == NULL)
return (-1);
count += write(1, str, _strlen(str));
free(str);
i += 2;
}
}
if (j > 0)
count += write(1, buffer, j);
va_end(args);
return (count);
}
