/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** get_short
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file get_short.c
/// \brief Contains the get_short function.
/// \author PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-26-05
////////////////////////////////////////////////////////////////////////////////

short get_short(byte_t *params, int adress);

////////////////////////////////////////////////////////////////////////////////
/// \brief Returns the short value of a parameter.
/// \param params A pointer to the parameters.
/// \param adress The adress of the parameter.
/// \return The short value of the parameter.
////////////////////////////////////////////////////////////////////////////////
short get_short(byte_t *params, int adress)
{
    if (adress < 0 || 12 < adress)
        return 0;
    return (((params[adress] & 0xff) << 8) | (params[adress + 1] & 0xff));
}
