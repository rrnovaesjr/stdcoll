#include <stdio.h>
#include <stdlib.h>
#include "common/assert.h"
#include "common/suite.h"
#include "stdcoll/linked_list.h"

const char description[] = "linked_list_test";

int * supply_int(int n) {
    int *pn = malloc(sizeof(int));
    *pn = n;
    return pn;
}

void should_initialize_linked_list() {
    stdlist *linked_list = LinkedListToList(NewLinkedList());

    assertd(Size(ListToCollection(linked_list)) == 0UL, "Should initialize with size 0");
    assertd(IsEmpty(ListToCollection(linked_list)), "Should initialize with size 0");

    free(linked_list);
}

void should_update_linked_list_and_query_elements() {
    stdlist *linked_list = LinkedListToList(NewLinkedList());

    assertd(IsEmpty(ListToCollection(linked_list)), "The list should be empty");
    assertd(Add(ListToCollection(linked_list), supply_int(1)) == 1, "Should modify linked list when adding 1");
    assertd(Add(ListToCollection(linked_list), supply_int(2)) == 1, "Should modify linked list when adding 2");
    assertd(Add(ListToCollection(linked_list), supply_int(3)) == 1, "Should modify linked list when adding 3");
    assertd(Add(ListToCollection(linked_list), supply_int(4)) == 1, "Should modify linked list when adding 4");
    assertd(Size(ListToCollection(linked_list)) == 4UL, "Should have 4 elements");
    assertd(!IsEmpty(ListToCollection(linked_list)), "The list should not be empty");
    assertd(*(int *) GetAtIndex(linked_list, 0) == 1, "Should return 1 at index 0");
    assertd(*(int *) GetAtIndex(linked_list, 1) == 2, "Should return 2 at index 1");
    assertd(*(int *) GetAtIndex(linked_list, 2) == 3, "Should return 3 at index 2");
    assertd(*(int *) GetAtIndex(linked_list, 3) == 4, "Should return 4 at index 3");
    assertd(!GetAtIndex(linked_list, -1), "Should not get element at invalid index");
    assertd(!GetAtIndex(linked_list, 10), "Should not get element at invalid index");
    Clear(ListToCollection(linked_list));
    assertd(IsEmpty(ListToCollection(linked_list)), "The list should be empty");
    assertd(Size(ListToCollection(linked_list)) == 0UL, "Should clear the linked list");
    free(linked_list);
}

test_instance tests[] = {
    { should_initialize_linked_list, "should_initialize_linked_list" },
    { should_update_linked_list_and_query_elements, "should_update_linked_list_and_query_elements" },
    { NULL, NULL }
};

void (*before_all)(void) = NULL;

void (*after_all)(void) = NULL;

void (*before_each[])(void) = {NULL};

void (*after_each[])(void) = {NULL};