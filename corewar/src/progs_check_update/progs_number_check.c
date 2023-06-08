/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** progs_number_check
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file progs_number_check.c
/// \brief Contains the progs_number_check function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-20-05
////////////////////////////////////////////////////////////////////////////////

int get_next_valid_prog_nbr(params_progs_t **progs);
void set_prog_numbers(params_progs_t **progs);
bool mulitple_prog_nbr_checker(params_progs_t **progs, int i, int prog_nbr);
bool mulitple_prog_nbr(params_progs_t **progs);

////////////////////////////////////////////////////////////////////////////////
/// \brief Get the next valid program number.
/// \param progs The progs structure.
/// \return The next valid program number.
/// \note Returns -1 if progs is NULL.
/// \note Returns -1 if no valid program number is found.
/// \note Returns the next valid program number.
////////////////////////////////////////////////////////////////////////////////
int get_next_valid_prog_nbr(params_progs_t **progs)
{
    int prog_nbr = -1;
    if (!progs) return prog_nbr;
    for (int i = 0; progs[i]; i++) {
        if (progs[i]->prog_nbr == prog_nbr) {
            prog_nbr++;
            i = -1;
        }
    }
    return prog_nbr;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Set the program numbers.
/// \param progs The progs structure.
/// \note Returns if progs is NULL.
/// \note Returns if no program number is set.
/// \note Set the program numbers.
////////////////////////////////////////////////////////////////////////////////
void set_prog_numbers(params_progs_t **progs)
{
    if (!progs) return;
    for (int i = 0; progs[i]; i++) {
        if (progs[i]->prog_nbr != -1) continue;
        progs[i]->prog_nbr = get_next_valid_prog_nbr(progs);
    }
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if a program number is used multiple times.
/// \param progs The progs structure.
/// \param i The index of the program number to check.
/// \param prog_nbr The program number to check.
/// \return true if the program number is used multiple times, false otherwise.
/// \note Returns false if progs is NULL.
/// \note Returns false if prog_nbr is not used multiple times.
/// \note Returns true if prog_nbr is used multiple times.
////////////////////////////////////////////////////////////////////////////////
bool mulitple_prog_nbr_checker(params_progs_t **progs, int i, int prog_nbr)
{
    if (!progs) return false;
    for (int j = 0; progs[j]; j++) {
        if (j == i) continue;
        if (progs[j]->prog_nbr == prog_nbr) return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if a program number is used multiple times.
/// \param progs The progs structure.
/// \return true if a program number is used multiple times, false otherwise.
/// \note Returns true if progs is NULL.
/// \note Returns false if no program number is used multiple times.
/// \note Returns true if a program number is used multiple times.
////////////////////////////////////////////////////////////////////////////////
bool mulitple_prog_nbr(params_progs_t **progs)
{
    if (!progs) return true;
    for (int i = 0; progs[i]; i++) {
        if (!mulitple_prog_nbr_checker(progs, i, progs[i]->prog_nbr))
            return true;
    }
    return false;
}
