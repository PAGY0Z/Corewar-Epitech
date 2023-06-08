/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** tests_src_booleans
*/

#include "tests_include_header.h"

Test(is_token, tests_is_token, .init=redirect, .timeout=1) {
    cr_assert_eq(is_token('a', NULL), false);
    cr_assert_eq(is_token('a', ""), false);
    cr_assert_eq(is_token('a', "a"), true);
    cr_assert_eq(is_token('a', "123456789a"), true);
    cr_assert_eq(is_token('a', "zertyuiopqsdfghjklmwxcvbn"), false);
}

Test(my_check_file_extension, tests_my_check_file_extension, .init=redirect, .timeout=1) {
    cr_assert_eq(my_check_file_extension(NULL, ".extension"), false);
    cr_assert_eq(my_check_file_extension("filepath", NULL), false);
    cr_assert_eq(my_check_file_extension("", ".extension"), false);
    cr_assert_eq(my_check_file_extension("filepath", ""), false);
    cr_assert_eq(my_check_file_extension("filepath", "extension longer than filepath"), false);
    cr_assert_eq(my_check_file_extension("filepath.extension", "notfit"), false);
    cr_assert_eq(my_check_file_extension("filepath.extension", ".extension"), true);
}

Test(my_help_identifier, tests_my_help_identifier, .init=redirect, .timeout=1) {
    char *test1[] = {"./mysh", "-h", NULL};
    char *test2[] = {"./mysh", "--help", NULL};
    char *test3[] = {"./mysh", "", "", NULL};
    cr_assert_eq(my_help_identifier(NULL), false);
    cr_assert_eq(my_help_identifier(test1), true);
    cr_assert_eq(my_help_identifier(test2), true);
    cr_assert_eq(my_help_identifier(test3), false);
}

Test(my_strcmp, tests_my_strcmp, .init=redirect, .timeout=1) {
    cr_assert_eq(my_strcmp(NULL, "NOT NULL"), false);
    cr_assert_eq(my_strcmp("NOT NULL", NULL), false);
    cr_assert_eq(my_strcmp("STR", "STRLONGER"), false);
    cr_assert_eq(my_strcmp("STRLONGER", "STR"), false);
    cr_assert_eq(my_strcmp("STR1A", "STR2A"), false);
    cr_assert_eq(my_strcmp("STR1", "STR1"), true);
}

Test(my_strncmp, tests_my_strncmp, .init=redirect, .timeout=1) {
    cr_assert_eq(my_strncmp(NULL, "NOT NULL", 100), false);
    cr_assert_eq(my_strncmp("NOT NULL", NULL, 100), false);
    cr_assert_eq(my_strncmp("DIFFERENT1", "DIFFERENT2", -100), true);
    cr_assert_eq(my_strncmp("DIFFERENT1", "DIFFERENT2", 0), true);
    cr_assert_eq(my_strncmp("DIFFERENT1", "DIFFERENT2", 1), true);
    cr_assert_eq(my_strncmp("DIFFERENT1", "DIFFERENT2", 2), true);
    cr_assert_eq(my_strncmp("DIFFERENT1", "DIFFERENT2", 3), true);
    cr_assert_eq(my_strncmp("DIFFERENT1", "DIFFERENT2", 4), true);
    cr_assert_eq(my_strncmp("DIFFERENT1", "DIFFERENT2", 5), true);
    cr_assert_eq(my_strncmp("DIFFERENT1", "DIFFERENT2", 6), true);
    cr_assert_eq(my_strncmp("DIFFERENT1", "DIFFERENT2", 7), true);
    cr_assert_eq(my_strncmp("DIFFERENT1", "DIFFERENT2", 8), true);
    cr_assert_eq(my_strncmp("DIFFERENT1", "DIFFERENT2", 9), true);
    cr_assert_eq(my_strncmp("DIFFERENT1", "DIFFERENT2", 10), false);
    cr_assert_eq(my_strncmp("DIFFERENT1", "DIFFERENT2", 100), false);
}

Test(my_strstr, tests_my_strstr, .init=redirect, .timeout=1) {
    cr_assert_eq(my_strstr(NULL, "NOT NULL"), false);
    cr_assert_eq(my_strstr("NOT NULL", NULL), false);
    cr_assert_eq(my_strstr("HELLO WORLD", ""), false);
    cr_assert_eq(my_strstr("", "HELLO WORLD"), false);
    cr_assert_eq(my_strstr("HELLO WORLD", "HELLO"), true);
    cr_assert_eq(my_strstr("HELLO WORLD", "WORLD"), true);
    cr_assert_eq(my_strstr("HELLO WORLD", "HELLO WORLD"), true);
    cr_assert_eq(my_strstr("HELLO WORLD", "HELLO WORLD!"), false);
    cr_assert_eq(my_strstr("abcdefghijklmnopqrstuvwxyz", "HELLO WORLD"), false);
}

Test(str_is_alpha, tests_str_is_alpha, .init=redirect, .timeout=1) {
    cr_assert_eq(str_is_alpha("a"), true);
    cr_assert_eq(str_is_alpha(""), false);
    cr_assert_eq(str_is_alpha("Hello"), true);
    cr_assert_eq(str_is_alpha("Hello World"), false);
    cr_assert_eq(str_is_alpha("Hello~World"), false);
    cr_assert_eq(str_is_alpha(NULL), false);
}

