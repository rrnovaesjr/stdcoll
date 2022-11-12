#include <stdio.h>
#include <stdlib.h>
#include "assert/assert.h"
#include "suite/suite.h"
#include "stdcoll/collections.h"

stdcoll *coll;
stditr *t;

const char description[] = "linked_list_iterator_test";

void InitializeList()
{
    coll = SupplyCollection();
}

void InitializeIterator()
{
    t = CollectionIterator(coll);
}

void DestroyIterator()
{
    IteratorDelete(t);
}

void DestroyList()
{
    CollectionDelete(coll);
}

int *SupplyInt(int n)
{
    int *pn = malloc(sizeof(int));
    *pn = n;
    return pn;
}

void should_iterate_over_collection()
{
    int i;
    const int size = 100000;
    for (i = 0; i < size; i++)
    {
        CollectionAdd(coll, SupplyInt(i));
    }

    for (i = 0; i < size; t = IteratorNext(t), i++)
    {
        ASSERT_TRUE(IteratorHasNext(t));
        ASSERTI_EQ(*(int *)IteratorGet(t), i);
    }

    ASSERT_FALSE(IteratorHasNext(t));
}

void should_remove_items_from_collection_using_iterator()
{
    const int total_size = 100000;
    const int expected_size = total_size / 2;
    int i;
    for (i = 0; i < total_size; i++)
    {
        ASSERT_TRUE(CollectionAdd(coll, SupplyInt(i)));
    }

    while (IteratorHasNext(t))
    {
        if ((*(int *)IteratorGet(t)) % 2 == 0)
        {
            t = IteratorRemove(t);
        }
        else
        {
            t = IteratorNext(t);
        }
    }

    ASSERTI_EQ((int)CollectionSize(coll), expected_size);
}

test_instance tests[] = {
    {should_iterate_over_collection, "should_iterate_over_collection"},
    {should_remove_items_from_collection_using_iterator, "should_remove_items_from_collection_using_iterator"},
    {NULL, NULL}};

void (*before_all)(void) = NULL;

void (*after_all)(void) = NULL;

void (*before_each[])(void) = {InitializeList, InitializeIterator, NULL};

void (*after_each[])(void) = {DestroyIterator, DestroyList, NULL};