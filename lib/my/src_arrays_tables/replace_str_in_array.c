/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** replace_str_in_array
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file replace_str_in_array.c
/// \brief Contains the replace_str_in_array function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

void replace_str_in_array(char **array, char *str, int index, int *mall_vs);

////////////////////////////////////////////////////////////////////////////////
/// \brief Replace an str in a array given the index.
/// \param array The array to add in which the str will be replaced.
/// \param str The str to replace.
/// \param index The index of the str to replace.
/// \param mall_vs The values to multiply the mallocs by. Use 'MALL_VS'
/// \return Returns true if the str was replaced.
/// \warning Returns false if an error occurs.
/// \note Returns false if the index is < 0 or >= the array length.
////////////////////////////////////////////////////////////////////////////////
void replace_str_in_array(char **array, char *str, int index, int *mall_vs)
{
    int arr_l = 0; char *save = NULL;
    if (!array || !str || index < 0) return;
    if (index >= (arr_l = my_array_len(array))) return;
    if (!(save = my_strdup(array[index], mall_vs[0]))) return;
    my_free(array[index]);
    if (!(array[index] = my_strdup(str, mall_vs[1]))) {
        array[index] = save;
        return;
    }
    my_free(save);
}
