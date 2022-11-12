#ifndef __ASSERTIONS_H__
#define __ASSERTIONS_H__

#include <stdio.h>

typedef struct assertion assertion;

void AssertionsInit();

void AssertionAdd(const char *t_test_description);

void AssertionSuccess();

int AssertionFail(const char *file, const int line, char *msg);

void AssertionsLogAll(FILE *output);

void AssertionsFinalize();

#endif