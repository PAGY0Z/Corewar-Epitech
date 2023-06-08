/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** add_four_bytes_to_buffer
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file add_four_bytes_to_buffer.c
/// \brief Contains the function that adds four bytes to the buffer.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool add_four_bytes_to_buffer(asm_t *asm_struct, int value);

////////////////////////////////////////////////////////////////////////////////
/// \brief Adds four bytes to the buffer.
/// \param asm_struct The asm structure.
/// \param value The value to add in an int.
/// \return true if the add was successful, false otherwise.
////////////////////////////////////////////////////////////////////////////////
bool add_four_bytes_to_buffer(asm_t *asm_struct, int value)
{
    byte_t bytes[4] = {0};
    bytes[0] = GET_BIGGEST_BYTE(value);
    bytes[1] = GET_BIG_BYTE(value);
    bytes[2] = GET_SMALL_BYTE(value);
    bytes[3] = GET_SMALLEST_BYTE(value);
    return add_bytes_to_buffer(asm_struct, bytes, 4);
}
