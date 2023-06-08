/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** params_check_update
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file params_check_update.c
/// \brief Contains the params_check_update function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-19-05
////////////////////////////////////////////////////////////////////////////////

bool params_check_update(params_t *params);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if the params structure is valid and update it.
/// \param params The params structure.
/// \return true if the params structure is valid, false otherwise.
/// \note Checks done in this function :
/// \note   - If the params structure is NULL.
/// \note   - If one load address is set, all must be set.
/// \note   - If multiple programs have the same number.
/// \note Updates done in this function :
/// \note   - If no load address is set, set them.
/// \note   - Sort the programs by prog_nbr.
/// \note   - Set the program numbers if they are not set.
////////////////////////////////////////////////////////////////////////////////
bool params_check_update(params_t *params)
{
    if (!params) return false;
    if (one_adress_is_set(params->progs))
        if (!all_adresses_are_set(params->progs)) {
            my_putstr("Error : One load address is set, all must be set\n", 2);
            return false;
        }
    set_prog_numbers(params->progs);
    if (mulitple_prog_nbr(params->progs)) {
        my_putstr("Error : Multiple programs have the same number\n", 2);
        return false;
    }
    sort_progs(params->progs);
    if (!one_adress_is_set(params->progs)) {
        for (int i = 0; params->progs[i]; i++)
            params->progs[i]->load_address = i * (MEM_SIZE / params->prog_nbr);
    }
    return true;
}
