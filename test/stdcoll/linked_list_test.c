#include <stdio.h>
#include <stdlib.h>
#include "common/assert.h"
#include "common/suite.h"
#include "stdcoll/linked_list.h"

stdlist *list;

const char description[] = "linked_list_test";

void initialize_list() {
    list = LinkedListSuper(LinkedList());
}

void destroy_list() {
    CollectionDelete(ListSuper(list));
}

int * supply_int(int n) {
    int *pn = malloc(sizeof(int));
    *pn = n;
    return pn;
}

void should_initialize_linked_list() {
    ASSERTI_EQ(CollectionSize(ListSuper(list)), (size_t) 0);
    ASSERT_TRUE(CollectionIsEmpty(ListSuper(list)));
}

void should_update_linked_list_and_query_elements() {
    ASSERT_TRUE(CollectionIsEmpty(ListSuper(list)));
    ASSERT_TRUE(CollectionAdd(ListSuper(list), supply_int(1)));
    ASSERT_TRUE(CollectionAdd(ListSuper(list), supply_int(2)));
    ASSERT_TRUE(CollectionAdd(ListSuper(list), supply_int(3)));
    ASSERT_TRUE(CollectionAdd(ListSuper(list), supply_int(4)));
    ASSERTI_EQ((int) CollectionSize(ListSuper(list)), 4);
    ASSERT_FALSE(CollectionIsEmpty(ListSuper(list)));
    ASSERTI_EQ(*(int *) ListGetAtIndex(list, 0), 1);
    ASSERTI_EQ(*(int *) ListGetAtIndex(list, 1), 2);
    ASSERTI_EQ(*(int *) ListGetAtIndex(list, 2), 3);
    ASSERTI_EQ(*(int *) ListGetAtIndex(list, 3), 4);
    ASSERT_TRUE(!ListGetAtIndex(list, -1));
    ASSERT_TRUE(!ListGetAtIndex(list, 100));
    CollectionClear(ListSuper(list));
    ASSERT_TRUE(CollectionIsEmpty(ListSuper(list)));
    ASSERTI_EQ((int) CollectionSize(ListSuper(list)), 0);
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