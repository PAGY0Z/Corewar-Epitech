/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_putstr
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_putstr.c
/// \brief Contains the my_putstr function.
/// \author PAGY0Z
/// \version 0.1
/// \date 2023-28-05
////////////////////////////////////////////////////////////////////////////////

int my_putstr(char const *str, int fd);

////////////////////////////////////////////////////////////////////////////////
/// \brief Write a string to a file descriptor.
/// \param str The string to write.
/// \param fd The file descriptor to write to.
/// \return The number of characters written.
/// \warning Returns -1 if the write failed.
/// \note If the string is NULL, "(null)" is written instead.
////////////////////////////////////////////////////////////////////////////////
int my_putstr(char const *str, int fd)
{
    int count = -1;
    if (str) {
        if ((count = write(fd, str, my_strlen(str))) == -1) {
            my_perror("write");
            return count;
        }
    } else {
        if ((count = write(fd, "(null)", 6)) == -1) {
            my_perror("write");
            return count;
        }
    }
    return count;
}
