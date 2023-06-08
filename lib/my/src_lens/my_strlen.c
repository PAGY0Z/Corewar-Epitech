/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_strlen
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_strlen.c
/// \brief Contains the my_strlen function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int my_strlen(char const *str);

////////////////////////////////////////////////////////////////////////////////
/// \brief Measures the length of a string.
/// \param str The string to measure the length of.
/// \return The length of the string.
/// \warning Returns -1 if the string is NULL.
////////////////////////////////////////////////////////////////////////////////
int my_strlen(char const *str)
{
    int i = 0;
    if (!str) return -1;
    for (; str[i]; i++);
    return i;
}
