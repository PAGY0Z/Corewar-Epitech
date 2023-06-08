/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_strncmp
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_strncmp.c
/// \brief Contains the my_strncmp function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

bool my_strncmp(char const *str1, char const *str2, int n);

////////////////////////////////////////////////////////////////////////////////
/// \brief Compare n characters of two strings.
/// \param str1 The first string to compare.
/// \param str2 The second string to compare.
/// \param n The number of characters to compare.
/// \return true if n characters of the strings are the same, false otherwise.
/// \warning Returns false if one of the strings is NULL.
////////////////////////////////////////////////////////////////////////////////
bool my_strncmp(char const *str1, char const *str2, int n)
{
    if (!str1 || !str2) return false;
    if ((n = MIN(n, my_strlen(str1))) <= 0) return true;
    for (int i = 0; i < n; i++)
        if (str1[i] != str2[i]) return false;
    return true;
}
