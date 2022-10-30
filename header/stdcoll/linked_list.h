#ifndef _STDCOLL_LINKED_LIST_H_
#define _STDCOLL_LINKED_LIST_H_

#include "stdcoll/collection.h"
#include "stdcoll/list.h"
#include <stdio.h>

typedef struct std_linked_list std_linked_list;

std_linked_list * NewLinkedList();

std_linked_list * NewLinkedListFromArray(void *base, size_t amount, size_t size);

std_list * LinkedListToList(std_linked_list *);

std_collection * LinkedListToCollection(std_linked_list *);

#endif