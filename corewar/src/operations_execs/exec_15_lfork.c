/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** exec_15_lfork
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file exec_15_lfork.c
/// \brief Contains the exec_15_lfork function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-26-05
////////////////////////////////////////////////////////////////////////////////

void exec_15_lfork(corewar_t *global, champ_t *champion);

////////////////////////////////////////////////////////////////////////////////
/// \brief Executes the lfork instruction.
/// \param global A pointer to the global structure.
/// \param champ A pointer to the champion structure.
////////////////////////////////////////////////////////////////////////////////
void exec_15_lfork(UNUSED corewar_t *global, champ_t *champion)
{
    if (champion->pc == -1) return;
    short pos_mem = get_short(champion->params, 1);
    int pc_new_champ = champion->pc + pos_mem;
    champ_t *new_champ = champdup(champion, pc_new_champ, MALL_VS);
    if (new_champ == NULL) {
        my_perror("malloc");
        exit(84);
    }
    global->champ = realloc(global->champ, sizeof(champ_t *) * \
        (global->nbr_champ + 2));
    if (global->champ == NULL) {
        my_perror("realloc");
        exit(84);
    }
    global->champ[global->nbr_champ] = new_champ;
    global->champ[global->nbr_champ + 1] = NULL;
    global->nbr_champ++;
    champion->pc += get_arena_adress(champion->pc + 3);
}
