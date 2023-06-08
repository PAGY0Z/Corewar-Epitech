/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** add_str_to_array
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file add_str_to_array.c
/// \brief Contains the add_str_to_array function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

char **add_str_to_array(char **array, char *str, int *mall_vs);

////////////////////////////////////////////////////////////////////////////////
/// \brief Add an str to an array.
/// \param array The array to add the str to.
/// \param int_array The str to add to the array.
/// \param mall_vs The values to multiply the mallocs by. Use 'MALL_VS'
/// \return The new array with the str added.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if the array or the str are NULL.
////////////////////////////////////////////////////////////////////////////////
char **add_str_to_array(char **array, char *str, int *mall_vs)
{
    int arr_l = 0; char **n_arr = NULL;
    if (!array || !str) return NULL;
    arr_l = my_array_len(array);
    n_arr = malloc(sizeof(char *) * ((arr_l + 2) * mall_vs[0]));
    if (!n_arr) {
        my_perror("malloc");
        return NULL;
    }
    for (int i = 0; i < arr_l; i++)
        if (!(n_arr[i] = my_strdup(array[i], mall_vs[1]))) {
            freen_array(n_arr, i);
            return NULL;
        }
    if (!(n_arr[arr_l] = my_strdup(str, mall_vs[2]))) {
        freen_array(n_arr, arr_l);
        return NULL;
    }
    n_arr[arr_l + 1] = NULL;
    return n_arr;
}
