/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_init_labels
*/

#include "tests_include_header.h"

Test(check_add_label, tests_check_add_label, .init=redirect, .timeout=1) {
    char *array1[] = {
        NULL,
    };
    char *array2[] = {
        "label1",
        NULL,
    };
    char **array3 = NULL;
    char **array4 = NULL;
    cr_assert_null(check_add_label(NULL, NULL));
    cr_assert_null(check_add_label(NULL, "label1"));
    cr_assert_null(check_add_label(array2, "label1:"));
    array3 = check_add_label(array1, "label1:");
    cr_assert_not_null(array3);
    cr_assert_str_eq(array3[0], "label1");
    cr_assert_null(array3[1]);
    cr_assert_null(check_add_label(array4, "label1:"));
    free_array(array3);
}

Test(get_labels_names, tests_get_labels_names, .init=redirect, .timeout=1) {
    char *valid_array[] = {
        "label1:",
        "label2:",
        "label3:",
        "",
        "hello world",
        "wtf is this test",
        "label8:",
        "label9:",
        "label10:",
        NULL
    };
    char *invalid_array[] = {
        "label1:",
        "label2:",
        "label3:",
        "label1:",
        "label2:",
        "label3:",
        NULL
    };
    char **labels_names = NULL;
    cr_assert_null(get_labels_names(NULL));
    cr_assert_null(get_labels_names(invalid_array));
    labels_names = get_labels_names(valid_array);
    cr_assert_not_null(labels_names);
    cr_assert_eq(my_array_len(labels_names), 6);
    cr_assert_str_eq(labels_names[0], "label1");
    cr_assert_str_eq(labels_names[1], "label2");
    cr_assert_str_eq(labels_names[2], "label3");
    cr_assert_str_eq(labels_names[3], "label8");
    cr_assert_str_eq(labels_names[4], "label9");
    cr_assert_str_eq(labels_names[5], "label10");
    cr_assert_null(labels_names[6]);
    free_array(labels_names);
}

Test(convert_labels, tests_convert_labels, .init=redirect, .timeout=1) {
    char *labels_array[] = {
        "label1",
        "label2",
        "label3",
        "label8",
        "label9",
        "label10",
        NULL
    };
    char **labels_array_dup = my_arraydup(labels_array, MALL_VS);
    labels_t **labels = NULL;
    cr_assert_null(convert_labels(NULL));
    labels = convert_labels(labels_array_dup);
    cr_assert_not_null(labels);
    cr_assert_str_eq(labels[0]->name, "label1");
    cr_assert_str_eq(labels[1]->name, "label2");
    cr_assert_str_eq(labels[2]->name, "label3");
    cr_assert_str_eq(labels[3]->name, "label8");
    cr_assert_str_eq(labels[4]->name, "label9");
    cr_assert_str_eq(labels[5]->name, "label10");
    cr_assert_null(labels[6]);
    free_labels(labels);
}

Test(init_labels, tests_init_labels, .init=redirect, .timeout=1) {
    char *valid_array[] = {
        "label1:",
        "label2:",
        "label3:",
        "",
        "hello world",
        "wtf is this test",
        "label8:",
        "label9:",
        "label10:",
        NULL
    };
    char *invalid_array[] = {
        "label1:",
        "label2:",
        "label3:",
        "label1:",
        "label2:",
        "label3:",
        NULL
    };
    labels_t **labels = NULL;
    cr_assert_null(init_labels(NULL));
    cr_assert_null(init_labels(invalid_array));
    labels = init_labels(valid_array);
    cr_assert_not_null(labels);
    cr_assert_str_eq(labels[0]->name, "label1");
    cr_assert_str_eq(labels[1]->name, "label2");
    cr_assert_str_eq(labels[2]->name, "label3");
    cr_assert_str_eq(labels[3]->name, "label8");
    cr_assert_str_eq(labels[4]->name, "label9");
    cr_assert_str_eq(labels[5]->name, "label10");
    cr_assert_null(labels[6]);
    free_labels(labels);
}
