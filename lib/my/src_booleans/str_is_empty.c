/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** str_is_empty
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file str_is_empty.c
/// \brief Contains the str_is_empty function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

bool str_is_empty(char const *str);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if a string is only of empty characters.
/// \param str The string to check.
/// \return true if the string is only of empty characters, false otherwise.
/// \warning Returns false if the string is NULL or empty.
////////////////////////////////////////////////////////////////////////////////
bool str_is_empty(char const *str)
{
    if (!str) return true;
    if (!*str) return true;
    for (int i = 0; str[i]; i++)
        if (!IS_EMPTY_CHAR(str[i])) return false;
    return true;
}
