/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_intarray_len
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_intarray_len.c
/// \brief Contains the my_intarray_len function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int my_intarray_len(int *int_array);

////////////////////////////////////////////////////////////////////////////////
/// \brief Measures the length of an int array.
/// \param int_array The int array to measure the length of.
/// \return The length of the int array.
/// \warning Returns -1 if the int array is NULL.
////////////////////////////////////////////////////////////////////////////////
int my_intarray_len(int *int_array)
{
    int i = 0;
    if (!int_array) return -1;
    for (; int_array[i] != -1; i++);
    return i;
}
