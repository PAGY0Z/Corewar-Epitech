/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_display_dump
*/

#include "tests_include_header.h"

Test(display_dump, tests_display_dump, .init=redirect, .timeout=1) {
    byte_t *arena = malloc(sizeof(byte_t) * 4096);
    for (int i = 0; i < 4096; i++)
        arena[i] = 0;
    arena[0] = 1;
    arena[1] = 2;
    arena[2] = 3;
    arena[3] = 4;
    arena[4] = 5;
    arena[5] = 6;
    arena[6] = 7;
    arena[7] = 8;
    arena[8] = 9;
    arena[9] = 10;
    arena[10] = 11;
    arena[11] = 12;
    arena[12] = 13;
    arena[13] = 14;
    arena[14] = 15;
    arena[15] = 16;
    arena[16] = 17;
    arena[17] = 18;
    arena[18] = 19;
    arena[19] = 20;
    arena[20] = 21;
    arena[21] = 22;
    arena[22] = 23;
    arena[23] = 24;
    display_dump(arena);
    free(arena);
}