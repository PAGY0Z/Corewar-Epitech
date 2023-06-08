/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** programm_main
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file corewar_programm_main.c
/// \brief Contains the main function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-23-04
////////////////////////////////////////////////////////////////////////////////

int display_corewar_help(char **corewar_help_array);
bool check_corewar_args(int argc, char **argv);
int corewar_programm_main(int argc, char **argv);

////////////////////////////////////////////////////////////////////////////////
/// \brief Display the help message for the corewar program.
/// \return 0 if the help message was displayed, 84 otherwise.
/// \warning Returns 84 if an error occurs.
////////////////////////////////////////////////////////////////////////////////
int display_corewar_help(char **corewar_help_array)
{
    if (!my_print_array(corewar_help_array, 0)) {
        my_putstr("Couldn't display the help message\n", 2);
        return ERR_OUT;
    }
    return SUC_OUT;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Check the arguments given to the program.
/// \param argc The number of arguments.
/// \param argv The arguments.
/// \return true if the arguments are valid, false otherwise.
/// \note Returns false if one of the arguments is invalid.
/// \note An argument is invalid if :
/// \note   - It is not '-dump'
/// \note   - It is not '-n'
/// \note   - It is not '-a'
/// \note   - It is not a number
/// \note   - It is not a '.cor' file
////////////////////////////////////////////////////////////////////////////////
bool check_corewar_args(int argc, char **argv)
{
    if (!argv) return false;
    for (int i = 0; i < argc; i++) {
        if (my_strcmp(argv[i], "-dump")) continue;
        if (my_strcmp(argv[i], "-n")) continue;
        if (my_strcmp(argv[i], "-a")) continue;
        if (str_is_token(argv[i], BASE_HEX_UP)) continue;
        if (my_check_file_extension(argv[i], EXT_COR)) continue;
        my_putstr("Error : [", 2);
        my_putstr(argv[i], 2);
        my_putstr("] : Invalid argument\n", 2);
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief The main function.
/// \param argc The number of arguments.
/// \param argv The arguments.
/// \return 0 if the program ran successfully, 84 otherwise.
////////////////////////////////////////////////////////////////////////////////
int corewar_programm_main(int argc, char **argv)
{
    params_t *params = NULL;
    if (!argv) return ERR_OUT;
    if (!argv[0]) return ERR_OUT;
    argv++; argc--;
    if (my_help_identifier(argv))
        return display_corewar_help((char **)corewar_help);
    if (!check_corewar_args(argc, argv)) return ERR_OUT;
    if (!(params = init_params(argv, 1, 1))) return ERR_OUT;
    if (!params_check_update(params)) {
        free_params(params);
        return ERR_OUT;
    }
    return init_corewar_programm(params);
}
