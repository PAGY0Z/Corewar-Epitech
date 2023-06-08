/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** parsing_16_aff
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file parsing_16_aff.c
/// \brief Contains the parsing function for the aff operation.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool parsing_16_aff(asm_t *asm_struct, char **line);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if the aff operation is well written and add it to the buffer.
/// \param asm_struct The asm struct.
/// \param line The line to parse.
/// \return true if the line was parsed correctly, false otherwise.
/// \note Return false in those cases:
/// \note   - The line is not 2 words long.
/// \note   - The first word is not "aff".
/// \note   - The instruction byte could not be added to the buffer.
/// \note   - The parsing byte could not be added to the buffer.
/// \note   - The second word is not a register.
////////////////////////////////////////////////////////////////////////////////
bool parsing_16_aff(asm_t *asm_struct, char **line)
{
    if (my_array_len(line) != 2) return false;
    if (!my_strcmp(line[0], "aff")) return false;
    if (!add_byte_to_buffer(asm_struct, 0x10)) return false;
    if (!add_byte_to_buffer(asm_struct, 0x40)) return false;
    return add_register(asm_struct, line[1]);
}
