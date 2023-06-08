/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** parsing_04_add
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file parsing_04_add.c
/// \brief Contains the parsing function for the add operation.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool parsing_04_add(asm_t *asm_struct, char **line);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if the add operation is well written and add it to the buffer.
/// \param asm_struct The asm struct.
/// \param line The line to parse.
/// \return true if the line was parsed correctly, false otherwise.
/// \note Return false in those cases:
/// \note   - The line is not 4 words long.
/// \note   - The first word is not "add".
/// \note   - The instruction byte could not be added to the buffer.
/// \note   - The parsing byte could not be added to the buffer.
/// \note   - The second word is not a register.
/// \note   - The third word is not a register.
/// \note   - The fourth word is not a register.
////////////////////////////////////////////////////////////////////////////////
bool parsing_04_add(asm_t *asm_struct, char **line)
{
    if (my_array_len(line) != 4) return false;
    if (!my_strcmp(line[0], "add")) return false;
    if (!add_byte_to_buffer(asm_struct, 0x04)) return false;
    if (!add_byte_to_buffer(asm_struct, 0x54)) return false;
    if (!add_register(asm_struct, line[1])) return false;
    if (!add_register(asm_struct, line[2])) return false;
    return add_register(asm_struct, line[3]);
}
