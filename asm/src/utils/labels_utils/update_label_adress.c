/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** update_label_adress
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file update_label_adress.c
/// \brief Contains the function that updates the address of a label.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool update_label_address(asm_t *asm_struct, char *label_name);

////////////////////////////////////////////////////////////////////////////////
/// \brief Updates the address of a label based on the current index.
/// \param asm_struct The asm struct.
/// \param label_name The label to update.
/// \return true if the label was found and updated, false otherwise.
/// \note A label written at the first instruction will have an address of 0.
/// \note The address is the index of the following instruction in the binary
/// file.
////////////////////////////////////////////////////////////////////////////////
bool update_label_address(asm_t *asm_struct, char *label_name)
{
    labels_t **labels = NULL;
    if (!asm_struct || !label_name) return false;
    labels = asm_struct->labels;
    for (int i = 0; labels[i]; i++) {
        if (!my_strcmp(labels[i]->name, label_name)) continue;
        labels[i]->address = asm_struct->index - FULL_HEADER_SIZE;
        return true;
    }
    return false;
}
