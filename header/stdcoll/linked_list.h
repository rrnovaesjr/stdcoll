#ifndef _STDCOLL_LINKED_LIST_H_
#define _STDCOLL_LINKED_LIST_H_

#include "stdcoll/collection.h"
#include "stdcoll/list.h"
#include <stdio.h>

typedef struct stdllist stdllist;

stdllist * NewLinkedList();

stdllist * NewLinkedListFromArray(void *base, size_t amount, size_t size);

stdlist * LinkedListToList(stdllist *);

stdcoll * LinkedListToCollection(stdllist *);

#endif