/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** signals_header
*/

////////////////////////////////////////////////////////////////////////////////
/// \file signals_header.h
/// \brief Contains the all the signals.
/// \authors PAGY0Z
/// \version 0.1
/// \date 2023-23-04
////////////////////////////////////////////////////////////////////////////////

#ifndef SIGNALS_HEADER_H_
    #define SIGNALS_HEADER_H_

    #include <signal.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <errno.h>

    ////////////////////////////////////////////////////////////////////////////
    /// \addtogroup LIBRARY
    /// \brief Contains all the files of the library.
    /// @{
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    /// \addtogroup LIBRARY_SIGNALS_ARRAY
    /// \brief Array containing the signal_t structures.
    /// @{
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    /// \typedef
    /// \brief Structure containing the signal id, the signal number and the
    /// signal display.
    /// \struct signal_s
    ////////////////////////////////////////////////////////////////////////////
    typedef struct signal_s {
        ////////////////////////////////////////////////////////////////////////
        /// \brief Signal id.
        ////////////////////////////////////////////////////////////////////////
        int id;
        ////////////////////////////////////////////////////////////////////////
        /// \brief Signal SIG number.
        ////////////////////////////////////////////////////////////////////////
        int signal;
        ////////////////////////////////////////////////////////////////////////
        /// \brief Signal display.
        ////////////////////////////////////////////////////////////////////////
        char *display;
    } signal_t;

    ////////////////////////////////////////////////////////////////////////////
    /// \brief Signal list containing all the signals. Each signal is
    /// associated with its id, its number and its display.
    ////////////////////////////////////////////////////////////////////////////
    static signal_t const signal_list[] = {
        {0, 0, NULL},
        {1, SIGHUP, "Hangup"},
        {2, SIGINT, ""},
        {3, SIGQUIT, "Quit"},
        {4, SIGILL, "Illegal instruction"},
        {5, SIGTRAP, "Trace/BPT trap"},
        {6, SIGABRT, "Abort"},
        {7, SIGBUS, "Bus error"},
        {8, SIGFPE, "Floating exception"},
        {9, SIGKILL, "Killed"},
        {10, SIGUSR1, "User signal 1"},
        {11, SIGSEGV, "Segmentation fault"},
        {12, SIGUSR2, "User signal 2"},
        {13, SIGPIPE, "Broken pipe"},
        {14, SIGALRM, "Alarm clock"},
        {15, SIGTERM, "Terminated"},
        {16, SIGSTKFLT, "Stack limit exceeded"},
        {17, SIGCHLD, ""},
        {18, SIGCONT, ""},
        {19, SIGSTOP, "\nSuspended (signal)"},
        {20, SIGTSTP, "\nSuspended"},
        {21, SIGTTIN, "\nSuspended (tty input)"},
        {22, SIGTTOU, "\nSuspended (tty output)"},
        {23, SIGURG, ""},
        {24, SIGXCPU, "Cputime limit exceeded"},
        {25, SIGXFSZ, "Filesize limit exceeded"},
        {26, SIGVTALRM, "Virtual time alarm"},
        {27, SIGPROF, "Profiling time alarm"},
        {28, SIGWINCH, ""},
        {29, SIGIO, "Pollable event occurred"},
        {30, SIGPWR, "Power failure"},
        {31, SIGSYS, "Bad system call"},
        {32, 32, "Signal  32"},
        {33, 32 + 1, "Signal  33"},
        {34, 32 + 2, "First Realtime Signal"},
        {35, 32 + 3, "Second Realtime Signal"},
        {36, 32 + 4, "Third Realtime Signal"},
        {37, 32 + 5, "Fourth Realtime Signal"},
        {38, 32 + 6, "Signal  38"},
        {39, 32 + 7, "Signal  39"},
        {40, 32 + 8, "Signal  40"},
        {41, 32 + 9, "Signal  41"},
        {42, 32 + 10, "Signal  42"},
        {43, 32 + 11, "Signal  43"},
        {44, 32 + 12, "Signal  44"},
        {45, 32 + 13, "Signal  45"},
        {46, 32 + 14, "Signal  46"},
        {47, 32 + 15, "Signal  47"},
        {48, 62 - 14, "Signal  48"},
        {49, 62 - 13, "Signal  49"},
        {50, 62 - 12, "Signal  50"},
        {51, 62 - 11, "Signal  51"},
        {52, 62 - 10, "Signal  52"},
        {53, 62 - 9, "Signal  53"},
        {54, 62 - 8, "Signal  54"},
        {55, 62 - 7, "Signal  55"},
        {56, 62 - 6, "Signal  56"},
        {57, 62 - 5, "Signal  57"},
        {58, 62 - 4, "Signal  58"},
        {59, 62 - 3, "Signal  59"},
        {60, 62 - 2, "Signal  60"},
        {61, 62 - 1, "Fourth Last Realtime Signal"},
        {62, 62, "Third Last Realtime Signal"},
        {63, 62 + 1, "Second Last Realtime Signal"},
        {64, 62 + 2, "Last Realtime Signal"},
        {65, 0, NULL},
    };

    ////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////

#endif /* !SIGNALS_HEADER_H_ */
