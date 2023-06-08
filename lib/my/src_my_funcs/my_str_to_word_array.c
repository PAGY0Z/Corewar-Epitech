/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_str_to_word_array
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_str_to_word_array.c
/// \brief Contains the my_str_to_word_array function.
/// \author PAGY0Z
/// \version 0.1
/// \date 2023-28-05
////////////////////////////////////////////////////////////////////////////////

char **my_str_to_word_array(char const *str, char *sepa, int *mall_vs);

////////////////////////////////////////////////////////////////////////////////
/// \brief Convert a string to a word array.
/// \param str The string to convert.
/// \param sepa The separators to use.
/// \param mall_vs The values to multiply the mallocs by. Use 'MALL_VS'
/// \return The word array divided by the separators.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if the string or separators are NULL.
////////////////////////////////////////////////////////////////////////////////
char **my_str_to_word_array(char const *str, char *sepa, int *mall_vs)
{
    int cwrd = 0; int y = 0; char **array = NULL; int strlen_sepa = 0;
    if (!str || !sepa) return NULL;
    cwrd = my_count_words(str, sepa);
    if (!(array = malloc(sizeof(char *) * ((cwrd + 1) * mall_vs[0]))))
        return NULL;
    for (int i = 0; i < cwrd; i++) {
        for (y = 0; is_token(str[y], sepa); y++);
        str = str + y;
        strlen_sepa = my_strlen_sepa(str, sepa);
        if (!(array[i] = my_strndup(str, strlen_sepa, mall_vs[1]))) {
            freen_array(array, i);
            return NULL;
        }
        str = str + strlen_sepa + 1;
    }
    array[cwrd] = NULL;
    return array;
}
