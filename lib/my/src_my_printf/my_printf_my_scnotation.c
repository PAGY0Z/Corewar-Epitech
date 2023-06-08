/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_printf_my_scnotation
*/

#include "my_printf_header.h"

int my_scnotation(double nb, int precision, int exp, char e)
{
    int count = 0;
    count += my_putfloat(nb, precision, e);
    count += my_putcharp(e);
    if (exp >= 0) {
        count += my_putcharp('+');
        if (exp < 10)
            count += my_putcharp('0');
        count += my_putnbr_my_printf(exp, "0123456789", e);
    } else  {
        count += my_putcharp('-');
        if (exp > -10)
            count += my_putcharp('0');
        count += my_putnbr_my_printf(-exp, "0123456789", e);
    }
    return count;
}

int int_to_scfloat(double nb, int precision, char e)
{
    int exp = 0;
    if (nb == 0.0)
        return my_scnotation(0.0, precision, exp, e);
    if (nb < 0) {
        my_putcharp ('-');
        nb = -nb;
    }
    while ( ! (1 <= nb && nb < 10)) {
        if (nb >= 10) {
            nb /= 10.0f;
            exp++;
        } else {
            nb *= 10.0f;
            exp--;
        }
    }
    return my_scnotation(nb, precision, exp, e);;
}

int my_scnotation_va(luggage_t *log, flags_t *flags, va_list *ap)
{
    char conversion = flags->conversion;
    double nbr = va_arg(*ap, double);
    int precision = 0;
    if (flags->precision_check)
        precision = flags->precision;
    else
        precision = 6;
    log->printed_char_count += int_to_scfloat(nbr, precision, conversion);
    return 0;
}
