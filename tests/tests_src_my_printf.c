/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** tests_src_my_printf
*/

#include "tests_include_header.h"

Test(my_printf, default_putnbr_b0, .init=redirect, .timeout=1)
{
    int value = my_printf("%b", 0);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_b1, .init=redirect, .timeout=1) 
{
    int value = my_printf("%b", 1);
    cr_assert_stdout_eq_str("1");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_b2, .init=redirect, .timeout=1)
{
    int value = my_printf("%b", 42);
    cr_assert_stdout_eq_str("101010");
    cr_assert_eq(value, 6);
}

Test(my_printf, default_putnbr_b3, .init=redirect, .timeout=1)
{
    int value = my_printf("%b", 424344);
    cr_assert_stdout_eq_str("1100111100110011000");
    cr_assert_eq(value, 19);
}

Test(my_printf, default_putnbr_b4, .init=redirect, .timeout=1)
{
    int value = my_printf("%b", 2147483647);
    cr_assert_stdout_eq_str("1111111111111111111111111111111");
    cr_assert_eq(value, 31);
}

Test(my_printf, default_putnbr_b5, .init=redirect, .timeout=1)
{
    int value = my_printf("%b", 2147483648);
    cr_assert_stdout_eq_str("10000000000000000000000000000000");
    cr_assert_eq(value, 32);
}

Test(my_printf, default_putnbr_b6, .init=redirect, .timeout=1)
{
    int value = my_printf("%b", 4294967295);
    cr_assert_stdout_eq_str("11111111111111111111111111111111");
    cr_assert_eq(value, 32);
}

Test(my_printf, default_putnbr_b7, .init=redirect, .timeout=1)
{
    int value = my_printf("%b", 4294967296);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_b8, .init=redirect, .timeout=1)
{
    int value = my_printf("%b", 4294967297);
    cr_assert_stdout_eq_str("1");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_b9, .init=redirect, .timeout=1)
{
    int value = my_printf("%b", -0);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_b10, .init=redirect, .timeout=1)
{
    int value = my_printf("%b", -1);
    cr_assert_stdout_eq_str("11111111111111111111111111111111");
    cr_assert_eq(value, 32);
}

Test(my_printf, default_putnbr_b11, .init=redirect, .timeout=1)
{
    int value = my_printf("%b", -42);
    cr_assert_stdout_eq_str("11111111111111111111111111010110");
    cr_assert_eq(value, 32);
}

Test(my_printf, default_putnbr_b12, .init=redirect, .timeout=1)
{
    int value = my_printf("%b", -424344);
    cr_assert_stdout_eq_str("11111111111110011000011001101000");
    cr_assert_eq(value, 32);
}

Test(my_printf, default_putnbr_b13, .init=redirect, .timeout=1) 
{
    int value = my_printf("%b", -2147483647);
    cr_assert_stdout_eq_str("10000000000000000000000000000001");
    cr_assert_eq(value, 32);
}

Test(my_printf, default_putnbr_b14, .init=redirect, .timeout=1) 
{
    int value = my_printf("%b", -2147483648);
    cr_assert_stdout_eq_str("10000000000000000000000000000000");
    cr_assert_eq(value, 32);
}

Test(my_printf, default_putnbr_b15, .init=redirect, .timeout=1) 
{
    int value = my_printf("%b", -4294967295);
    cr_assert_stdout_eq_str("1");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_b16, .init=redirect, .timeout=1) 
{
    int value = my_printf("%b", -4294967296);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_b17, .init=redirect, .timeout=1) 
{
    int value = my_printf("%b", -4294967297);
    cr_assert_stdout_eq_str("11111111111111111111111111111111");
    cr_assert_eq(value, 32);
}

Test(my_printf, default_my_putchar_my_printf_c0, .init=redirect, .timeout=1)
{
    int value = my_printf("%c", 0);
    FILE *f_stdout = cr_get_redirected_stdout();
    char byte = 0;
    fread(&byte, 1, 1, f_stdout);
    cr_log_info("%u\n", byte & 0xff);
    cr_assert_eq(byte & 0xff, 0);
    cr_assert_stdout_eq_str("");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_putchar_my_printf_c1, .init=redirect, .timeout=1)
{
    int value = my_printf("%c", 1);
    FILE *f_stdout = cr_get_redirected_stdout();
    char byte = 0;
    fread(&byte, 1, 1, f_stdout);
    cr_log_info("%u\n", byte & 0xff);  
    cr_assert_eq(byte & 0xff, 1);
    cr_assert_stdout_eq_str("\0x1");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_putchar_my_printf_c2, .init=redirect, .timeout=1)
{
    my_printf("%c", 500);
    FILE *f_stdout = cr_get_redirected_stdout();
    char byte = 0;
    fread(&byte, 1, 1, f_stdout);
    cr_log_info("%u\n", byte & 0xff);  
    cr_assert_eq(byte & 0xff, 244);
}

Test(my_printf, default_my_putchar_my_printf_c3, .init=redirect, .timeout=1)
{
    int value = my_printf("%c", -500);
    FILE *f_stdout = cr_get_redirected_stdout();
    char byte = 0;
    fread(&byte, 1, 1, f_stdout);
    cr_log_info("%u\n", byte & 0xff);  
    cr_assert_eq(byte & 0xff, 12);
    cr_assert_stdout_eq_str("\0xc");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_putchar_my_printf_c4, .init=redirect, .timeout=1)
{
    my_printf("%c", 255);
    FILE *f_stdout = cr_get_redirected_stdout();
    char byte = 0;
    fread(&byte, 1, 1, f_stdout);
    cr_log_info("%u\n", byte & 0xff);  
    cr_assert_eq(byte & 0xff, 255);
}

