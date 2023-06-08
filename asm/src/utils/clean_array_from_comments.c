/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** clean_array_from_comments
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file clean_array_from_comments.c
/// \brief Contains the function that removes the comments from an array.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool clean_array_from_comments(char **array);

////////////////////////////////////////////////////////////////////////////
/// \brief Remove the comments from an array.
/// \param array The array to clean from comments.
/// \return true if success, false otherwise.
/// \note Return false if array is NULL.
/// \note The comments are removed by replacing the '#' char by '\0'.
////////////////////////////////////////////////////////////////////////////
bool clean_array_from_comments(char **array)
{
    if (!array) return false;
    for (int i = 0; array[i]; i++)
        for (int j = 0; array[i][j]; j++)
            array[i][j] = (array[i][j] == '#') ? '\0' : array[i][j];
    return true;
}
