/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** free_asm_struct
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file free_asm_struct.c
/// \brief Contains the function that frees the asm struct.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

void free_asm_struct(asm_t *asm_struct);

////////////////////////////////////////////////////////////////////////////////
/// \brief Free the asm struct and its content.
/// \param asm_struct The asm struct.
/// \note Frees the structure in the following order:
/// \note   - The labels.
/// \note   - The file lines.
/// \note   - The buffer.
/// \note   - The new file name.
/// \note   - The asm struct.
////////////////////////////////////////////////////////////////////////////////
void free_asm_struct(asm_t *asm_struct)
{
    free_labels(asm_struct->labels);
    free_array(asm_struct->file_lines);
    my_free(asm_struct->buffer);
    my_free(asm_struct->file_name);
    my_free(asm_struct);
}
