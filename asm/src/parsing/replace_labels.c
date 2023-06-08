/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** replace_labels
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file replace_labels.c
/// \brief Contains the functions that replaces the labels by their relative
/// address.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

void replace_values_in_buffer(asm_t *asm_struct, int rpos, int pos, int size);
void replace_labels(asm_t *asm_struct);

////////////////////////////////////////////////////////////////////////////////
/// \brief Replace the values in the buffer by their address. Depending on the
/// size of the value.
/// \param asm_struct The asm struct.
/// \param value The value to replace.
/// \param pos The position of the value in the buffer.
/// \param size The size of the value.
/// \note The buffer bytes are replaced by the value bytes.
/// \note The value is the relative address.
/// \note The size is the size of the value.
/// \note The position is the position of the value in the buffer.
////////////////////////////////////////////////////////////////////////////////
void replace_values_in_buffer(asm_t *asm_struct, int value, int pos, int size)
{
    if (size == 4) {
        asm_struct->buffer[pos] = GET_BIGGEST_BYTE(value);
        asm_struct->buffer[pos + 1] = GET_BIG_BYTE(value);
        asm_struct->buffer[pos + 2] = GET_SMALL_BYTE(value);
        asm_struct->buffer[pos + 3] = GET_SMALLEST_BYTE(value);
        return;
    }
    if (size == 2) {
        asm_struct->buffer[pos] = GET_SMALL_BYTE(value);
        asm_struct->buffer[pos + 1] = GET_SMALLEST_BYTE(value);
        return;
    }
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Replace the labels by their relative address.
/// \param asm_struct The asm struct.
/// \warning The labels must be NULL terminated.
/// \note The labels called are replaced by their relative address.
/// \note The relative address is the difference between the label address and
/// the call address.
/// \note The call address is the address of the instruction that calls the
/// label.
////////////////////////////////////////////////////////////////////////////////
void replace_labels(asm_t *asm_struct)
{
    int rpos = 0; int label_pos = 0; int size = 0;
    labels_t **labels = asm_struct->labels; labels_t *lab = NULL;
    for (int i = 0; labels[i]; i++) {
        lab = labels[i];
        for (int j = 0; j < lab->nbcalls; j++) {
            rpos = lab->address - lab->cmdpos[j];
            label_pos = lab->callpos[j];
            size = lab->callsize[j];
            replace_values_in_buffer(asm_struct, rpos, label_pos, size);
        }
    }
}
