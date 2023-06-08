/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** tests_src_my_funcs
*/

#include "tests_include_header.h"

Test(convert_4chars_1int, tests_convert_4chars_1int, .init=redirect, .timeout=1) {
    cr_assert_eq(convert_4chars_1int(0, 0, 0, 0), 0);
    cr_assert_eq(convert_4chars_1int(0, 0, 0, 0), 0);
    cr_assert_eq(convert_4chars_1int(0, 0, 0, 0), 0);
    cr_assert_eq(convert_4chars_1int(0, 0, 0, 0), 0);
}

Test(my_count_words, tests_my_count_words, .init=redirect, .timeout=1) {
    cr_assert_eq(my_count_words(NULL, NULL), -1);
    cr_assert_eq(my_count_words(NULL, ""), -1);
    cr_assert_eq(my_count_words("", NULL), -1);
    cr_assert_eq(my_count_words("\n\n\n\n\n\n\n", "\n"), 0);
    cr_assert_eq(my_count_words("a", "a"), 0);
    cr_assert_eq(my_count_words("a", "b"), 1);
    cr_assert_eq(my_count_words("Hello World !", " "), 3);
    cr_assert_eq(my_count_words("Hello World !      ", " "), 3);
}

Test(my_get_file_name, tests_my_get_file_name, .init=redirect, .timeout=1) {
    cr_assert_null(my_get_file_name(NULL, MALL_VS, 1));
    cr_assert_null(my_get_file_name("", MALL_VS, 1));
    cr_assert_null(my_get_file_name("tests/", MALL_VS, 1));
    cr_assert_null(my_get_file_name("test/test", MALL_VS0, 1));
    cr_assert_null(my_get_file_name("////", MALL_VS, 1));
    cr_assert_null(my_get_file_name("test/test", MALL_VS, -1));
    cr_assert_str_eq(my_get_file_name("test/test", MALL_VS, 1), "test");
}

Test(my_getnbr_base, tests_my_getnbr_base, .init=redirect, .timeout=1) {
    cr_assert_eq(my_getnbr_base(NULL, NULL), -1);
    cr_assert_eq(my_getnbr_base("Hello", NULL), -1);
    cr_assert_eq(my_getnbr_base(NULL, "Hello"), -1);
    cr_assert_eq(my_getnbr_base("", "Hello"), -1);
    cr_assert_eq(my_getnbr_base("Hello", "0"), -1);
    cr_assert_eq(my_getnbr_base("+-+-+-+-+-+-+-", "01"), -1);
    cr_assert_eq(my_getnbr_base("01010101012", "01"), -1);
    cr_assert_eq(my_getnbr_base("010101", "01"), 0b010101);
}

Test(my_getnbr, tests_my_getnbr, .init=redirect, .timeout=1) {
    cr_assert_eq(my_getnbr(NULL), -1);
    cr_assert_eq(my_getnbr(""), -1);
    cr_assert_eq(my_getnbr("a"), -1);
    cr_assert_eq(my_getnbr("a1"), -1);
    cr_assert_eq(my_getnbr("1a"), -1);
    cr_assert_eq(my_getnbr("84"), 84);
    cr_assert_eq(my_getnbr("0849"), 849);
    cr_assert_eq(my_getnbr("\t849"), -1);
    cr_assert_eq(my_getnbr("-84"), -84);
    cr_assert_eq(my_getnbr("-+-84"), 84);
    cr_assert_eq(my_getnbr("-+-"), -1);
    cr_assert_eq(my_getnbr("-+-84~"), -1);
    cr_assert_eq(my_getnbr("-+-84\t"), -1);
}

Test(my_itoa, tests_my_itoa, .init=redirect, .timeout=1) {
    cr_assert_null(my_itoa(15, -1));
    cr_assert_str_eq(my_itoa(-15, 1), "-15");
    cr_assert_str_eq(my_itoa(15, 1), "15");
}

Test(my_perror, tests_my_perror, .init=redirect, .timeout=1) {
    errno = 0;
    my_perror("test return instant");
    errno = -1;
    my_perror("test return instant");
    errno = 1;
    my_perror(NULL);
    errno = 1;
    my_perror("");
    errno = 1;
    my_perror("test");
    errno = 134;
    my_perror("test");
    errno = 135;
    my_perror("test");
    errno = 133;
    my_perror("test");
    cr_assert_stderr_eq_str("Operation not permittedOperation not permittedtest: Operation not permittedtest: Unknown error 134test: Unknown error 135test: Memory page has hardware error");
}

Test(my_print_array, tests_my_print_array, .init=redirect, .timeout=1) {
    char *array[4] = {"Hello", "World", "!", NULL};
    cr_assert_eq(my_print_array(NULL, '\n'), false);
    cr_assert_eq(my_print_array(array, ' '), true);
    cr_assert_eq(my_print_array(array, '\0'), true);
}

