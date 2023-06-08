/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_printf_my_putstr
*/

#include "my_printf_header.h"

int my_strlen_my_printf(char const *str, int count)
{
    while (str[count]) {
        count++;
    }
    return count;
}

int my_putstr_va(luggage_t *log, flags_t *flags, va_list *ap)
{
    (void)flags;
    return log->printed_char_count += my_putstrp(va_arg(*ap, char*));
}
