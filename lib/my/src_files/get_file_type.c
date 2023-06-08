/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** get_file_type
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file get_file_type.c
/// \brief Contains the get_file_type function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int get_file_type(char const *filepath);

////////////////////////////////////////////////////////////////////////////////
/// \brief Gets the type of a file.
/// \param filepath The path to the file.
/// \return The type of the file.
/// \attention Returns -1 if an error occurs.
/// \note Returns -1 if the filepath is NULL or empty. Or if the process
/// fails to get the file type.
////////////////////////////////////////////////////////////////////////////////
int get_file_type(char const *filepath)
{
    struct stat file_stat;
    if (!filepath) return -1;
    if (!*filepath) return -1;
    if (stat(filepath, &file_stat) == -1) {
        my_perror("stat");
        return -1;
    }
    return file_stat.st_mode;
}
