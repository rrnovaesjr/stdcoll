#ifndef __ASSERTION_LIST_H__
#define __ASSERTION_LIST_H__

#include <stdio.h>

typedef struct assertion assertion;

void AssertionsInit();

void AssertionAdd(const char *t_test_description);

void AssertionSuccess();

int AssertionFail(char *test, char *msg);

int AssertionsLogAll(FILE *output);

void AssertionsFinalize();

#endif