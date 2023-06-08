/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** check_04_add
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file check_04_add.c
/// \brief Contains the check_04_add functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-25-05
////////////////////////////////////////////////////////////////////////////////

bool check_04_add(byte_t op_code, byte_t pars_byte, byte_t *params);

////////////////////////////////////////////////////////////////////////////////
/// \brief The parsing byte checker for add instruction.
/// \param op_code A byte which represent the instruction
/// \param pars_byte A byte which represent the parsing byte
/// \return True if the arguments are correct, False otherwise.
/// \note Returns false in those cases:
/// \note   - op_code is not 0x04
/// \note   - bits 0b{11} 00 00 00 are not REG
/// \note   - bits 0b00 {11} 00 00 are not REG
/// \note   - bits 0b00 00 {11} 00 are not REG
/// \note   - bits 0b00 00 00 {11} are not OTH
////////////////////////////////////////////////////////////////////////////////
bool check_04_add(byte_t op_code, byte_t pars_byte, byte_t *params)
{
    if (op_code != 0x04) return false;
    if (!(IS_REG(P1(pars_byte)))) return false;
    if (!(IS_REG(P2(pars_byte)))) return false;
    if (!(IS_REG(P3(pars_byte)))) return false;
    if (!(IS_OTH(P4(pars_byte)))) return false;
    if ((params[2] & 0xFF) < 1 || (params[2] & 0xFF) > REG_NUMBER) return false;
    if ((params[3] & 0xFF) < 1 || (params[3] & 0xFF) > REG_NUMBER) return false;
    if ((params[4] & 0xFF) < 1 || (params[4] & 0xFF) > REG_NUMBER) return false;
    return true;
}
