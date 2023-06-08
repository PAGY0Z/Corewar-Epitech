/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_printf_my_putchar
*/

#include "my_printf_header.h"

int my_putchar_va(luggage_t *log, flags_t *flags, va_list *ap)
{
    log->printed_char_count += my_putcharp(va_arg(*ap, int));
    (void)flags;
    return 0;
}
