#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Function
 * @format: format
 * Return: Printed chars.
 */

int _printf(const char *format, ...)

{
int w, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (w = 0; format && format[w] != '\0'; w++)
{
if (format[w] != '%')
{
buffer[buff_ind++] = format[w];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
/* write(1, &format[w], 1);*/
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(format, &w);
width = get_width(format, &w, list);
precision = get_precision(format, &w, list);
size = get_size(format, &w);
++w;
printed = handle_print(format, &w, list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
print_buffer(buffer, &buff_ind);
va_end(list);
return (printed_chars);

}


/**
 * print_buffer - Prints the contents of the buffer
 * @buffer: Array
 * @buff_ind: Index
 */

void print_buffer(char buffer[], int *buff_ind)

{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;

}
