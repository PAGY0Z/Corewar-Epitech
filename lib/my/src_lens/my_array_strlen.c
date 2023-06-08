/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_array_strlen
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_array_strlen.c
/// \brief Contains the my_array_strlen function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int my_array_strlen(char **array);

////////////////////////////////////////////////////////////////////////////////
/// \brief Measures the length of an array and the length of each element.
/// \param array The array of strings to measure the length of.
/// \return The length of the strings of the array.
/// \warning Returns -1 if the array is NULL.
////////////////////////////////////////////////////////////////////////////////
int my_array_strlen(char **array)
{
    int len = 0;
    if (!array) return -1;
    for (int i = 0; array[i]; i++) len += my_strlen(array[i]);
    return len;
}
