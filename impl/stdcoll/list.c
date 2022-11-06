#include "stdcoll/list_impl.h"
#include "stdcoll/collection_impl.h"
#include <stdio.h>
#include <stdlib.h>

stdlist * _List(
    void *t_stdlist_impl,
    int (*t_Add)(stdcoll *, void *),
    void * (*t_Remove)(stdcoll *, const void *),
    void (*t_ToArray)(stdcoll *, void *),
    int (*t_AddAll)(stdcoll *, stdcoll *const),
    void (*t_Clear)(stdcoll *),
    size_t (*t_Size)(stdcoll *),
    int (*t_Contains)(stdcoll *),
    void (*t_Delete)(stdcoll *),
    void * (*t_GetAtIndex)(stdlist *std_list, const int idx),
    void * (*t_Front)(stdlist *std_list),
    void * (*t_Back)(stdlist *std_list),
    void * (*t_RemoveAtIndex)(stdlist *std_list, const int idx),
    void (*t_ItemRelease)(void *),
    int (*t_ItemEquals)(void *, void *)) {

    stdlist *list = malloc(sizeof(stdlist));
    list->m_super = _Collection(
        list, 
        t_Add, 
        t_Remove,
        t_ToArray, 
        t_AddAll, 
        t_Clear, 
        t_Size, 
        t_Contains,
        t_Delete,
        t_ItemRelease,
        t_ItemEquals);

    list->m_stdlist_impl = t_stdlist_impl;
    list->m_GetAtIndex = t_GetAtIndex;
    list->m_Front = t_Front;
    list->m_Back = t_Back;
    list->m_RemoveAtIndex = t_RemoveAtIndex;

    return list;
}

void * ListGetAtIndex(stdlist *std_list, const int idx) {
    return std_list->m_GetAtIndex(std_list, idx);
}

void * ListFront(stdlist *std_list) {
    return std_list->m_Front(std_list);
}

void * ListBack(stdlist *std_list) {
    return std_list->m_Back(std_list);
}

void * ListRemoveAtIndex(stdlist *std_list, const int idx) {
    return std_list->m_RemoveAtIndex(std_list, idx);
}

void * ListCast(stdlist *std_list) {
    return std_list->m_stdlist_impl;
}

stdcoll * ListSuper(stdlist *std_list) {
    return std_list->m_super;
}

void _ListClear(stdcoll *coll) {
    size_t size;

    while ((size = CollectionSize(coll)) > (size_t) 0) {
        void *obj = ListRemoveAtIndex(CollectionCast(coll), (int) size - 1);
        if (obj) {
            coll->m_ItemRelease(obj);
        }
    }
}

void _ListDelete(stdcoll *coll) {
    stdlist *list = CollectionCast(coll);
    _CollectionDelete(coll);
    free(list);
}