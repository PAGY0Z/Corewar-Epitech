/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** free_table
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file free_table.c
/// \brief Contains the free_table function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

void free_table(int **table);

////////////////////////////////////////////////////////////////////////////////
/// \brief Frees an table.
/// \param table The table to free.
/// \attention The table must be NULL terminated & memory allocated
/// \warning Returns if the table is NULL.
////////////////////////////////////////////////////////////////////////////////
void free_table(int **table)
{
    if (!table) return;
    for (int i = 0; table[i]; i++) my_free(table[i]);
    my_free(table);
}
