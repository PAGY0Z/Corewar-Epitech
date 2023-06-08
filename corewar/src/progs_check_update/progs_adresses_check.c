/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** progs_adresses_check
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file progs_adresses_check.c
/// \brief Contains the progs_adresses_check function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-20-05
////////////////////////////////////////////////////////////////////////////////

bool one_adress_is_set(params_progs_t **progs);
bool all_adresses_are_set(params_progs_t **progs);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if one load address is set.
/// \param progs The progs structure.
/// \return true if one load address is set, false otherwise.
/// \note Returns false if progs is NULL.
/// \note Returns false if no load address is set.
/// \note Returns true if one load address is set.
////////////////////////////////////////////////////////////////////////////////
bool one_adress_is_set(params_progs_t **progs)
{
    if (!progs) return false;
    for (int i = 0; progs[i]; i++) {
        if (progs[i]->load_address != -1) return true;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if all load addresses are set.
/// \param progs The progs structure.
/// \return true if all load addresses are set, false otherwise.
/// \note Returns false if progs is NULL.
/// \note Returns false if one load address is not set.
/// \note Returns true if all load addresses are set.
////////////////////////////////////////////////////////////////////////////////
bool all_adresses_are_set(params_progs_t **progs)
{
    if (!progs) return false;
    for (int i = 0; progs[i]; i++) {
        if (progs[i]->load_address == -1) return false;
    }
    return true;
}
