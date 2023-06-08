/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** add_instructions
*/

#include "asm_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file add_instructions.c
/// \brief Contains the functions to add instructions to the buffer.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-13-05
////////////////////////////////////////////////////////////////////////////////

bool exit_false_line_treatment(char **line_words);
bool add_instruction(asm_t *asm_struct, char **line_words);
bool line_treatment(asm_t *asm_struct, char *line);
bool add_instructions(asm_t *asm_struct);

////////////////////////////////////////////////////////////////////////////////
/// \brief Exit the line_treatment function if an error occurs.
/// \param line_words The array of words of the line.
/// \return false.
/// \note Free the array of words.
/// \note It is used to exit the line_treatment function if an error occurs.
////////////////////////////////////////////////////////////////////////////////
bool exit_false_line_treatment(char **line_words)
{
    free_array(line_words);
    return false;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Add an instruction to the buffer.
/// \param asm_struct The asm struct.
/// \param line_words The array of words of the line.
/// \return true if the instruction was added, false otherwise.
/// \note Return false if the line words or the asm_struct is NULL.
/// \note Return true if the line words is empty.
/// \note Return false if the instruction is not found.
/// \note Return false if the instruction function returns false.
/// \note Return true if the instruction function returns true.
////////////////////////////////////////////////////////////////////////////////
bool add_instruction(asm_t *asm_struct, char **line_words)
{
    if (!asm_struct || !line_words) return false;
    if (!line_words[0]) return true;
    for (int i = 0; instructions[i].name; i++) {
        if (!my_strcmp(instructions[i].name, line_words[0])) continue;
        if (!instructions[i].function) return false;
        return instructions[i].function(asm_struct, line_words);
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Treat a single line. Divide it into words and add the instruction to
/// the buffer.
/// \param asm_struct The asm struct.
/// \param line The line to treat.
/// \return true if the line was correctly treated, false otherwise.
/// \note Return false if the asm_struct or the line is NULL.
/// \note Return false if the line could not be divided into words.
/// \note Case 1 : The first is a registered label.
/// \note   - The label adress is updated.
/// \note   - The instruction is added to the buffer. line_words + 1 is passed
/// \note Case 2 : The first word is not a registered label.
/// \note   - The instruction is added to the buffer. line_words is passed
////////////////////////////////////////////////////////////////////////////////
bool line_treatment(asm_t *asm_struct, char *line)
{
    char **line_words = NULL;
    if (!asm_struct || !line) return false;
    if (!(line_words = my_str_to_word_array(line, ", \t", MALL_VS)))
        return false;
    if (is_registered_label(asm_struct, line_words[0])) {
        line_words[0][my_strlen(line_words[0]) - 1] = '\0';
        if (!update_label_address(asm_struct, line_words[0]))
            return exit_false_line_treatment(line_words);
        if (!add_instruction(asm_struct, line_words + 1))
            return exit_false_line_treatment(line_words);
        free_array(line_words);
        return true;
    }
    if (!add_instruction(asm_struct, line_words))
        return exit_false_line_treatment(line_words);
    free_array(line_words);
    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Add all the instructions to the buffer. Skip empty lines. Return
/// false if an error occurs.
/// \param asm_struct The asm struct.
/// \return true if the instructions were added, false otherwise.
/// \details This function is the main function of the parsing. It calls the
/// line_treatment function for each line of the file. It stops when it reaches
/// the end of the file. It returns false if the line_treatment function returns
/// false. It returns true otherwise.
/// \note Return false if the asm_struct is NULL.
/// \note Return false if the line_treatment function returns false.
////////////////////////////////////////////////////////////////////////////////
bool add_instructions(asm_t *asm_struct)
{
    char **lines = NULL;
    if (!asm_struct) return false;
    lines = asm_struct->file_lines;
    for (; lines[asm_struct->line_index]; asm_struct->line_index++) {
        if (str_is_empty(lines[asm_struct->line_index])) continue;
        if (!line_treatment(asm_struct, lines[asm_struct->line_index]))
            return false;
    }
    return true;
}
