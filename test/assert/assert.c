#include "assert/assert_impl.h"
#include "assertions/assertions.h"
#include <setjmp.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define __ABS__(a) ( a < 0 ? -a : a )

static jmp_buf jmp;

static const int ASSERTION_STARTED = 0;
static const int ASSERTION_FAILED = -1;
static const int SUCCESS = 0;
static const int FAILURE = 1;

void _print_filename_and_number(char *out, const int line, const char *file) {
    char filename[512];
    int i = strlen(file) - 1;
    while (i > 0 && file[i] != '/') i--;
    i++;
    int j;
    for (j = 0; file[i] != '\0'; i++, j++)
        filename[j] = file[i];

    filename[j] = '\0';

    sprintf(out, "%s:%d", filename, line);
}

void assertd(int condition, const int line, const char *file, const char *fmt, ...) {
    char message[strlen(fmt) * 2], file_label[strlen(file) + 10];

    _print_filename_and_number(file_label, line, file);

    va_list args;
    va_start(args, fmt);
    vsprintf(message, fmt, args);

    if (!condition) {
        AssertionFail(file, line, message);
        longjmp(jmp, ASSERTION_FAILED);
    }
}

void assert_true(const int actual, int line, const char *file)
{
    assertd(actual, line, file, "expected to be true");
}

void assert_false(const int actual, int line, const char *file)
{
    assertd(!actual, line, file, "expected to be false");
}

void asserti_equals(int actual, int expected, int line, const char *file)
{
    assertd((actual == expected), line, file, "expected %d to be %d", actual, expected);
}

void assert_same(void *actual, void *expected, int line, const char *file)
{
    assertd(actual == expected, line, file, "expected %p to be the same as %p", actual, expected);
}

int run_assertd(void (*f)(void), const char *test_description) {
    int c = setjmp(jmp);

    if (c == ASSERTION_STARTED) {
        AssertionAdd(test_description);
        f();
    } else if (c == ASSERTION_FAILED) {
        return FAILURE;
    }
    AssertionSuccess();
    return SUCCESS;
}