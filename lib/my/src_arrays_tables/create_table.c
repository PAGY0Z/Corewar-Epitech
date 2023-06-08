/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** create_table
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file create_table.c
/// \brief Contains the create_table function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int **create_table(int size_y, int size_x, int *mall_vs);

////////////////////////////////////////////////////////////////////////////////
/// \brief Create an table.
/// \param size_y The size of the table in the y axis.
/// \param size_x The size of the table in the x axis.
/// \param mall_vs The values to multiply the mallocs by. Use 'MALL_VS'
/// \return The created table.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if the size is < 0 on the x or y axis.
////////////////////////////////////////////////////////////////////////////////
int **create_table(int size_y, int size_x, int *mall_vs)
{
    int **table = NULL;
    if (size_y < 0 || size_x < 0) return NULL;
    if (!(table = malloc(sizeof(int *) * ((size_y + 1) * mall_vs[0])))) {
        my_perror("malloc");
        return NULL;
    }
    for (int y = 0; y < size_y; y++) {
        if (!(table[y] = malloc(sizeof(int) * ((size_x + 1) * mall_vs[1])))) {
            my_perror("malloc");
            freen_table(table, y);
            return NULL;
        }
        for (int x = 0; x < size_x; x++) table[y][x] = 0;
        table[y][size_x] = -1;
    }
    table[size_y] = NULL;
    return table;
}
