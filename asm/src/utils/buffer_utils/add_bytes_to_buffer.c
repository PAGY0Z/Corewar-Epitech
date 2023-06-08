/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** add_bytes_to_buffer
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file add_bytes_to_buffer.c
/// \brief Contains the function that add multiple bytes to the buffer.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool add_bytes_to_buffer(asm_t *asm_struct, byte_t *bytes, int n);

////////////////////////////////////////////////////////////////////////////////
/// \brief Add bytes to the buffer.
/// \param asm_struct The asm struct.
/// \param bytes The bytes to add.
/// \param n The number of bytes to add.
/// \return true if the bytes were added, false otherwise.
/// \warning Returns false if an error occurs.
/// \note Returns false if an error occurs while reallocating memory.
/// \note The index is incremented for each byte added.
////////////////////////////////////////////////////////////////////////////////
bool add_bytes_to_buffer(asm_t *asm_struct, byte_t *bytes, int n)
{
    for (int i = 0; i < n; i++)
        if (!add_byte_to_buffer(asm_struct, bytes[i])) return false;
    return true;
}
