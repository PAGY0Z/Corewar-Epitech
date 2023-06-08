/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** init_params
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file init_params.c
/// \brief Contains the init_params function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-16-05
////////////////////////////////////////////////////////////////////////////////

success_t get_dump_nbr_cycle(char **argv, params_t *params);
bool get_params_prog_nbr(char **argv, params_t *params);
bool init_params_progs(params_t *params, int mall_v1);
bool get_params_progs(char **argv, params_t *params, int mall_v1);
params_t *init_params(char **argv, int mall_v1, int mall_v2);

////////////////////////////////////////////////////////////////////////////////
/// \brief Get the number of cycles to dump.
/// \param argv The arguments.
/// \param params The params structure.
/// \return true if the number of cycles to dump is valid, false otherwise.
/// \note Returns false if the dump flag is not set.
/// \note Sets the dump_nbr_cycles to -1 if an error occurs.
/// \note Returns true if the dump flag is set & valid. Sets the dump_nbr_cycles
/// to the number of cycles to dump. Sets the current_arg to the next argument.
////////////////////////////////////////////////////////////////////////////////
success_t get_dump_nbr_cycle(char **argv, params_t *params)
{
    if (!argv || !params) {
        my_putstr("Error : Couldn't get the dump value\n", 2);
        return FAILURE;
    }
    if (my_array_len(argv) < 2) return NONE;
    if (!my_strcmp(argv[0], "-dump")) return NONE;
    if (!str_is_token(argv[1], BASE_HEX_UP)) {
        params->dump_nbr_cycles = -1;
        my_putstr("Error : [", 2);
        my_putstr(argv[1], 2);
        my_putstr("] : Invalid argument (-dump flag in UPPERCASE HEX)\n", 2);
        return FAILURE;
    }
    params->dump_nbr_cycles = ABS(my_getnbr_base(argv[1], BASE_HEX_UP));
    return SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Get the number of programs in the arguments.
/// \param argv The arguments.
/// \param params The params structure.
/// \return true if the number of programs is greater than 2, false otherwise.
////////////////////////////////////////////////////////////////////////////////
bool get_params_prog_nbr(char **argv, params_t *params)
{
    if (!argv || !params) {
        my_putstr("Error : Couldn't get the number of programs\n", 2);
        return false;
    }
    int prog_nbr = 0;
    for (int i = 0; argv[i]; i++)
        if (my_check_file_extension(argv[i], EXT_COR)) prog_nbr++;
    if (prog_nbr < 2) {
        my_putstr("Error : Not enough programs\n", 2);
        return false;
    }
    params->prog_nbr = prog_nbr;
    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Initialize the progs params structure array.
/// \param params The params structure.
/// \param mall_v1 The value to multiply the malloc size by. USE '1'.
/// \return true if the progs params structure array is initialized, false
/// otherwise.
/// \note Returns false if an error occurs.
/// \note The progs params structure array is NULL terminated.
////////////////////////////////////////////////////////////////////////////////
bool init_params_progs(params_t *params, int mall_v1)
{
    if (!params) {
        my_putstr("Error : Couldn't initialize the programms\n", 2);
        return false;
    }
    params->progs = malloc(sizeof(params_progs_t *) * (params->prog_nbr + 1));
    if (!params->progs) {
        my_perror("malloc");
        return false;
    }
    for (int i = 0; i < params->prog_nbr; i++) {
        if (!(params->progs[i] = malloc(sizeof(params_progs_t) * mall_v1))) {
            my_perror("malloc");
            freen_params_progs(params->progs, i);
            return false;
        }
        params->progs[i]->load_address = -1; params->progs[i]->prog_nbr = -1;
        params->progs[i]->prog_name = NULL;
    }
    params->progs[params->prog_nbr] = NULL;
    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Get the programs params.
/// \param argv The arguments.
/// \param params The params structure.
/// \param mall_v1 The value to multiply the malloc size by. USE '1'.
/// \return true if the programs params are valid, false otherwise.
/// \note Returns false if an error occurs.
/// \note The progs params structure array is NULL terminated.
/// \note Algorithm :
/// \note   - y is the index of the current prog.
/// \note   - slider is the number of arguments to skip.
/// \note   - if the current argument is a program name :
/// \note       - add the program name to the progs params structure array.
/// \note       - skip 1 argument.
/// \note   - if the current argument is an adress & a program name :
/// \note       - add the program name to the progs params structure array.
/// \note       - add the adress to the progs params structure array.
/// \note       - skip 3 arguments.
/// \note   - if the current argument is a program number & a program name :
/// \note       - add the program name to the progs params structure array.
/// \note       - add the program number to the progs params structure array.
/// \note       - skip 3 arguments.
/// \note   - if the current argument is an adress, a program number & a
/// program name :
/// \note       - add the program name to the progs params structure array.
/// \note       - add the program number to the progs params structure array.
/// \note       - add the adress to the progs params structure array.
/// \note       - skip 5 arguments.
/// \note   - if the current argument is a program number, an adress & a
/// program name :
/// \note       - add the program name to the progs params structure array.
/// \note       - add the program number to the progs params structure array.
/// \note       - add the adress to the progs params structure array.
/// \note       - skip 5 arguments.
/// \note   - if the current argument is none of the above :
/// \note       - return false.
////////////////////////////////////////////////////////////////////////////////
bool get_params_progs(char **argv, params_t *params, int mall_v1)
{
    if (!argv || !params) return false;
    for (int y = 0, slider = 0; *argv; y++) {
        slider = add_progname(argv, params, y, mall_v1) ? 1 : 0;
        argv += slider;
        if (slider) continue;
        slider = add_adress_name(argv, params, y, mall_v1) ? 3 : 0;
        argv += slider;
        if (slider) continue;
        slider = add_pnbr_name(argv, params, y, mall_v1) ? 3 : 0;
        argv += slider;
        if (slider) continue;
        slider = add_adress_pnbr_name(argv, params, y, mall_v1) ? 5 : 0;
        argv += slider;
        if (slider) continue;
        slider = add_pnbr_adress_name(argv, params, y, mall_v1) ? 5 : 0;
        argv += slider;
        if (slider) continue;
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Initialize the params structure.
/// \param argv The arguments.
/// \param mall_v1 The malloc value for the first malloc. USE '1'.
/// \param mall_v2 The malloc value for the second malloc. USE '1'.
/// \return The params structure.
/// \note Returns NULL if an error occurs.
/// \note Returns the params structure if no error occurs.
/// \note Initializes the params in this order:
/// \note   - 1. The dump_nbr_cycles.
/// \note   - 2. Get the number of programs.
/// \note   - 3. Initialize the params_progs_t structure array.
/// \note   - 4. Get the programs parameters.
////////////////////////////////////////////////////////////////////////////////
params_t *init_params(char **argv, int mall_v1, int mall_v2)
{
    params_t *params = NULL; success_t dump_return = NONE;
    if (!argv) return NULL;
    if (!(params = malloc(sizeof(params_t) * mall_v1))) return NULL;
    params->dump_nbr_cycles = -1;
    params->prog_nbr = -1;
    params->progs = NULL;
    dump_return = get_dump_nbr_cycle(argv, params);
    if (dump_return == FAILURE) return e_init_params(params);
    if (dump_return == SUCCESS) argv += 2;
    if (!(get_params_prog_nbr(argv, params))) return e_init_params(params);
    if (!(init_params_progs(params, mall_v2))) return e_init_params(params);
    if (!(get_params_progs(argv, params, 1))) {
        my_putstr("Error : Invalid program parameters\n", 2);
        free_params_progs(params->progs);
        return e_init_params(params);
    }
    return params;
}
