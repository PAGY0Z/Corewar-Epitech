/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** champions_validity_checkers
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file champions_validity_checkers.c
/// \brief Contains the champions_validity_checkers functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-23-05
////////////////////////////////////////////////////////////////////////////////

bool check_header_magic_number_prog_size(header_t header, int size);
bool check_header_prog_name(header_t header);
bool check_header_comment(header_t header);
bool champions_validity_checkers(params_progs_t *prog);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if the champions are valid.
/// \param prog The program to check.
/// \return true if the champions are valid, false otherwise.
/// \note The magic number is valid if it is equal to MAGIC_NUMBER_VALUE.
/// \note The program size is valid if it is equal to the size of the program.
////////////////////////////////////////////////////////////////////////////////
bool check_header_magic_number_prog_size(header_t header, int size)
{
    if (reverse_int(header.magic) != MAGIC_NUMBER_VALUE) {
        my_putstr("Error: Magic number is invalid.\n", 2);
        return false;
    }
    if (reverse_int(header.prog_size) != size - FULL_HEADER_SIZE) {
        my_putstr("Error: Program size is invalid.\n", 2);
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if the program name is valid.
/// \param header The header to check.
/// \return true if the program name is valid, false otherwise.
/// \note The program name is valid if it contains only printable characters.
/// \note The program name is valid if it is padded with '\0'.
////////////////////////////////////////////////////////////////////////////////
bool check_header_prog_name(header_t header)
{
    for (int i = 0; i < PROG_NAME_LENGTH; i++) {
        if (header.prog_name[i] == '\0') continue;
        if (!IS_PRINTABLE(header.prog_name[i])) {
            my_putstr("Error: Program name is invalid.\n", 2);
            return false;
        }
    }
    for (int i = PROG_NAME_LENGTH; i < PROG_NAME_LENGTH + 4; i++)
        if (header.prog_name[i] != '\0') {
            my_putstr("Error: Program name padding is invalid.\n", 2);
            return false;
        }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if the program comment is valid.
/// \param header The header to check.
/// \return true if the program comment is valid, false otherwise.
/// \note The program comment is valid if it contains only printable characters.
/// \note The program comment is valid if it is padded with '\0'.
////////////////////////////////////////////////////////////////////////////////
bool check_header_comment(header_t header)
{
    for (int i = 0; i < COMMENT_LENGTH; i++) {
        if (header.comment[i] == '\0') continue;
        if (!IS_PRINTABLE(header.comment[i])) {
            my_putstr("Error: Program comment is invalid.\n", 2);
            return false;
        }
    }
    for (int i = COMMENT_LENGTH; i < COMMENT_LENGTH + 4; i++)
        if (header.comment[i] != '\0') {
            my_putstr("Error: Program comment padding is invalid.\n", 2);
            return false;
        }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if the champion is valid.
/// \param prog The champion to check.
/// \return true if the champion is valid, false otherwise.
/// \note The champion is valid if the magic number is valid, the program size
/// is valid, the program name is valid and the program comment is valid.
/// \note Function steps:
/// \note 0.0 File size is valid.
/// \note 0.1 File is readable.
/// \note 0.2 File is big enough to contain a header.
/// \note 1. Check if the magic number is valid.
/// \note 2. Check if the program size is valid.
/// \note 3. Check if the program name is valid.
/// \note 4. Check if the program comment is valid.
////////////////////////////////////////////////////////////////////////////////
bool champions_validity_checkers(params_progs_t *prog)
{
    FILE *stream = NULL; header_t header; int size = 0;
    if (!prog) return false;
    if (!prog->prog_name) return false;
    if ((size = get_file_size_lseek(prog->prog_name)) < FULL_HEADER_SIZE)
        return false;
    if (!(stream = fopen(prog->prog_name, "r"))) return false;
    if (fread(&header, sizeof(header_t), 1, stream) != 1) return false;
    fclose(stream);
    if (!check_header_magic_number_prog_size(header, size)) return false;
    if (!check_header_prog_name(header)) return false;
    if (!check_header_comment(header)) return false;
    return true;
}
