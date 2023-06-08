/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_array_len
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_array_len.c
/// \brief Contains the my_array_len function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int my_array_len(char **array);

////////////////////////////////////////////////////////////////////////////////
/// \brief Measures the length of an array.
/// \param array The array to measure the length of.
/// \return The length of the array.
/// \warning Returns -1 if the array is NULL.
////////////////////////////////////////////////////////////////////////////////
int my_array_len(char **array)
{
    int i = 0;
    if (!array) return -1;
    for (; array[i]; i++);
    return i;
}
