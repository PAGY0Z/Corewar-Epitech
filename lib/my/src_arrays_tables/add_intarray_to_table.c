/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** add_intarray_to_table
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file add_intarray_to_table.c
/// \brief Contains the add_intarray_to_table function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int **add_intarray_to_table(int **table, int *int_array, int *mall_vs);

////////////////////////////////////////////////////////////////////////////////
/// \brief Add an int array to a table.
/// \param table The table to add the int array to.
/// \param int_array The int array to add to the table.
/// \param mall_vs The values to multiply the mallocs by. Use 'MALL_VS'
/// \return The new table with the int array added.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if the table or the int array are NULL.
////////////////////////////////////////////////////////////////////////////////
int **add_intarray_to_table(int **table, int *int_array, int *mall_vs)
{
    int tab_l = 0; int **n_tab = NULL;
    if (!table || !int_array) return NULL;
    tab_l = my_table_len(table);
    if (!(n_tab = malloc(sizeof(int *) * ((tab_l + 2) * mall_vs[0])))) {
        my_perror("malloc");
        return NULL;
    }
    for (int i = 0; i < tab_l; i++)
        if (!(n_tab[i] = my_intarraydup(table[i], mall_vs[1]))) {
            freen_table(n_tab, i);
            return NULL;
        }
    if (!(n_tab[tab_l] = my_intarraydup(int_array, mall_vs[2]))) {
        freen_table(n_tab, tab_l);
        return NULL;
    }
    n_tab[tab_l + 1] = NULL;
    return n_tab;
}
