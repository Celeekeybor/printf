#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024

/**
 * struct print_fn - Struct to hold format specifier and corresponding function
 * @spec: The format specifier
 * @fn: The corresponding function to print the specifier
 */
typedef struct print_fn
{
char *spec;
int (*fn)(va_list);
} print_fn_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

#endif /* MAIN_H */
