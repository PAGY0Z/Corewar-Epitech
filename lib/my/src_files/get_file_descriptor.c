/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** get_file_descriptor
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file get_file_descriptor.c
/// \brief Contains the get_file_descriptor function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int get_file_descriptor(char const *filepath);

////////////////////////////////////////////////////////////////////////////////
/// \brief Gets the file descriptor of a file.
/// \param filepath The path to the file.
/// \return The file descriptor of the file.
/// \attention Returns -1 if an error occurs.
/// \note Returns -1 if the filepath is NULL or empty. Or if the process
/// fails to open the file.
////////////////////////////////////////////////////////////////////////////////
int get_file_descriptor(char const *filepath)
{
    int fd = 0;
    if (!filepath) return -1;
    if (!*filepath) return -1;
    if ((fd = open(filepath, O_RDONLY)) == -1) {
        my_perror("open");
        return -1;
    }
    return fd;
}
