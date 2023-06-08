/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** get_header
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file get_header.c
/// \brief Contains the get_header function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-23-05
////////////////////////////////////////////////////////////////////////////////

bool get_header(header_t *header, char const *filepath);

////////////////////////////////////////////////////////////////////////////////
/// \brief Get the header of a file.
/// \param header The header structure.
/// \param filepath The filepath of the file.
/// \return true if the header is valid, false otherwise.
////////////////////////////////////////////////////////////////////////////////
bool get_header(header_t *header, char const *filepath)
{
    FILE *stream = NULL;
    if (!header || !filepath) return false;
    if (!*filepath) return false;
    if (!(stream = fopen(filepath, "r"))) return false;
    if (fread(header, sizeof(header_t), 1, stream) != 1) {
        fclose(stream);
        return false;
    }
    fclose(stream);
    return true;
}
