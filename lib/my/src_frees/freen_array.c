/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** freen_array
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file freen_array.c
/// \brief Contains the freen_array function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

void freen_array(char **array, int n);

////////////////////////////////////////////////////////////////////////////////
/// \brief Frees n elements of an array.
/// \param array The array to free.
/// \param n The number of elements to free.
/// \attention The array must be NULL terminated & memory allocated
/// \warning Returns if the array is NULL or n is negative.
////////////////////////////////////////////////////////////////////////////////
void freen_array(char **array, int n)
{
    if (!array || n < 0) return;
    n = MIN(n, my_array_len(array));
    for (int i = 0; i < n; i++) my_free(array[i]);
    my_free(array);
}
