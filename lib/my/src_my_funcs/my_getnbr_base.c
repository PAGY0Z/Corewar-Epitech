/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_getnbr_base
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_getnbr_base.c
/// \brief Contains the my_getnbr_base function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int my_getnbr_base(char const *str, char const *base);

////////////////////////////////////////////////////////////////////////////////
/// \brief Get the number from a string in a given base.
/// \param str The string.
/// \param base The base.
/// \return The number.
/// \note Returns -1 if the string or the base is NULL or empty.
/// \note Returns 0 if the base length is less than 2.
/// \note Returns 0 if the string contains a character not in the base.
////////////////////////////////////////////////////////////////////////////////
int my_getnbr_base(char const *str, char const *base)
{
    long long nbr = 0; int sign = 1; int base_len = 0; int i = 0;
    if (!str || !base) return -1;
    if (!*str || (base_len = my_strlen(base)) < 2) return -1;
    for (; IS_SIGN(str[i]); i++) sign = (str[i] == '-') ? sign * -1 : sign;
    if (!str_is_token(str + i, base)) return -1;
    for (; str[i]; i++)
        nbr = nbr * base_len + my_strlen_sepa(base, (char []){str[i], 0});
    return (int)(nbr * sign);
}
