/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_table_len
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_table_len.c
/// \brief Contains the my_table_len function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int my_table_len(int **table);

////////////////////////////////////////////////////////////////////////////////
/// \brief Measures the length of a table.
/// \param table The table to measure the length of.
/// \return The length of the table.
/// \warning Returns -1 if the table is NULL.
////////////////////////////////////////////////////////////////////////////////
int my_table_len(int **table)
{
    int i = 0;
    if (!table) return -1;
    for (; table[i]; i++);
    return i;
}
