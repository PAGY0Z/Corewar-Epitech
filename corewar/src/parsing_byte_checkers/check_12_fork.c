/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** check_12_fork
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file check_12_fork.c
/// \brief Contains the check_12_fork functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-25-05
////////////////////////////////////////////////////////////////////////////////

bool check_12_fork(byte_t op_code, byte_t pars_byte, byte_t *params);

////////////////////////////////////////////////////////////////////////////////
/// \brief The parsing byte checker for fork instruction.
/// \param op_code A byte which represent the instruction
/// \param pars_byte A byte which represent the parsing byte
/// \return True if the arguments are correct, False otherwise.
/// \note Returns false in those cases:
/// \note   - op_code is not 0x0c
////////////////////////////////////////////////////////////////////////////////
bool check_12_fork(byte_t op_code, UNUSED byte_t pars_byte, UNUSED byte_t *pams)
{
    if (op_code != 0x0c) return false;
    return true;
}
