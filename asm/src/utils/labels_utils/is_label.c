/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** is_label
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file is_label.c
/// \brief Contains the function that tells if a string is a label.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool is_label(char const *str);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if a string is a label.
/// \param str The string to check.
/// \return true if the string is a label, false otherwise.
/// \warning Returns false if an error occurs.
/// \note Returns false if the string is NULL or len < 2.
/// \note Returns false if the last char of the string is not LABEL_CHAR.
/// \note Returns false if the string contains an invalid char.
////////////////////////////////////////////////////////////////////////////////
bool is_label(char const *str)
{
    int len = 0;
    if (!str) return false;
    if (!*str) return false;
    if ((len = my_strlen(str)) < 2) return false;
    if (str[len - 1] != LABEL_CHAR) return false;
    for (int i = 0; i < len - 1; i++)
        if (!IS_LABEL_VALID_CHAR(str[i])) return false;
    return true;
}
