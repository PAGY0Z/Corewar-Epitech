/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** progs_sort_check
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file progs_sort_check.c
/// \brief Contains the progs_sort_check function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-20-05
////////////////////////////////////////////////////////////////////////////////

void swapprogs(params_progs_t **progs, int i, int j);
void sort_progs(params_progs_t **progs);

////////////////////////////////////////////////////////////////////////////////
/// \brief Swap two params_progs_t structures depending on their prog_nbr.
/// \param progs The progs structure.
/// \param i The first index.
/// \param j The second index.
/// \note Returns if progs is NULL.
/// \note Returns if i or j is out of range.
/// \note Swap the two params_progs_t structures. '>' is used to sort the
/// structure in ascending order.
///////////////////////////////////////////////////////////////////////////
void swapprogs(params_progs_t **progs, int i, int j)
{
    params_progs_t *tmp = NULL;
    int len = 0;
    if (!progs) return;
    for (len = 0; progs[len]; len++);
    if (i < 0 || i >= len || j < 0 || j >= len) return;
    if (progs[i]->prog_nbr > progs[j]->prog_nbr) {
        tmp = progs[i];
        progs[i] = NULL;
        progs[i] = progs[j];
        progs[j] = NULL;
        progs[j] = tmp;
    }
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Sort the progs structure depending on the prog_nbr.
/// \param progs The progs structure.
/// \note Returns if progs is NULL.
/// \note Sort the progs structure.
///////////////////////////////////////////////////////////////////////////
void sort_progs(params_progs_t **progs)
{
    if (!progs) return;
    for (int i = 0; progs[i]; i++)
        for (int j = i + 1; progs[j]; j++)
            swapprogs(progs, i, j);
}
