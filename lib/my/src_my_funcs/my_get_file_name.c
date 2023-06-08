/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_get_file_name
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_get_file_name.c
/// \brief Contains the my_get_file_name function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

char *my_get_file_name(char const *filepath, int *mall_vs, int mall_v1);

////////////////////////////////////////////////////////////////////////////////
/// \brief Get the file name from a file path.
/// \param filepath The file path.
/// \param mall_vs The values to multiply the mallocs by. Use 'MALL_VS'
/// \return The file name.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if the filepath is NULL or empty. Returns NULL if the
/// filepath ends with a '/'.
////////////////////////////////////////////////////////////////////////////////
char *my_get_file_name(char const *filepath, int *mall_vs, int mall_v1)
{
    char **file_path_array = NULL; char *result = NULL; int array_len = 0;
    if (!filepath) return NULL;
    if (!*filepath) return NULL;
    if (filepath[my_strlen(filepath) - 1] == '/') return NULL;
    if (!(file_path_array = my_str_to_word_array(filepath, "/", mall_vs)))
        return NULL;
    array_len = my_array_len(file_path_array);
    if (!(result = my_strdup(file_path_array[array_len - 1], mall_v1))) {
        free_array(file_path_array);
        return NULL;
    }
    free_array(file_path_array);
    return result;
}
