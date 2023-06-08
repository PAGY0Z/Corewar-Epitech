/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** check_08_xor
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file check_08_xor.c
/// \brief Contains the check_08_xor functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-25-05
////////////////////////////////////////////////////////////////////////////////

bool check_08_xor(byte_t op_code, byte_t pars_byte, byte_t *params);

////////////////////////////////////////////////////////////////////////////////
/// \brief The parsing byte checker for xor instruction.
/// \param op_code A byte which represent the instruction
/// \param pars_byte A byte which represent the parsing byte
/// \return True if the arguments are correct, False otherwise.
/// \note Returns false in those cases:
/// \note   - op_code is not 0x08
/// \note   - bits 0b{11} 00 00 00 are not REG or DIR or IND
/// \note   - bits 0b00 {11} 00 00 are not REG or DIR or IND
/// \note   - bits 0b00 00 {11} 00 are not REG
/// \note   - bits 0b00 00 00 {11} are not OTH
////////////////////////////////////////////////////////////////////////////////
bool check_08_xor(byte_t op_code, byte_t pars_byte, byte_t *params)
{
    int pos = 2;
    if (op_code != 0x08) return false;
    if (RDI(P1(pars_byte))) return false;
    pos += (IS_REG(P1(pars_byte))) ? 1 : 0;
    pos += (IS_DIR(P1(pars_byte))) ? 4 : 0;
    pos += (IS_IND(P1(pars_byte))) ? 2 : 0;
    if (RDI(P2(pars_byte))) return false;
    pos += (IS_REG(P2(pars_byte))) ? 1 : 0;
    pos += (IS_DIR(P2(pars_byte))) ? 4 : 0;
    pos += (IS_IND(P2(pars_byte))) ? 2 : 0;
    if (!(IS_REG(P3(pars_byte)))) return false;
    if ((params[pos] & 0xFF) < 1 || (params[pos] & 0xFF) > REG_NUMBER)
        return false;
    if (!(IS_OTH(P4(pars_byte)))) return false;
    return true;
}
