/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** free_array
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file free_array.c
/// \brief Contains the free_array function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

void free_array(char **array);

////////////////////////////////////////////////////////////////////////////////
/// \brief Frees an array.
/// \param array The array to free.
/// \attention The array must be NULL terminated & memory allocated
/// \warning Returns if the array is NULL.
////////////////////////////////////////////////////////////////////////////////
void free_array(char **array)
{
    if (!array) return;
    for (int i = 0; array[i]; i++) my_free(array[i]);
    my_free(array);
}
