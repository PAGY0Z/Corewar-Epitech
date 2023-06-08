/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** is_registered_label2
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file is_registered_label2.c
/// \brief Contains the function that checks if a label is registered.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool is_registered_label2(asm_t *asm_struct, char *label_name);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if the label is registered.
/// \param asm_struct The asm struct.
/// \param label_name The label to check.
/// \return true if the label is registered, false otherwise.
/// \note Returns false if the label is NULL or empty.
/// \note Returns false if the label is not registered.
/// \note Returns true if the label is registered.
////////////////////////////////////////////////////////////////////////////////
bool is_registered_label2(asm_t *asm_struct, char *label_name)
{
    if (!asm_struct || !label_name) return false;
    if (label_name[0] != ':') return false;
    for (int i = 0; asm_struct->labels[i]; i++)
        if (my_strcmp(asm_struct->labels[i]->name, label_name + 1)) return true;
    return false;
}
