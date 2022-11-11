#include <stdio.h>
#include <stdlib.h>
#include "assert/assert.h"
#include "suite/suite.h"
#include "stdcoll/collections.h"

stdcoll *llist;

const char description[] = "collections_test";

void InitializeList()
{
    llist = SupplyCollection();
}

void DestroyList()
{
    CollectionDelete(llist);
}

int *SupplyInt(int n)
{
    int *pn = malloc(sizeof(int));
    *pn = n;
    return pn;
}

void should_initialize_collection()
{
    ASSERTI_EQ(CollectionSize(llist), (size_t)0);
    ASSERT_TRUE(CollectionIsEmpty(llist));
}

void should_update_collection_and_query_elements()
{
    ASSERT_TRUE(CollectionIsEmpty(llist));
    ASSERT_TRUE(CollectionAdd(llist, SupplyInt(1)));
    ASSERT_TRUE(CollectionAdd(llist, SupplyInt(2)));
    ASSERT_TRUE(CollectionAdd(llist, SupplyInt(3)));
    ASSERT_TRUE(CollectionAdd(llist, SupplyInt(4)));
    ASSERTI_EQ((int)CollectionSize(llist), 4);
    ASSERT_FALSE(CollectionIsEmpty(llist));
    CollectionClear(llist);
    ASSERT_TRUE(CollectionIsEmpty(llist));
    ASSERTI_EQ((int)CollectionSize(llist), 0);
}

void should_iterate_over_collection()
{
    int i;
    for (i = 0; i < 10000; i++)
    {
        ASSERT_TRUE(CollectionAdd(llist, SupplyInt(i)));
    }

    stditr *llitr;
    for (llitr = CollectionIterator(llist), i = 0; IteratorHasNext(llitr); llitr = IteratorNext(llitr), i++)
    {
        ASSERTI_EQ(*(int *)IteratorGet(llitr), i);
    }
    IteratorDelete(llitr);

    for (llitr = CollectionIterator(llist); IteratorHasNext(llitr);)
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

    for (llitr = CollectionIterator(llist); IteratorHasNext(llitr); llitr = IteratorNext(llitr))
    {
        ASSERT_TRUE(*(int *)IteratorGet(llitr) % 2 != 0);
    }
    IteratorDelete(llitr);
}

test_instance tests[] = {
    {should_initialize_collection, "should_initialize_collection"},
    {should_update_collection_and_query_elements, "should_update_collection_and_query_elements"},
    {should_iterate_over_collection, "should_iterate_over_collection"},
    {NULL, NULL}};

void (*before_all)(void) = NULL;

void (*after_all)(void) = NULL;

void (*before_each[])(void) = {InitializeList, NULL};

void (*after_each[])(void) = {DestroyList, NULL};