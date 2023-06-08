/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** champdup
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file champdup.c
/// \brief Contains the champdup functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

champ_t *champdup(champ_t *champ, int new_champ_pc, int *mall_vs);

////////////////////////////////////////////////////////////////////////////////
/// \brief Duplicates a champ structure.
/// \param champ A pointer to the champ structure.
/// \param new_champ_pc The new pc of the champ.
/// \param mall_vs An array of int containing the size of the mallocs.
/// \return A pointer to the new champ structure.
/// \note Returns NULL in those cases:
/// \note   - The malloc of the new champ structure failed.
/// \note   - The my_strdup of the comment failed.
/// \note   - The my_strdup of the name failed.
/// \note   - The malloc of the params failed.
/// \note   - The malloc of the regs failed.
/// \note Functions steps:
/// \note   - Mallocs the new champ structure.
/// \note   - Duplicates the comment.
/// \note   - Duplicates the name.
/// \note   - Mallocs the params.
/// \note   - Mallocs the regs.
/// \note   - Copies the params.
/// \note   - Copies the regs.
/// \note   - Sets the new pc.
/// \note   - Sets the prog_nbr.
/// \note   - Sets the cycle_to_wait to -1.
/// \note   - Copies the carry.
/// \note   - Copies the alive_during_last_cycle.
////////////////////////////////////////////////////////////////////////////////
champ_t *champdup(champ_t *champ, int new_champ_pc, int *mall_vs)
{
    champ_t *new_champ = malloc(sizeof(champ_t) * mall_vs[0]);
    if (new_champ == NULL) return NULL;
    if (!(new_champ->comment = my_strdup(champ->comment, mall_vs[1])))
        return e_champdup_comment(new_champ);
    if (!(new_champ->name = my_strdup(champ->name, mall_vs[2])))
        return e_champdup_name(new_champ);
    if (!(new_champ->params = malloc(sizeof(byte_t) * 14 * mall_vs[3])))
        return e_champdup_params(new_champ);
    if (!(new_champ->regs = malloc(sizeof(int) * REG_NUMBER * mall_vs[4])))
        return e_champdup_regs(new_champ);
    for (int i = 0; i < 14; i++) new_champ->params[i] = 0;
    for (int i = 0; i < REG_NUMBER; i++) new_champ->regs[i] = champ->regs[i];
    new_champ->pc = new_champ_pc;
    new_champ->prog_nbr = champ->prog_nbr;
    new_champ->cycle_to_wait = -1;
    new_champ->carry = champ->carry;
    new_champ->alive_during_last_cycle = champ->alive_during_last_cycle;
    return new_champ;
}
