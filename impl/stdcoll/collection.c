#include "stdcoll/collection_impl.h"
#include <stdio.h>
#include <stdlib.h>

int _CollectionIsEmpty(stdcoll *coll);

void _CollectionDelete(stdcoll *coll);

stdcoll *_Collection(
    void *t_stdcoll_impl,
    int (*t_Add)(stdcoll *, void *),
    void *(*t_Remove)(stdcoll *, const void *),
    void (*t_ToArray)(stdcoll *, void *),
    int (*t_AddAll)(stdcoll *, stdcoll *const),
    void (*t_Clear)(stdcoll *),
    size_t (*t_Size)(stdcoll *),
    int (*t_Contains)(stdcoll *),
    stditr *(*t_Iterator)(stdcoll *),
    void (*t_ItemRelease)(void *),
    int (*t_ItemEquals)(void *, void *))
{

    stdcoll *coll = malloc(sizeof(stdcoll));
    coll->m_IsEmpty = _CollectionIsEmpty;
    coll->m_Delete = _CollectionDelete;

    coll->m_stdcoll_impl = t_stdcoll_impl;
    coll->m_Add = t_Add;
    coll->m_Remove = t_Remove;
    coll->m_ToArray = t_ToArray;
    coll->m_Clear = t_Clear;
    coll->m_Size = t_Size;
    coll->m_Contains = t_Contains;
    coll->m_Iterator = t_Iterator;
    coll->m_ItemRelease = t_ItemRelease;
    coll->m_ItemEquals = t_ItemEquals;

    return coll;
}

int CollectionAdd(stdcoll *std_coll, void *obj)
{
    std_coll->m_Add(std_coll, obj);
}

void *CollectionRemove(stdcoll *std_coll, const void *obj)
{
    return std_coll->m_Remove(std_coll, obj);
}

void CollectionToArray(stdcoll *std_coll, void *output)
{
    std_coll->m_ToArray(std_coll, output);
}

int CollectionAddAll(stdcoll *std_coll, stdcoll *const other_coll)
{
    return std_coll->m_AddAll(std_coll, other_coll);
}

void CollectionClear(stdcoll *coll)
{
    coll->m_Clear(coll);
}

unsigned long CollectionSize(stdcoll *std_coll)
{
    return std_coll->m_Size(std_coll);
}

int CollectionIsEmpty(stdcoll *coll)
{
    return coll->m_IsEmpty(coll);
}

int CollectionContains(stdcoll *std_coll)
{
    return std_coll->m_Contains(std_coll);
}

stditr *CollectionIterator(stdcoll *coll)
{
    return coll->m_Iterator(coll);
}

void CollectionDelete(stdcoll *coll)
{
    coll->m_Delete(coll);
}

void *CollectionCast(stdcoll *std_coll)
{
    return std_coll->m_stdcoll_impl;
}

int _CollectionIsEmpty(stdcoll *coll)
{
    return CollectionSize(coll) == (size_t)0;
}

void _CollectionDelete(stdcoll *coll)
{
    CollectionClear(coll);
    free(coll);
}