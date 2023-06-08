/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_strcmp
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_strcmp.c
/// \brief Contains the my_strcmp function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

bool my_strcmp(char const *str1, char const *str2);

////////////////////////////////////////////////////////////////////////////////
/// \brief Compare two strings.
/// \param str1 The first string to compare.
/// \param str2 The second string to compare.
/// \return true if the strings are the same, false otherwise.
/// \warning Returns false if one of the strings is NULL.
////////////////////////////////////////////////////////////////////////////////
bool my_strcmp(char const *str1, char const *str2)
{
    if (!str1 || !str2) return false;
    for (int i = 0; str1[i] || str2[i]; i++)
        if (str1[i] != str2[i]) return false;
    return true;
}
