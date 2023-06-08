/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** get_file_size_lseek
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file get_file_size_lseek.c
/// \brief Contains the get_file_size_lseek function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int get_file_size_lseek(char const *filepath);

////////////////////////////////////////////////////////////////////////////////
/// \brief Get the size of a file using lseek.
/// \param filepath The path of the file.
/// \return The size of the file.
/// \warning Returns -1 if an error occurs.
/// \note Returns -1 if the filepath is NULL or empty.
/// \note Returns -1 if the file could not be opened.
////////////////////////////////////////////////////////////////////////////////
int get_file_size_lseek(char const *filepath)
{
    int fd = 0; int size = 0;
    if (!filepath) return -1;
    if (!*filepath) return -1;
    if ((fd = open(filepath, O_RDONLY)) == -1) {
        my_perror("open");
        return -1;
    }
    size = lseek(fd, 0, SEEK_END);
    my_close_fd(fd);
    return size;
}
