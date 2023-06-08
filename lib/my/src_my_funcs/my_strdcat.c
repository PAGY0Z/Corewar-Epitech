/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_strdcat
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_strdcat.c
/// \brief Contains the my_strdcat function.
/// \author PAGY0Z
/// \version 0.1
/// \date 2023-28-05
////////////////////////////////////////////////////////////////////////////////

char *my_strdcat(char const *s1, char const *s2, char const *s3, int mall_v1);

////////////////////////////////////////////////////////////////////////////////
/// \brief Concatenate 3 strings into a new string.
/// \param s1 The first string to concatenate.
/// \param s2 The second string to concatenate.
/// \param s3 The third string to concatenate.
/// \param mall_v1 The value to multiply the malloc by. Use '1'
/// \return The new string with the 3 strings concatenated.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if one of the strings is NULL.
////////////////////////////////////////////////////////////////////////////////
char *my_strdcat(char const *s1, char const *s2, char const *s3, int mall_v1)
{
    int i = 0; int size = 0; char *new_str = NULL;
    if (!s1 || !s2 || !s3) return NULL;
    size = my_strlen(s1) + my_strlen(s2) + my_strlen(s3);
    if (!(new_str = malloc(sizeof(char) * ((size + 1) * mall_v1)))) {
        my_perror("malloc");
        return NULL;
    }
    for (; s1[i]; i++) new_str[i] = s1[i];
    for (int j = 0; s2[j]; j++, i++) new_str[i] = s2[j];
    for (int j = 0; s3[j]; j++, i++) new_str[i] = s3[j];
    new_str[size] = '\0';
    return new_str;
}
