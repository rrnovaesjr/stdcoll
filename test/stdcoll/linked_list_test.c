#include <stdio.h>
#include <stdlib.h>
#include "common/assert.h"
#include "common/suite.h"

const char description[] = "linked_list_test";

test_instance tests[] = {
    { NULL, NULL }
};

void (*before_all)(void) = NULL;

void (*after_all)(void) = NULL;

void (*before_each[])(void) = {NULL};

void (*after_each[])(void) = {NULL};