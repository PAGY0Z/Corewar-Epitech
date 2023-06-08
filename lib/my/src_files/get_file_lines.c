/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** get_file_lines
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file get_file_lines.c
/// \brief Contains the get_file_lines function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

char **get_file_lines(char const *filepath, int *mall_vs1, int *mall_vs2);

////////////////////////////////////////////////////////////////////////////////
/// \brief Get the lines of a file.
/// \param filepath The path of the file.
/// \param mall_vs1 The values to multiply the mallocs by. Use 'MALL_VS'
/// \param mall_vs2 The values to multiply the mallocs by. Use 'MALL_VS'
/// \return The lines of the file.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if the filepath is NULL or empty.
/// \note Returns NULL if the file content is NULL.
/// \note Returns NULL if the file lines are NULL.
////////////////////////////////////////////////////////////////////////////////
char **get_file_lines(char const *filepath, int *mall_vs1, int *mall_vs2)
{
    char *file_content = NULL; char **file_lines = NULL;
    if (!filepath) return NULL;
    if (!*filepath) return NULL;
    if (!(file_content = get_file_content(filepath, mall_vs1))) return NULL;
    if (!(file_lines = my_str_to_word_array(file_content, "\n", mall_vs2))) {
        my_free(file_content);
        return NULL;
    }
    my_free(file_content);
    return file_lines;
}
