#include <stdio.h>
#include <stdlib.h>
#include "common/assert.h"
#include "common/suite.h"

void should_create_linked_list() {
    assertd(0 == 1, "0 == 1");
}

void should_add_element_to_linked_list() {
    assertd(0 == 0, "0 == 0");
}

const char description[] = "linked_list_test";

test_instance tests[] = {
    { should_create_linked_list, "should_create_linked_list"},
    { should_add_element_to_linked_list, "should_add_element_to_linked_list" }, 
    { NULL, NULL }
};

void (*before_all)(void) = NULL;

void (*after_all)(void) = NULL;

void (*before_each[])(void) = {NULL};

void (*after_each[])(void) = {NULL};