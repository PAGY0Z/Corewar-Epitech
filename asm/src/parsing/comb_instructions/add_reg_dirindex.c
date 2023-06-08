/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** add_reg_dirindex
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file add_reg_dirindex.c
/// \brief Contains the function that add a register or direct index to the
/// buffer.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool add_reg_dirindex(asm_t *asm_s, char *param, int cmd_pos, pbyte_t p_byte);

////////////////////////////////////////////////////////////////////////////////
/// \brief Add a register or direct index argument to the buffer.
/// \param asm_struct The asm struct.
/// \param param The argument to add.
/// \param cmd_position The position of the command in the buffer.
/// \param p_byte The position of the bits to add in the parsing byte.
/// \return true if the argument was added correctly, false otherwise.
/// \note Return false in those cases:
/// \note   - The argument is not a register or direct index.
/// \note   - The argument is a register and a direct index.
////////////////////////////////////////////////////////////////////////////////
bool add_reg_dirindex(asm_t *asm_s, char *param, int cmd_pos, pbyte_t p_byte)
{
    byte_t parsing_byte = asm_s->buffer[cmd_pos + FULL_HEADER_SIZE + 1];
    bool is_register = false; bool is_direct_index = 0;
    is_register = add_register(asm_s, param);
    is_direct_index = add_direct_index(asm_s, param, cmd_pos);
    if ((is_register + is_direct_index) != 1) return false;
    if (p_byte) {
        if (is_register) parsing_byte = parsing_byte | (T_REG << p_byte);
        if (is_direct_index) parsing_byte = parsing_byte | (T_DIR << p_byte);
        asm_s->buffer[cmd_pos + FULL_HEADER_SIZE + 1] = parsing_byte;
    }
    return true;
}
