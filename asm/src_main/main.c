/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** main
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file main.c
/// \brief Contains the main function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv);

////////////////////////////////////////////////////////////////////////////////
/// \brief The main function.
/// \param argc The number of arguments.
/// \param argv The arguments.
/// \return 0 if the program ran successfully, 84 otherwise.
/// \note This function calls the asm_programm_main function. It allows us to
/// test the whole programm without a main function in the asm_programm_main.
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    return asm_programm_main(argc, argv);
}
