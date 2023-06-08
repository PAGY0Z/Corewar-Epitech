/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** freen_table
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file freen_table.c
/// \brief Contains the freen_table function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

void freen_table(int **table, int n);

////////////////////////////////////////////////////////////////////////////////
/// \brief Frees n elements of an table.
/// \param table The table to free.
/// \param n The number of elements to free.
/// \attention The table must be NULL terminated & memory allocated
/// \warning Returns if the table is NULL or n is negative.
////////////////////////////////////////////////////////////////////////////////
void freen_table(int **table, int n)
{
    if (!table || n < 0) return;
    n = MIN(n, my_table_len(table));
    for (int i = 0;  i < n; i++) my_free(table[i]);
    my_free(table);
}
