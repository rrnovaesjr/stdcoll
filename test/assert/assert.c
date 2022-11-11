#include "assert/assert_impl.h"
#include "assertions/assertions.h"
#include <setjmp.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define __ABS__(a) (a < 0 ? -a : a)

static jmp_buf jmp;

static const int ASSERTION_STARTED = 0;
static const int ASSERTION_FAILED = -1;
static const int SUCCESS = 0;
static const int FAILURE = 1;

void _print_filename_and_number(char *out, const int line, const char *file)
{
    char filename[512];
    int i = strlen(file) - 1;
    while (i > 0 && file[i] != '/')
        i--;
    i++;
    int j;
    for (j = 0; file[i] != '\0'; i++, j++)
        filename[j] = file[i];

    filename[j] = '\0';

    sprintf(out, "%s:%d", filename, line);
}

void AssertD(int condition, const int line, const char *file, const char *fmt, ...)
{
    char message[strlen(fmt) * 2], file_label[strlen(file) + 10];

    _print_filename_and_number(file_label, line, file);

    va_list args;
    va_start(args, fmt);
    vsprintf(message, fmt, args);

    if (!condition)
    {
        AssertionFail(file, line, message);
        longjmp(jmp, ASSERTION_FAILED);
    }
}

void AssertTrue(const int actual, int line, const char *file)
{
    AssertD(actual, line, file, "expected to be true");
}

void AssertFalse(const int actual, int line, const char *file)
{
    AssertD(!actual, line, file, "expected to be false");
}

void AssertIEquals(int actual, int expected, int line, const char *file)
{
    AssertD((actual == expected), line, file, "expected %d to be %d", actual, expected);
}

void AssertSame(void *actual, void *expected, int line, const char *file)
{
    AssertD(actual == expected, line, file, "expected %p to be the same as %p", actual, expected);
}

int RunAssertD(void (*f)(void), const char *test_description)
{
    int c = setjmp(jmp);

    AssertionAdd(test_description);
    if (c == ASSERTION_STARTED)
    {
        f();
    }
    else if (c == ASSERTION_FAILED)
    {
        return FAILURE;
    }
    AssertionSuccess();
    return SUCCESS;
}