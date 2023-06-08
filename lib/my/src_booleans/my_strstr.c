/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_strstr
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_strstr.c
/// \brief Contains the my_strstr function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

bool my_strstr(char const *str1, char const *str2);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if a string is in another string.
/// \param str1 The string to check.
/// \param str2 The string to check in.
/// \return true if the string is in the other string, false otherwise.
/// \warning Returns false if one of the strings is NULL or empty.
////////////////////////////////////////////////////////////////////////////////
bool my_strstr(char const *str1, char const *str2)
{
    int len1 = 0; int len2 = 0;
    if (!str1 || !str2) return false;
    if (!*str1 || !*str2) return false;
    if ((len1 = my_strlen(str1)) < (len2 = my_strlen(str2))) return false;
    for (int i = 0; str1[i]; i++)
        if (my_strncmp(str1 + i, str2, len2)) return true;
    return false;
}
