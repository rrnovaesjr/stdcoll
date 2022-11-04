#ifndef _STD_COLL_LIST_H_
#define _STD_COLL_LIST_H_

#include "stdcoll/collection.h"

typedef struct stdlist stdlist;

void * GetAtIndex(stdlist *, const int idx);

int AddAtIndex(stdlist *, void *obj, const int idx);

void * Front(stdlist *);

void * Back(stdlist *);

void * RemoveAtIndex(stdlist *, const int idx);

void * CastList(stdlist *);

stdcoll * ListToCollection(stdlist *);

#endif