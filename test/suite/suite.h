#ifndef __DEF_SUITE_H__
#define __DEF_SUITE_H__

#include <stdio.h>
#include "assert/assert.h"

typedef struct test_instance
{
    void (*f)(void);
    const char *description;
} test_instance;

extern void (*before_all)(void);

extern void (*after_all)(void);

extern void (*before_each[])(void);

extern void (*after_each[])(void);

extern const char description[];

extern test_instance tests[];

int run_assertable_test(test_instance test);

#endif