/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_remove_file_extension
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_remove_file_extension.c
/// \brief Contains the my_remove_file_extension function.
/// \author PAGY0Z
/// \version 0.1
/// \date 2023-28-05
////////////////////////////////////////////////////////////////////////////////

char *my_remove_file_extension(char const *f_path, char const *ext, int mallv1);

////////////////////////////////////////////////////////////////////////////////
/// \brief Remove the file extension from a file name.
/// \param filepath The file name.
/// \param extension The extension to remove.
/// \param mall_v1 The value to multiply the malloc by. Use '1'
/// \return The file name without the extension.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if the f_path is NULL or empty. Returns NULL if the
/// f_path doesn't have the extension.
////////////////////////////////////////////////////////////////////////////////
char *my_remove_file_extension(char const *f_path, char const *ext, int mall_v1)
{
    int f_len = 0; int e_len = 0;
    if (!f_path || !ext) return NULL;
    if (!*f_path || !*ext) return NULL;
    if (!my_check_file_extension(f_path, ext)) return NULL;
    f_len = my_strlen(f_path); e_len = my_strlen(ext);
    return my_strndup(f_path, f_len - e_len, mall_v1);
}
