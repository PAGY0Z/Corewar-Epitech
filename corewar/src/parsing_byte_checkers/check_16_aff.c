/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** check_16_aff
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file check_16_aff.c
/// \brief Contains the check_16_aff functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-25-05
////////////////////////////////////////////////////////////////////////////////

bool check_16_aff(byte_t op_code, byte_t pars_byte, byte_t *params);

////////////////////////////////////////////////////////////////////////////////
/// \brief The parsing byte checker for aff instruction.
/// \param op_code A byte which represent the instruction
/// \param pars_byte A byte which represent the parsing byte
/// \return True if the arguments are correct, False otherwise.
/// \note Returns false in those cases:
/// \note   - op_code is not 0x10
/// \note   - bits 0b{11} 00 00 00 are not REG
/// \note   - bits 0b00 {11} 00 00 are not OTH
/// \note   - bits 0b00 00 {11} 00 are not OTH
/// \note   - bits 0b00 00 00 {11} are not OTH
////////////////////////////////////////////////////////////////////////////////
bool check_16_aff(byte_t op_code, byte_t pars_byte, byte_t *params)
{
    if (op_code != 0x10) return false;
    if (!(IS_REG(P1(pars_byte)))) return false;
    if (!(IS_OTH(P2(pars_byte)))) return false;
    if (!(IS_OTH(P3(pars_byte)))) return false;
    if (!(IS_OTH(P4(pars_byte)))) return false;
    if ((params[2] & 0xFF) < 1 || (params[2] & 0xFF) > REG_NUMBER) return false;
    return true;
}
