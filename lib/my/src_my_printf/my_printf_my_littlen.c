/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_printf_my_littlen
*/

#include "my_printf_header.h"

int my_littlen(luggage_t *log, flags_t *flags, va_list *ap)
{
    *va_arg(*ap, int *) = log->printed_char_count;
    (void)flags;
    return 0;
}
