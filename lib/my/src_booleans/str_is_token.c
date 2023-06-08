/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** str_is_token
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file str_is_token.c
/// \brief Contains the str_is_token function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

bool str_is_token(char const *str, char const *tokens);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if a string is only of tokens characters.
/// \param str The string to check.
/// \param tokens The string of tokens to check in.
/// \return true if the string is only of tokens characters, false otherwise.
/// \warning Returns false if one the the strings is NULL or empty.
////////////////////////////////////////////////////////////////////////////////
bool str_is_token(char const *str, char const *tokens)
{
    if (!str || !tokens) return false;
    if (!*str || !*tokens) return false;
    for (int i = 0; str[i]; i++)
        if (!is_token(str[i], tokens)) return false;
    return true;
}
