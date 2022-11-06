#include <stdio.h>
#include <stdlib.h>
#include "common/assert.h"
#include "common/suite.h"
#include "stdcoll/linked_list.h"

stdlist *list;

const char description[] = "linked_list_test";

void initialize_list() {
    list = LinkedListToList(NewLinkedList());
}

void destroy_list() {
    CollectionDelete(ListToCollection(list));
}

int * supply_int(int n) {
    int *pn = malloc(sizeof(int));
    *pn = n;
    return pn;
}

void should_initialize_linked_list() {
    assertd(CollectionSize(ListToCollection(list)) == 0UL, "Should initialize with size 0");
    assertd(CollectionIsEmpty(ListToCollection(list)), "Should initialize with size 0");
}

void should_update_linked_list_and_query_elements() {
    assertd(CollectionIsEmpty(ListToCollection(list)), "The list should be empty");
    assertd(CollectionAdd(ListToCollection(list), supply_int(1)) == 1, "Should modify linked list when adding 1");
    assertd(CollectionAdd(ListToCollection(list), supply_int(2)) == 1, "Should modify linked list when adding 2");
    assertd(CollectionAdd(ListToCollection(list), supply_int(3)) == 1, "Should modify linked list when adding 3");
    assertd(CollectionAdd(ListToCollection(list), supply_int(4)) == 1, "Should modify linked list when adding 4");
    assertd(CollectionSize(ListToCollection(list)) == 4UL, "Should have 4 elements");
    assertd(!CollectionIsEmpty(ListToCollection(list)), "The list should not be empty");
    assertd(*(int *) GetAtIndex(list, 0) == 1, "Should return 1 at index 0");
    assertd(*(int *) GetAtIndex(list, 1) == 2, "Should return 2 at index 1");
    assertd(*(int *) GetAtIndex(list, 2) == 3, "Should return 3 at index 2");
    assertd(*(int *) GetAtIndex(list, 3) == 4, "Should return 4 at index 3");
    assertd(!GetAtIndex(list, -1), "Should not get element at invalid index");
    assertd(!GetAtIndex(list, 10), "Should not get element at invalid index");
    CollectionClear(ListToCollection(list));
    assertd(CollectionIsEmpty(ListToCollection(list)), "The list should be empty");
    assertd(CollectionSize(ListToCollection(list)) == 0UL, "Should clear the linked list");
}

test_instance tests[] = {
    { should_initialize_linked_list, "should_initialize_linked_list" },
    { should_update_linked_list_and_query_elements, "should_update_linked_list_and_query_elements" },
    { NULL, NULL }
};

void (*before_all)(void) = NULL;

void (*after_all)(void) = NULL;

void (*before_each[])(void) = {initialize_list, NULL};

void (*after_each[])(void) = {destroy_list, NULL};