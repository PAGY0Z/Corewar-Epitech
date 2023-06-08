/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_len_nbr
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_len_nbr.c
/// \brief Contains the my_len_nbr function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int my_len_nbr(int nbr);

////////////////////////////////////////////////////////////////////////////////
/// \brief Measures the length of an int.
/// \param nbr The int to measure the length of.
/// \return The length of the int.
/// \warning Returns +1 if the int is negative.
////////////////////////////////////////////////////////////////////////////////
int my_len_nbr(int nbr)
{
    int i = 0;
    if (nbr < 0) {
        nbr = -nbr;
        i++;
    }
    for (; nbr > 9; i++, nbr /= 10);
    return i + 1;
}
