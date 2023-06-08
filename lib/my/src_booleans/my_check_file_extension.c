/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_check_file_extension
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_check_file_extension.c
/// \brief Contains the my_check_file_extension function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

bool my_check_file_extension(char const *filepath, char const *extension);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if a file has a certain extension.
/// \param filepath The path to the file.
/// \param extension The extension to check for.
/// \return True if the file has the extension, false otherwise.
/// \note Returns false if the filepath or the extension are NULL.
/// \note Returns false if the filepath or the extension are empty.
/// \note Returns false if the filepath is shorter than the extension.
/// \note Returns false if the filepath doesn't end with the extension.
////////////////////////////////////////////////////////////////////////////////
bool my_check_file_extension(char const *filepath, char const *extension)
{
    int f_len = 0; int e_len = 0;
    if (!filepath || !extension) return false;
    if (!*filepath || !*extension) return false;
    if ((f_len = my_strlen(filepath)) <= (e_len = my_strlen(extension)))
        return false;
    for (int i = 0; i < e_len; i++)
        if (filepath[f_len - e_len + i] != extension[i]) return false;
    return true;
}
