/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** str_is_num
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file str_is_num.c
/// \brief Contains the str_is_num function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

bool str_is_num(char const *str);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if a string is only of numerical characters.
/// \param str The string to check.
/// \return true if the string is only of numerical characters, false otherwise.
/// \warning Returns false if the string is NULL or empty.
////////////////////////////////////////////////////////////////////////////////
bool str_is_num(char const *str)
{
    if (!str) return false;
    if (!*str) return false;
    for (int i = 0; str[i]; i++)
        if (!IS_NUM(str[i])) return false;
    return true;
}
