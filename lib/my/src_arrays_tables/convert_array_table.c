/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** convert_array_table
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file convert_array_table.c
/// \brief Contains the convert_array_table function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int **convert_array_table(char **array, int *mall_vs);

////////////////////////////////////////////////////////////////////////////////
/// \brief Convert an array to a table.
/// \param array The array to convert to a table.
/// \param mall_vs The values to multiply the mallocs by. Use 'MALL_VS'
/// \return The new table with the array converted.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if the array is NULL.
////////////////////////////////////////////////////////////////////////////////
int **convert_array_table(char **array, int *mall_vs)
{
    int size = 0; int tab_l = 0; int **n_tab = NULL;
    if (!array) return NULL;
    tab_l = my_array_len(array);
    if (!(n_tab = malloc(sizeof(int *) * ((tab_l + 1) * mall_vs[0])))) {
        my_perror("malloc");
        return NULL;
    }
    for (int i = 0; i < tab_l; i++) {
        size = my_strlen(array[i]);
        if (!(n_tab[i] = malloc(sizeof(int) * ((size + 1) * mall_vs[1])))) {
            my_perror("malloc");
            freen_table(n_tab, i);
            return NULL;
        }
        for (int j = 0; j < size; j++) n_tab[i][j] = array[i][j];
        n_tab[i][size] = -1;
    }
    n_tab[tab_l] = NULL;
    return n_tab;
}
