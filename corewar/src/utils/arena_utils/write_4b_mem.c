/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** write_4b_mem
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file write_4b_mem.c
/// \brief Contains the write_4b_mem function.
/// \author PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-26-05
////////////////////////////////////////////////////////////////////////////////

void write_4b_mem(corewar_t *global, int val, int pos_mem);

////////////////////////////////////////////////////////////////////////////////
/// \brief Write 4b in VM memory
/// \param global A pointer to the VM
/// \param val the value to write.
/// \param pos_mem The position where to start writing.
////////////////////////////////////////////////////////////////////////////////
void write_4b_mem(corewar_t *glob, int val, int pos_mem)
{
    glob->arena[get_arena_adress(pos_mem)] = GET_BIGGEST_BYTE(val) & 0xFF;
    glob->arena[get_arena_adress(pos_mem + 1)] = GET_BIG_BYTE(val) & 0xFF;
    glob->arena[get_arena_adress(pos_mem + 2)] = GET_SMALL_BYTE(val) & 0xFF;
    glob->arena[get_arena_adress(pos_mem + 3)] = GET_SMALLEST_BYTE(val) & 0xFF;
}
