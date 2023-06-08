/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** add_name_comment_to_buffer
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file add_name_comment_to_buffer.c
/// \brief Contains the parsing functions that add the name and the comment to
/// the buffer.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool add_comment_to_buffer(asm_t *asm_struct, char *line);
bool add_name_to_buffer(asm_t *asm_struct, char *line);

////////////////////////////////////////////////////////////////////////////////
/// \brief Adds the comment to the buffer.
/// \param asm_struct The asm struct.
/// \param line Contains the line to parse.
/// \return true if the comment has been added to the buffer, false otherwise.
/// \note The comment must be between double quotes.
/// \note The comment must be less than COMMENT_LENGTH.
/// \note The comment must be on the same line as the .comment directive.
////////////////////////////////////////////////////////////////////////////////
bool add_comment_to_buffer(asm_t *asm_struct, char *line)
{
    char *comment = NULL; int len_to_comment = 0;
    if (!asm_struct || !line) return false;
    if ((len_to_comment = my_strlen_sepa(line, "\"")) == -1) return false;
    line += len_to_comment + 1;
    if (!*line) return false;
    if ((len_to_comment = my_strlen_sepa(line, "\"")) == -1) return false;
    if (len_to_comment > COMMENT_LENGTH) return false;
    if ((comment = my_strndup(line, len_to_comment, 1)) == NULL) return false;
    if (!add_bytes_to_buffer(asm_struct, comment, my_strlen(comment)))
        return false;
    my_free(comment);
    for (int i = len_to_comment; i < COMMENT_LENGTH; i++)
        if (!add_byte_to_buffer(asm_struct, 0)) return false;
    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Adds the name to the buffer.
/// \param asm_struct The asm struct.
/// \param line Contains the line to parse.
/// \return true if the name has been added to the buffer, false otherwise.
/// \note The name must be between double quotes.
/// \note The name must be less than PROG_NAME_LENGTH.
/// \note The name must be on the same line as the .name directive.
////////////////////////////////////////////////////////////////////////////////
bool add_name_to_buffer(asm_t *asm_struct, char *line)
{
    char *name = NULL; int len_to_name = 0;
    if (!asm_struct || !line) return false;
    if ((len_to_name = my_strlen_sepa(line, "\"")) == -1) return false;
    line += len_to_name + 1;
    if (!*line) return false;
    if ((len_to_name = my_strlen_sepa(line, "\"")) == -1) return false;
    if (len_to_name > PROG_NAME_LENGTH) return false;
    if ((name = my_strndup(line, len_to_name, 1)) == NULL) return false;
    if (!add_bytes_to_buffer(asm_struct, name, my_strlen(name))) return false;
    my_free(name);
    for (int i = len_to_name; i < PROG_NAME_LENGTH; i++)
        if (!add_byte_to_buffer(asm_struct, 0)) return false;
    return true;
}
