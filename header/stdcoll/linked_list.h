#ifndef _STDCOLL_LINKED_LIST_H_
#define _STDCOLL_LINKED_LIST_H_

#include "stdcoll/collection.h"
#include "stdcoll/list.h"
#include <stdio.h>

typedef struct stdllist stdllist;

int LinkedListAdd(stdllist *, void *obj);

void * LinkedListRemove(stdllist *, const void *obj);

int LinkedListAddAll(stdllist *, stdcoll *const other_coll);

void LinkedListClear(stdllist *);

int LinkedListIsEmpty(stdllist *);

size_t LinkedListSize(stdllist *);

int LinkedListContains(stdllist *);

void LinkedListDelete(stdllist *);

void * LinkedListGetAtIndex(stdllist *, const int idx);

int LinkedListAddAtIndex(stdllist *, void *obj, const int idx);

void * LinkedListFront(stdllist *);

void * LinkedListBack(stdllist *);

void * LinkedListRemoveAtIndex(stdllist *, const int idx);

stdllist * LinkedList();

stdllist * LinkedListFromArray(void *base, size_t amount, size_t size);

stdlist * LinkedListSuper(stdllist *);

stdcoll * LinkedListToCollection(stdllist *);

#endif