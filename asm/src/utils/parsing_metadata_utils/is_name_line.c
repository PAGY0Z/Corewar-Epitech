/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** is_name_line
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file is_name_line.c
/// \brief Contains the function to check if a line is a .name line.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool is_name_line(char *line);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if a line is a .name line.
/// \param line The line to check.
/// \return true if the line is a .name line, false otherwise.
/// \note A .name line is a line that follows the following format :
/// \note [SPACES] .name SPACE "NAME" [SPACES]
/// \note All the checks done :
/// \note - The line is not NULL.
/// \note - The line is not empty.
/// \note - Slides in the line until the first non empty char.
/// \note - Check if the line starts with ".name".
/// \note - Slides in the line until the first non empty char.
/// \note - Check if the line starts with '"'.
/// \note - Slides in while the char is not '"'.
/// \note - Check if the line starts with '"'.
/// \note - Slides in the line until the first non empty char.
/// \note - Check if the line is empty.
/// \note - Check if the name length is not greater than PROG_NAME_LENGTH.
////////////////////////////////////////////////////////////////////////////////
bool is_name_line(char *line)
{
    int i = 0; int save = 0; int name_len = 0;
    if (!line) return false;
    if (!*line) return false;
    for (; IS_EMPTY_CHAR(line[i]); i++);
    if (!my_strncmp(line + i, ".name", 5)) return false;
    i += 5; save = i;
    for (; IS_EMPTY_CHAR(line[i]); i++);
    if (save == i) return false;
    if (line[i++] != '"') return false;
    for (; line[i] && line[i] != '"'; i++, name_len++);
    if (line[i++] != '"') return false;
    for (; IS_EMPTY_CHAR(line[i]); i++);
    if (line[i]) return false;
    if (name_len > PROG_NAME_LENGTH) return false;
    return true;
}
