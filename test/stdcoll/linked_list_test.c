#include <stdio.h>
#include <stdlib.h>
#include "assert/assert.h"
#include "suite/suite.h"
#include "stdcoll/linked_list.h"

stdllist *list;

const char description[] = "linked_list_test";

void InitializeList()
{
    list = LinkedList();
}

void DestroyList()
{
    LinkedListDelete(list);
}

int *SupplyInt(int n)
{
    int *pn = malloc(sizeof(int));
    *pn = n;
    return pn;
}

void should_initialize_linked_list()
{
    ASSERTI_EQ(LinkedListSize(list), (size_t)0);
    ASSERT_TRUE(LinkedListIsEmpty(list));
}

void should_update_linked_list_and_query_elements()
{
    ASSERT_TRUE(LinkedListIsEmpty(list));
    ASSERT_TRUE(LinkedListAdd(list, SupplyInt(1)));
    ASSERT_TRUE(LinkedListAdd(list, SupplyInt(2)));
    ASSERT_TRUE(LinkedListAdd(list, SupplyInt(3)));
    ASSERT_TRUE(LinkedListAdd(list, SupplyInt(4)));
    ASSERTI_EQ((int)LinkedListSize(list), 4);
    ASSERT_FALSE(LinkedListIsEmpty(list));
    ASSERTI_EQ(*(int *)LinkedListGetAtIndex(list, 0), 1);
    ASSERTI_EQ(*(int *)LinkedListGetAtIndex(list, 1), 2);
    ASSERTI_EQ(*(int *)LinkedListGetAtIndex(list, 2), 3);
    ASSERTI_EQ(*(int *)LinkedListGetAtIndex(list, 3), 4);
    ASSERT_SAME(LinkedListGetAtIndex(list, -1), NULL);
    ASSERT_SAME(LinkedListGetAtIndex(list, 100), NULL);
    LinkedListClear(list);
    ASSERT_TRUE(LinkedListIsEmpty(list));
    ASSERTI_EQ((int)LinkedListSize(list), 0);    
    ASSERT_TRUE(LinkedListAdd(list, SupplyInt(1)));
    ASSERT_TRUE(LinkedListAdd(list, SupplyInt(2)));
    ASSERT_TRUE(LinkedListAdd(list, SupplyInt(3)));
    ASSERT_TRUE(LinkedListAdd(list, SupplyInt(4)));
    ASSERTI_EQ((int)LinkedListSize(list), 4);
    void *value = LinkedListRemoveAtIndex(list, 2);
    ASSERT_TRUE(value != NULL);
    free(value);
    ASSERTI_EQ((int)LinkedListSize(list), 3);
    ASSERT_TRUE(LinkedListAdd(list, SupplyInt(2)));
    ASSERTI_EQ((int)LinkedListSize(list), 4);
    LinkedListClear(list);
}

test_instance tests[] = {
    {should_initialize_linked_list, "should_initialize_linked_list"},
    {should_update_linked_list_and_query_elements, "should_update_linked_list_and_query_elements"},
    {NULL, NULL}};

void (*before_all)(void) = NULL;

void (*after_all)(void) = NULL;

void (*before_each[])(void) = {InitializeList, NULL};

void (*after_each[])(void) = {DestroyList, NULL};