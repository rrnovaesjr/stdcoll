#ifndef __STD_COLL_H__
#define __STD_COLL_H__

#include <stdio.h>
#include "stditr/iterator.h"

typedef struct stdcoll stdcoll;

int CollectionAdd(stdcoll *, void *obj);

void *CollectionRemove(stdcoll *, const void *obj);

void CollectionToArray(stdcoll *, void *output);

int CollectionAddAll(stdcoll *, stdcoll *const other_coll);

void CollectionClear(stdcoll *);

int CollectionIsEmpty(stdcoll *);

size_t CollectionSize(stdcoll *);

int CollectionContains(stdcoll *);

void CollectionDelete(stdcoll *);

void *CollectionCast(stdcoll *);

stditr *CollectionIterator(stdcoll *);

#endif