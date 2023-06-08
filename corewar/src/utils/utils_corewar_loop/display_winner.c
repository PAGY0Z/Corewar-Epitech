/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** display_winner
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file display_winner.c
/// \brief Contains the display_winner function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-26-05
////////////////////////////////////////////////////////////////////////////////

void display_winner(corewar_t *global);

////////////////////////////////////////////////////////////////////////////////
/// \brief Displays the winner of the game.
/// \param global A pointer to the global structure.
////////////////////////////////////////////////////////////////////////////////
void display_winner(corewar_t *global)
{
    if (!global) return;
    for (int i = 0; global->champ[i]; i++) {
        if (global->last_alive == global->champ[i]->prog_nbr) {
            my_printf("The player %d(%s) has won.\n",
                global->champ[i]->prog_nbr, global->champ[i]->name);
            return;
        }
    }
    my_printf("No winner.\n");
}
