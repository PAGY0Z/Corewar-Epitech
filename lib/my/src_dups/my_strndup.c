/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_strndup
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_strndup.c
/// \brief Contains the my_strndup function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

char *my_strndup(char const *str, int n, int mall_v1);

////////////////////////////////////////////////////////////////////////////////
/// \brief Duplicates n elements of a string.
/// \param str The string to duplicate.
/// \param n The number of elements to duplicate.
/// \param mall_v1 The value to multiply the malloc by. USE '1'
/// \return The duplicated string.
/// \attention Returns NULL if an error occurs.
/// \note Returns NULL if the string is NULL. Returns NULL if n < 0.
////////////////////////////////////////////////////////////////////////////////
char *my_strndup(char const *str, int n, int mall_v1)
{
    char *new_str = NULL;
    if (!str || n < 0) return NULL;
    n = MIN(my_strlen(str), n);
    if (!(new_str = malloc(sizeof(char) * ((n + 1) * mall_v1)))) {
        my_perror("malloc");
        return NULL;
    }
    for (int i = 0; i < n; i++) new_str[i] = str[i];
    new_str[n] = '\0';
    return new_str;
}
