/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** display_file_content
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file display_file_content.c
/// \brief Contains the display_file_content function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

bool display_file_content(char const *filepath, int *mall_vs);

////////////////////////////////////////////////////////////////////////////////
/// \brief Display the content of a file.
/// \param filepath The path to the file.
/// \param mall_vs The values to multiply the mallocs by. Use 'MALL_VS'
/// \return true if the file content was displayed, false otherwise.
/// \warning Returns false if an error occurs.
/// \note Returns false if the filepath is NULL or empty. Or if the process
/// fails to get the file content.
////////////////////////////////////////////////////////////////////////////////
bool display_file_content(char const *filepath, int *mall_vs)
{
    char *file_content = NULL;
    if (!filepath) return false;
    if (!*filepath) return false;
    if (!(file_content = get_file_content(filepath, mall_vs))) return false;
    my_printf(file_content);
    my_free(file_content);
    return true;
}
