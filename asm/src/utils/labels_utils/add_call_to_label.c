/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** add_call_to_label
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file add_call_to_label.c
/// \brief Contains the function related to adding a call to the labels.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool add_call_to_label(asm_t *asm_struct, char *label, call_t *call);

////////////////////////////////////////////////////////////////////////////////
/// \brief Add a call to a label.
/// \param asm_struct The asm struct.
/// \param label_name The label to add the call to.
/// \param call The call to add.
/// \return true if the call was added, false otherwise.
/// \warning Returns false if an error occurs.
/// \note Returns false if the label is not found.
/// \note Returns false if an error occurs while allocating memory.
/// \note Returns true if the call was added.
/// \note A call is composed of :
/// \note   - The position of the command that contains the call.
/// \note   - The position of the call. (The position at which we'll write)
/// \note   - The size of the call. (2 or 4)
////////////////////////////////////////////////////////////////////////////////
bool add_call_to_label(asm_t *asm_struct, char *label_name, call_t *call)
{
    labels_t **labels = asm_struct->labels; labels_t *lab = NULL;
    int nbcalls = 0;
    for (int i = 0; labels[i]; i++) {
        lab = labels[i];
        if (!my_strcmp(lab->name, label_name)) continue;
        nbcalls = lab->nbcalls;
        lab->callpos = realloc(lab->callpos, sizeof(int) * (nbcalls + 1));
        if (!lab->callpos) return false;
        lab->callsize = realloc(lab->callsize, sizeof(int) * (nbcalls + 1));
        if (!lab->callsize) return false;
        lab->cmdpos = realloc(lab->cmdpos, sizeof(int) * (nbcalls + 1));
        if (!lab->cmdpos) return false;
        lab->callpos[nbcalls] = call->callpos;
        lab->callsize[nbcalls] = call->size;
        lab->cmdpos[nbcalls] = call->cmdpos;
        lab->nbcalls++;
        return true;
    }
    return false;
}
