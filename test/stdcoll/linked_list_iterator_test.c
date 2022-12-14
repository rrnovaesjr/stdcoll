#include <stdio.h>
#include <stdlib.h>
#include "assert/assert.h"
#include "suite/suite.h"
#include "stdcoll/linked_list.h"

stdllist *list;
stditr *t;

const char description[] = "linked_list_iterator_test";

void InitializeList()
{
    list = LinkedList();
}

void InitializeIterator()
{
    t = LinkedListIterator(list);
}

void DestroyIterator()
{
    IteratorDelete(t);
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

void should_iterate_over_linked_list()
{
    int i;
    const int size = 100000;
    for (i = 0; i < size; i++)
    {
        LinkedListAdd(list, SupplyInt(i));
    }

    for (i = 0; i < size; t = IteratorNext(t), i++)
    {
        ASSERT_TRUE(IteratorHasNext(t));
        ASSERTI_EQ(*(int *)IteratorGet(t), i);
    }

    ASSERT_FALSE(IteratorHasNext(t));
}

void should_remove_elements_from_list_using_iterator()
{
    const int total_size = 100000;
    const int expected_size = total_size / 2;
    int i;
    for (i = 0; i < total_size; i++)
    {
        ASSERT_TRUE(LinkedListAdd(list, SupplyInt(i)));
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

    ASSERTI_EQ((int)LinkedListSize(list), expected_size);
}

test_instance tests[] = {
    {should_iterate_over_linked_list, "should_iterate_over_linked_list"},
    {should_remove_elements_from_list_using_iterator, "should_remove_elements_from_list_using_iterator"},
    {NULL, NULL}};

void (*before_all)(void) = NULL;

void (*after_all)(void) = NULL;

void (*before_each[])(void) = {InitializeList, InitializeIterator, NULL};

void (*after_each[])(void) = {DestroyIterator, DestroyList, NULL};