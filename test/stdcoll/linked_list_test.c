#include <stdio.h>
#include <stdlib.h>
#include "assert/assert.h"
#include "suite/suite.h"
#include "stdcoll/linked_list.h"

stdllist *llist;

const char description[] = "linked_list_test";

void initialize_list()
{
    llist = LinkedList();
}

void destroy_list()
{
    LinkedListDelete(llist);
}

int *supply_int(int n)
{
    int *pn = malloc(sizeof(int));
    *pn = n;
    return pn;
}

void should_initialize_linked_list()
{
    ASSERTI_EQ(LinkedListSize(llist), (size_t)0);
    ASSERT_TRUE(LinkedListIsEmpty(llist));
}

void should_update_linked_list_and_query_elements()
{
    ASSERT_TRUE(LinkedListIsEmpty(llist));
    ASSERT_TRUE(LinkedListAdd(llist, supply_int(1)));
    ASSERT_TRUE(LinkedListAdd(llist, supply_int(2)));
    ASSERT_TRUE(LinkedListAdd(llist, supply_int(3)));
    ASSERT_TRUE(LinkedListAdd(llist, supply_int(4)));
    ASSERTI_EQ((int)LinkedListSize(llist), 4);
    ASSERT_FALSE(LinkedListIsEmpty(llist));
    ASSERTI_EQ(*(int *)LinkedListGetAtIndex(llist, 0), 1);
    ASSERTI_EQ(*(int *)LinkedListGetAtIndex(llist, 1), 2);
    ASSERTI_EQ(*(int *)LinkedListGetAtIndex(llist, 2), 3);
    ASSERTI_EQ(*(int *)LinkedListGetAtIndex(llist, 3), 4);
    ASSERT_SAME(LinkedListGetAtIndex(llist, -1), NULL);
    ASSERT_SAME(LinkedListGetAtIndex(llist, 100), NULL);
    LinkedListClear(llist);
    ASSERT_TRUE(LinkedListIsEmpty(llist));
    ASSERTI_EQ((int)LinkedListSize(llist), 0);    
    ASSERT_TRUE(LinkedListAdd(llist, supply_int(1)));
    ASSERT_TRUE(LinkedListAdd(llist, supply_int(2)));
    ASSERT_TRUE(LinkedListAdd(llist, supply_int(3)));
    ASSERT_TRUE(LinkedListAdd(llist, supply_int(4)));
    ASSERTI_EQ((int)LinkedListSize(llist), 4);
    void *value = LinkedListRemoveAtIndex(llist, 2);
    ASSERT_TRUE(value != NULL);
    free(value);
    ASSERTI_EQ((int)LinkedListSize(llist), 3);
    ASSERT_TRUE(LinkedListAdd(llist, supply_int(2)));
    ASSERTI_EQ((int)LinkedListSize(llist), 4);
    LinkedListClear(llist);
}

void should_iterate_over_list()
{
    int i;
    for (i = 0; i < 10000; i++)
    {
        ASSERT_TRUE(LinkedListAdd(llist, supply_int(i)));
    }

    stditr *llitr;
    for (llitr = LinkedListIterator(llist), i = 0; IteratorHasNext(llitr); llitr = IteratorNext(llitr), i++)
    {
        ASSERTI_EQ(*(int *)IteratorGet(llitr), i);
    }
    IteratorDelete(llitr);

    for (llitr = LinkedListIterator(llist); IteratorHasNext(llitr);)
    {
        if (*(int *)IteratorGet(llitr) % 2 == 0)
        {
            IteratorRemove(llitr);
        }
        else
        {
            llitr = IteratorNext(llitr);
        }
    }
    IteratorDelete(llitr);

    for (llitr = LinkedListIterator(llist); IteratorHasNext(llitr); llitr = IteratorNext(llitr))
    {
        ASSERT_TRUE(*(int *)IteratorGet(llitr) % 2 != 0);
    }
    IteratorDelete(llitr);
}

test_instance tests[] = {
    {should_initialize_linked_list, "should_initialize_linked_list"},
    {should_update_linked_list_and_query_elements, "should_update_linked_list_and_query_elements"},
    {should_iterate_over_list, "should_iterate_over_list"},
    {NULL, NULL}};

void (*before_all)(void) = NULL;

void (*after_all)(void) = NULL;

void (*before_each[])(void) = {initialize_list, NULL};

void (*after_each[])(void) = {destroy_list, NULL};