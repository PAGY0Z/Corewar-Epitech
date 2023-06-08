/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** str_is_number
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file str_is_number.c
/// \brief Contains the str_is_number function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

bool str_is_number(char const *str);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if a string is only of number characters.
/// \param str The string to check.
/// \return true if the string is only of number characters, false otherwise.
/// \warning Returns false if the string is NULL or empty.
////////////////////////////////////////////////////////////////////////////////
bool str_is_number(char const *str)
{
    int i = 0; int save = 0;
    if (!str) return false;
    if (!*str) return false;
    for (; IS_SIGN(str[i]); i++);
    save = i;
    for (; IS_NUM(str[i]); i++);
    if (i == save) return false;
    if (str[i]) return false;
    return true;
}
