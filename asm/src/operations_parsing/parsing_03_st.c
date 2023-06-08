/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** parsing_03_st
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file parsing_03_st.c
/// \brief Contains the parsing function for the st operation.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool parsing_03_st(asm_t *asm_struct, char **line);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if the st operation is well written and add it to the buffer.
/// \param asm_struct The asm struct.
/// \param line The line to parse.
/// \return true if the line was parsed correctly, false otherwise.
/// \note Return false in those cases:
/// \note   - The line is not 3 words long.
/// \note   - The first word is not "st".
/// \note   - The instruction byte could not be added to the buffer.
/// \note   - The parsing byte could not be added to the buffer.
/// \note   - The second word is not a register.
/// \note   - The third word is not a register or an indirect.
////////////////////////////////////////////////////////////////////////////////
bool parsing_03_st(asm_t *asm_struct, char **line)
{
    int cmd_position = asm_struct->index - FULL_HEADER_SIZE;
    if (my_array_len(line) != 3) return false;
    if (!my_strcmp(line[0], "st")) return false;
    if (!add_byte_to_buffer(asm_struct, 0x03)) return false;
    if (!add_byte_to_buffer(asm_struct, 0b01000000)) return false;
    if (!add_register(asm_struct, line[1])) return false;
    return add_reg_ind(asm_struct, line[2], cmd_position, SECOND);
}
