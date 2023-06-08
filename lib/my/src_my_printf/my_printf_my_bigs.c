/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_printf_my_bigs
*/

#include "my_printf_header.h"

int my_putstrp(char const *str)
{
    int count = 0;

    while (str[count]) {
        my_putcharp(str[count]);
        count++;
    }
    return count;
}

int my_putcharp(char c)
{
    return write(1, &c, 1);
}

int print_octal(long long oct)
{
    if (oct < 8) {
        my_putstrp("00");
        return 2;
    } else if (oct < 32) {
        my_putcharp('0');
        return 1;
    }
    return 0;
}

int my_bigs(luggage_t *log, flags_t *flags, va_list *ap)
{
    (void)*flags;
    char *str = va_arg(*ap, char*);
    unsigned char c;
    int count;
    for (int i = 0; str[i]; i++) {
        if (32 < str[i] && str[i] < 127)
            log->printed_char_count += my_putcharp(str[i]);
        else {
            c = str[i];
            log->printed_char_count += my_putcharp('\\');
            log->printed_char_count += print_octal((long long)c);
            count = my_putnbr_my_printf((long long)c, "01234567", 'S');
            log->printed_char_count += count;
        }
    }
    return 0;
}
