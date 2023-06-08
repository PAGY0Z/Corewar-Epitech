/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** create_array
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file create_array.c
/// \brief Contains the create_array function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

char **create_array(int size_y, int size_x, int *mall_vs);

////////////////////////////////////////////////////////////////////////////////
/// \brief Create an array.
/// \param size_y The size of the array in the y axis.
/// \param size_x The size of the array in the x axis.
/// \param mall_vs The values to multiply the mallocs by. Use 'MALL_VS'
/// \return The created array.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if the size is < 0 on the x or y axis.
////////////////////////////////////////////////////////////////////////////////
char **create_array(int size_y, int size_x, int *mall_vs)
{
    char **array = NULL;
    if (size_y < 0 || size_x < 0) return NULL;
    if (!(array = malloc(sizeof(char *) * ((size_y + 1) * mall_vs[0])))) {
        my_perror("malloc");
        return NULL;
    }
    for (int y = 0; y < size_y; y++) {
        if (!(array[y] = malloc(sizeof(char) * ((size_x + 1) * mall_vs[1])))) {
            my_perror("malloc");
            freen_array(array, y);
            return NULL;
        }
        for (int x = 0; x < size_x; x++) array[y][x] = ' ';
        array[y][size_x] = '\0';
    }
    array[size_y] = NULL;
    return array;
}
