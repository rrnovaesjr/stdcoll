#ifndef _STD_COLL_LIST_H_
#define _STD_COLL_LIST_H_

#include "stdcoll/collection.h"

typedef struct stdlist stdlist;

void * ListGetAtIndex(stdlist *, const int idx);

int ListAddAtIndex(stdlist *, void *obj, const int idx);

void * ListFront(stdlist *);

void * ListBack(stdlist *);

void * ListRemoveAtIndex(stdlist *, const int idx);

void * ListCast(stdlist *);

stdcoll * ListSuper(stdlist *);

#endif