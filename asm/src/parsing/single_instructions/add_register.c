/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** add_register
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file add_register.c
/// \brief Contains the function that add a register to the buffer.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool add_register(asm_t *asm_struct, char *param);

////////////////////////////////////////////////////////////////////////////////
/// \brief Add the register id from the param to the buffer.
/// \param asm_struct The asm struct.
/// \param param The param to check and add.
/// \return true if the register was added, false otherwise.
/// \warning Returns false if an error occurs.
/// \note Will compare the param with the register names.
////////////////////////////////////////////////////////////////////////////////
bool add_register(asm_t *asm_struct, char *param)
{
    if (!param) return false;
    if (!*param) return false;
    for (register_asm_t reg = R01; reg <= REG_NUMBER; reg++) {
        if (!my_strcmp(param, register_array[reg].name)) continue;
        return add_byte_to_buffer(asm_struct, reg);
    }
    return false;
}
