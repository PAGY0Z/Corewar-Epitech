/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** convert_4chars_1int
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file convert_4chars_1int.c
/// \brief Contains the convert_4chars_1int function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int convert_4chars_1int(uchar_t b1, uchar_t b2, uchar_t b3, uchar_t b4);

////////////////////////////////////////////////////////////////////////////////
/// \brief Convert 4 chars into 1 int
/// \param b1 The first char.
/// \param b2 The second char.
/// \param b3 The third char.
/// \param b4 The fourth char.
/// \return The int converted from the 4 chars.
////////////////////////////////////////////////////////////////////////////////
int convert_4chars_1int(uchar_t b1, uchar_t b2, uchar_t b3, uchar_t b4)
{
    return ((b1 << 24) | (b2 << 16) | (b3 << 8) | b4);
}
