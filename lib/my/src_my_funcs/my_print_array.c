/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_print_array
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_print_array.c
/// \brief Contains the my_print_array function.
/// \author PAGY0Z
/// \version 0.1
/// \date 2023-28-05
////////////////////////////////////////////////////////////////////////////////

bool my_print_array(char **array, char sepa);

////////////////////////////////////////////////////////////////////////////////
/// \brief Dispays on the STDOUT an with a separator between each element.
/// \param array The array to display.
/// \param sepa The separator to use between each element.
/// \return true if the array was displayed.
/// \note Returns false if the array is NULL.
////////////////////////////////////////////////////////////////////////////////
bool my_print_array(char **array, char sepa)
{
    if (!array) return false;
    if (!sepa) {
        for (int i = 0; array[i]; i++)
            my_printf("%s", array[i]);
    } else {
        for (int i = 0; array[i]; i++)
            my_printf("%s%c", array[i], sepa);
    }
    return true;
}
