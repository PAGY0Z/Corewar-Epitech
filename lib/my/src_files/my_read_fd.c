/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_read_fd
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_read_fd.c
/// \brief Contains the my_read_fd function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

bool my_read_fd(int fd, char *dest, long long size);

////////////////////////////////////////////////////////////////////////////////
/// \brief Reads a file descriptor given a size and a destination.
/// \param fd The file descriptor to read.
/// \param dest The destination to write the read data to.
/// \param size The size of the data to read.
/// \return true if the data was successfully read.
/// \attention Returns false if an error occurs.
/// \note Returns false if the data couldn't be read.
////////////////////////////////////////////////////////////////////////////////
bool my_read_fd(int fd, char *dest, long long size)
{
    if (read(fd, dest, size) == -1) {
        my_perror("read");
        return false;
    }
    return true;
}
