#include "main.h"

/**
 * _printf - Print formatted output to stdout
 * @format: A string containing format specifiers
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
int count = 0;
va_list args;
const char *p;
va_start(args, format);
for (p = format; *p != '\0'; p++) {
if (*p == '%') {
/* Handle conversion specifier */
switch (*(++p)) {
case 'p':
count += printf("%p", va_arg(args, void *));
break;
default:
count += printf("%%%c", *p);
break;
}
} else {
/* Handle normal characters */
count += printf("%c", *p);
}
}
va_end(args);
return count;
}
