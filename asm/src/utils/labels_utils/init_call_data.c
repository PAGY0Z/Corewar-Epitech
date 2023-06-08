/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** init_call_data
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file init_call_data.c
/// \brief Contains the function that initializes the call data structure.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

call_t *init_call_data(int cmdpos, int callpos, int size);

////////////////////////////////////////////////////////////////////////////////
/// \brief Initializes the call data structure.
/// \param cmdpos The position of the command.
/// \param callpos The position of the call.
/// \param size The size of the call.
/// \return The call data structure.
/// \note Returns NULL if an error occurs.
/// \note Returns NULL if an error occurs while allocating memory.
/// \note The label position is the position at which the label will be written.
/// \note The cmd position is the position at which the call is written.
/// \note The size is the size of the call. (2 or 4)
////////////////////////////////////////////////////////////////////////////////
call_t *init_call_data(int cmdpos, int callpos, int size)
{
    call_t *call_data = malloc(sizeof(call_t));
    if (!call_data) return NULL;
    call_data->cmdpos = cmdpos;
    call_data->callpos = callpos;
    call_data->size = size;
    return call_data;
}
