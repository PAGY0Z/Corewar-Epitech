/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** exits_init_champion
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file exits_init_champion.c
/// \brief Contains the exits functions of the init_champion functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-23-05
////////////////////////////////////////////////////////////////////////////////

void *e_init_comment(champ_t *champ);
void *e_init_name(champ_t *champ);
void *e_init_regs(champ_t *champ);
void *e_init_params_bytes(champ_t *champ);

////////////////////////////////////////////////////////////////////////////////
/// \brief Exits the init_comment function.
/// \param champ The champion to free.
/// \return NULL.
/// \note Frees the champ as it is the first element allocated when initializing
/// the champion's comment.
////////////////////////////////////////////////////////////////////////////////
void *e_init_comment(champ_t *champ)
{
    my_free(champ);
    return NULL;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Exits the init_name function.
/// \param champ The champion to free.
/// \return NULL.
/// \note Frees the comment and the champ as they are allocated when initializin
/// the champion's name.
////////////////////////////////////////////////////////////////////////////////
void *e_init_name(champ_t *champ)
{
    my_free(champ->comment);
    return e_init_comment(champ);
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Exits the init_regs function.
/// \param champ The champion to free.
/// \return NULL.
/// \note Frees the name, the comment and the champ as they are allocated when
/// initializing the champion's registers.
////////////////////////////////////////////////////////////////////////////////
void *e_init_regs(champ_t *champ)
{
    my_free(champ->name);
    return e_init_name(champ);
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Exits the init_params_bytes function.
/// \param champ The champion to free.
/// \return NULL.
/// \note Frees the registers, the name, the comment and the champ as they are
/// allocated when initializing the champion's params bytes.
////////////////////////////////////////////////////////////////////////////////
void *e_init_params_bytes(champ_t *champ)
{
    my_free(champ->regs);
    return e_init_regs(champ);
}
