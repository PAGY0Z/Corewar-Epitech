/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** get_len
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file get_len.c
/// \brief Contains the get_len function.
/// \author PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-26-05
////////////////////////////////////////////////////////////////////////////////

int get_len(int arg_type);
int get_len_mod(int arg_type);

////////////////////////////////////////////////////////////////////////////////
/// \brief Returns the length of an argument.
/// \param arg_type The type of the argument.
/// \return The length of the argument.
////////////////////////////////////////////////////////////////////////////////
int get_len(int arg_type)
{
    if (arg_type == REG)
        return 1;
    if (arg_type == IND)
        return 2;
    if (arg_type == DIR)
        return 4;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Returns the length of an argument. SPECIFIC to INDEX VALUES
/// \param arg_type The type of the argument.
/// \return The length of the argument.
////////////////////////////////////////////////////////////////////////////////
int get_len_mod(int arg_type)
{
    if (arg_type == REG)
        return 1;
    if (arg_type == IND)
        return 2;
    if (arg_type == DIR)
        return 2;
    return 0;
}
