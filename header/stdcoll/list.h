#ifndef _STD_COLL_LIST_H_
#define _STD_COLL_LIST_H_

#include "stdcoll/collection.h"

typedef struct stdlist stdlist;

inline int ListAdd(stdlist *, void *obj);

inline void * ListRemove(stdlist *, const void *obj);

inline void ListToArray(stdlist *, void *output);

inline int ListAddAll(stdlist *, stdcoll *const other_coll);

inline void ListClear(stdlist *);

inline int ListIsEmpty(stdlist *);

inline size_t ListSize(stdlist *);

inline int ListContains(stdlist *);

inline void ListDelete(stdlist *);

void * ListGetAtIndex(stdlist *, const int idx);

int ListAddAtIndex(stdlist *, void *obj, const int idx);

void * ListFront(stdlist *);

void * ListBack(stdlist *);

void * ListRemoveAtIndex(stdlist *, const int idx);

void * ListCast(stdlist *);

stdcoll * ListSuper(stdlist *);

inline int ListAdd(stdlist *list, void *obj)
{
    return CollectionAdd(ListSuper(list), obj);
}

inline void *ListRemove(stdlist *list, const void *obj)
{
    CollectionRemove(ListSuper(list), obj);
}

inline void ListToArray(stdlist *list, void *output)
{
    CollectionToArray(ListSuper(list), output);
}

inline int ListAddAll(stdlist *list, stdcoll *const other_coll)
{
    CollectionAddAll(ListSuper(list), other_coll);
}

inline void ListClear(stdlist *list)
{
    CollectionClear(ListSuper(list));
}

inline int ListIsEmpty(stdlist *list)
{
    return CollectionIsEmpty(ListSuper(list));
}

inline size_t ListSize(stdlist *list)
{
    return CollectionSize(ListSuper(list));
}

inline int ListContains(stdlist *list)
{
    return CollectionContains(ListSuper(list));
}

inline void ListDelete(stdlist *list)
{
    CollectionDelete(ListSuper(list));
}

#endif