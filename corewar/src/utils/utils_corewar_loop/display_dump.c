/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** display_dump
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file display_dump.c
/// \brief Contains the display_dump function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-25-05
////////////////////////////////////////////////////////////////////////////////

void display_dump(byte_t *arena);

////////////////////////////////////////////////////////////////////////////////
/// \brief Display the arena.
/// \param arena The arena.
/// \return void
////////////////////////////////////////////////////////////////////////////////
void display_dump(byte_t *arena)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        if ((unsigned char)arena[i] < 16) my_printf("0");
        my_printf("%X", arena[i] & 0xFF);
        if (i % 32 == 31) my_printf("\n");
    }
}
