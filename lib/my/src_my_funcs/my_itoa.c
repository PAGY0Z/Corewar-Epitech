/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_itoa
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_itoa.c
/// \brief Contains the my_itoa function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

char *my_itoa_helper(char *str, int nbr);
char *my_itoa(int nbr, int mall_v1);

////////////////////////////////////////////////////////////////////////////////
/// \brief Helper function for my_itoa.
/// \param str The string to convert.
/// \param nbr The int to convert.
/// \return The string converted from the int.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if the table or the int array are NULL.
////////////////////////////////////////////////////////////////////////////////
char *my_itoa_helper(char *str, int nbr)
{
    if (nbr <= -10)
        str = my_itoa_helper(str, nbr / 10);
    *str++ = '0' - nbr % 10;
    return str;
}

////////////////////////////////////////////////////////////////////////////
/// \brief Converts an int to a string.
/// \param nbr The int to convert.
/// \param mall_v1 The value to multiply the malloc by. USE '1'.
/// \return The string converted from the int.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if the table or the int array are NULL.
////////////////////////////////////////////////////////////////////////////
char *my_itoa(int nbr, int mall_v1)
{
    char *str_ptr = malloc(sizeof(char) * (my_len_nbr(nbr) * mall_v1));
    char *str = NULL;
    if (str_ptr == NULL) {
        my_perror("malloc");
        return NULL;
    }
    str = str_ptr;
    if (nbr < 0)
        *str++ = '-';
    else
        nbr = -nbr;
    *my_itoa_helper(str, nbr) = '\0';
    return str_ptr;
}
