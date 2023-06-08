/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** functions_header
*/

////////////////////////////////////////////////////////////////////////////////
/// \file functions_header.h
/// \brief Contains the prototypes of all the functions of the libmy.a
/// \authors PAGY0Z
/// \version 0.1
/// \date 2023-23-04
////////////////////////////////////////////////////////////////////////////////

#ifndef FUNCTIONS_HEADER_H_
    #define FUNCTIONS_HEADER_H_

    #include "types_header.h"

    ////////////////////////////////////////////////////////////////////////////
    /// \addtogroup LIBRARY
    /// \brief Contains all the files of the library.
    /// @{
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    /// \addtogroup LIBRARY_FUNCTIONS
    /// \brief All the functions of the library.
    /// @{
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    /// \addtogroup LIBRARY_ARRAY_TABLE_FUNCTIONS
    /// \brief The functions that handle arrays and tables.
    /// @{
    ////////////////////////////////////////////////////////////////////////////

    int **add_intarray_to_table(int **table, int *int_array, int *mall_vs);
    char **add_str_to_array(char **array, char *str, int *mall_vs);
    int **convert_array_table(char **array, int *mall_vs);
    char **convert_table_array(int **table, int *mall_vs);
    char **create_array(int size_y, int size_x, int *mall_vs);
    int **create_table(int size_y, int size_x, int *mall_vs);
    bool fill_array(char **array, char value);
    bool fill_table(int **table, int value);
    void replace_str_in_array(char **array, char *str, int index, int *mall_vs);

    ////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    /// \addtogroup LIBRARY_BOOLEAN_FUNCTIONS
    /// \brief The functions that handle booleans.
    /// @{
    ////////////////////////////////////////////////////////////////////////////

    bool is_token(char c, char const *tokens);
    bool my_check_file_extension(char const *filepath, char const *extension);
    bool my_help_identifier(char **array);
    bool my_strcmp(char const *str1, char const *str2);
    bool my_strncmp(char const *str1, char const *str2, int n);
    bool my_strstr(char const *str1, char const *str2);
    bool str_is_alpha(char const *str);
    bool str_is_alphanum(char const *str);
    bool str_is_empty(char const *str);
    bool str_is_in_array(char **array, char const *str);
    bool str_is_lower(char const *str);
    bool str_is_num(char const *str);
    bool str_is_number(char const *str);
    bool str_is_printable(char const *str);
    bool str_is_token(char const *str, char const *tokens);
    bool str_is_upper(char const *str);

    ////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    /// \addtogroup LIBRARY_DUPLICATE_FUNCTIONS
    /// \brief The functions that duplicate arrays, tables and strings.
    /// @{
    ////////////////////////////////////////////////////////////////////////////

    char **my_arraydup(char **array, int *mall_vs);
    int *my_intarraydup(int *intarray, int mall_v1);
    int *my_intarrayndup(int *intarray, int n, int mall_v1);
    char *my_strdup(char const *str, int mall_v1);
    char *my_strndup(char const *str, int n, int mall_v1);
    int **my_tabledup(int **table, int *mall_vs);

    ////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    /// \addtogroup LIBRARY_FILE_FUNCTIONS
    /// \brief The functions that handle files.
    /// @{
    ////////////////////////////////////////////////////////////////////////////

    int create_writable_file(char const *filepath);
    bool display_file_content(char const *filepath, int *mall_vs);
    char *get_file_content(char const *filepath, int *mall_vs);
    int get_file_descriptor(char const *filepath);
    char **get_file_lines_getline(char const *filepath, int *mall1, int *mall2);
    char **get_file_lines(char const *filepath, int *mall_vs1, int *mall_vs2);
    int get_file_size_lseek(char const *filepath);
    long long get_file_size(char const *filepath);
    FILE *get_file_stream(char const *filepath);
    int get_file_type(char const *filepath);
    char *get_new_file_name(char const *fp, char *o_ext, char *n_ext, int m_v1);
    bool my_close_fd(int fd);
    bool my_close_stream(FILE *stream);
    bool my_read_fd(int fd, char *dest, long long size);

    ////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    /// \addtogroup LIBRARY_FREE_FUNCTIONS
    /// \brief The functions that free arrays, tables and strings.
    /// @{
    ////////////////////////////////////////////////////////////////////////////

    void free_array(char **array);
    void free_table(int **table);
    void freen_array(char **array, int n);
    void freen_table(int **table, int n);
    void my_free(void *ptr);

    ////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    /// \addtogroup LIBRARY_LENGTH_FUNCTIONS
    /// \brief The functions that return the length of arrays, tables and
    /// strings.
    /// @{
    ////////////////////////////////////////////////////////////////////////////

    int my_array_len(char **array);
    int my_array_strlen(char **array);
    int my_intarray_len(int *int_array);
    int my_len_nbr(int nbr);
    int my_strlen_sepa(char const *str, char const *sepa);
    int my_strlen(char const *str);
    int my_table_len(int **table);

    ////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    /// \addtogroup LIBRARY_MY_FUNCS_FUNCTIONS
    /// \brief My personnal functions.
    /// @{
    ////////////////////////////////////////////////////////////////////////////

    int convert_4chars_1int(uchar_t b1, uchar_t b2, uchar_t b3, uchar_t b4);
    int my_count_words(char const *str, char const *sepa);
    char *my_get_file_name(char const *filepath, int *mall_vs, int mall_v1);
    int my_getnbr_base(char const *str, char const *base);
    int my_getnbr(char const *str);
    char *my_itoa(int nbr, int mall_v1);
    void my_perror(char const *str);
    bool my_print_array(char **array, char sepa);
    int my_putchar(char c, int fd);
    int my_putnbr(unsigned int nb, char const *base, int fd);
    int my_putstr_sepa(char const *str, char const *sepa, int fd);
    int my_putstr(char const *str, int fd);
    char *my_remove_file_extension(char const *fp, char const *ex, int mall_v1);
    char **my_str_to_word_array(char const *str, char *sepa, int *mall_vs);
    char *my_strarraycat(char **array, int mall_v1);
    char *my_strcat(char const *str1, char const *str2, int mall_v1);
    char *my_strdcat(char const *s1, char const *s2, char const *s3, int ma_v1);
    char *my_strncat(char const *str1, char const *str2, int n, int mall_v1);

    ////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    /// \addtogroup LIBRARY_MY_PRINTF_FUNCTION
    /// \brief My personnal printf function.
    /// @{
    ////////////////////////////////////////////////////////////////////////////

    int my_printf(char const *format, ...);

    ////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////

#endif /* !FUNCTIONS_HEADER_H_ */
