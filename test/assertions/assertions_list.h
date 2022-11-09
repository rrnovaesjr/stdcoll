#ifndef __ASSERTION_LIST_H__
#define __ASSERTION_LIST_H__

#include <stdio.h>

typedef struct assertion assertion;

void init();

int assertion_add(char *test, char *msg);

int log_all_assertions(FILE *output);

void release();

#endif