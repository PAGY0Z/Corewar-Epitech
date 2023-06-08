/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_printf_my_hexaptr
*/

#include "my_printf_header.h"

int my_little_pony(long long ptr, char conversion)
{
    int count = 0;
    count += my_putstrp("0x");
    count += my_putnbr_my_printf(ptr, "0123456789abcdef", conversion);
    return count;
}

int my_hexaptr_va(luggage_t *log, flags_t *flags, va_list *ap)
{
    long long next_arg = va_arg(*ap, long long);
    log->printed_char_count += my_little_pony(next_arg, flags->conversion);
    return 0;
}
