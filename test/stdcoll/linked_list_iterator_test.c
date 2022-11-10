#include <stdio.h>
#include <stdlib.h>
#include "assert/assert.h"
#include "suite/suite.h"
#include "stdcoll/linked_list.h"

stdllist *llist;
stditr *itr;

const char description[] = "linked_list_test";

void InitializeList()
{
    llist = LinkedList();
}

void InitializeIterator()
{
    itr = LinkedListIterator(llist);
}

void DestroyIterator()
{
    IteratorDelete(itr);
}

void DestroyList()
{
    LinkedListDelete(llist);
}

int *SupplyInt(int n)
{
    int *pn = malloc(sizeof(int));
    *pn = n;
    return pn;
}

void should_iterate_over_linked_list()
{
    int i;
    const int size = 100000;
    for (i = 0; i < size; i++)
    {
        LinkedListAdd(llist, SupplyInt(i));
    }

    for (i = 0; i < size; itr = IteratorNext(itr), i++)
    {
        ASSERT_TRUE(IteratorHasNext(itr));
        ASSERTI_EQ(*(int *)IteratorGet(itr), i);
    }

    ASSERT_FALSE(IteratorHasNext(itr));
}

void should_remove_elements_from_list_using_iterator()
{
    const int total_size = 100000;
    const int expected_size = total_size / 2;
    int i;
    for (i = 0; i < total_size; i++)
    {
        ASSERT_TRUE(LinkedListAdd(llist, SupplyInt(i)));
    }

    while (IteratorHasNext(itr))
    {
        if ((*(int *)IteratorGet(itr)) % 2 == 0)
        {
            itr = IteratorRemove(itr);
        }
        else
        {
            itr = IteratorNext(itr);
        }
    }

    ASSERTI_EQ((int)LinkedListSize(llist), expected_size);
}

test_instance tests[] = {
    {should_iterate_over_linked_list, "should_iterate_over_linked_list"},
    {should_remove_elements_from_list_using_iterator, "should_remove_elements_from_list_using_iterator"},
    {NULL, NULL}};

void (*before_all)(void) = NULL;

void (*after_all)(void) = NULL;

void (*before_each[])(void) = {InitializeList, InitializeIterator, NULL};

void (*after_each[])(void) = {DestroyIterator, DestroyList, NULL};