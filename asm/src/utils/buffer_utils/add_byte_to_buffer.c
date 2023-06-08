/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** add_byte_to_buffer
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file add_byte_to_buffer.c
/// \brief Contains the function that add a single byte to the buffer.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool add_byte_to_buffer(asm_t *asm_struct, byte_t byte);

////////////////////////////////////////////////////////////////////////////////
/// \brief Add a byte to the buffer.
/// \param asm_struct The asm struct.
/// \param byte The byte to add.
/// \return true if the byte was added, false otherwise.
/// \warning Returns false if an error occurs.
/// \note Returns false if an error occurs while reallocating memory.
/// \note The index is incremented.
////////////////////////////////////////////////////////////////////////////////
bool add_byte_to_buffer(asm_t *asm_struct, byte_t byte)
{
    char *new_buffer = NULL;
    if (!(new_buffer = realloc(asm_struct->buffer, asm_struct->index + 1)))
        return false;
    asm_struct->buffer = new_buffer;
    asm_struct->buffer[asm_struct->index] = byte;
    asm_struct->index++;
    return true;
}
