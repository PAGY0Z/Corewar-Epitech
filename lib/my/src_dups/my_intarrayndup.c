/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_intarrayndup
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_intarrayndup.c
/// \brief Contains the my_intarrayndup function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int *my_intarrayndup(int *intarray, int n, int mall_v1);

////////////////////////////////////////////////////////////////////////////////
/// \brief Duplicates n element of an int array.
/// \param intarray The int array to duplicate.
/// \param n The number of elements to duplicate.
/// \param mall_v1 The value to multiply the malloc by. USE '1'
/// \return The new table with the int array added.
/// \attention Returns NULL if an error occurs.
/// \note Returns NULL if the table or the int array are NULL.
////////////////////////////////////////////////////////////////////////////////
int *my_intarrayndup(int *intarray, int n, int mall_v1)
{
    int *n_arr = NULL;
    if (!intarray || n < 0) return NULL;
    n = MIN(my_intarray_len(intarray), n);
    if (!(n_arr = malloc(sizeof(int) * ((n + 1) * mall_v1)))) {
        my_perror("malloc");
        return NULL;
    }
    for (int i = 0; i < n; i++) n_arr[i] = intarray[i];
    n_arr[n] = -1;
    return n_arr;
}
