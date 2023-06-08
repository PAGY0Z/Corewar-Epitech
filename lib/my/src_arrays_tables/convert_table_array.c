/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** convert_table_array
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file convert_table_array.c
/// \brief Contains the convert_table_array function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

char **convert_table_array(int **table, int *mall_vs);

////////////////////////////////////////////////////////////////////////////////
/// \brief Convert a table to an array.
/// \param table The table to convert to an array.
/// \param mall_vs The values to multiply the mallocs by. Use 'MALL_VS'
/// \return The new array with the table converted.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if the table is NULL.
////////////////////////////////////////////////////////////////////////////////
char **convert_table_array(int **table, int *mall_vs)
{
    int size = 0; int arr_l = 0; char **n_arr = NULL;
    if (!table) return NULL;
    arr_l = my_table_len(table);
    if (!(n_arr = malloc(sizeof(char *) * ((arr_l + 1) * mall_vs[0])))) {
        my_perror("malloc");
        return NULL;
    }
    for (int i = 0; i < arr_l; i++) {
        size = my_intarray_len(table[i]);
        if (!(n_arr[i] = malloc(sizeof(char) * ((size + 1) * mall_vs[1])))) {
            my_perror("malloc");
            freen_array(n_arr, i);
            return NULL;
        }
        for (int j = 0; j < size; j++) n_arr[i][j] = table[i][j];
        n_arr[i][size] = '\0';
    }
    n_arr[arr_l] = NULL;
    return n_arr;
}
