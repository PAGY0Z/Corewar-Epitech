/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_printf_my_getnbr
*/

#include "my_printf_header.h"

int my_getnbr_my_printf(char const * str, int starting_point, luggage_t *log)
{
    int i = starting_point;
    int nbr = 0;

    while (47 < str[i] && str[i] < 58) {
        nbr = nbr * 10 + (str[i] - 48);
        i++;
    }
    log->pos += i - starting_point;
    return nbr;
}
