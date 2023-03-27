#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/* Recursively prints the binary representation of a number */
void print_binary(unsigned int num) {
if (num > 1) {
print_binary(num >> 1); /* recursively call print_binary with shifted number */
}
putchar((num & 1) ? '1' : '0'); /* print the least significant bit */
}
/* Custom printf function that handles binary conversion specifier (%b) */
int _printf(const char *format, ...) {
va_list args;
int printed_chars = 0;
va_start(args, format);
for (int i = 0; format[i] != '\0'; i++) {
if (format[i] == '%') {
i++;
if (format[i] == 'b') {
unsigned int num = va_arg(args, unsigned int); /* get the binary number */
print_binary(num); /* print its binary representation */
printed_chars += sizeof(num) * 8; /* count the number of bits printed */
}
/* handle other conversion specifiers */
} else {
putchar(format[i]); /* print the character as is */
printed_chars++;
}
}
va_end(args);
return printed_chars; /* return the number of characters printed */
}
/* Example usage */
int main() {
int num = 42;
_printf("The binary representation of %d is %b\n", num, num);
return 0;
}
