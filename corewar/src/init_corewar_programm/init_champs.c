/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** init_champs
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file init_champs.c
/// \brief Contains the init_champs function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-23-05
////////////////////////////////////////////////////////////////////////////////

void init_default_values(params_progs_t *prog, champ_t *champ);
champ_t *init_champion(params_progs_t *prog, int *mall_vs);
bool load_champ(params_progs_t *prog, byte_t *arena);
bool init_champs(corewar_t *glob, params_t *params);

////////////////////////////////////////////////////////////////////////////////
/// \brief Initializes the default values of the champion.
/// \param prog The program's parameters.
/// \param champ The champion to initialize.
/// \return void.
/// \note Initializes the default values of the champion.
////////////////////////////////////////////////////////////////////////////////
void init_default_values(params_progs_t *prog, champ_t *champ)
{
    for (int i = 0; i < REG_NUMBER; i++) champ->regs[i] = 0;
    for (int i = 0; i < 14; i++) champ->params[i] = 0;
    champ->regs[0] = prog->prog_nbr;
    champ->pc = prog->load_address;
    champ->prog_nbr = prog->prog_nbr;
    champ->carry = false;
    champ->alive_during_last_cycle = false;
    champ->cycle_to_wait = -1;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Initializes the champion.
/// \param prog The program's parameters.
/// \param mall_vs The malloc values.
/// \return The allocated champion.
/// \note Initializes the champion :
/// \note   - Allocates the champion.
/// \note   - Gets the header.
/// \note   - Allocates the comment.
/// \note   - Allocates the name.
/// \note   - Allocates the registers.
/// \note   - Allocates the params.
/// \note   - Initializes the default values.
////////////////////////////////////////////////////////////////////////////////
champ_t *init_champion(params_progs_t *prog, int *mall_vs)
{
    champ_t *champ = NULL; header_t header = {0};
    if (!prog) return NULL;
    if (!get_header(&header, prog->prog_name)) return NULL;
    if (!(champ = malloc(sizeof(champ_t) * mall_vs[0]))) return NULL;
    if (!(champ->comment = my_strdup(header.comment, mall_vs[1])))
        return e_init_comment(champ);
    if (!(champ->name = my_strdup(header.prog_name, mall_vs[2])))
        return e_init_name(champ);
    if (!(champ->regs = malloc(sizeof(int) * REG_NUMBER * mall_vs[3])))
        return e_init_regs(champ);
    if (!(champ->params = malloc(sizeof(byte_t) * 14 * mall_vs[4])))
        return e_init_params_bytes(champ);
    init_default_values(prog, champ);
    return champ;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Loads the champion in the arena.
/// \param prog The program's parameters.
/// \param arena The arena.
/// \return true if the champion has been loaded, false otherwise.
/// \note Loads the champion in the arena.
////////////////////////////////////////////////////////////////////////////////
bool load_champ(params_progs_t *prog, byte_t *arena)
{
    int fd = 0; int size = 0; int i = 0; char c = 0;
    if (!prog || !arena) return false;
    if (!prog->prog_name) return false;
    if ((fd = open(prog->prog_name, O_RDONLY)) == -1) return false;
    if ((size = lseek(fd, 0, SEEK_END)) == -1) return false;
    if (size < FULL_HEADER_SIZE) return false;
    if (lseek(fd, FULL_HEADER_SIZE, SEEK_SET) == -1) return false;
    for (i = 0; i < size - FULL_HEADER_SIZE; i++) {
        if (read(fd, &c, 1) == -1) return false;
        arena[get_arena_adress(prog->load_address + i)] = c;
    }
    if (close(fd) == -1) return false;
    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Initializes the champions.
/// \param glob The global structure.
/// \param params The parameters.
/// \return true if the champions have been initialized, false otherwise.
/// \note Initializes the champions :
/// \note   - Checks the validity of the champions.
/// \note   - Initializes the champions.
/// \note   - Loads the champions in the arena.
////////////////////////////////////////////////////////////////////////////////
bool init_champs(corewar_t *glob, params_t *params)
{
    if (!glob || !params) return false;
    for (int i = 0; i < params->prog_nbr; i++) {
        if (!(champions_validity_checkers(params->progs[i]))) {
            freen_champs(glob->champ, i);
            return false;
        }
        if (!(glob->champ[i] = init_champion(params->progs[i], MALL_VS))) {
            freen_champs(glob->champ, i);
            return false;
        }
        if (!(load_champ(params->progs[i], glob->arena))) {
            freen_champs(glob->champ, i + 1);
            return false;
        }
    }
    return true;
}
