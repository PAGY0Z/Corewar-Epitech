/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** parsing_14_lldi
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file parsing_14_lldi.c
/// \brief Contains the parsing function for the lldi operation.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool parsing_14_lldi(asm_t *asm_struct, char **line);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if the lldi operation is well written and add it to the buffer.
/// \param asm_struct The asm struct.
/// \param line The line to parse.
/// \return true if the line was parsed correctly, false otherwise.
/// \note Return false in those cases:
/// \note   - The line is not 4 words long.
/// \note   - The first word is not "lldi".
/// \note   - The instruction byte could not be added to the buffer.
/// \note   - The parsing byte could not be added to the buffer.
/// \note   - The second word is not a register, direct index or indirect.
/// \note   - The third word is not a register or direct index.
/// \note   - The fourth word is not a register.
////////////////////////////////////////////////////////////////////////////////
bool parsing_14_lldi(asm_t *asm_struct, char **line)
{
    int cmd_position = asm_struct->index - FULL_HEADER_SIZE;
    if (my_array_len(line) != 4) return false;
    if (!my_strcmp(line[0], "lldi")) return false;
    if (!add_byte_to_buffer(asm_struct, 0x0e)) return false;
    if (!add_byte_to_buffer(asm_struct, 0b00000100)) return false;
    if (!add_reg_dirindex_ind(asm_struct, line[1], cmd_position, FIRST))
        return false;
    if (!add_reg_dirindex(asm_struct, line[2], cmd_position, SECOND))
        return false;
    return add_register(asm_struct, line[3]);
}
