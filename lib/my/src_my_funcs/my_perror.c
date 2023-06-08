/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_perror
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_perror.c
/// \brief Contains the my_perror function.
/// \author PAGY0Z
/// \version 0.1
/// \date 2023-28-05
////////////////////////////////////////////////////////////////////////////////

void my_perror(char const *str);

////////////////////////////////////////////////////////////////////////////////
/// \brief Displays on the STDERR the errno error message.
/// \param str The string to display before the error message.
/// \warning MUST BE USED AFTER A FUNCTION THAT SETS THE ERRNO VARIABLE.
/// \note If str is NULL, nothing will be displayed before the error message.
////////////////////////////////////////////////////////////////////////////////
void my_perror(char const *str)
{
    int errnum = errno;
    if (errnum <= 0) return;
    if (str) {
        if (my_strlen(str)) {
            write(2, str, my_strlen(str));
            write(2, ": ", 2);
        }
    }
    if (errnum >= 134) {
        write(2, "Unknown error ", 14);
        my_putnbr(errnum, "0123456789", 2);
        return;
    }
    for (int i = 1; i < 134; i++)
        if (i == errnum) write(2, err[i].strerr, my_strlen(err[i].strerr));
}
