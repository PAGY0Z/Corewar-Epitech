/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** is_token
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file is_token.c
/// \brief Contains the is_token function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

bool is_token(char c, char const *tokens);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if a char is in a string.
/// \param c The char to check.
/// \param tokens The string to check in.
/// \return true if the char is in the string, false otherwise.
/// \warning Returns false if the tokens is NULL or empty.
////////////////////////////////////////////////////////////////////////////////
bool is_token(char c, char const *tokens)
{
    if (!tokens) return false;
    if (!*tokens) return false;
    for (int i = 0; tokens[i]; i++)
        if (c == tokens[i]) return true;
    return false;
}
