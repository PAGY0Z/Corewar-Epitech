/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** add_two_bytes_to_buffer
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file add_two_bytes_to_buffer.c
/// \brief Contains the function that adds two bytes to the buffer.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool add_two_bytes_to_buffer(asm_t *asm_struct, short value);

////////////////////////////////////////////////////////////////////////////////
/// \brief Adds two bytes to the buffer.
/// \param asm_struct The asm structure.
/// \param value The value to add in a short.
/// \return true if the add was successful, false otherwise.
////////////////////////////////////////////////////////////////////////////////
bool add_two_bytes_to_buffer(asm_t *asm_struct, short value)
{
    byte_t bytes[2] = {0};
    bytes[0] = GET_SMALL_BYTE(value);
    bytes[1] = GET_SMALLEST_BYTE(value);
    return add_bytes_to_buffer(asm_struct, bytes, 2);
}