Test(my_printf, default_my_putchar_my_printf_c5, .init=redirect, .timeout=1)
{
    int value = my_printf("%c", 256);
    FILE *f_stdout = cr_get_redirected_stdout();
    char byte = 0;
    fread(&byte, 1, 1, f_stdout);
    cr_log_info("%u\n", byte & 0xff);  
    cr_assert_eq(byte & 0xff, 0);
    cr_assert_stdout_eq_str("\000");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_putchar_my_printf_c6, .init=redirect, .timeout=1)
{
    int value = my_printf("%c", 257);
    FILE *f_stdout = cr_get_redirected_stdout();
    char byte = 0;
    fread(&byte, 1, 1, f_stdout);
    cr_log_info("%u\n", byte & 0xff);  
    cr_assert_eq(byte & 0xff, 1);
    cr_assert_stdout_eq_str("\0x1");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_putchar_my_printf_c7, .init=redirect, .timeout=1)
{
    my_printf("%c", -255);
    FILE *f_stdout = cr_get_redirected_stdout();
    char byte = 0;
    fread(&byte, 1, 1, f_stdout);
    cr_log_info("%u\n", byte & 0xff);  
    cr_assert_eq(byte & 0xff, 1);
}

Test(my_printf, default_my_putchar_my_printf_c8, .init=redirect, .timeout=1)
{
    int value = my_printf("%c", -256);
    FILE *f_stdout = cr_get_redirected_stdout();
    char byte = 0;
    fread(&byte, 1, 1, f_stdout);
    cr_log_info("%u\n", byte & 0xff);  
    cr_assert_eq(byte & 0xff, 0);
    cr_assert_stdout_eq_str("\000");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_putchar_my_printf_c9, .init=redirect, .timeout=1)
{
    my_printf("%c", -257);
    FILE *f_stdout = cr_get_redirected_stdout();
    char byte = 0;
    fread(&byte, 1, 1, f_stdout);
    cr_log_info("%u\n", byte & 0xff);  
    cr_assert_eq(byte & 0xff, 255);
}

Test(my_printf, default_my_putchar_my_printf_c10, .init=redirect, .timeout=1)
{
    my_printf("%c", -1);
    FILE *f_stdout = cr_get_redirected_stdout();
    char byte = 0;
    fread(&byte, 1, 1, f_stdout);
    cr_log_info("%u\n", byte & 0xff);  
    cr_assert_eq(byte & 0xff, 255);
}

Test(my_printf, default_my_putchar_my_printf_c11, .init=redirect, .timeout=1)
{
    int value = my_printf("%c", 12597);
    FILE *f_stdout = cr_get_redirected_stdout();
    char byte = 0;
    fread(&byte, 1, 1, f_stdout);
    cr_log_info("%u\n", byte & 0xff);  
    cr_assert_eq(byte & 0xff, 53);
    cr_assert_stdout_eq_str("\0x35");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_putchar_my_printf_c12, .init=redirect, .timeout=1)
{
    my_printf("%c", -12597);
    FILE *f_stdout = cr_get_redirected_stdout();
    char byte = 0;
    fread(&byte, 1, 1, f_stdout);
    cr_log_info("%u\n", byte & 0xff);  
    cr_assert_eq(byte & 0xff, 203);
}

Test(my_printf, default_my_putchar_my_printf_c13, .init=redirect, .timeout=1)
{
    int value = my_printf("%c", '\n');
    FILE *f_stdout = cr_get_redirected_stdout();
    char byte = 0;
    fread(&byte, 1, 1, f_stdout);
    cr_log_info("%u\n", byte & 0xff);  
    cr_assert_eq(byte & 0xff, 10);
    cr_assert_stdout_eq_str("\0xc");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_putchar_my_printf_c14, .init=redirect, .timeout=1)
{
    int value = my_printf("%c", 127);
    FILE *f_stdout = cr_get_redirected_stdout();
    char byte = 0;
    fread(&byte, 1, 1, f_stdout);
    cr_log_info("%u\n", byte & 0xff);  
    cr_assert_eq(byte & 0xff, 127);
    cr_assert_stdout_eq_str("\0x7f");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_scnotation_e0, .init=redirect, .timeout=1)
{
    int value = my_printf("%.0e", 45.2f);
    cr_assert_stdout_eq_str("5e+01");
    cr_assert_eq(value, 5);
}

Test(my_printf, default_scnotation_e1, .init=redirect, .timeout=1)
{
    int value = my_printf("%e", 0.2f);
    cr_assert_stdout_eq_str("2.000000e-01");
    cr_assert_eq(value, 12);
}

Test(my_printf, default_scnotation_e2, .init=redirect, .timeout=1)
{
    int value = my_printf("%.3e", 4.52f);
    cr_assert_stdout_eq_str("4.520e+00");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_scnotation_e3, .init=redirect, .timeout=1)
{
    int value = my_printf("%e", 5.0f);
    cr_assert_stdout_eq_str("5.000000e+00");
    cr_assert_eq(value, 12);
}

Test(my_printf, default_scnotation_e4, .init=redirect, .timeout=1)
{
    int value = my_printf("%e", 0.0f);
    cr_assert_stdout_eq_str("0.000000e+00");
    cr_assert_eq(value, 12);
}

Test(my_printf, default_scnotation_e5, .init=redirect, .timeout=1)
{
    int value = my_printf("%e", -5.0f);
    cr_assert_stdout_eq_str("-5.000000e+00");
    cr_assert_eq(value, 12);
}

Test(my_printf, default_scnotation_e6, .init=redirect, .timeout=1)
{
    int value = my_printf("%e", 0.000000000005f);
    cr_assert_stdout_eq_str("5.000000e-12");
    cr_assert_eq(value, 12);
}

Test(my_printf, default_scnotation_e7, .init=redirect, .timeout=1)
{
    int value = my_printf("%e", 12345678900.0F);
    cr_assert_stdout_eq_str("1.234568e+10");
    cr_assert_eq(value, 12);
}

