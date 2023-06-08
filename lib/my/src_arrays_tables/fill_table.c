/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** fill_table
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file fill_table.c
/// \brief Contains the fill_table function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

bool fill_table(int **table, int value);

////////////////////////////////////////////////////////////////////////////////
/// \brief Fill an table with a value.
/// \param table The table to fill.
/// \param value The value to fill the table with.
/// \return true if the table was filled, false otherwise.
/// \warning The table & each sub-table must be NULL or -1 terminated.
/// \note Returns false if the table is NULL.
////////////////////////////////////////////////////////////////////////////////
bool fill_table(int **table, int value)
{
    if (!table) return false;
    for (int y = 0; table[y]; y++)
        for (int x = 0; table[y][x] != -1; x++)
            table[y][x] = value;
    return true;
}
