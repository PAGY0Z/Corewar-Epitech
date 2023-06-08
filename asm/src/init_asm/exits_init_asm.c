/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** exits_init_asm
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file exits_init_asm.c
/// \brief Contains the exits functions of the init_asm_programm functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

void *e_init_buffer(asm_t *asm_struct);
void *e_init_file_name(asm_t *asm_struct);
void *e_init_file_lines(asm_t *asm_struct);
void *e_init_init_labels(asm_t *asm_struct);
int e_init_asm_programm(asm_t *asm_struct);

////////////////////////////////////////////////////////////////////////////////
/// \brief Exit the init_asm_struct function. From the buffer Init.
/// \param asm_struct The asm structure.
/// \return NULL.
/// \note Free the structure as it is the first element to be allocated.
////////////////////////////////////////////////////////////////////////////////
void *e_init_buffer(asm_t *asm_struct)
{
    my_free(asm_struct);
    return NULL;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Exit the init_asm_struct function. From the file name Init.
/// \param asm_struct The asm structure.
/// \return NULL.
/// \note Free the buffer as it is the second element to be allocated.
////////////////////////////////////////////////////////////////////////////////
void *e_init_file_name(asm_t *asm_struct)
{
    my_free(asm_struct->buffer);
    return e_init_buffer(asm_struct);
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Exit the init_asm_struct function. From the file lines Init.
/// \param asm_struct The asm structure.
/// \return NULL.
/// \note Free the file name as it is the third element to be allocated.
////////////////////////////////////////////////////////////////////////////////
void *e_init_file_lines(asm_t *asm_struct)
{
    my_free(asm_struct->file_name);
    return e_init_file_name(asm_struct);
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Exit the init_asm_struct function. From the labels Init.
/// \param asm_struct The asm structure.
/// \return NULL.
/// \note Free the file lines as it is the fourth element to be allocated.
////////////////////////////////////////////////////////////////////////////////
void *e_init_init_labels(asm_t *asm_struct)
{
    free_array(asm_struct->file_lines);
    return e_init_file_lines(asm_struct);
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Exit the init_asm_programm function.
/// \param asm_struct The asm structure.
/// \return ERR_OUT (=84).
/// \note Free the asm structure as all the elements have been allocated.
////////////////////////////////////////////////////////////////////////////////
int e_init_asm_programm(asm_t *asm_struct)
{
    if (!asm_struct) return ERR_OUT;
    free_asm_struct(asm_struct);
    return ERR_OUT;
}
