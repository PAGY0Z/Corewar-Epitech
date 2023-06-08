/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** add_indirect
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file add_indirect.c
/// \brief Contains the function that adds an indirect to the buffer.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool add_indirect(asm_t *asm_struct, char *param, int cmd_position);

////////////////////////////////////////////////////////////////////////////////
/// \brief Adds an indirect to the buffer.
/// \param asm_struct The asm structure.
/// \param param param The param to check and add.
/// \param cmd_position The position of the command.
/// \return true if the add was successful, false otherwise.
/// \warning Returns false if an error occurs.
/// \note Will determine if the param is a label or a number.
/// \note If it's a label, it will add a call to the label and add space for
/// the address. (2 bytes)
/// \note If it's a number, it will add the number to the buffer.
////////////////////////////////////////////////////////////////////////////////
bool add_indirect(asm_t *asm_struct, char *param, int cmd_position)
{
    call_t *call = NULL;
    if (param[0] != ':' && !IS_NUM(param[0]) && !IS_SIGN(param[0]))
        return false;
    if (str_is_number(param))
        return add_two_bytes_to_buffer(asm_struct, my_getnbr(param));
    if (is_registered_label2(asm_struct, param)) {
        if (!(call = init_call_data(cmd_position, asm_struct->index, 2)))
            return false;
        if (!add_call_to_label(asm_struct, param + 1, call)) {
            my_free(call);
            return false;
        }
        my_free(call);
        return add_two_bytes_to_buffer(asm_struct, 0);
    }
    return false;
}
