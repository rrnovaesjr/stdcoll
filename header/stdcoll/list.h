#ifndef _STD_COLL_LIST_H_
#define _STD_COLL_LIST_H_

#include "stdcoll/collection.h"

typedef struct std_list std_list;

void * GetAtIndex(std_list *, const int idx);

int AddAtIndex(std_list *, void *obj, const int idx);

void * Front(std_list *);

void * Back(std_list *);

void * RemoveAtIndex(std_list *, const int idx);

void * CastList(std_list *);

std_collection * ListToCollection(std_list *);

#endif