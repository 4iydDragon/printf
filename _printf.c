#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom implementation of printf function
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
        va_list args;
        int printed_chars = 0;
        char c;
        char *s;

        va_start(args, format);

        while (*format != '\0')
        {
                if (*format == '%')
                {
                        format++;
                        switch (*format)
                        {
                                case 'c':
                                        c = va_arg(args, int);
                                        putchar(c);
                                        printed_chars++;
                                        break;
                                case 's':
                                        s = va_arg(args, char *);
                                        if (s == NULL)
                                                s = "(null)";
                                        while (*s != '\0')
                                        {
                                                putchar(*s);
                                                s++;
                                                printed_chars++;
                                        }
                                        break;
                                case '%':
                                        putchar('%');
                                        printed_chars++;
                                        break;
                                default:
                                        putchar('%');
                                        putchar(*format);
                                        printed_chars += 2;
                                        break;
                        }
                }
                else
                {
                        putchar(*format);
                        printed_chars++;
                }
                format++;
        }

        va_end(args);

        return printed_chars;
}
