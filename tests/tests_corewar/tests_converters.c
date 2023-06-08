/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_converters
*/

#include "tests_include_header.h"

Test(get_len, tests_get_len, .init=redirect, .timeout=1) {
    cr_assert_eq(get_len(0b01), 1);
    cr_assert_eq(get_len(0b11), 2);
    cr_assert_eq(get_len(0b10), 4);
    cr_assert_eq(get_len(0b00), 0);
}

Test(get_short, tests_get_short, .init=redirect, .timeout=1) {
    byte_t params[] = {0x00, 0x00, 0x11, 0x11, 0x22, 0x22, 0x33, 0x33, 0x44, 0x44, 0x55, 0x55, 0x66, 0x66};
    cr_assert_eq(get_short(params, -1), 0x0000);
    cr_assert_eq(get_short(params, 0), 0x0000);
    cr_assert_eq(get_short(params, 1), 0x0011);
    cr_assert_eq(get_short(params, 2), 0x1111);
    cr_assert_eq(get_short(params, 3), 0x1122);
    cr_assert_eq(get_short(params, 4), 0x2222);
    cr_assert_eq(get_short(params, 5), 0x2233);
    cr_assert_eq(get_short(params, 6), 0x3333);
    cr_assert_eq(get_short(params, 7), 0x3344);
    cr_assert_eq(get_short(params, 8), 0x4444);
    cr_assert_eq(get_short(params, 9), 0x4455);
    cr_assert_eq(get_short(params, 10), 0x5555);
    cr_assert_eq(get_short(params, 11), 0x5566);
    cr_assert_eq(get_short(params, 12), 0x6666);
    cr_assert_eq(get_short(params, 13), 0x0000);
}

Test(get_type_p1, tests_get_type_p1, .init=redirect, .timeout=1) {
    byte_t params[] = {0b00000000, 0b01000000, 0b10000000, 0b11000000};
    cr_assert_eq(get_type_p1(params[0]), 0);
    cr_assert_eq(get_type_p1(params[1]), 1);
    cr_assert_eq(get_type_p1(params[2]), 2);
    cr_assert_eq(get_type_p1(params[3]), 3);
}

Test(get_type_p2, tests_get_type_p2, .init=redirect, .timeout=1) {
    byte_t params[] = {0b00000000, 0b00010000, 0b00100000, 0b00110000};
    cr_assert_eq(get_type_p2(params[0]), 0);
    cr_assert_eq(get_type_p2(params[1]), 1);
    cr_assert_eq(get_type_p2(params[2]), 2);
    cr_assert_eq(get_type_p2(params[3]), 3);
}

Test(get_type_p3, tests_get_type_p3, .init=redirect, .timeout=1) {
    byte_t params[] = {0b00000000, 0b00000100, 0b00001000, 0b00001100};
    cr_assert_eq(get_type_p3(params[0]), 0);
    cr_assert_eq(get_type_p3(params[1]), 1);
    cr_assert_eq(get_type_p3(params[2]), 2);
    cr_assert_eq(get_type_p3(params[3]), 3);
}
