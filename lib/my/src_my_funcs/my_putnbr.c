/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_putnbr
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_putnbr.c
/// \brief Contains the my_putnbr function.
/// \author PAGY0Z
/// \version 0.1
/// \date 2023-28-05
////////////////////////////////////////////////////////////////////////////////

int my_putnbr(unsigned int nb, char const *base, int fd);

////////////////////////////////////////////////////////////////////////////////
/// \brief Write a number in a given base to a file descriptor.
/// \param nb The number to write.
/// \param base The base to write the number in.
/// \param fd The file descriptor to write to.
/// \return The number of characters written.
/// \warning Returns -1 if the write failed.
/// \note If the base is NULL or less than 2 in lenght, -1 is returned.
////////////////////////////////////////////////////////////////////////////////
int my_putnbr(unsigned int nb, char const *base, int fd)
{
    int count = 0;
    if (!base) return -1;
    if (my_strlen(base) < 2) return -1;
    if (nb < (unsigned int)my_strlen(base)) {
        my_putchar(base[nb], fd);
        count++;
    } else {
        my_putnbr(nb / (unsigned int)my_strlen(base), base, fd);
        my_putchar(base[nb % (unsigned int)my_strlen(base)], fd);
        count++;
    }
    return count;
}
