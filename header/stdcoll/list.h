#ifndef _STD_COLL_LIST_H_
#define _STD_COLL_LIST_H_

#include "stdcoll/collection.h"

typedef struct stdlist stdlist;

void *ListGetAtIndex(stdlist *, const int idx);

int ListAddAtIndex(stdlist *, void *obj, const int idx);

void *ListFront(stdlist *);

void *ListBack(stdlist *);

void *ListRemoveAtIndex(stdlist *, const int idx);

void *ListCast(stdlist *);

stdcoll *ListSuper(stdlist *);

int ListAdd(stdlist *list, void *obj);

void *ListRemove(stdlist *list, const void *obj);

void ListToArray(stdlist *list, void *output);

int ListAddAll(stdlist *list, stdcoll *const other_coll);

void ListClear(stdlist *list);

int ListIsEmpty(stdlist *list);

size_t ListSize(stdlist *list);

int ListContains(stdlist *list);

void ListDelete(stdlist *list);

stditr *ListIterator(stdlist *list);

#endif