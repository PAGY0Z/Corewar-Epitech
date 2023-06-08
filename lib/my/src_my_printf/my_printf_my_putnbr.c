/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_printf_my_putnbr
*/

#include "my_printf_header.h"

int nbr_flags(long long nb, luggage_t *log, flags_t *flags)
{
    int sharp = (flags->sharp);
    if (nb > 0) {
        if (flags->conversion == 'o' && sharp)
            log->printed_char_count += my_putcharp('0');
        if (is_tokenp(flags->conversion, "xX") && sharp) {
            log->printed_char_count += my_putcharp('0');
            log->printed_char_count += my_putcharp(flags->conversion);
        }
        if (is_tokenp(flags->conversion, "bB") && sharp) {
            log->printed_char_count += my_putcharp('0');
            log->printed_char_count += my_putcharp(flags->conversion);
        }
        if (flags->plus && is_tokenp(flags->conversion, PRINTF_INT_FLAGS))
            log->printed_char_count += my_putcharp('+');
    }
    return 0;
}

long long nb_conversion(long long nb, char c)
{
    if (is_tokenp(c, PRINTF_INT_FLAGS))
        nb = (int)nb;
    if (is_tokenp(c, PRINTF_UINT_FLAGS))
        nb = (unsigned int)nb;
    return nb;
}

int my_putnbr_my_printf(long long nb,  char const *bs, char cnv)
{
    int count = 0;
    if (nb < 0) {
        nb = -nb;
        count += my_putcharp('-');
    }
    if (nb < my_strlen_my_printf(bs, 0)) {
        count += my_putcharp(bs[nb]);
    } else {
        count += my_putnbr_my_printf(nb / my_strlen_my_printf(bs, 0), bs, cnv);
        count += my_putcharp(bs[nb % my_strlen_my_printf(bs, 0)]);
    }
    return count;
}

int my_putnbr_va(luggage_t *l, flags_t *f, va_list *ap)
{
    long long n = va_arg(*ap, long long);
    n = nb_conversion(n, f->conversion);
    nbr_flags(n, l, f);
    int i = 0;
    while (base[i].c != f->conversion) {
        i++;
    }
    l->printed_char_count += my_putnbr_my_printf(n, base[i].base,
    f->conversion);
    return 0;
}
