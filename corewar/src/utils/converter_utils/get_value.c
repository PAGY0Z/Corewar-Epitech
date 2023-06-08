/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** get_value
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file get_value.c
/// \brief Contains the get_value function.
/// \author PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-26-05
////////////////////////////////////////////////////////////////////////////////

int get_value(int arg_type, int pos, champ_t *champion, corewar_t *glo);
int get_value_mod(int arg_type, int pos, champ_t *champion, corewar_t *glo);

////////////////////////////////////////////////////////////////////////////////
/// \brief Returns the value of a parameter.
/// \param arg_type The type of the parameter.
/// \param pos The position of the parameter.
/// \param champion A pointer to the champion.
/// \param glo A pointer to the VM.
/// \return The value of the parameter.
////////////////////////////////////////////////////////////////////////////////
int get_value(int arg_type, int pos, champ_t *champion, UNUSED corewar_t *glo)
{
    byte_t *para = champion->params;
    if (arg_type == REG)
        return (champion->regs[(para[pos] & 0xff) - 1]);
    if (arg_type == IND)
        return get_short(para, pos);
    if (arg_type == DIR)
        return get_4b_mem(glo, pos);
    if (arg_type == DIR_IDX)
        return get_short(para, pos);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Returns the value of a parameter.
/// \param arg_type The type of the parameter.
/// \param pos The position of the parameter.
/// \param champion A pointer to the champion.
/// \param glo A pointer to the VM.
/// \return The value of the parameter.
////////////////////////////////////////////////////////////////////////////////
int get_value_mod(int arg_type, int pos, champ_t *champ, UNUSED corewar_t *glo)
{
    byte_t *para = champ->params;
    if (arg_type == REG)
        return (champ->regs[(para[pos] & 0xff) - 1]);
    if (arg_type == IND)
        return get_short(para, pos);
    if (arg_type == DIR)
        return get_short(para, pos);
    return 0;
}
