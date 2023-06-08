/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** create_writable_file
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file create_writable_file.c
/// \brief Contains the create_writable_file function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int create_writable_file(char const *filepath);

////////////////////////////////////////////////////////////////////////////////
/// \brief Create a writable file.
/// \param filepath The path to the file.
/// \return The file descriptor of the created file.
/// \warning Returns -1 if an error occurs.
/// \note Returns -1 if the filepath is NULL or empty.
////////////////////////////////////////////////////////////////////////////////
int create_writable_file(char const *filepath)
{
    int fd = 0;
    if (!filepath) return -1;
    if (!*filepath) return -1;
    if ((fd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) {
        my_perror("open");
        return -1;
    }
    return fd;
}
