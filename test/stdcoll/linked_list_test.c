#include <stdio.h>
#include <stdlib.h>
#include "assert/assert.h"
#include "suite/suite.h"
#include "stdcoll/linked_list.h"

stdllist *llist;

const char description[] = "linked_list_test";

void initialize_list() {
    llist = LinkedList();
}

void destroy_list() {
    LinkedListDelete(llist);
}

int * supply_int(int n) {
    int *pn = malloc(sizeof(int));
    *pn = n;
    return pn;
}

void should_initialize_linked_list() {
    ASSERTI_EQ(LinkedListSize(llist), (size_t) 0);
    ASSERT_TRUE(LinkedListIsEmpty(llist));
}

void should_update_linked_list_and_query_elements() {
    ASSERT_TRUE(LinkedListIsEmpty(llist));
    ASSERT_TRUE(LinkedListAdd(llist, supply_int(1)));
    ASSERT_TRUE(LinkedListAdd(llist, supply_int(2)));
    ASSERT_TRUE(LinkedListAdd(llist, supply_int(3)));
    ASSERT_TRUE(LinkedListAdd(llist, supply_int(4)));
    ASSERTI_EQ((int) LinkedListSize(llist), 4);
    ASSERT_FALSE(LinkedListIsEmpty(llist));
    ASSERTI_EQ(*(int *) LinkedListGetAtIndex(llist, 0), 1);
    ASSERTI_EQ(*(int *) LinkedListGetAtIndex(llist, 1), 2);
    ASSERTI_EQ(*(int *) LinkedListGetAtIndex(llist, 2), 4);
    ASSERTI_EQ(*(int *) LinkedListGetAtIndex(llist, 3), 4);
    ASSERT_SAME(LinkedListGetAtIndex(llist, -1), NULL);
    ASSERT_SAME(LinkedListGetAtIndex(llist, 100), NULL);
    LinkedListClear(llist);
    ASSERT_TRUE(LinkedListIsEmpty(llist));
    ASSERTI_EQ((int) LinkedListSize(llist), 0);
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