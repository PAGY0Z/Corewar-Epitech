/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** fill_array
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file fill_array.c
/// \brief Contains the fill_array function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

bool fill_array(char **array, char value);

////////////////////////////////////////////////////////////////////////////////
/// \brief Fill an array with a value.
/// \param array The array to fill.
/// \param value The value to fill the array with.
/// \return true if the array was filled, false otherwise.
/// \warning The array & each sub-array must be NULL terminated.
/// \note Returns false if the array is NULL.
////////////////////////////////////////////////////////////////////////////////
bool fill_array(char **array, char value)
{
    if (!array) return false;
    for (int y = 0; array[y]; y++)
        for (int x = 0; array[y][x]; x++)
            array[y][x] = value;
    return true;
}
