/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** str_is_in_array
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file str_is_in_array.c
/// \brief Contains the str_is_in_array function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

bool str_is_in_array(char **array, char const *str);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if a string is in an array.
/// \param array The array to check.
/// \param str The string to check.
/// \return true if the string is in the array, false otherwise.
/// \warning The array must be NULL terminated.
/// \note The function will return false if the array or the string is NULL.
////////////////////////////////////////////////////////////////////////////////
bool str_is_in_array(char **array, char const *str)
{
    if (!array || !str) return false;
    for (int i = 0; array[i]; i++)
        if (my_strcmp(array[i], str)) return true;
    return false;
}
