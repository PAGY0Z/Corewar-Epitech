/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_close_stream
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_close_stream.c
/// \brief Contains the my_close_stream function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

bool my_close_stream(FILE *stream);

////////////////////////////////////////////////////////////////////////////////
/// \brief Closes a file descriptor.
/// \param fd The file descriptor to close.
/// \return true if the file descriptor was successfully closed.
/// \attention Returns false if an error occurs.
/// \note Returns false if the file descriptor couldn't be closed.
////////////////////////////////////////////////////////////////////////////////
bool my_close_stream(FILE *stream)
{
    if (!stream) return false;
    fclose(stream);
    return true;
}
