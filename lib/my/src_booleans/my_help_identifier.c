/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_help_identifier
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_help_identifier.c
/// \brief Contains the my_help_identifier function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

bool my_help_identifier(char **array);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if one of the array's string is HELP_FLAG0 or HELP_FLAG1.
/// \param array The array to check in.
/// \return true if one of the array's string is HELP_FLAG0 or HELP_FLAG1.
/// \warning Returns false if the array is NULL or empty.
/// \note HELP_FLAG0 and HELP_FLAG1 are defined in types_header.h.
////////////////////////////////////////////////////////////////////////////////
bool my_help_identifier(char **array)
{
    if (!array) return false;
    for (int i = 0; array[i]; i++)
        if (my_strcmp(array[i], HELP_FLAG0) || my_strcmp(array[i], HELP_FLAG1))
            return true;
    return false;
}
