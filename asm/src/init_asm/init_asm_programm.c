/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** init_asm_programm
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file init_asm_programm.c
/// \brief Contains the init_asm_programm functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

asm_t *init_asm_struct(char const *filepath);
int init_asm_programm(char const *filepath);

////////////////////////////////////////////////////////////////////////////////
/// \brief Initialize the asm structure.
/// \param filepath The path of the file to read.
/// \return The initialized asm structure.
/// \warning The asm structure must be freed with free_asm_struct.
/// \note The asm structure is initialized with :
/// \note   - The file buffer. (empty)
/// \note   - The file lines. (From the file)
/// \note   - The new file name. (The file name with the new extension)
/// \note   - The labels. (Empty from data except their names)
/// \note   - The index. (initialized to 0)
/// \note   - The line index. (initialized to 0)
////////////////////////////////////////////////////////////////////////////////
asm_t *init_asm_struct(char const *filepath)
{
    asm_t *asm_struct = malloc(sizeof(asm_t));
    if (!asm_struct) return NULL;
    if (!(asm_struct->buffer = malloc(sizeof(char))))
        return e_init_buffer(asm_struct);
    asm_struct->file_name = get_new_file_name(filepath, EXT_ASM, EXT_COR, 1);
    if (!asm_struct->file_name) return e_init_file_name(asm_struct);
    asm_struct->file_lines = get_file_lines_getline(filepath, MALL_VS, MALL_VS);
    if (!asm_struct->file_lines) return e_init_file_lines(asm_struct);
    if (!(asm_struct->labels = init_labels(asm_struct->file_lines)))
        return e_init_init_labels(asm_struct);
    if (!clean_array_from_comments(asm_struct->file_lines))
        return e_init_init_labels(asm_struct);
    asm_struct->buffer[0] = '\0';
    asm_struct->index = 0;
    asm_struct->line_index = 0;
    return asm_struct;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Init the asm programm execute it.
/// \param filepath The path of the file
/// \return 0 if success, 84 if error
/// \note The asm programm is initialized & ran with these steps:
/// \note   - The asm structure init.
/// \note   - The file parsing.
/// \note   - The file writing.
/// \note   - The asm structure freeing.
/// \note If an error occurs during the execution, the asm structure is freed.
/// \note The whole programm is stopped nicely.
////////////////////////////////////////////////////////////////////////////////
int init_asm_programm(char const *filepath)
{
    asm_t *asm_struct = NULL; int fd = 0;
    if (!(asm_struct = init_asm_struct(filepath))) return ERR_OUT;
    if (!file_parsing(asm_struct)) return e_init_asm_programm(asm_struct);
    if ((fd = create_writable_file(asm_struct->file_name)) == -1)
        return e_init_asm_programm(asm_struct);
    if (!write_file(fd, asm_struct)) return e_init_asm_programm(asm_struct);
    free_asm_struct(asm_struct);
    return SUC_OUT;
}
