/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_strdup
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_strdup.c
/// \brief Contains the my_strdup function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

char *my_strdup(char const *str, int mall_v1);

////////////////////////////////////////////////////////////////////////////////
/// \brief Duplicates a string.
/// \param str The string to duplicate.
/// \param mall_v1 The value to multiply the malloc by. USE '1'
/// \return The duplicated string.
/// \attention Returns NULL if an error occurs.
/// \note Returns NULL if the string is NULL.
////////////////////////////////////////////////////////////////////////////////
char *my_strdup(char const *str, int mall_v1)
{
    int size = 0; char *new_str = NULL;
    if (!str) return NULL;
    size = my_strlen(str);
    if (!(new_str = malloc(sizeof(char) * ((size + 1) * mall_v1)))) {
        my_perror("malloc");
        return NULL;
    }
    for (int i = 0; str[i]; i++) new_str[i] = str[i];
    new_str[size] = '\0';
    return new_str;
}
