/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_strncat
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_strncat.c
/// \brief Contains the my_strncat function.
/// \author PAGY0Z
/// \version 0.1
/// \date 2023-28-05
////////////////////////////////////////////////////////////////////////////////

char *my_strncat(char const *str1, char const *str2, int n, int mall_v1);

////////////////////////////////////////////////////////////////////////////////
/// \brief Concatenate a string to n characters of another string.
/// \param str1 The string to concatenate to.
/// \param str2 The string to concatenate.
/// \param n The number of characters to concatenate.
/// \param mall_v1 The value to multiply the malloc by. Use '1'
/// \return The concatenated string.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if one of the strings is NULL. Returns NULL if n < 0.
////////////////////////////////////////////////////////////////////////////////
char *my_strncat(char const *str1, char const *str2, int n, int mall_v1)
{
    int i = 0; int size = 0; char *new_str = NULL;
    if (!str1 || !str2 || n < 0) return NULL;
    size = my_strlen(str1) + MIN(my_strlen(str2), n);
    if (!(new_str = malloc(sizeof(char) * ((size + 1) * mall_v1)))) {
        my_perror("malloc");
        return NULL;
    }
    for (; str1[i]; i++) new_str[i] = str1[i];
    for (int j = 0; str2[j] && j < n; j++, i++) new_str[i] = str2[j];
    new_str[size] = '\0';
    return new_str;
}
