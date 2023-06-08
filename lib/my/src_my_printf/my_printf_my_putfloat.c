/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_printf_my_putfloat
*/

#include "my_printf_header.h"

float rounded_float(double nbr, int precision)
{
    int i = 0;
    while (i < precision) {
        nbr *= 10.0;
        i++;
    }
    if (((nbr * 10.0) - ((int)nbr) * 10) >= 5)
        nbr += 1;
    for (i = 0; i < precision; i++)
        nbr /= 10.0;
    return nbr;
}

double my_negfloat(double nb)
{
    if (nb < 0)
        return -nb;
    return nb;
}

int my_putfloat(double nbr, int precision, char conversion)
{
    int count = 0;
    if (nbr < 0.0)
        count += my_putcharp('-');
    nbr = my_negfloat(nbr);
    nbr = rounded_float(nbr, precision);

    count += my_putnbr_my_printf((int)nbr, "0123456789", conversion);
    nbr -= (int)nbr;
    if (precision > 0.0) {
        count += write(1, ".", 1);
        while (precision != 0) {
            nbr *= 10.0;
            count += my_putnbr_my_printf((int)nbr, "0123456789", conversion);
            nbr -= (int)nbr;
            precision--;
        }
    }
    return count;
}

int my_putfloat_va(luggage_t *log, flags_t *flags, va_list *ap)
{
    double nb = va_arg(*ap, double);
    int precision = (flags->precision_check) ? flags->precision : 6;
    char f = flags->conversion;

    log->printed_char_count += my_putfloat(nb, precision, f);
    return 0;
}
