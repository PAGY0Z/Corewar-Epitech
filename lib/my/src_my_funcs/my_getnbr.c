/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_getnbr
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_getnbr.c
/// \brief Contains the my_getnbr function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int my_getnbr(char const *str);

////////////////////////////////////////////////////////////////////////////////
/// \brief Converts a string to an int.
/// \param str The string to convert.
/// \return The int converted from the string.
/// \warning Returns -1 if an error occurs.
/// \note Returns -1 if the string is NULL or empty or if it contains a
/// non-number character.
////////////////////////////////////////////////////////////////////////////////
int my_getnbr(char const *str)
{
    long nbr = 0; int sign = 1; int i = 0;
    if (!str) return -1;
    if (!*str) return -1;
    if (!str_is_number(str)) return -1;
    for (; IS_SIGN(str[i]); i++) sign = (str[i] == '-') ? sign * -1 : sign;
    for (; str[i]; i++)
        nbr = nbr * 10 + (str[i] - '0');
    return nbr * sign;
}
