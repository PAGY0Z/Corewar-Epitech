/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** exec_01_live
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file exec_01_live.c
/// \brief Contains the exec_01_live function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-26-05
////////////////////////////////////////////////////////////////////////////////

void kill_dead_champs(corewar_t *global);
void check_nbr_live(corewar_t *global);
void set_champs_to_alive(corewar_t *global, int prog_nbr);
void exec_01_live(corewar_t *global, champ_t *champ);

////////////////////////////////////////////////////////////////////////////////
/// \brief Removes the champions that were not alive during the last cycle.
/// \param global A pointer to the global structure.
/// \note Their pc is set to -1.
/// \note Their alive_during_last_cycle is set to false.
/// \note The champions that were alive during the last cycle have their
/// \note alive_during_last_cycle set to false.
////////////////////////////////////////////////////////////////////////////////
void kill_dead_champs(corewar_t *global)
{
    for (int i = 0; global->champ[i]; i++) {
        if (global->champ[i]->alive_during_last_cycle == false) {
            global->champ[i]->pc = -1;
            continue;
        }
        global->champ[i]->alive_during_last_cycle = false;
    }
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Checks if the nbr_live is superior or equal to NBR_LIVE.
/// \param global A pointer to the global structure.
/// \note If it is, the cycle_to_die is decreased by CYCLE_DELTA.
/// \note The nbr_live is reset to 0.
/// \note All the champions that were not alive during the last cycle are killed
/// \note (their pc is set to -1).
////////////////////////////////////////////////////////////////////////////////
void check_nbr_live(corewar_t *global)
{
    if (global->nbr_live >= NBR_LIVE) {
        global->cycle_to_die -= CYCLE_DELTA;
        global->nbr_live = 0;
        kill_dead_champs(global);
    }
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Sets the alive_during_last_cycle of the champions with the
/// \brief corresponding prog_nbr to true.
/// \param global A pointer to the global structure.
/// \param prog_nbr The prog_nbr of the champion that is alive.
////////////////////////////////////////////////////////////////////////////////
void set_champs_to_alive(corewar_t *global, int prog_nbr)
{
    for (int i = 0; global->champ[i]; i++) {
        if (global->champ[i]->pc == -1) continue;
        if (global->champ[i]->prog_nbr == prog_nbr) {
            global->champ[i]->alive_during_last_cycle = true;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Executes the live instruction.
/// \param global A pointer to the global structure.
/// \param champ A pointer to the champion structure.
////////////////////////////////////////////////////////////////////////////////
void exec_01_live(corewar_t *global, champ_t *champion)
{
    if (champion->pc == -1) return;
    champ_t *champ = NULL;
    int prog_nbr = get_4b_mem(global, champion->pc + 1);
    for (int i = 0; global->champ[i]; i++) {
        champ = global->champ[i];
        if (champ->prog_nbr == prog_nbr) {
            set_champs_to_alive(global, prog_nbr);
            my_printf("The player %d(%s) is alive.\n", \
                champ->prog_nbr, champ->name);
            global->last_alive = champ->prog_nbr;
            global->nbr_live++;
            check_nbr_live(global);
            break;
        }
    }
    champ->pc = get_arena_adress(champ->pc + 5);
}
