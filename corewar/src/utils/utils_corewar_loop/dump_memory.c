/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** dump_memory
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file dump_memory.c
/// \brief Contains the dump_memory function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-26-05
////////////////////////////////////////////////////////////////////////////////

void dump_memory(byte_t *arena);

////////////////////////////////////////////////////////////////////////////////
/// \brief Dumps the memory.
/// \param arena A pointer to the arena.
////////////////////////////////////////////////////////////////////////////////
void dump_memory(byte_t *arena)
{
    if (!arena) return;
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % 32 == 0) my_printf("0x");
        if (i % 32 == 0 && i < 0x10) my_printf("0");
        if (i % 32 == 0 && i < 0x100) my_printf("0");
        if (i % 32 == 0 && i < 0x1000) my_printf("0");
        if (i % 32 == 0) my_printf("%x : ", i);
        if ((arena[i] & 0xFF) < 0x10) my_printf("0");
        my_printf("%X ", (arena[i] & 0xFF));
        if (i % 32 == 31) my_printf("\n");
    }
}
