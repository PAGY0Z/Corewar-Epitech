/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** change_prog_size
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file change_prog_size.c
/// \brief Contains the function that changes the prog size in the buffer.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

void change_prog_size(asm_t *asm_struct);

////////////////////////////////////////////////////////////////////////////////
/// \brief Change the prog_size in the header.
/// \param asm_struct The asm struct.
/// \note The prog_size is the size of the buffer without the header.
/// \note The prog_size is stored in the header at the 136th byte.
////////////////////////////////////////////////////////////////////////////////
void change_prog_size(asm_t *asm_struct)
{
    byte_t bytes[4] = {0};
    int size = asm_struct->index - FULL_HEADER_SIZE;
    bytes[0] = GET_BIGGEST_BYTE(size);
    bytes[1] = GET_BIG_BYTE(size);
    bytes[2] = GET_SMALL_BYTE(size);
    bytes[3] = GET_SMALLEST_BYTE(size);
    for (int i = 0; i < 4; i++)
        asm_struct->buffer[LEN_MAGIC_NAME_PADDING + i] = bytes[i];
}
