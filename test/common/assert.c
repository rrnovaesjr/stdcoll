#include "common/assert_impl.h"
#include <setjmp.h>
#include <stdio.h>

static jmp_buf jmp;

static const int ASSERTION_STARTED = 0;
static const int ASSERTION_OK = 1;
static const int ASSERTION_FAILED = -1;
static const int SUCCESS = 0;
static const int FAILURE = 1;

void assertd(int condition, const char *description) {
    if (condition) {
        longjmp(jmp, ASSERTION_OK);
    } else {
        fprintf(stderr, "Assertion failed: %s\n", description);
        longjmp(jmp, ASSERTION_FAILED);
    }
}

void assert(int condition) {
    if (condition) {
        longjmp(jmp, ASSERTION_OK);
    } else {
        longjmp(jmp, ASSERTION_FAILED);
    }
}

int run_assertd(void (*f)(void)) {
    int c = setjmp(jmp);

    if (c == ASSERTION_STARTED) {
        f();
    } else if (c == ASSERTION_OK) {
        return SUCCESS;
    }
    return FAILURE;
}