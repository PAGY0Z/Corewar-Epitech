/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** init_labels
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file init_labels.c
/// \brief Contains all the functions related to the labels initialization.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

char **check_add_label(char **array, char *line);
char **get_labels_names(char **file_lines);
labels_t **convert_labels(char **labels_name);
labels_t **init_labels(char **file_lines);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check if the line contains a label and add it to the array.
/// \param array The array to add the label to.
/// \param line The line to check.
/// \return The array with/out the label added.
/// \warning Returns NULL if an error occurs.
/// \note Returns the same array if the line does not contain a label.
/// \note Returns NULL if an error occurs while allocating memory.
/// \note Returns NULL if the label is already in the array.
////////////////////////////////////////////////////////////////////////////////
char **check_add_label(char **array, char *line)
{
    char *label = NULL; char **l_array = NULL;
    if (!(l_array = my_str_to_word_array(line, " \t", MALL_VS))) return NULL;
    if (!is_label(l_array[0])) {
        free_array(l_array);
        return array;
    }
    if (!(label = my_strndup(l_array[0], my_strlen_sepa(l_array[0], ":"), 1))) {
        free_array(l_array);
        return NULL;
    }
    free_array(l_array);
    if (str_is_in_array(array, label)) {
        my_free(label);
        return NULL;
    }
    if (!(array = add_str_to_array(array, label, MALL_VS))) {
        my_free(label); return NULL;
    }
    my_free(label);
    return array;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Get the labels names from the file.
/// \param file_lines The file lines.
/// \return The labels names in an array.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if an error occurs while allocating memory.
/// \note Returns NULL if 2 labels have the same name.
////////////////////////////////////////////////////////////////////////////////
char **get_labels_names(char **file_lines)
{
    char **save = NULL; char **labels_name = NULL;
    if (!file_lines) return NULL;
    if (!(labels_name = my_arraydup((char **)default_array, MALL_VS)))
        return NULL;
    for (int i = 0; file_lines[i]; i++) {
        save = labels_name;
        if (!(labels_name = check_add_label(labels_name, file_lines[i]))) {
            free_array(save);
            return NULL;
        }
        if (save == labels_name) continue;
        free_array(save);
    }
    return labels_name;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Convert the labels names array to a labels_t structure array.
/// \param labels_names The labels to convert.
/// \return The converted labels.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if an error occurs while allocating memory.
/// \note Each label is initialized with :
/// \note   - The label name.
/// \note   - The label address (set to 0).
/// \note   - The label command position (set to NULL).
/// \note   - The label sizes (set to NULL).
/// \note   - The label position (set to NULL).
/// \note   - The label number of calls (set to 0).
/// \note The last element of the array is set to NULL.
////////////////////////////////////////////////////////////////////////////////
labels_t **convert_labels(char **labels_name)
{
    labels_t **labels_array = NULL; int len = 0;
    if (!labels_name) return NULL;
    len = my_array_len(labels_name);
    if (!(labels_array = malloc(sizeof(labels_t *) * (len + 1)))) return NULL;
    for (int i = 0; labels_name[i]; i++) {
        if (!(labels_array[i] = malloc(sizeof(labels_t)))) {
            free_array(labels_name);
            freen_labels(labels_array, i);
            return NULL;
        }
        labels_array[i]->name = labels_name[i];
        labels_array[i]->address = 0;
        labels_array[i]->cmdpos = NULL;
        labels_array[i]->callsize = NULL;
        labels_array[i]->callpos = NULL;
        labels_array[i]->nbcalls = 0;
    }
    labels_array[len] = NULL;
    return labels_array;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Get the labels from the file.
/// \param file_lines The file lines.
/// \return The labels in an array.
/// \warning Returns NULL if an error occurs.
/// \note Returns NULL if an error occurs while getting the labels names.
/// \note Returns NULL if an error occurs while checking the labels.
/// \note Returns NULL if an error occurs while adding the labels.
/// \note Returns NULL if an error occurs while converting the labels.
////////////////////////////////////////////////////////////////////////////////
labels_t **init_labels(char **file_lines)
{
    char **labels_names = get_labels_names(file_lines);
    labels_t **labels_array = NULL;
    if (!labels_names) return NULL;
    if (!(labels_array = convert_labels(labels_names))) {
        free_array(labels_names);
        return NULL;
    }
    my_free(labels_names);
    return labels_array;
}
