/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** check_15_lfork
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file check_15_lfork.c
/// \brief Contains the check_15_lfork functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-25-05
////////////////////////////////////////////////////////////////////////////////

bool check_15_lfork(byte_t op_code, byte_t pars_byte, byte_t *params);

////////////////////////////////////////////////////////////////////////////////
/// \brief The parsing byte checker for lfork instruction.
/// \param op_code A byte which represent the instruction
/// \param pars_byte A byte which represent the parsing byte
/// \return True if the arguments are correct, False otherwise.
/// \note Returns false in those cases:
/// \note   - op_code is not 0x0f
////////////////////////////////////////////////////////////////////////////////
bool check_15_lfork(byte_t op_code, UNUSED byte_t pars_byte, UNUSED byte_t *pms)
{
    if (op_code != 0x0f) return false;
    return true;
}
