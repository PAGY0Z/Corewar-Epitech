/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** tests_src_files
*/

#include "tests_include_header.h"

Test(create_writable_file, tests_create_writable_file, .init=redirect, .timeout=1) {
    cr_assert_eq(create_writable_file(NULL), -1);
    cr_assert_eq(create_writable_file(""), -1);
    cr_assert_eq(create_writable_file("4567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789"), -1);
    cr_assert_eq(create_writable_file("unitests/"), -1);
    cr_assert_neq(create_writable_file("create_writable_file"), -1);
    remove("create_writable_file");
}

Test(display_file_content, tests_display_file_content, .init=redirect, .timeout=1) {
    cr_assert_eq(display_file_content(NULL, MALL_VS), false);
    cr_assert_eq(display_file_content("", MALL_VS), false);
    cr_assert_eq(display_file_content("non_existent", MALL_VS), false);
    cr_assert_eq(display_file_content("tests/tests_files/empty_readable", MALL_VS), true);
}

Test(get_file_content, tests_get_file_content, .init=redirect, .timeout=1) {
    cr_assert_null(get_file_content(NULL,MALL_VS));
    cr_assert_null(get_file_content("",MALL_VS));
    cr_assert_null(get_file_content("non_existent",MALL_VS));
    cr_assert_null(get_file_content("tests/tests_files/empty_readable", MALL_VS0));
    cr_assert_null(get_file_content("tests/tests_files/empty_readable", MALL_VS1));
    cr_assert_str_eq(get_file_content("tests/tests_files/empty_readable",MALL_VS), "");
    cr_assert_str_eq(get_file_content("tests/tests_files/filled_readable",MALL_VS), "0123456789");
}

Test(get_file_descriptor, tests_get_file_descriptor, .init=redirect, .timeout=1) {
    cr_assert_eq(get_file_descriptor(NULL), -1);
    cr_assert_eq(get_file_descriptor(""), -1);
    cr_assert_eq(get_file_descriptor("non_existent"), -1);
    cr_assert_neq(get_file_descriptor("tests/tests_files/empty_readable"), -1);
}

Test(get_file_lines_getline, tests_get_file_lines_getline, .init=redirect, .timeout=1) {
    cr_assert_null(get_file_lines_getline(NULL, MALL_VS, MALL_VS));
    cr_assert_null(get_file_lines_getline("", MALL_VS, MALL_VS));
    cr_assert_null(get_file_lines_getline("non_existent", MALL_VS, MALL_VS));
    cr_assert_null(get_file_lines_getline("tests/tests_files/filled_readable", MALL_VS0, MALL_VS));
    cr_assert_null(get_file_lines_getline("tests/tests_files/filled_readable", MALL_VS, MALL_VS0));
    char **file_lines = get_file_lines_getline("tests/tests_files/filled_readable", MALL_VS, MALL_VS);
    cr_assert_neq(file_lines, NULL);
    cr_assert_str_eq(file_lines[0], "0123456789");
    cr_assert_null(file_lines[1]);
    free_array(file_lines);
}

Test(get_file_lines, tests_get_file_lines, .init=redirect, .timeout=1) {
    cr_assert_null(get_file_lines(NULL, MALL_VS, MALL_VS));
    cr_assert_null(get_file_lines("", MALL_VS, MALL_VS));
    cr_assert_null(get_file_lines("tests/tests_files/filled_readable", MALL_VS0, MALL_VS));
    cr_assert_null(get_file_lines("tests/tests_files/filled_readable", MALL_VS, MALL_VS0));
    char **file_lines = get_file_lines("tests/tests_files/filled_readable", MALL_VS, MALL_VS);
    cr_assert_neq(file_lines, NULL);
    cr_assert_str_eq(file_lines[0], "0123456789");
    cr_assert_null(file_lines[1]);
    free_array(file_lines);
}

Test(get_file_size_lseek, tests_get_file_size_lseek, .init=redirect, .timeout=1) {
    cr_assert_eq(get_file_size_lseek(NULL), -1);
    cr_assert_eq(get_file_size_lseek(""), -1);
    cr_assert_eq(get_file_size_lseek("non_existent"), -1);
    cr_assert_eq(get_file_size_lseek("tests/tests_files/empty_readable"), 0);
    cr_assert_eq(get_file_size_lseek("tests/tests_files/filled_readable"), 10);
}

Test(get_file_size, tests_get_file_size, .init=redirect, .timeout=1) {
    cr_assert_eq(get_file_size(NULL), -1);
    cr_assert_eq(get_file_size(""), -1);
    cr_assert_eq(get_file_size("non_existent"), -1);
    cr_assert_eq(get_file_size("tests/tests_files/empty_readable"), 0);
}

Test(get_file_stream, tests_get_file_stream, .init=redirect, .timeout=1) {
    cr_assert_null(get_file_stream(NULL), -1);
    cr_assert_null(get_file_stream(""), -1);
    cr_assert_null(get_file_stream("non_existent"), -1);
    cr_assert_not_null(get_file_stream("tests/tests_files/empty_readable"));
}

Test(get_file_type, tests_get_file_type, .init=redirect, .timeout=1) {
    cr_assert_eq(get_file_type(NULL), -1);
    cr_assert_eq(get_file_type(""), -1);
    cr_assert_eq(get_file_type("non_existent"), -1);
    cr_assert_neq(get_file_type("tests/tests_files/empty_readable"), -1);
}

Test(get_new_file_name, tests_get_new_file_name, .init=redirect, .timeout=1) {
    cr_assert_null(get_new_file_name(NULL, "new_file", "txt", 1));
    cr_assert_null(get_new_file_name("", "new_file", "txt", 1));
    cr_assert_null(get_new_file_name("tests/", "new_file", "txt", 1));
    cr_assert_null(get_new_file_name("tests/tests_files/empty_readable", "txt", "txt", 1));
    cr_assert_null(get_new_file_name("tests/tests_files/empty_readable.txt", ".txt", ".lol", -1));
    cr_assert_str_eq(get_new_file_name("tests/tests_files/empty_readable.txt", ".txt", ".odt", 1), "empty_readable.odt");
}

Test(my_close_fd, tests_my_close_fd, .init=redirect, .timeout=1) {
    int fd = get_file_descriptor("tests/tests_files/empty_readable");
    cr_assert_neq(fd, -1);
    cr_assert_eq(my_close_fd(fd), true);
    cr_assert_eq(my_close_fd(fd), false);
    cr_assert_stderr_neq_str("");
}

Test(my_close_stream, tests_my_close_stream, .init=redirect, .timeout=1) {
    FILE *stream = get_file_stream("tests/tests_files/empty_readable");
    cr_assert_not_null(stream);
    cr_assert_eq(my_close_stream(NULL), false);
    cr_assert_eq(my_close_stream(stream), true);
}

Test(my_read_fd, tests_my_read_fd, .init=redirect, .timeout=1) {
    int fd = get_file_descriptor("tests/tests_files/filled_readable");
    char *dest = malloc(sizeof(char) * 11);
    cr_assert_neq(fd, -1);
    cr_assert_neq(dest, NULL);
    cr_assert_eq(my_read_fd(fd, dest, 10), true);
    cr_assert_eq(my_read_fd(-1, dest, 10), false);
}
