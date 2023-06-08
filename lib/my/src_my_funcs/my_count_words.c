/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_count_words
*/

#include "my.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_count_words.c
/// \brief Contains the my_count_words function.
/// \author PAGY0Z
/// \version 1.0
/// \date 2023-27-05
////////////////////////////////////////////////////////////////////////////////

int my_count_words(char const *str, char const *sepa);

////////////////////////////////////////////////////////////////////////////////
/// \brief Counts the number of words in a string separated by separators.
/// \param str The string to count the words in.
/// \param sepa The separators to count the words with.
/// \return The number of words in the string.
/// \warning Returns -1 if is str or sepa is NULL.
/// \note Returns 0 if the string is empty or only contains separators.
////////////////////////////////////////////////////////////////////////////////
int my_count_words(char const *str, char const *sepa)
{
    int i = 0; int word_count = 0;
    if (!str || !sepa) return -1;
    if (str_is_token(str, sepa)) return 0;
    for (;str[i];) {
        for (; str[i] && is_token(str[i], sepa); i++);
        word_count = (str[i]) ? word_count + 1 : word_count;
        for (; str[i] && !is_token(str[i], sepa); i++);
    }
    return word_count;
}
