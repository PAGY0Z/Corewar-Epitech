/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** get_file_lines_getline
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file get_file_lines_getline.c
/// \brief Contains the get_file_lines_getline function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

char **get_file_lines_getline(char const *filepath, int *mall1, int *mall2);

////////////////////////////////////////////////////////////////////////////////
/// \brief Get the lines of a file using getline.
/// \param filepath The path of the file.
/// \param mall_vs1 The values to multiply the mallocs by. Use 'MALL_VS'
/// \param mall_vs2 The values to multiply the mallocs by. Use 'MALL_VS'
/// \return The lines of the file.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if the filepath is NULL or empty.
/// \note Returns NULL if the file could not be opened.
////////////////////////////////////////////////////////////////////////////////
char **get_file_lines_getline(char const *filepath, int *mall1, int *mall2)
{
    char *line = NULL; size_t len = 0; FILE *st = NULL;
    char **lines = NULL; char **save = NULL;
    if (!(st = get_file_stream(filepath))) return NULL;
    if (!(lines = my_arraydup(DEFAULT_ARRAY, mall1))) {
        my_close_stream(st);
        return NULL;
    }
    while (getline(&line, &len, st) != -1) {
        save = lines; line[my_strlen_sepa(line, "\n")] = '\0';
        if (!(lines = add_str_to_array(lines, line, mall2))) {
            my_close_stream(st);
            free_array(save);
            return NULL;
        }
        free_array(save);
    }
    my_close_stream(st); my_free(line);
    return lines;
}
