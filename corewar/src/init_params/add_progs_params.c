/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** add_progs_params
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file add_progs_params.c
/// \brief Contains the add_progs_params function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-18-05
////////////////////////////////////////////////////////////////////////////////

bool add_progname(char **argv, params_t *params, int prog, int mall_v1);
bool add_pnbr_name(char **argv, params_t *params, int prog, int mall_v1);
bool add_adress_name(char **argv, params_t *params, int prog, int mall_v1);
bool add_pnbr_adress_name(char **argv, params_t *params, int prog, int mall_v1);
bool add_adress_pnbr_name(char **argv, params_t *params, int prog, int mall_v1);

////////////////////////////////////////////////////////////////////////////////
/// \brief Checks if the progname has a progname. Adds it to the params
/// structure.
/// \param argv The arguments of the program.
/// \param params The params structure.
/// \param prog The current prog.
/// \param mall_v1 The value to multiply the size of the malloc. USE '1'.
/// \return true if the progname has a progname, false otherwise.
/// \note Returns false in those cases:
/// \note   - argv is NULL.
/// \note   - params is NULL.
/// \note   - array_len is inferior to 1.
/// \note   - argv[0] is not a .cor file.
/// \note   - prog is superior or equal to params->prog_nbr.
/// \note   - my_strdup failed.
////////////////////////////////////////////////////////////////////////////////
bool add_progname(char **argv, params_t *params, int prog, int mall_v1)
{
    if (!argv || !params || prog < 0) return false;
    if (my_array_len(argv) < 1) return false;
    if (!my_check_file_extension(argv[0], EXT_COR)) return false;
    if (prog >= params->prog_nbr) return false;
    if (!(params->progs[prog]->prog_name = my_strdup(argv[0], mall_v1)))
        return false;
    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Checks if the progname has a progname and a load address. Adds them
/// to the params structure.
/// \param argv The arguments of the program.
/// \param params The params structure.
/// \param prog The current prog.
/// \param mall_v1 The value to multiply the size of the malloc. USE '1'.
/// \return true if the progname has a progname and a load address, false
/// otherwise.
/// \note Returns false in those cases:
/// \note   - argv is NULL.
/// \note   - params is NULL.
/// \note   - array_len is inferior to 5.
/// \note   - argv[0] is not "-n".
/// \note   - argv[1] is not a number.
/// \note   - argv[2] is not "-a".
/// \note   - argv[3] is not a number.
/// \note   - argv[4] is not a .cor file.
/// \note   - prog is superior or equal to params->prog_nbr.
/// \note   - my_strdup failed.
////////////////////////////////////////////////////////////////////////////////
bool add_pnbr_name(char **argv, params_t *params, int prog, int mall_v1)
{
    if (!argv || !params || prog < 0) return false;
    if (my_array_len(argv) < 3) return false;
    if (!my_strcmp(argv[0], "-n")) return false;
    if (!str_is_num(argv[1])) return false;
    if (!my_check_file_extension(argv[2], EXT_COR)) return false;
    if (prog >= params->prog_nbr) return false;
    params->progs[prog]->prog_nbr = ABS(my_getnbr(argv[1]));
    if (!(params->progs[prog]->prog_name = my_strdup(argv[2], mall_v1)))
        return false;
    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Checks if the progname has a load address and a progname. Adds them
/// to the params structure.
/// \param argv The arguments of the program.
/// \param params The params structure.
/// \param prog The current prog.
/// \param mall_v1 The value to multiply the size of the malloc. USE '1'.
/// \return true if the progname has a load address and a progname, false
/// otherwise.
/// \note Returns false in those cases:
/// \note   - argv is NULL.
/// \note   - params is NULL.
/// \note   - array_len is inferior to 3.
/// \note   - argv[0] is not "-a".
/// \note   - argv[1] is not a number.
/// \note   - argv[2] is not a .cor file.
/// \note   - prog is superior or equal to params->prog_nbr.
/// \note   - my_strdup failed.
////////////////////////////////////////////////////////////////////////////////
bool add_adress_name(char **argv, params_t *params, int prog, int mall_v1)
{
    int load_adress = 0;
    if (!argv || !params || prog < 0) return false;
    if (my_array_len(argv) < 3) return false;
    if (!my_strcmp(argv[0], "-a")) return false;
    if (!str_is_token(argv[1], BASE_HEX_UP)) return false;
    if (!my_check_file_extension(argv[2], EXT_COR)) return false;
    if (prog >= params->prog_nbr) return false;
    load_adress = ABS(my_getnbr_base(argv[1], BASE_HEX_UP)) % MEM_SIZE;
    params->progs[prog]->load_address = load_adress;
    if (!(params->progs[prog]->prog_name = my_strdup(argv[2], mall_v1)))
        return false;
    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Checks if the progname has a progname, a load address and a progname.
/// Adds them to the params structure.
/// \param argv The arguments of the program.
/// \param params The params structure.
/// \param prog The current prog.
/// \param mall_v1 The value to multiply the size of the malloc. USE '1'.
/// \return true if the progname has a progname, a load address and a progname,
/// false otherwise.
/// \note Returns false in those cases:
/// \note   - argv is NULL.
/// \note   - params is NULL.
/// \note   - array_len is inferior to 5.
/// \note   - argv[0] is not "-n".
/// \note   - argv[1] is not a number.
/// \note   - argv[2] is not "-a".
/// \note   - argv[3] is not a number.
/// \note   - argv[4] is not a .cor file.
/// \note   - prog is superior or equal to params->prog_nbr.
/// \note   - my_strdup failed.
////////////////////////////////////////////////////////////////////////////////
bool add_pnbr_adress_name(char **argv, params_t *params, int prog, int mall_v1)
{
    int load_adress = 0;
    if (!argv || !params || prog < 0) return false;
    if (my_array_len(argv) < 5) return false;
    if (!my_strcmp(argv[0], "-n")) return false;
    if (!str_is_num(argv[1])) return false;
    if (!my_strcmp(argv[2], "-a")) return false;
    if (!str_is_token(argv[3], BASE_HEX_UP)) return false;
    if (!my_check_file_extension(argv[4], EXT_COR)) return false;
    if (prog >= params->prog_nbr) return false;
    params->progs[prog]->prog_nbr = ABS(my_getnbr(argv[1]));
    load_adress = ABS(my_getnbr_base(argv[3], BASE_HEX_UP)) % MEM_SIZE;
    params->progs[prog]->load_address = load_adress;
    if (!(params->progs[prog]->prog_name = my_strdup(argv[4], mall_v1)))
        return false;
    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Checks if the progname has a progname and a load address. Adds them
/// to the params structure.
/// \param argv The arguments of the program.
/// \param params The params structure.
/// \param prog The current prog.
/// \param mall_v1 The value to multiply the size of the malloc. USE '1'.
/// \return true if the progname has a progname and a load address, false
/// otherwise.
/// \note Returns false in those cases:
/// \note   - argv is NULL.
/// \note   - params is NULL.
/// \note   - array_len is inferior to 5.
/// \note   - argv[0] is not "-a".
/// \note   - argv[1] is not a number.
/// \note   - argv[2] is not "-n".
/// \note   - argv[3] is not a number.
/// \note   - argv[4] is not a .cor file.
/// \note   - prog is superior or equal to params->prog_nbr.
/// \note   - my_strdup failed.
////////////////////////////////////////////////////////////////////////////////
bool add_adress_pnbr_name(char **argv, params_t *params, int prog, int mall_v1)
{
    int load_adress = 0;
    if (!argv || !params || prog < 0) return false;
    if (my_array_len(argv) < 5) return false;
    if (!my_strcmp(argv[0], "-a")) return false;
    if (!str_is_token(argv[1], BASE_HEX_UP)) return false;
    if (!my_strcmp(argv[2], "-n")) return false;
    if (!str_is_num(argv[3])) return false;
    if (!my_check_file_extension(argv[4], EXT_COR)) return false;
    if (prog >= params->prog_nbr) return false;
    load_adress = ABS(my_getnbr_base(argv[1], BASE_HEX_UP)) % MEM_SIZE;
    params->progs[prog]->load_address = load_adress;
    params->progs[prog]->prog_nbr = ABS(my_getnbr(argv[3]));
    if (!(params->progs[prog]->prog_name = my_strdup(argv[4], mall_v1)))
        return false;
    return true;
}
