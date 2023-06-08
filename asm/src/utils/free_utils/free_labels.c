/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** free_labels
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file free_labels.c
/// \brief Contains the function that frees the labels.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

void free_labels(labels_t **labels);

////////////////////////////////////////////////////////////////////////////////
/// \brief Free the labels and their content.
/// \param labels The labels to free.
/// \warning The labels must be NULL terminated.
/// \note Frees the labels in the following order:
/// \note   - The label name.
/// \note   - The command positions.
/// \note   - The call sizes.
/// \note   - The call positions.
/// \note   - The label itself.
/// \note   - The labels array.
////////////////////////////////////////////////////////////////////////////////
void free_labels(labels_t **labels)
{
    for (int i = 0; labels[i]; i++) {
        my_free(labels[i]->name);
        if (labels[i]->nbcalls) {
            my_free(labels[i]->cmdpos);
            my_free(labels[i]->callsize);
            my_free(labels[i]->callpos);
        }
        my_free(labels[i]);
        labels[i] = NULL;
    }
    my_free(labels);
}
