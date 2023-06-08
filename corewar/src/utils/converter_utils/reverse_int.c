/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** reverse_int
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file reverse_int.c
/// \brief Contains the reverse_int function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-23-05
////////////////////////////////////////////////////////////////////////////////

int reverse_int(int nb);

////////////////////////////////////////////////////////////////////////////////
/// \brief Reverse an int.
/// \param nb The int to reverse.
/// \return The reversed int.
////////////////////////////////////////////////////////////////////////////////
int reverse_int(int nb)
{
    int res = 0;

    res |= (nb & 0xFF) << 24;
    res |= (nb & 0xFF00) << 8;
    res |= (nb & 0xFF0000) >> 8;
    res |= (nb & 0xFF000000) >> 24;
    return res;
}
