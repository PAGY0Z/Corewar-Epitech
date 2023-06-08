/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_strarraycat
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_strarraycat.c
/// \brief Contains the my_strarraycat function.
/// \author PAGY0Z
/// \version 0.1
/// \date 2023-28-05
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// \brief Concatenate an array into a new string.
/// \param array The array to concatenate.
/// \param mall_v1 The value to multiply the malloc by. Use 'MALL_VS'
/// \return The new string with the array concatenated.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if the array is NULL.
////////////////////////////////////////////////////////////////////////////////
char *my_strarraycat(char **array, int mall_v1)
{
    int len = 0; char *new_str = NULL;
    if ((len = my_array_strlen(array)) == -1) return NULL;
    if (!(new_str = malloc(sizeof(char) * ((len + 1) * mall_v1)))) return NULL;
    for (int i = 0, j = 0; array[i]; i++)
        for (int k = 0; array[i][k]; k++, j++)
            new_str[j] = array[i][k];
    new_str[len] = '\0';
    return new_str;
}
