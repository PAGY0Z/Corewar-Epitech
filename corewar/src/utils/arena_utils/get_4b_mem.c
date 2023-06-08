/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** get_4b_mem
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file get_4b_mem.c
/// \brief Contains the get_4b_mem function.
/// \author PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-26-05
////////////////////////////////////////////////////////////////////////////////

int get_4b_mem(corewar_t *corewar, int pos_mem);

////////////////////////////////////////////////////////////////////////////////
/// \brief Get 4b in VM memory
/// \param global A pointer to the VM
/// \param pos_mem The position where to start reading.
/// \return The 4b in memory as an int.
////////////////////////////////////////////////////////////////////////////////
int get_4b_mem(corewar_t *corewar, int pos_mem)
{
    int value = 0;
    for (int i = 0; i < 4; i++) {
        value <<= 8;
        value |= corewar->arena[get_arena_adress(pos_mem + i)];
    }
    return value;
}
