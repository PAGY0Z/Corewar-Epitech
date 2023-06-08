/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** get_type
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file get_type.c
/// \brief Contains the get_type function.
/// \author PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-26-05
////////////////////////////////////////////////////////////////////////////////

int get_type_p1(byte_t params);
int get_type_p2(byte_t params);
int get_type_p3(byte_t params);

////////////////////////////////////////////////////////////////////////////////
/// \brief Returns the type of a parameter at the position 1.
/// \param params The parameters.
/// \return The type of the parameter.
////////////////////////////////////////////////////////////////////////////////
int get_type_p1(byte_t params)
{
    if (IS_REG(P1(params)))
        return REG;
    if (IS_IND(P1(params)))
        return IND;
    if (IS_DIR(P1(params)))
        return DIR;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Returns the type of a parameter at the position 2.
/// \param params The parameters.
/// \return The type of the parameter.
////////////////////////////////////////////////////////////////////////////////
int get_type_p2(byte_t params)
{
    if (IS_REG(P2(params)))
        return REG;
    if (IS_IND(P2(params)))
        return IND;
    if (IS_DIR(P2(params)))
        return DIR;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Returns the type of a parameter at the position 3.
/// \param params The parameters.
/// \return The type of the parameter.
////////////////////////////////////////////////////////////////////////////////
int get_type_p3(byte_t params)
{
    if (IS_REG(P3(params)))
        return REG;
    if (IS_IND(P3(params)))
        return IND;
    if (IS_DIR(P3(params)))
        return DIR;
    return 0;
}