Test(my_putchar, tests_my_putchar, .init=redirect, .timeout=1) {
    cr_assert_eq(my_putchar('c', 1), 1);
    cr_assert_eq(my_putchar('c', -1), -1);
}

Test(my_putnbr, tests_my_putnbr, .init=redirect, .timeout=1) {
    cr_assert_eq(my_putnbr(15, NULL, 1), -1);
    cr_assert_eq(my_putnbr(15, "a", 1), -1);
    cr_assert_eq(my_putnbr(15, "0123456789", 1), 1);
    cr_assert_eq(my_putnbr(150, "01234567", 1), 1);
}

Test(my_putstr_sepa, tests_my_putstr_sepa, .init=redirect, .timeout=1) {
    cr_assert_eq(my_putstr_sepa(NULL, "abcd", 1), 6);
    cr_assert_eq(my_putstr_sepa("Hello World !", NULL, 1), 13);
    cr_assert_eq(my_putstr_sepa("", "abcd", 1), 0);
    cr_assert_eq(my_putstr_sepa("Hello World !", "", 1), 13);
    cr_assert_eq(my_putstr_sepa("Hello World !", "abcd", -15), -1);
    cr_assert_eq(my_putstr_sepa("Hello World !", " ", 1), 5);
}

Test(my_putstr, tests_my_putstr, .init=redirect, .timeout=1) {
    cr_assert_eq(my_putstr(NULL, 1), 6);
    cr_assert_eq(my_putstr(NULL, -15), -1);
    cr_assert_eq(my_putstr("Hello World !", 1), 13);
    cr_assert_eq(my_putstr("Hello World !", -15), -1);
}

Test(my_remove_file_extension, tests_my_remove_file_extension, .init=redirect, .timeout=1) {
    cr_assert_null(my_remove_file_extension(NULL, "extension", 1));
    cr_assert_null(my_remove_file_extension("filepath", NULL, 1));
    cr_assert_null(my_remove_file_extension("", "extension", 1));
    cr_assert_null(my_remove_file_extension("filepath", "", 1));
    cr_assert_null(my_remove_file_extension("filepath", ".extension", 1));
    cr_assert_null(my_remove_file_extension("filepath.extension", ".extension", -1));
    cr_assert_str_eq(my_remove_file_extension("filepath.extension", ".extension", 1), "filepath");
}

Test(my_str_to_word_array, tests_my_str_to_word_array, .init=redirect, .timeout=1) {
    char *str = "   Hello Is          ALL RIGHT      ";
    char **result = my_str_to_word_array(str, " ",MALL_VS);
    cr_assert_str_eq(result[0], "Hello");
    cr_assert_str_eq(result[1], "Is");
    cr_assert_str_eq(result[2], "ALL");
    cr_assert_str_eq(result[3], "RIGHT");
    cr_assert_null(result[4]);
}

Test(my_strarraycat, tests_my_strarraycat, .init=redirect, .timeout=1) {
    char *array[4] = {"Hello", "World", "!", NULL};
    cr_assert_null(my_strarraycat(NULL, 1));
    cr_assert_null(my_strarraycat(array, -1));
    char *result = my_strarraycat(array, 1);
    cr_assert_str_eq(result, "HelloWorld!");
}

Test(my_strcat, tests_my_strcat, .init=redirect, .timeout=1) {
    cr_assert_null(my_strcat(NULL, "Hello", 1));
    cr_assert_null(my_strcat("Hello", NULL, 1));
    cr_assert_null(my_strcat("Hello", "Hello", -1));
    char *str1 = my_strcat("Hello", " World!", 1);
    cr_assert_str_eq(str1, "Hello World!");
}

Test(my_strdcat, tests_my_strdcat, .init=redirect, .timeout=1) {
    cr_assert_null(my_strdcat(NULL, "World", "!", 1));
    cr_assert_null(my_strdcat("Hello", NULL, "!", 1));
    cr_assert_null(my_strdcat("Hello", "World", NULL, 1));
    cr_assert_null(my_strdcat("Hello", "World", "!", -1));
    char *str1 = my_strdcat("Hello", " World", "!", 1);
    cr_assert_str_eq(str1, "Hello World!");
}

Test(my_strncat, tests_my_strncat, .init=redirect, .timeout=1) {
    cr_assert_null(my_strncat(NULL, "Hello", 1, 1));
    cr_assert_null(my_strncat("Hello", NULL, 1, 1));
    cr_assert_null(my_strncat("Hello", "Hello", -1, 1));
    cr_assert_null(my_strncat("Hello", "Hello", 1, -1));
    char *str1 = my_strncat("Hello", " World!", 3, 1);
    cr_assert_str_eq(str1, "Hello Wo");
        char *str2 = my_strncat("Hello", " World!", 100, 1);
    cr_assert_str_eq(str2, "Hello World!");
}