Test(str_is_alphanum, tests_str_is_alphanum, .init=redirect, .timeout=1) {
    cr_assert_eq(str_is_alphanum("a"), true);
    cr_assert_eq(str_is_alphanum(""), false);
    cr_assert_eq(str_is_alphanum("Hello"), true);
    cr_assert_eq(str_is_alphanum("Hello123"), true);
    cr_assert_eq(str_is_alphanum("Hello World"), false);
    cr_assert_eq(str_is_alphanum("Hello World 123"), false);
    cr_assert_eq(str_is_alphanum("Hello~World 123!"), false);
    cr_assert_eq(str_is_alphanum(NULL), false);
}

Test(str_is_empty, tests_str_is_empty, .init=redirect, .timeout=1) {
    cr_assert_eq(str_is_empty(NULL), true);
    cr_assert_eq(str_is_empty(""), true);
    cr_assert_eq(str_is_empty(" "), true);
    cr_assert_eq(str_is_empty("  "), true);
    cr_assert_eq(str_is_empty(" \t  "), true);
    cr_assert_eq(str_is_empty(" \t\n  "), false);
    cr_assert_eq(str_is_empty("Hello World"), false);
}

Test(str_is_in_array, tests_str_is_in_array, .init=redirect, .timeout=1)
{
    char *array[] = {
        "Hello",
        "World",
        "!",
        NULL,
    };
    cr_assert_eq(str_is_in_array(NULL, "Hello"), false);
    cr_assert_eq(str_is_in_array(array, NULL), false);
    cr_assert_eq(str_is_in_array(array, "Not there"), false);
    cr_assert_eq(str_is_in_array(array, "Hello"), true);
}

Test(str_is_lower, tests_str_is_lower, .init=redirect, .timeout=1) {
    cr_assert_eq(str_is_lower("a"), true);
    cr_assert_eq(str_is_lower(""), false);
    cr_assert_eq(str_is_lower("Hello"), false);
    cr_assert_eq(str_is_lower("Hello123"), false);
    cr_assert_eq(str_is_lower("helloworld"), true);
    cr_assert_eq(str_is_lower("hello~World 123!"), false);
    cr_assert_eq(str_is_lower("hello World 123!"), false);
    cr_assert_eq(str_is_lower(NULL), false);
}

Test(str_is_num, tests_str_is_num, .init=redirect, .timeout=1) {
    cr_assert_eq(str_is_num("a"), false);
    cr_assert_eq(str_is_num(""), false);
    cr_assert_eq(str_is_num("Hello"), false);
    cr_assert_eq(str_is_num("Hello123"), false);
    cr_assert_eq(str_is_num("123"), true);
    cr_assert_eq(str_is_num("1234567890"), true);
    cr_assert_eq(str_is_num("1234567890!"), false);
    cr_assert_eq(str_is_num("1234567890!"), false);
    cr_assert_eq(str_is_num(NULL), false);
}

Test(str_is_number, tests_str_is_number, .init=redirect, .timeout=1) {
    cr_assert_eq(str_is_number(NULL), false);
    cr_assert_eq(str_is_number(""), false);
    cr_assert_eq(str_is_number("-+-+-+-848484"), true);
    cr_assert_eq(str_is_number("-+-+-/84"), false);
    cr_assert_eq(str_is_number("-+-+-~84"), false);
}

Test(str_is_printable, tests_str_is_printable, .init=redirect, .timeout=1) {
    cr_assert_eq(str_is_printable(NULL), false);
    cr_assert_eq(str_is_printable(""), false);
    cr_assert_eq(str_is_printable("Hello"), true);
    cr_assert_eq(str_is_printable("Hello123"), true);
    cr_assert_eq(str_is_printable("123"), true);
    cr_assert_eq(str_is_printable("1234567890"), true);
    cr_assert_eq(str_is_printable("1234567890!"), true);
    cr_assert_eq(str_is_printable("1234567890!"), true);
    cr_assert_eq(str_is_printable("\004"), false);
    cr_assert_eq(str_is_printable("\004\005"), false);
    cr_assert_eq(str_is_printable("\004\005\006"), false);
    cr_assert_eq(str_is_printable("\004\005\006\007"), false);
    cr_assert_eq(str_is_printable("\177"), false);
}

Test(str_is_token, tests_str_is_token, .init=redirect, .timeout=1) {
    cr_assert_eq(str_is_token(NULL, "NOT NULL"), false);
    cr_assert_eq(str_is_token("NOT NULL", NULL), false);
    cr_assert_eq(str_is_token("", "NOT NULL"), false);
    cr_assert_eq(str_is_token("NOT NULL", ""), false);
    cr_assert_eq(str_is_token("Hello World", "Helo Wrd"), true);
    cr_assert_eq(str_is_token("Hello World", "Helo Wr"), false);
}

Test(str_is_upper, tests_str_is_upper, .init=redirect, .timeout=1) {
    cr_assert_eq(str_is_upper("a"), false);
    cr_assert_eq(str_is_upper(""), false);
    cr_assert_eq(str_is_upper("Hello"), false);
    cr_assert_eq(str_is_upper("Hello123"), false);
    cr_assert_eq(str_is_upper("helloworld"), false);
    cr_assert_eq(str_is_upper("HELLOWORLD"), true);
    cr_assert_eq(str_is_upper("HELLO~World 123!"), false);
    cr_assert_eq(str_is_upper("HELLO World 123!"), false);
    cr_assert_eq(str_is_upper(NULL), false);
}
