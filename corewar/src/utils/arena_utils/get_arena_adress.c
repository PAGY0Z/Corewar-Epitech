/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** get_arena_adress
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file get_arena_adress.c
/// \brief Contains the get_arena_adress function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-23-05
////////////////////////////////////////////////////////////////////////////////

int get_arena_adress(int adress);

////////////////////////////////////////////////////////////////////////////////
/// \brief Get the arena adress.
/// \param adress The adress to get.
/// \return The arena adress.
/// \note The arena adress is the adress of the arena in the memory.
////////////////////////////////////////////////////////////////////////////////
int get_arena_adress(int adress)
{
    if (adress >= MEM_SIZE)
        return adress % MEM_SIZE;
    while (adress < 0)
        adress += MEM_SIZE;
    return adress % MEM_SIZE;
}
