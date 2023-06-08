/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** champdup_exits
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file champdup_exits.c
/// \brief Contains the champdup_exits functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

void *e_champdup_comment(champ_t *champ);
void *e_champdup_name(champ_t *champ);
void *e_champdup_params(champ_t *champ);
void *e_champdup_regs(champ_t *champ);

////////////////////////////////////////////////////////////////////////////////
/// \brief Frees the champ structure and returns NULL.
/// \param champ A pointer to the champ structure.
/// \return NULL.
////////////////////////////////////////////////////////////////////////////////
void *e_champdup_comment(champ_t *champ)
{
    my_free(champ);
    return NULL;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Frees the champ structure and returns NULL. From the comment.
/// \param champ A pointer to the champ structure.
/// \return NULL.
////////////////////////////////////////////////////////////////////////////////
void *e_champdup_name(champ_t *champ)
{
    my_free(champ->comment);
    return e_champdup_comment(champ);
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Frees the champ structure and returns NULL. From the name.
/// \param champ A pointer to the champ structure.
/// \return NULL.
////////////////////////////////////////////////////////////////////////////////
void *e_champdup_params(champ_t *champ)
{
    my_free(champ->name);
    return e_champdup_name(champ);
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Frees the champ structure and returns NULL. From the params.
/// \param champ A pointer to the champ structure.
/// \return NULL.
////////////////////////////////////////////////////////////////////////////////
void *e_champdup_regs(champ_t *champ)
{
    my_free(champ->params);
    return e_champdup_params(champ);
}
