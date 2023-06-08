/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** write_file
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file write_file.c
/// \brief Contains the function that writes the buffer into the file
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool write_file(int fd, asm_t *asm_struct);

////////////////////////////////////////////////////////////////////////////////
/// \brief Write the buffer into the file.
/// \param fd The file descriptor of the file.
/// \param asm_struct The asm struct.
/// \return true if the write was successful, false otherwise.
////////////////////////////////////////////////////////////////////////////////
bool write_file(int fd, asm_t *asm_struct)
{
    if (write(fd, asm_struct->buffer, asm_struct->index) == -1)
        return false;
    return true;
}
