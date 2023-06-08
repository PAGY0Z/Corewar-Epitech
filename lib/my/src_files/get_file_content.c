/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** get_file_content
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file get_file_content.c
/// \brief Contains the get_file_content function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

char *get_file_content(char const *filepath, int *mall_vs);

////////////////////////////////////////////////////////////////////////////////
/// \brief Gets the content of a file and returns it as a string.
/// \param filepath The path to the file.
/// \param mall_vs The values to multiply the mallocs & read by. Use 'MALL_VS'
/// \return The content of the file as a string. (malloc'd.)
/// \attention Returns NULL if an error occurs.
/// \note Returns NULL if the filepath is NULL or empty. Or if the process
/// fails to get the file content.
////////////////////////////////////////////////////////////////////////////////
char *get_file_content(char const *filepath, int *mall_vs)
{
    int fd = 0; long long size = 0; char *buffer = NULL;
    if (!filepath) return NULL;
    if (!*filepath) return NULL;
    size = get_file_size(filepath);
    fd = get_file_descriptor(filepath);
    if (MIN(size, fd) < 0) return NULL;
    if (!(buffer = malloc(sizeof(char) * ((size + 1) * mall_vs[0])))) {
        my_perror("malloc");
        my_close_fd(fd);
        return NULL;
    }
    if (!my_read_fd(fd * mall_vs[1], buffer, size)) {
        free(buffer);
        my_close_fd(fd);
        return NULL;
    }
    my_close_fd(fd);
    buffer[size] = '\0';
    return buffer;
}
