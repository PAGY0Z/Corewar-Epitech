/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** get_file_stream
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file get_file_stream.c
/// \brief Contains the get_file_stream function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

FILE *get_file_stream(char const *filepath);

////////////////////////////////////////////////////////////////////////////////
/// \brief Gets the file stream of a file.
/// \param filepath The path to the file.
/// \return The file stream of the file.
/// \attention Returns NULL if an error occurs.
/// \note Returns NULL if the filepath is NULL or empty. Or if the process
/// fails to fopen the file.
////////////////////////////////////////////////////////////////////////////////
FILE *get_file_stream(char const *filepath)
{
    FILE *stream = NULL;
    if (!filepath) return NULL;
    if (!*filepath) return NULL;
    if (!(stream = fopen(filepath, "r"))) {
        my_perror("fopen");
        return NULL;
    }
    return stream;
}
