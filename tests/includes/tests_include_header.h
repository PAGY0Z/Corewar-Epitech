/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** tests_include_header
*/

#ifndef TESTS_INCLUDE_HEADER_H_
    #define TESTS_INCLUDE_HEADER_H_

    #include <criterion/criterion.h>
    #include <criterion/redirect.h>
    #include <criterion/parameterized.h>
    #include <criterion/assert.h>
    #include <criterion/internal/assert.h>
    #include <criterion/internal/redirect.h>
    #include <criterion/internal/test.h>
    #include <criterion/internal/ordered-set.h>
    #include "my.h"
    #include "asm_programm_header.h"
    #include "corewar_programm_header.h"

    void redirect(void);

    #define MALL_VS0 ((int[]){-1, 1, 1, 1, 1, 1, 1, 1, 1, 1})
    #define MALL_VS1 ((int[]){1, -1, 1, 1, 1, 1, 1, 1, 1, 1})
    #define MALL_VS2 ((int[]){1, 1, -1, 1, 1, 1, 1, 1, 1, 1})
    #define MALL_VS3 ((int[]){1, 1, 1, -1, 1, 1, 1, 1, 1, 1})
    #define MALL_VS4 ((int[]){1, 1, 1, 1, -1, 1, 1, 1, 1, 1})
    #define MALL_VS5 ((int[]){1, 1, 1, 1, 1, -1, 1, 1, 1, 1})
    #define MALL_VS6 ((int[]){1, 1, 1, 1, 1, 1, -1, 1, 1, 1})
    #define MALL_VS7 ((int[]){1, 1, 1, 1, 1, 1, 1, -1, 1, 1})
    #define MALL_VS8 ((int[]){1, 1, 1, 1, 1, 1, 1, 1, -1, 1})
    #define MALL_VS9 ((int[]){1, 1, 1, 1, 1, 1, 1, 1, 1, -1})

#endif /* !TESTS_INCLUDE_HEADER_H_ */
