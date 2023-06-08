/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** asm_programm_main
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file asm_programm_main.c
/// \brief Contains the functions that are the entry point of the asm program.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

int display_asm_help(char **asm_help_array);
bool check_asm_args(int argc, char **argv);
int asm_programm_main(int argc, char **argv);

////////////////////////////////////////////////////////////////////////////////
/// \brief Display the help message for the asm program.
/// \return 0 if the help message was displayed, 84 otherwise.
/// \warning Returns 84 if an error occurs.
////////////////////////////////////////////////////////////////////////////////
int display_asm_help(char **asm_help_array)
{
    if (!my_print_array(asm_help_array, 0)) return ERR_OUT;
    return SUC_OUT;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Check the arguments given to the program. Should be 2 and the file
/// extension should be '.s'.
/// \param argc The number of arguments.
/// \param argv The arguments.
/// \return true if the arguments are valid, false otherwise.
/// \warning Returns false if an error occurs.
/// \note Returns false if the number of arguments is not 2.
/// \note Returns false if the file extension is not '.s'.
////////////////////////////////////////////////////////////////////////////////
bool check_asm_args(int argc, char **argv)
{
    if (argc != 2) return false;
    if (!my_check_file_extension(argv[1], EXT_ASM)) return false;
    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief The main function of the asm program.
/// \param argc The number of arguments.
/// \param argv The arguments.
/// \return Returns 0 if the program ran successfully, 84 otherwise.
/// \warning Returns 84 if an error occurs.
/// \attention Calls the function init_asm_programm to start the program.
/// \note Returns 0 if the help message was displayed.
/// \note Returns 84 if the arguments are invalid.
////////////////////////////////////////////////////////////////////////////////
int asm_programm_main(int argc, char **argv)
{
    if (my_help_identifier(argv)) return display_asm_help((char **)asm_help);
    if (!check_asm_args(argc, argv)) return ERR_OUT;
    return init_asm_programm(argv[1]);
}
