/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** corewar_loop
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file corewar_loop.c
/// \brief Contains the corewar_loop function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-26-05
////////////////////////////////////////////////////////////////////////////////

bool corewar_loop_condition(corewar_t *global);
bool champion_is_waiting(champ_t *champ);
void invalid_instruction(champ_t *champ);
void execute_cycle(corewar_t *global);
int corewar_loop(corewar_t *global);

////////////////////////////////////////////////////////////////////////////////
/// \brief The corewar loop's condition.
/// \param global A pointer to the global structure.
/// \return True if the condition is true, False otherwise.
/// \note Returns false in those cases:
/// \note   - global is NULL
/// \note   - There is one or less champion alive
/// \note   - The dump_nbr_cycles is set and reached 0
////////////////////////////////////////////////////////////////////////////////
bool corewar_loop_condition(corewar_t *global)
{
    if (!global) return false;
    if (global->dump_nbr_cycles != -1) {
        if (global->dump_nbr_cycles <= 0) {
            dump_memory(global->arena);
            return false;
        }
        global->dump_nbr_cycles--;
    }
    if (!different_champ_alive(global)) return false;
    if (global->cycle_to_die <= 0) return false;
    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Checks if a champion is waiting.
/// \param champ A pointer to the champion structure.
/// \return True if the champion is waiting, False otherwise.
/// \note Returns true in those cases:
/// \note   - champ is NULL
/// \note   - champ->cycle_to_wait is more than 0
/// \note Returns false in those cases:
/// \note   - champ->cycle_to_wait is less than or equal to 0
////////////////////////////////////////////////////////////////////////////////
bool champion_is_waiting(champ_t *champ)
{
    if (!champ) return true;
    if (champ->cycle_to_wait <= -1) return false;
    if (champ->cycle_to_wait > 0) {
        champ->cycle_to_wait--;
        return true;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Resets the champion parameters.
/// \param champ A pointer to the champion structure.
/// \return Nothing.
/// \note Resets the champion parameters to 0.
/// \note Pushes the program counter to the next instruction.
/// \note Sets the cycle to wait to -1.
////////////////////////////////////////////////////////////////////////////////
void invalid_instruction(champ_t *champ)
{
    reset_champ_params(champ);
    champ->pc = get_arena_adress(champ->pc + 1);
    champ->cycle_to_wait = -1;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Executes a cycle.
/// \param global A pointer to the global structure.
/// \return Nothing.
/// \note Functions steps:
/// \note   - For each champion:
/// \note       - If the champion is dead (pc == -1), continue.
/// \note       - If the champion is waiting, continue.
/// \note       - If the instruction is valid, execute it.
/// \note       - Update the champion parameters.
/// \note       - If the instruction is invalid, reset the champion parameters.
/// \note           - Update the champion program counter.
/// \note           - Set the cycle to wait to -1.
/// \note       - If the instruction is valid, set the cycle to wait to the
/// \note           instruction cycle to wait.
////////////////////////////////////////////////////////////////////////////////
void execute_cycle(corewar_t *global)
{
    champ_t *champ = NULL; byte_t opc = 0;
    for (int i = 0; global->champ[i]; i++) {
        champ = global->champ[i];
        opc = champ->params[0];
        if (champ->pc == -1) continue;
        if (champion_is_waiting(champ)) continue;
        if (1 <= (opc & 0xFF) && (opc & 0xFF) <= 16)
            op_tab[(opc & 0xFF)].exec(global, champ);
        update_champ_params(global->arena, champ);
        opc = champ->params[0];
        if ((opc & 0xFF) < 1 || 16 < (opc & 0xFF)) {
            invalid_instruction(champ);
            continue;
        }
        if (!op_tab[(opc & 0xFF)].check(opc, champ->params[1], champ->params)) {
            invalid_instruction(champ);
            continue;
        }
        champ->cycle_to_wait = op_tab[(opc & 0xFF)].op_duration;
    }
}

////////////////////////////////////////////////////////////////////////////////
/// \brief The corewar loop.
/// \param global A pointer to the global structure.
/// \return 0 if the function has run correctly, 84 otherwise.
/// \note Functions steps:
/// \note   - While the corewar loop condition is true:
/// \note       - Execute a cycle.
/// \note       - Increment the current cycle.
/// \note   - Display the winner.
/// \note   - Free the corewar.
/// \note Returns 84 in those cases:
/// \note   - global is NULL
/// \note Returns 0 in those cases:
/// \note   - The corewar loop condition is false
////////////////////////////////////////////////////////////////////////////////
int corewar_loop(corewar_t *global)
{
    if (!global) return ERR_OUT;
    while (corewar_loop_condition(global)) {
        execute_cycle(global);
        if (global->current_cycle == __INT32_MAX__) {
            global->current_cycle = 0;
            continue;
        }
        global->current_cycle++;
    }
    if (global->dump_nbr_cycles > 0)
        dump_memory(global->arena);
    display_winner(global);
    free_corewar(global);
    return 0;
}
