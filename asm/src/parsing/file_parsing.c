/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** file_parsing
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file file_parsing.c
/// \brief Contains the parsing functions for the file.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool add_magic_number(asm_t *asm_struct);
bool add_comment(asm_t *asm_struct);
bool add_name(asm_t *asm_struct);
bool file_parsing(asm_t *asm_struct);

////////////////////////////////////////////////////////////////////////////////
/// \brief Add the magic number to the buffer.
/// \param asm_struct The asm structure.
/// \return true if the write was successful, false otherwise.
////////////////////////////////////////////////////////////////////////////////
bool add_magic_number(asm_t *asm_struct)
{
    return add_bytes_to_buffer(asm_struct, MAGIC_NUMBER, MAGIC_NUMBER_SIZE);
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Add the comment to the buffer.
/// \param asm_struct The asm struct.
/// \return true if the write was successful, false otherwise.
/// \note Functions steps:
/// \note   - In a loop, go through the lines of the file.
/// \note   - If the line is empty, go to the next line.
/// \note   - If the line is not a comment, return false.
/// \note   - If the line is a comment, add it to the buffer.
/// \note   - Return true.
/// \note Return false if no comment is found.
////////////////////////////////////////////////////////////////////////////////
bool add_comment(asm_t *asm_struct)
{
    char **lines = NULL;
    if (!asm_struct) return false;
    lines = asm_struct->file_lines;
    for (; lines[asm_struct->line_index]; asm_struct->line_index++) {
        if (str_is_empty(lines[asm_struct->line_index]))
            continue;
        if (!is_comment_line(lines[asm_struct->line_index]))
            return false;
        return add_comment_to_buffer(asm_struct, lines[asm_struct->line_index]);
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Add the name to the buffer.
/// \param asm_struct The asm struct.
/// \return true if the write was successful, false otherwise.
/// \note Functions steps:
/// \note   - In a loop, go through the lines of the file.
/// \note   - If the line is empty, go to the next line.
/// \note   - If the line is not a name, return false.
/// \note   - If the line is a name, add it to the buffer.
/// \note   - Return true.
/// \note Return false if no name is found.
////////////////////////////////////////////////////////////////////////////////
bool add_name(asm_t *asm_struct)
{
    char **lines = NULL;
    if (!asm_struct) return false;
    lines = asm_struct->file_lines;
    for (; lines[asm_struct->line_index]; asm_struct->line_index++) {
        if (str_is_empty(lines[asm_struct->line_index]))
            continue;
        if (!is_name_line(lines[asm_struct->line_index]))
            return false;
        return add_name_to_buffer(asm_struct, lines[asm_struct->line_index]);
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Parse the file.
/// \param asm_struct The asm struct.
/// \return true if the write was successful, false otherwise.
/// \note The file will be parsed in this order:
/// \note   - Add Magic number
/// \note   - Add Name
/// \note   - Add Comment
/// \note   - Add The instructions
/// \note   - Replace the program size by its value
/// \note   - Replace the labels by their address
/// \note Returns false if the name or the comment is not found.
/// \note Returns false if an error occurs during the parsing.
/// \note 8 bytes are added to the buffer after the name. 4 bytes as padding
/// and 4 bytes for the program size.
/// \note 4 bytes are added to the buffer after the comment. 4 bytes as padding.
////////////////////////////////////////////////////////////////////////////////
bool file_parsing(asm_t *asm_struct)
{
    if (!asm_struct) return false;
    if (!add_magic_number(asm_struct)) return false;
    if (!add_name(asm_struct)) return false;
    asm_struct->line_index++;
    for (int i = 0; i < 8; i++)
        if (!add_byte_to_buffer(asm_struct, 0x00)) return false;
    if (!add_comment(asm_struct)) return false;
    asm_struct->line_index++;
    for (int i = 0; i < 4; i++)
        if (!add_byte_to_buffer(asm_struct, 0x00)) return false;
    if (!add_instructions(asm_struct)) return false;
    change_prog_size(asm_struct);
    replace_labels(asm_struct);
    return true;
}
