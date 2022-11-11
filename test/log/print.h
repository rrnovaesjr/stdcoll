#ifndef __PRINT_H__
#define __PRINT_H__

#include <stdio.h>
#include <stdarg.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define LOG_RESET_COLOR(out) fprintf(out, ANSI_COLOR_RESET)
#define LOG_INFO(out, ...)                      \
    fprintf(out, ANSI_COLOR_RESET __VA_ARGS__); \
    LOG_RESET_COLOR(out)
#define LOG_OK(out, ...)                        \
    fprintf(out, ANSI_COLOR_GREEN __VA_ARGS__); \
    LOG_RESET_COLOR(out)
#define LOG_ERROR(out, ...)                   \
    fprintf(out, ANSI_COLOR_RED __VA_ARGS__); \
    LOG_RESET_COLOR(out)
#define LOG_WARN(out, ...)                            \
    fprintf(out, ANSI_COLOR_YELLOW fmt, __VA_ARGS__); \
    LOG_RESET_COLOR(out)

#endif