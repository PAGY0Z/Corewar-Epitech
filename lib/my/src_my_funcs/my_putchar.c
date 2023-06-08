/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_putchar
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_putchar.c
/// \brief Contains the my_putchar function.
/// \author PAGY0Z
/// \version 0.1
/// \date 2023-28-05
////////////////////////////////////////////////////////////////////////////////

int my_putchar(char c, int fd);

////////////////////////////////////////////////////////////////////////////////
/// \brief Prints a character to the given file descriptor.
/// \param c The character to print.
/// \param fd The file descriptor to print to.
/// \return 1 if the character was printed.
/// \warning Returns -1 if the write failed.
////////////////////////////////////////////////////////////////////////////////
int my_putchar(char c, int fd)
{
    if (write(fd, &c, 1) == -1) {
        my_perror("write");
        return -1;
    }
    return 1;
}
