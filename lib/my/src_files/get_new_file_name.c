/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** get_new_file_name
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file get_new_file_name.c
/// \brief Contains the get_new_file_name function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

char *get_new_file_name(char const *filepah, char *o_ext, char *n_ext, int ma1);

////////////////////////////////////////////////////////////////////////////////
/// \brief Get the new file name from a file path.
/// \param filepath The file path.
/// \param old_extension The old extension.
/// \param new_extension The new extension.
/// \param mall_v1 The values to multiply the mallocs by. Use '1'
/// \return The new file name.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if the filepath is NULL or empty.
/// \note Returns NULL if the filepath ends with a '/'.
////////////////////////////////////////////////////////////////////////////////
char *get_new_file_name(char const *filepath, char *o_ext, char *n_ext, int ma1)
{
    char *filename = NULL; char *exfilename = NULL; char *new_filename = NULL;
    if (!filepath) return NULL;
    if (!*filepath) return NULL;
    if (!(filename = my_get_file_name(filepath, MALL_VS, 1))) return NULL;
    if (!(exfilename = my_remove_file_extension(filename, o_ext, 1))) {
        my_free(filename);
        return NULL;
    }
    if (!(new_filename = my_strcat(exfilename, n_ext, ma1))) {
        my_free(filename);
        my_free(exfilename);
        return NULL;
    }
    my_free(filename);
    my_free(exfilename);
    return new_filename;
}