Test(my_printf, default_putfloat_f0, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 0.0);
    cr_assert_stdout_eq_str("0.000000");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putfloat_f1, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", -0.0);
    cr_assert_stdout_eq_str("0.000000");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putfloat_f2, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 1.1);
    cr_assert_stdout_eq_str("1.100000");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putfloat_f3, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", -1.1);
    cr_assert_stdout_eq_str("-1.100000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f4, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 12.0);
    cr_assert_stdout_eq_str("12.000000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f5, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", -12.0);
    cr_assert_stdout_eq_str("-12.000000");
    cr_assert_eq(value, 10);
}

Test(my_printf, default_putfloat_f6, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f7, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f8, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f9, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f10, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

/* ------------------------------------------------------------- */

Test(my_printf, default_putfloat_f11, .init=redirect, .timeout=1)
{
    int value = my_printf("%.4f", 1.324654);
    cr_assert_stdout_eq_str("1.3247");
    cr_assert_eq(value, 6);
}

Test(my_printf, default_putfloat_f12, .init=redirect, .timeout=1)
{
    int value = my_printf("%.4f", -1.324654);
    cr_assert_stdout_eq_str("-1.3247");
    cr_assert_eq(value, 7);
}

Test(my_printf, default_putfloat_f13, .init=redirect, .timeout=1)
{
    my_printf("%.f", 42.42);
}

Test(my_printf, default_putfloat_f14, .init=redirect, .timeout=1)
{
    my_printf("%.f", -42.42);
}

Test(my_printf, default_putfloat_f15, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f16, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f17, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f18, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f19, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f20, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

/* ------------------------------------------------------------- */

Test(my_printf, default_putfloat_f21, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f22, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f23, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f24, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f25, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f26, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f27, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f28, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f29, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f30, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

/* ------------------------------------------------------------- */

Test(my_printf, default_putfloat_f31, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f32, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f33, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f34, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putfloat_f35, .init=redirect, .timeout=1)
{
    int value = my_printf("%f", 42.2f);
    cr_assert_stdout_eq_str("42.200000");
    cr_assert_eq(value, 9);
}

Test(my_printf, default_putnbr_i0, .init=redirect, .timeout=1)
{
    int value = my_printf("%i", 0);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_i1, .init=redirect, .timeout=1)
{
    int value = my_printf("%i", 1);
    cr_assert_stdout_eq_str("1");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_i2, .init=redirect, .timeout=1)
{
    int value = my_printf("%i", 42);
    cr_assert_stdout_eq_str("42");
    cr_assert_eq(value, 2);
}
    
Test(my_printf, default_putnbr_i3, .init=redirect, .timeout=1)
{
    int value = my_printf("%i", 424344);
    cr_assert_stdout_eq_str("424344");
    cr_assert_eq(value, 6);
}

Test(my_printf, default_putnbr_i4, .init=redirect, .timeout=1)
{
    int value = my_printf("%i", 2147483647);
    cr_assert_stdout_eq_str("2147483647");
    cr_assert_eq(value, 10);
} 

Test(my_printf, default_putnbr_i5, .init=redirect, .timeout=1)
{
    int value = my_printf("%i", 2147483648);
    cr_assert_stdout_eq_str("-2147483648");
    cr_assert_eq(value, 11);
} 

Test(my_printf, default_putnbr_i6, .init=redirect, .timeout=1)
{
    int value = my_printf("%i", -1);
    cr_assert_stdout_eq_str("-1");
    cr_assert_eq(value, 2);
} 

Test(my_printf, default_putnbr_i7, .init=redirect, .timeout=1)
{
    int value = my_printf("%i", -42);
    cr_assert_stdout_eq_str("-42");
    cr_assert_eq(value, 3);
} 

Test(my_printf, default_putnbr_i8, .init=redirect, .timeout=1)
{
    int value = my_printf("%i", -424344);
    cr_assert_stdout_eq_str("-424344");
    cr_assert_eq(value, 7);
} 

Test(my_printf, default_putnbr_i9, .init=redirect, .timeout=1)
{
    int value = my_printf("%i", -2147483648);
    cr_assert_stdout_eq_str("-2147483648");
    cr_assert_eq(value, 11);
} 

Test(my_printf, default_putnbr_i10, .init=redirect, .timeout=1)
{
    int value = my_printf("%i", -2147483649);
    cr_assert_stdout_eq_str("2147483647");
    cr_assert_eq(value, 10);
} 

Test(my_printf, default_putnbr_i11, .init=redirect, .timeout=1)
{
    int value = my_printf("%i", '0');
    cr_assert_stdout_eq_str("48");
    cr_assert_eq(value, 2);
} 

Test(my_printf, default_putnbr_i12, .init=redirect, .timeout=1)
{
    int value = my_printf("%i", 'a');
    cr_assert_stdout_eq_str("97");
    cr_assert_eq(value, 2);
}  

Test(my_printf, default_putnbr_i13, .init=redirect, .timeout=1)
{
    int value = my_printf("%i", '\n');
    cr_assert_stdout_eq_str("10");
    cr_assert_eq(value, 2);
}  

Test(my_printf, default_putnbr_o0, .init=redirect, .timeout=1)
{
    int value = my_printf("%o", 0);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_o1, .init=redirect, .timeout=1)
{
    int value = my_printf("%o", -0);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_o2, .init=redirect, .timeout=1)
{
    int value = my_printf("%o", 1);
    cr_assert_stdout_eq_str("1");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_o3, .init=redirect, .timeout=1)
{
    int value = my_printf("%o", 42);
    cr_assert_stdout_eq_str("52");
    cr_assert_eq(value, 2);
}

Test(my_printf, default_putnbr_o4, .init=redirect, .timeout=1)
{
    int value = my_printf("%o", 424344);
    cr_assert_stdout_eq_str("1474630");
    cr_assert_eq(value, 7);
}

Test(my_printf, default_putnbr_o5, .init=redirect, .timeout=1)
{
    int value = my_printf("%o", 2147483647);
    cr_assert_stdout_eq_str("17777777777");
    cr_assert_eq(value, 11);
}

Test(my_printf, default_putnbr_o6, .init=redirect, .timeout=1)
{
    int value = my_printf("%o", 4294967295);
    cr_assert_stdout_eq_str("37777777777");
    cr_assert_eq(value, 11);
}

Test(my_printf, default_putnbr_o7, .init=redirect, .timeout=1)
{
    int value = my_printf("%o", 4294967296);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_o8, .init=redirect, .timeout=1)
{
    int value = my_printf("%o", -1);
    cr_assert_stdout_eq_str("37777777777");
    cr_assert_eq(value, 11);
}

Test(my_printf, default_putnbr_o9, .init=redirect, .timeout=1)
{
    int value = my_printf("%o", -42);
    cr_assert_stdout_eq_str("37777777726");
    cr_assert_eq(value, 11);
}

Test(my_printf, default_putnbr_o10, .init=redirect, .timeout=1)
{
    int value = my_printf("%o", -424344);
    cr_assert_stdout_eq_str("37776303150");
    cr_assert_eq(value, 11);
}

Test(my_printf, default_putnbr_o11, .init=redirect, .timeout=1)
{
    int value = my_printf("%o", -2147483647);
    cr_assert_stdout_eq_str("20000000001");
    cr_assert_eq(value, 11);
}

Test(my_printf, default_putnbr_o12, .init=redirect, .timeout=1)
{
    int value = my_printf("%o", -4294967295);
    cr_assert_stdout_eq_str("1");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_o13, .init=redirect, .timeout=1)
{
    int value = my_printf("%o", -4294967296);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_o14, .init=redirect, .timeout=1)
{
    int value = my_printf("%o", '0');
    cr_assert_stdout_eq_str("60");
    cr_assert_eq(value, 2);
}

Test(my_printf, default_putnbr_o15, .init=redirect, .timeout=1)
{
    int value = my_printf("%o", 'a');
    cr_assert_stdout_eq_str("141");
    cr_assert_eq(value, 3);
}

Test(my_printf, default_putnbr_o16, .init=redirect, .timeout=1)
{
    int value = my_printf("%o", '\n');
    cr_assert_stdout_eq_str("12");
    cr_assert_eq(value, 2);
}

Test(my_printf, default_my_putstr_s0, .init=redirect, .timeout=1)
{
    int value = my_printf("%s", "TEST");
    cr_assert_stdout_eq_str("TEST");
    cr_assert_eq(value, 4);
}

Test(my_printf, default_my_putstr_s1, .init=redirect, .timeout=1)
{
    int value = my_printf("%s", "test");
    cr_assert_stdout_eq_str("test");
    cr_assert_eq(value, 4);
}

Test(my_printf, default_my_putstr_s2, .init=redirect, .timeout=1)
{
    int value = my_printf("%s", "test n\n");
    cr_assert_stdout_eq_str("test n\n");
    cr_assert_eq(value, 7);
}

Test(my_printf, default_my_putstr_s3, .init=redirect, .timeout=1)
{
    int value = my_printf("%s", "    ");
    cr_assert_stdout_eq_str("    ");
    cr_assert_eq(value, 4);
}

Test(my_printf, default_my_putstr_s4, .init=redirect, .timeout=1)
{
    int value = my_printf("%s", "0123456789");
    cr_assert_stdout_eq_str("0123456789");
    cr_assert_eq(value, 10);
}

Test(my_printf, default_my_putstr_s5, .init=redirect, .timeout=1)
{
    int value = my_printf("%s", "\t\a\010\0");
    cr_assert_stdout_eq_str("\t\a\010");
    cr_assert_eq(value, 3);
}

Test(my_printf, default_my_putstr_s6, .init=redirect, .timeout=1)
{
    int value = my_printf("%s", "Hello World");
    cr_assert_stdout_eq_str("Hello World");
    cr_assert_eq(value, 11);
}

Test(my_printf, default_my_putstr_s7, .init=redirect, .timeout=1)
{
    int value = my_printf("%s", "Hello 42 World");
    cr_assert_stdout_eq_str("Hello 42 World");
    cr_assert_eq(value, 14);
}

Test(my_printf, default_my_putstr_s8, .init=redirect, .timeout=1)
{
    int value = my_printf("%s", "0x888");
    cr_assert_stdout_eq_str("0x888");
    cr_assert_eq(value, 5);
}

Test(my_printf, default_my_putstr_s9, .init=redirect, .timeout=1)
{
    int value = my_printf("%s", "\109\100");
    cr_assert_stdout_eq_str("\109\100");
    cr_assert_eq(value, 3);
}

Test(my_printf, default_my_putstr_s10, .init=redirect, .timeout=1)
{
    int value = my_printf("Hello %s World", "Wolrd | World");
    cr_assert_stdout_eq_str("Hello Wolrd | World World");
    cr_assert_eq(value, 25);
}

Test(my_printf, default_my_putstr_s11, .init=redirect, .timeout=1)
{
    int value = my_printf("%%%% Hello World 42 %%d %s %%", "hi");
    cr_assert_stdout_eq_str("%% Hello World 42 %d hi %");
    cr_assert_eq(value, 25);
}

Test(my_printf, default_my_bigs_S0, .init=redirect, .timeout=1)
{
    char str[] = {'a','\0'};
    int value = my_printf("%S", str);
    cr_assert_stdout_eq_str("a");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_bigs_S1, .init=redirect, .timeout=1)
{
    char str[] = {'z','\0'};
    int value = my_printf("%S", str);
    cr_assert_stdout_eq_str("z");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_bigs_S2, .init=redirect, .timeout=1)
{
    char str[] = {'A','\0'};
    int value = my_printf("%S", str);
    cr_assert_stdout_eq_str("A");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_bigs_S3, .init=redirect, .timeout=1)
{
    char str[] = {'Z','\0'};
    int value = my_printf("%S", str);
    cr_assert_stdout_eq_str("Z");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_bigs_S4, .init=redirect, .timeout=1)
{
    char str[] = { 35 ,'\0'};
    int value = my_printf("%S", str);
    cr_assert_stdout_eq_str("#");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_bigs_S5, .init=redirect, .timeout=1)
{
    char str[] = { 50 ,'\0'};
    int value = my_printf("%S", str);
    cr_assert_stdout_eq_str("2");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_bigs_S6, .init=redirect, .timeout=1)
{
    char str[] = { 81 ,'\0'};
    int value = my_printf("%S", str);
    cr_assert_stdout_eq_str("Q");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_bigs_S7, .init=redirect, .timeout=1)
{
    char str[] = { 69 ,'\0'};
    int value = my_printf("%S", str);
    cr_assert_stdout_eq_str("E");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_bigs_S8, .init=redirect, .timeout=1)
{
    char str[] = { 7,'\0'};
    int value = my_printf("%S", str);
    cr_assert_stdout_eq_str("\\007");
    cr_assert_eq(value, 4);
}

Test(my_printf, default_my_bigs_S9, .init=redirect, .timeout=1)
{
    char str[] = { 9,'\0'};
    int value = my_printf("%S", str);
    cr_assert_stdout_eq_str("\\011");
    cr_assert_eq(value, 4);
}

Test(my_printf, default_my_bigs_S10, .init=redirect, .timeout=1)
{
    char str[] = {127,'\0'};
    int value = my_printf("%S", str);
    cr_assert_stdout_eq_str("\\177");
    cr_assert_eq(value, 4);
}

Test(my_printf, default_my_bigs_S11, .init=redirect, .timeout=1)
{
    char str[] = {'h','e', 127,'a','\0'};
    int value = my_printf("%S", str);
    cr_assert_stdout_eq_str("he\\177a");
    cr_assert_eq(value, 7);
}

Test(my_printf, default_my_bigs_S12, .init=redirect, .timeout=1)
{
    char str[] = {'a', 'e','\0'};
    int value = my_printf("%S", str);
    cr_assert_stdout_eq_str("ae");
    cr_assert_eq(value, 2);
}

Test(my_printf, default_my_bigs_S13, .init=redirect, .timeout=1)
{
    char str[] = {'a','\0'};
    int value = my_printf("%S", str);
    cr_assert_stdout_eq_str("a");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_bigs_S14, .init=redirect, .timeout=1)
{
    char str[] = {'a','\0'};
    int value = my_printf("%S", str);
    cr_assert_stdout_eq_str("a");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_bigs_S15, .init=redirect, .timeout=1)
{
    char str[] = {'a','\0'};
    int value = my_printf("%S", str);
    cr_assert_stdout_eq_str("a");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_bigs_S16, .init=redirect, .timeout=1)
{
    char str[] = {'a','\0'};
    int value = my_printf("%S", str);
    cr_assert_stdout_eq_str("a");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_my_bigs_S17, .init=redirect, .timeout=1)
{
    char str[] = {126,'\0'};
    int value = my_printf("%S", str);
    cr_assert_stdout_eq_str("~");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_u0, .init=redirect, .timeout=1)
{
    int value = my_printf("%u", 0);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_u1, .init=redirect, .timeout=1)
{
    int value = my_printf("%u", 1);
    cr_assert_stdout_eq_str("1");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_u2, .init=redirect, .timeout=1)
{
    int value = my_printf("%u", 42);
    cr_assert_stdout_eq_str("42");
    cr_assert_eq(value, 2);
}

Test(my_printf, default_putnbr_u3, .init=redirect, .timeout=1)
{
    int value = my_printf("%u", 424344);
    cr_assert_stdout_eq_str("424344");
    cr_assert_eq(value, 6);
}

Test(my_printf, default_putnbr_u4, .init=redirect, .timeout=1)
{
    int value = my_printf("%u", 2147483647);
    cr_assert_stdout_eq_str("2147483647");
    cr_assert_eq(value, 10);
}

Test(my_printf, default_putnbr_u5, .init=redirect, .timeout=1)
{
    int value = my_printf("%u", 2147483648);
    cr_assert_stdout_eq_str("2147483648");
    cr_assert_eq(value, 10);
}

Test(my_printf, default_putnbr_u6, .init=redirect, .timeout=1)
{
    int value = my_printf("%u", 4294967295);
    cr_assert_stdout_eq_str("4294967295");
    cr_assert_eq(value, 10);
}

Test(my_printf, default_putnbr_u7, .init=redirect, .timeout=1)
{
    int value = my_printf("%u", 4294967296);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_u8, .init=redirect, .timeout=1)
{
    int value = my_printf("%u", 4294967297);
    cr_assert_stdout_eq_str("1");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_u9, .init=redirect, .timeout=1)
{
    int value = my_printf("%u", -0);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_u10, .init=redirect, .timeout=1)
{
    int value = my_printf("%u", -1);
    cr_assert_stdout_eq_str("4294967295");
    cr_assert_eq(value, 10);
}

Test(my_printf, default_putnbr_u11, .init=redirect, .timeout=1)
{
    int value = my_printf("%u", -42);
    cr_assert_stdout_eq_str("4294967254");
    cr_assert_eq(value, 10);
}

Test(my_printf, default_putnbr_u12, .init=redirect, .timeout=1)
{
    int value = my_printf("%u", -424344);
    cr_assert_stdout_eq_str("4294542952");
    cr_assert_eq(value, 10);
}

Test(my_printf, default_putnbr_u13, .init=redirect, .timeout=1)
{
    int value = my_printf("%u", -2147483647);
    cr_assert_stdout_eq_str("2147483649");
    cr_assert_eq(value, 10);
}

Test(my_printf, default_putnbr_u14, .init=redirect, .timeout=1)
{
    int value = my_printf("%u", -2147483648);
    cr_assert_stdout_eq_str("2147483648");
    cr_assert_eq(value, 10);
}

Test(my_printf, default_putnbr_u15, .init=redirect, .timeout=1)
{
    int value = my_printf("%u", -4294967295);
    cr_assert_stdout_eq_str("1");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_u16, .init=redirect, .timeout=1)
{
    int value = my_printf("%u", -4294967296);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_u17, .init=redirect, .timeout=1)
{
    int value = my_printf("%u", -4294967297);
    cr_assert_stdout_eq_str("4294967295");
    cr_assert_eq(value, 10);
}

Test(my_printf, default_putnbr_x0, .init=redirect, .timeout=1)
{
    int value = my_printf("%x", 0);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_x1, .init=redirect, .timeout=1)
{
    int value = my_printf("%x", 1);
    cr_assert_stdout_eq_str("1");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_x2, .init=redirect, .timeout=1)
{
    int value = my_printf("%x", 42);
    cr_assert_stdout_eq_str("2a");
    cr_assert_eq(value, 2);
}

Test(my_printf, default_putnbr_x3, .init=redirect, .timeout=1)
{
    int value = my_printf("%x", 424344);
    cr_assert_stdout_eq_str("67998");
    cr_assert_eq(value, 5);
}

Test(my_printf, default_putnbr_x4, .init=redirect, .timeout=1)
{
    int value = my_printf("%x", 2147483647);
    cr_assert_stdout_eq_str("7fffffff");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putnbr_x5, .init=redirect, .timeout=1)
{
    int value = my_printf("%x", 2147483648);
    cr_assert_stdout_eq_str("80000000");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putnbr_x6, .init=redirect, .timeout=1)
{
    int value = my_printf("%x", 4294967295);
    cr_assert_stdout_eq_str("ffffffff");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putnbr_x7, .init=redirect, .timeout=1)
{
    int value = my_printf("%x", 4294967296);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_x8, .init=redirect, .timeout=1)
{
    int value = my_printf("%x", 4294967297);
    cr_assert_stdout_eq_str("1");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_x9, .init=redirect, .timeout=1)
{
    int value = my_printf("%x", -0);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_x10, .init=redirect, .timeout=1)
{
    int value = my_printf("%x", -1);
    cr_assert_stdout_eq_str("ffffffff");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putnbr_x11, .init=redirect, .timeout=1)
{
    int value = my_printf("%x", -42);
    cr_assert_stdout_eq_str("ffffffd6");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putnbr_x12, .init=redirect, .timeout=1)
{
    int value = my_printf("%x", -424344);
    cr_assert_stdout_eq_str("fff98668");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putnbr_x13, .init=redirect, .timeout=1)
{
    int value = my_printf("%x", -2147483647);
    cr_assert_stdout_eq_str("80000001");
    fflush(stdout);
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putnbr_x14, .init=redirect, .timeout=1)
{
    int value = my_printf("%x", -2147483648);
    cr_assert_stdout_eq_str("80000000");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putnbr_x15, .init=redirect, .timeout=1)
{
    int value = my_printf("%x", -4294967295);
    cr_assert_stdout_eq_str("1");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_x16, .init=redirect, .timeout=1)
{
    int value = my_printf("%x", -4294967296);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_x17, .init=redirect, .timeout=1)
{
    int value = my_printf("%x", -4294967297);
    cr_assert_stdout_eq_str("ffffffff");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putnbr_X0, .init=redirect, .timeout=1)
{
    int value = my_printf("%X", 0);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_X1, .init=redirect, .timeout=1)
{
    int value = my_printf("%X", 1);
    cr_assert_stdout_eq_str("1");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_X2, .init=redirect, .timeout=1)
{
    int value = my_printf("%X", 42);
    cr_assert_stdout_eq_str("2A");
    cr_assert_eq(value, 2);
}

Test(my_printf, default_putnbr_X3, .init=redirect, .timeout=1)
{
    int value = my_printf("%X", 424344);
    cr_assert_stdout_eq_str("67998");
    cr_assert_eq(value, 5);
}

Test(my_printf, default_putnbr_X4, .init=redirect, .timeout=1)
{
    int value = my_printf("%X", 2147483647);
    cr_assert_stdout_eq_str("7FFFFFFF");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putnbr_X5, .init=redirect, .timeout=1)
{
    int value = my_printf("%X", 2147483648);
    cr_assert_stdout_eq_str("80000000");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putnbr_X6, .init=redirect, .timeout=1)
{
    int value = my_printf("%X", 4294967295);
    cr_assert_stdout_eq_str("FFFFFFFF");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putnbr_X7, .init=redirect, .timeout=1)
{
    int value = my_printf("%X", 4294967296);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_X8, .init=redirect, .timeout=1)
{
    int value = my_printf("%X", 4294967297);
    cr_assert_stdout_eq_str("1");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_X9, .init=redirect, .timeout=1)
{
    int value = my_printf("%X", -0);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_X10, .init=redirect, .timeout=1)
{
    int value = my_printf("%X", -1);
    cr_assert_stdout_eq_str("FFFFFFFF");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putnbr_X11, .init=redirect, .timeout=1)
{
    int value = my_printf("%X", -42);
    cr_assert_stdout_eq_str("FFFFFFD6");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putnbr_X12, .init=redirect, .timeout=1)
{
    int value = my_printf("%X", -424344);
    cr_assert_stdout_eq_str("FFF98668");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putnbr_X13, .init=redirect, .timeout=1)
{
    int value = my_printf("%X", -2147483647);
    cr_assert_stdout_eq_str("80000001");
    fflush(stdout);
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putnbr_X14, .init=redirect, .timeout=1)
{
    int value = my_printf("%X", -2147483648);
    cr_assert_stdout_eq_str("80000000");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_putnbr_X15, .init=redirect, .timeout=1)
{
    int value = my_printf("%X", -4294967295);
    cr_assert_stdout_eq_str("1");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_X16, .init=redirect, .timeout=1)
{
    int value = my_printf("%X", -4294967296);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_X17, .init=redirect, .timeout=1)
{
    int value = my_printf("%X", -4294967297);
    cr_assert_stdout_eq_str("FFFFFFFF");
    cr_assert_eq(value, 8);
}

Test(my_printf, default_flags_finder_00, .init=redirect, .timeout=1)
{
    int value = my_printf("%#0+- ");
    cr_assert_stdout_eq_str("%#0+- ");
    cr_assert_eq(value, 6);
}

Test(my_printf, default_flags_finder_01, .init=redirect, .timeout=1)
{
    int value = my_printf("%4");
    cr_assert_stdout_eq_str("%4");
    cr_assert_eq(value, 2);
}

Test(my_printf, default_flags_finder_02, .init=redirect, .timeout=1)
{
    int value = my_printf("%42-");
    cr_assert_stdout_eq_str("%42-");
    cr_assert_eq(value, 4);
}

Test(my_printf, default_flags_finder_03, .init=redirect, .timeout=1)
{
    int value = my_printf("%.");
    cr_assert_stdout_eq_str("%.");
    cr_assert_eq(value, 2);
}

Test(my_printf, default_flags_finder_04, .init=redirect, .timeout=1)
{
    int value = my_printf("%.4;");
    cr_assert_stdout_eq_str("%.4;");
    cr_assert_eq(value, 4);
}

Test(my_printf, default_flags_finder_05, .init=redirect, .timeout=1)
{
    int value = my_printf("%.44-");
    cr_assert_stdout_eq_str("%.44-");
    cr_assert_eq(value, 5);
}

Test(my_printf, default_flags_finder_06, .init=redirect, .timeout=1)
{
    int value = my_printf("%hh");
    cr_assert_stdout_eq_str("%hh");
    cr_assert_eq(value, 3);
}

Test(my_printf, default_flags_finder_07, .init=redirect, .timeout=1)
{
    int value = my_printf("%h");
    cr_assert_stdout_eq_str("%h");
    cr_assert_eq(value, 2);
}

Test(my_printf, default_flags_finder_08, .init=redirect, .timeout=1)
{
    int value = my_printf("%l");
    cr_assert_stdout_eq_str("%l");
    cr_assert_eq(value, 2);
}

Test(my_printf, default_flags_finder_09, .init=redirect, .timeout=1)
{
    int value = my_printf("%ll");
    cr_assert_stdout_eq_str("%ll");
    cr_assert_eq(value, 3);
}

Test(my_printf, default_flags_finder_010, .init=redirect, .timeout=1)
{
    int value = my_printf("%L");
    cr_assert_stdout_eq_str("%L");
    cr_assert_eq(value, 2);
}

Test(my_printf, default_flags_finder_011, .init=redirect, .timeout=1)
{
    int value = my_printf("%j");
    cr_assert_stdout_eq_str("%j");
    cr_assert_eq(value, 2);
}

Test(my_printf, default_flags_finder_012, .init=redirect, .timeout=1)
{
    int value = my_printf("%j");
    cr_assert_stdout_eq_str("%j");
    cr_assert_eq(value, 2);
}

Test(my_printf, default_flags_finder_013, .init=redirect, .timeout=1)
{
    int value = my_printf("%z");
    cr_assert_stdout_eq_str("%z");
    cr_assert_eq(value, 2);
}

Test(my_printf, default_flags_finder_014, .init=redirect, .timeout=1)
{
    int value = my_printf("%t");
    cr_assert_stdout_eq_str("%t");
    cr_assert_eq(value, 2);
}

Test(my_printf, default_flags_finder_015, .init=redirect, .timeout=1)
{
    int value = my_printf("%");
    cr_assert_stdout_eq_str("%");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_flags_finder_016, .init=redirect, .timeout=1)
{
    int value = my_printf("%%");
    cr_assert_stdout_eq_str("%");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_flags_finder_017, .init=redirect, .timeout=1)
{
    int value = my_printf("%%%");
    cr_assert_stdout_eq_str("%%");
    cr_assert_eq(value, 2);
}

Test(my_printf, default_flags_finder_018, .init=redirect, .timeout=1)
{
    int value = my_printf("%-44");
    cr_assert_stdout_eq_str("%-44");
    cr_assert_eq(value, 4);
}

Test(my_printf, default_flags_finder_019, .init=redirect, .timeout=1)
{
    int value = my_printf("%.-44");
    cr_assert_stdout_eq_str("%.-44");
    cr_assert_eq(value, 5);
}
///////////////////////////////////////////////////////////////////////////////////////
Test(my_printf, default_flags_finder_020, .init=redirect, .timeout=1)
{
    int value = my_printf("%#o", 42);
    cr_assert_stdout_eq_str("052");
    cr_assert_eq(value, 3);
}

Test(my_printf, default_flags_finder_021, .init=redirect, .timeout=1)
{
    int value = my_printf("%#x", 42);
    cr_assert_stdout_eq_str("0x2a");
    cr_assert_eq(value, 4);
}

Test(my_printf, default_flags_finder_022, .init=redirect, .timeout=1)
{
    int value = my_printf("%#b", 24);
    cr_assert_stdout_eq_str("0b11000");
    cr_assert_eq(value, 7);
}

Test(my_printf, default_flags_finder_023, .init=redirect, .timeout=1)
{
    int value = my_printf("%+d", 42);
    cr_assert_stdout_eq_str("+42");
    cr_assert_eq(value, 3);
}

Test(my_printf, default_flags_finder_024, .init=redirect, .timeout=1)
{
    int value = my_printf("%#d", -42);
    cr_assert_stdout_eq_str("-42");
    cr_assert_eq(value, 3);
}

Test(my_printf, default_flags_finder_025, .init=redirect, .timeout=1)
{
    int value = my_printf("%+d", -42);
    cr_assert_stdout_eq_str("-42");
    cr_assert_eq(value, 3);
}

Test(my_printf, default_flags_finder_026, .init=redirect, .timeout=1)
{
    int value = my_printf("%#+o", 42);
    cr_assert_stdout_eq_str("052");
    cr_assert_eq(value, 3);
}

Test(my_printf, default_format_0, .init=redirect, .timeout=1)
{
    int value = my_printf("Hello World!");
    cr_assert_stdout_eq_str("Hello World!");
    cr_assert_eq(value, 12);
}

Test(my_printf, default_format_1, .init=redirect, .timeout=1)
{
    int value = my_printf("Hello World!%");
    cr_assert_stdout_eq_str("Hello World!%");
    cr_assert_eq(value, 13);
}

Test(my_printf, default_format_2, .init=redirect, .timeout=1)
{
    int value = my_printf("Hello World %%%");
    cr_assert_stdout_eq_str("Hello World %%");
    cr_assert_eq(value, 14);
}

Test(my_printf, default_format_3, .init=redirect, .timeout=1)
{
    int value = my_printf("Hello 44 World %%%");
    cr_assert_stdout_eq_str("Hello 44 World %%");
    cr_assert_eq(value, 17);
}

Test(my_printf, default_format_4, .init=redirect, .timeout=1)
{
    int value = my_printf("Hello 44 World %%%");
    cr_assert_stdout_eq_str("Hello 44 World %%");
    cr_assert_eq(value, 17);
}

Test(my_printf, default_format_5, .init=redirect, .timeout=1)
{
    int value = my_printf("Hello 44 World %%%");
    cr_assert_stdout_eq_str("Hello 44 World %%");
    cr_assert_eq(value, 17);
}

Test(my_printf, default_little_n0, .init=redirect, .timeout=1)
{
    int n = 0;
    int value = my_printf("Hello %n", &n);
    cr_assert_stdout_eq_str("Hello ");
    cr_assert_eq(value, 6);
    cr_assert_eq(value, n);
}

Test(my_printf, default_little_pony_p0, .init=redirect, .timeout=1)
{
    int n = 42;
    char *toto = NULL;
    char str[25];
    my_printf("%p", &n);
    read(1, &str, 24);
    strtol(str, &toto, 16);
}


Test(my_printf, default_putnbr_d0, .init=redirect, .timeout=1)
{
    int value = my_printf("%d", 0);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_d1, .init=redirect, .timeout=1)
{
    int value = my_printf("%d", 1);
    cr_assert_stdout_eq_str("1");
    cr_assert_eq(value, 1);
}

Test(my_printf, default_putnbr_d2, .init=redirect, .timeout=1)
{
    int value = my_printf("%d", 42);
    cr_assert_stdout_eq_str("42");
    cr_assert_eq(value, 2);
}
    
Test(my_printf, default_putnbr_d3, .init=redirect, .timeout=1)
{
    int value = my_printf("%d", 424344);
    cr_assert_stdout_eq_str("424344");
    cr_assert_eq(value, 6);
}

Test(my_printf, default_putnbr_d4, .init=redirect, .timeout=1)
{
    int value = my_printf("%d", 2147483647);
    cr_assert_stdout_eq_str("2147483647");
    cr_assert_eq(value, 10);
} 

Test(my_printf, default_putnbr_d5, .init=redirect, .timeout=1)
{
    int value = my_printf("%d", 2147483648);
    cr_assert_stdout_eq_str("-2147483648");
    cr_assert_eq(value, 11);
} 

Test(my_printf, default_putnbr_d6, .init=redirect, .timeout=1)
{
    int value = my_printf("%d", -1);
    cr_assert_stdout_eq_str("-1");
    cr_assert_eq(value, 2);
} 

Test(my_printf, default_putnbr_d7, .init=redirect, .timeout=1)
{
    int value = my_printf("%d", -42);
    cr_assert_stdout_eq_str("-42");
    cr_assert_eq(value, 3);
} 

Test(my_printf, default_putnbr_d8, .init=redirect, .timeout=1)
{
    int value = my_printf("%d", -424344);
    cr_assert_stdout_eq_str("-424344");
    cr_assert_eq(value, 7);
} 

Test(my_printf, default_putnbr_d9, .init=redirect, .timeout=1)
{
    int value = my_printf("%d", -2147483648);
    cr_assert_stdout_eq_str("-2147483648");
    cr_assert_eq(value, 11);
} 

Test(my_printf, default_putnbr_d10, .init=redirect, .timeout=1)
{
    int value = my_printf("%d", -2147483649);
    cr_assert_stdout_eq_str("2147483647");
    cr_assert_eq(value, 10);
} 

Test(my_printf, default_putnbr_d11, .init=redirect, .timeout=1)
{
    int value = my_printf("%d", '0');
    cr_assert_stdout_eq_str("48");
    cr_assert_eq(value, 2);
} 

Test(my_printf, default_putnbr_d12, .init=redirect, .timeout=1)
{
    int value = my_printf("%d", 'a');
    cr_assert_stdout_eq_str("97");
    cr_assert_eq(value, 2);
}  

Test(my_printf, default_putnbr_d13, .init=redirect, .timeout=1)
{
    int value = my_printf("%d", '\n');
    cr_assert_stdout_eq_str("10");
    cr_assert_eq(value, 2);
}  
