/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_strcat
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_strcat.c
/// \brief Contains the my_strcat function.
/// \author PAGY0Z
/// \version 0.1
/// \date 2023-28-05
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// \brief Concatenate two strings.
/// \param str1 The first string to concatenate.
/// \param str2 The second string to concatenate.
/// \param mall_v1 The value to multiply the malloc by. Use '1'
/// \return The concatenated string.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if one of the strings is NULL.
////////////////////////////////////////////////////////////////////////////////
char *my_strcat(char const *str1, char const *str2, int mall_v1)
{
    int i = 0; int size = 0; char *new_str = NULL;
    if (!str1 || !str2) return NULL;
    size = my_strlen(str1) + my_strlen(str2);
    if (!(new_str = malloc(sizeof(char) * ((size + 1) * mall_v1)))) {
        my_perror("malloc");
        return NULL;
    }
    for (; str1[i]; i++) new_str[i] = str1[i];
    for (int j = 0; str2[j]; j++, i++) new_str[i] = str2[j];
    new_str[size] = '\0';
    return new_str;
}
