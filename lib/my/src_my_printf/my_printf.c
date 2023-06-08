/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** my_printf
*/

#include "my_printf_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file my_printf.c
/// \brief Contains the my_printf function.
/// \author PAGY0Z
/// \version 0.1
/// \date 2023-28-05
////////////////////////////////////////////////////////////////////////////////

int is_tokenp(char c, char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (c == str[i])
            return 1;
    }
    return 0;
}

int my_treatment(luggage_t *log, flags_t *flags, va_list *ap)
{
    int i = 0;
    if (flags->conversion == '%')
        return log->printed_char_count += my_putcharp('%');
    while (flags->conversion != flags_list[i].conversion_flag) {
        i++;
    }
    flags_list[i].fonction(log, flags, ap);
    return 0;
}

void my_parsing(luggage_t *log, va_list *ap)
{
    flags_t flags = {0};
    while (is_tokenp(log->str[log->pos], PRINTF_CHARFLAGS))
        my_charflags_finder(log, &flags);
    while ('0' <= log->str[log->pos] && log->str[log->pos] <= '9')
        flags.width = my_getnbr_my_printf(log->str, log->pos, log);
    if (log->str[log->pos++] == '.') {
        flags.precision_check = 1;
        if ('0' <= log->str[log->pos] && log->str[log->pos] <= '9')
            flags.precision = my_getnbr_my_printf(log->str, log->pos, log);
    } else
        log->pos--;
    if (is_tokenp(log->str[log->pos], PRINTF_LENGHTMODIFIER))
        my_lenght_modifier(log, &flags);
    if (is_tokenp(log->str[log->pos], PRINTF_CONVERSIONS)) {
        flags.conversion = log->str[log->pos];
        my_treatment(log, &flags, ap);
    } else {
        log->printed_char_count += my_putcharp('%');
        log->pos = log->save_pos;
    }
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Displays a formatted string on the STDOUT.
/// \param format The string to display.
/// \param ... The values to replace the % flags with.
/// \return The number of characters displayed.
/// \note Supported flags: %b %B %c %d %e %E %f %F %i %n %o %p %s %S %u %x %X
////////////////////////////////////////////////////////////////////////////////
int my_printf(char const *format, ...)
{
    luggage_t log = {0};
    log.str = format;
    va_list ap;
    va_start(ap, format);
    for (log.pos = 0; log.str[log.pos]; log.pos++) {
        if (log.str[log.pos] == '%') {
            log.save_pos = log.pos;
            log.pos++;
            my_parsing(&log, &ap);
        } else {
            log.printed_char_count += my_putcharp(log.str[log.pos]);
        }
    }
    va_end(ap);
    return log.printed_char_count;
}
