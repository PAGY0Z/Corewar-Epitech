/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_putstr_sepa
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_putstr_sepa.c
/// \brief Contains the my_putstr_sepa function.
/// \author PAGY0Z
/// \version 0.1
/// \date 2023-28-05
////////////////////////////////////////////////////////////////////////////////

int my_putstr_sepa(char const *str, char const *sepa, int fd);

////////////////////////////////////////////////////////////////////////////////
/// \brief Write a string to a separator to a file descriptor.
/// \param str The string to write.
/// \param sepa The separator to stop to.
/// \param fd The file descriptor to write to.
/// \return The number of characters written.
/// \warning Returns -1 if the write failed.
/// \note If the string or the separators are NULL or empty, my_putstr is
/// called instead.
////////////////////////////////////////////////////////////////////////////////
int my_putstr_sepa(char const *str, char const *sepa, int fd)
{
    int count = -1;
    if (!str || !sepa) return my_putstr(str, fd);
    if (!*str || !*sepa) return my_putstr(str, fd);
    if ((count = write(fd, str, my_strlen_sepa(str, sepa))) == -1) {
        my_perror("write");
        return count;
    }
    return count;
}
