#include <stdio.h>
#include <stdlib.h>
#include "assert/assert.h"
#include "suite/suite.h"
#include "stdcoll/collections.h"

stdcoll *coll;

const char description[] = "collections_test";

void InitializeList()
{
    coll = SupplyCollection();
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

void should_initialize_collection()
{
    ASSERTI_EQ(CollectionSize(coll), (size_t)0);
    ASSERT_TRUE(CollectionIsEmpty(coll));
}

void should_update_collection_and_query_elements()
{
    ASSERT_TRUE(CollectionIsEmpty(coll));
    ASSERT_TRUE(CollectionAdd(coll, SupplyInt(1)));
    ASSERT_TRUE(CollectionAdd(coll, SupplyInt(2)));
    ASSERT_TRUE(CollectionAdd(coll, SupplyInt(3)));
    ASSERT_TRUE(CollectionAdd(coll, SupplyInt(4)));
    ASSERTI_EQ((int)CollectionSize(coll), 4);
    ASSERT_FALSE(CollectionIsEmpty(coll));
    CollectionClear(coll);
    ASSERT_TRUE(CollectionIsEmpty(coll));
    ASSERTI_EQ((int)CollectionSize(coll), 0);
}

test_instance tests[] = {
    {should_initialize_collection, "should_initialize_collection"},
    {should_update_collection_and_query_elements, "should_update_collection_and_query_elements"},
    {NULL, NULL}};

void (*before_all)(void) = NULL;

void (*after_all)(void) = NULL;

void (*before_each[])(void) = {InitializeList, NULL};

void (*after_each[])(void) = {DestroyList, NULL};