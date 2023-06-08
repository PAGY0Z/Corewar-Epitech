/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_intarraydup
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_intarraydup.c
/// \brief Contains the my_intarraydup function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int *my_intarraydup(int *intarray, int mall_v1);

////////////////////////////////////////////////////////////////////////////////
/// \brief Duplicates an int array.
/// \param intarray The int array to duplicate.
/// \param mall_v1 The value to multiply the malloc by. USE '1'
/// \return The duplicated int array.
/// \attention Returns NULL if an error occurs.
/// \note Returns NULL if the array is NULL.
////////////////////////////////////////////////////////////////////////////////
int *my_intarraydup(int *intarray, int mall_v1)
{
    int arr_l = 0; int *n_arr = NULL;
    if (!intarray) return NULL;
    arr_l = my_intarray_len(intarray);
    if (!(n_arr = malloc(sizeof(int) * ((arr_l + 1) * mall_v1)))) {
        my_perror("malloc");
        return NULL;
    }
    for (int i = 0; i < arr_l; i++) n_arr[i] = intarray[i];
    n_arr[arr_l] = -1;
    return n_arr;
}
