/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_strlen_sepa
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_strlen_sepa.c
/// \brief Contains the my_strlen_sepa function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int my_strlen_sepa(char const *str, char const *sepa);

////////////////////////////////////////////////////////////////////////////////
/// \brief Measures the length of a string until a separator.
/// \param str The string to measure the length of.
/// \param sepa The separators to measure the length of the string with.
/// \return The length of the string until a separator.
/// \warning Returns -1 if is str or sepa is NULL.
////////////////////////////////////////////////////////////////////////////////
int my_strlen_sepa(char const *str, char const *sepa)
{
    int i = 0;
    if (!str || !sepa) return -1;
    for (; str[i] && !is_token(str[i], sepa); i++);
    return i;
}
