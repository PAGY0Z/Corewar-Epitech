/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** is_comment_line
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file is_comment_line.c
/// \brief Contains the function to check if a line is a .comment line.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool is_comment_line(char *line);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if a line is a .comment line.
/// \param line The line to check.
/// \return true if the line is a .comment line, false otherwise.
/// \note A .comment line is a line that follows the following format :
/// \note [SPACES] .comment SPACE "COMMENT" [SPACES]
/// \note All the checks done :
/// \note - The line is not NULL.
/// \note - The line is not empty.
/// \note - Slides in the line until the first non empty char.
/// \note - Check if the line starts with ".comment".
/// \note - Slides in the line until the first non empty char.
/// \note - Check if the line starts with '"'.
/// \note - Slides in while the char is not '"'.
/// \note - Check if the line starts with '"'.
/// \note - Slides in the line until the first non empty char.
/// \note - Check if the line is empty.
/// \note - Check if the comment length is not greater than COMMENT_LENGTH.
////////////////////////////////////////////////////////////////////////////////
bool is_comment_line(char *line)
{
    int i = 0; int save = 0; int comment_len = 0;
    if (!line) return false;
    if (!*line) return false;
    for (; IS_EMPTY_CHAR(line[i]); i++);
    if (!my_strncmp(line + i, ".comment", 8)) return false;
    i += 8; save = i;
    for (; IS_EMPTY_CHAR(line[i]); i++);
    if (save == i) return false;
    if (line[i++] != '"') return false;
    for (; line[i] && line[i] != '"'; i++, comment_len++);
    if (line[i++] != '"') return false;
    for (; IS_EMPTY_CHAR(line[i]); i++);
    if (line[i]) return false;
    if (comment_len > COMMENT_LENGTH) return false;
    return true;
}
