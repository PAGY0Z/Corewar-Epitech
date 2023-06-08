/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_tabledup
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_tabledup.c
/// \brief Contains the my_tabledup function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int **my_tabledup(int **table, int *mall_vs);

////////////////////////////////////////////////////////////////////////////////
/// \brief Duplicates a table.
/// \param table The table to duplicate.
/// \param mall_vs The values to multiply the mallocs by. USE 'MALL_VS'
/// \return The duplicated table.
/// \attention Returns NULL if an error occurs.
/// \note Returns NULL if the table is NULL.
////////////////////////////////////////////////////////////////////////////////
int **my_tabledup(int **table, int *mall_vs)
{
    int size = 0; int **new_table = NULL;
    if (!table) return NULL;
    size = my_table_len(table);
    if (!(new_table = malloc(sizeof(int *) * ((size + 1) * mall_vs[0])))) {
        my_perror("malloc");
        return NULL;
    }
    for (int i = 0; table[i]; i++)
        if (!(new_table[i] = my_intarraydup(table[i], mall_vs[1]))) {
            my_perror("malloc");
            freen_table(new_table, i);
            return NULL;
        }
    new_table[size] = NULL;
    return new_table;
}
