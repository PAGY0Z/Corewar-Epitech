/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_arraydup
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_arraydup.c
/// \brief Contains the my_arraydup function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

char **my_arraydup(char **array, int *mall_vs);

////////////////////////////////////////////////////////////////////////////////
/// \brief Duplicates an array of strings.
/// \param array The array to duplicate.
/// \param mall_vs The values to multiply the mallocs by. USE 'MALL_VS'
/// \return The duplicated array.
/// \attention Returns NULL if an error occurs.
/// \note Returns NULL if the array is NULL.
////////////////////////////////////////////////////////////////////////////////
char **my_arraydup(char **array, int *mall_vs)
{
    int size = 0; char **new_array = NULL;
    if (!array) return NULL;
    size = my_array_len(array);
    if (!(new_array = malloc(sizeof(char *) * ((size + 1) * mall_vs[0])))) {
        my_perror("malloc");
        return NULL;
    }
    for (int i = 0; array[i]; i++)
        if (!(new_array[i] = my_strdup(array[i], mall_vs[1]))) {
            my_perror("malloc");
            freen_array(new_array, i);
            return NULL;
        }
    new_array[size] = NULL;
    return new_array;
}
