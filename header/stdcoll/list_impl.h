#ifndef __STD_LIST_IMPL_H__
#define __STD_LIST_IMPL_H__

#include "stdcoll/list.h"

typedef struct stdlist {
    stdcoll *m_super;
    void *m_stdlist_impl;

    void * (*m_GetAtIndex)(stdlist *std_list, const int idx);
    void * (*m_Front)(stdlist *std_list);
    void * (*m_Back)(stdlist *std_list);
    void * (*m_RemoveAtIndex)(stdlist *std_list, const int idx);
    void (*m_Super_Delete)(stdcoll *coll);
} stdlist;

stdlist * _List(
    void *t_stdlist_impl,
    int (*t_Add)(stdcoll *, void *),
    void * (*t_Remove)(stdcoll *, const void *),
    void (*t_ToArray)(stdcoll *, void *),
    int (*t_AddAll)(stdcoll *, stdcoll *const),
    size_t (*t_Size)(stdcoll *),
    int (*t_Contains)(stdcoll *),
    void * (*t_GetAtIndex)(stdlist *std_list, const int idx),
    void * (*t_Front)(stdlist *std_list),
    void * (*t_Back)(stdlist *std_list),
    void * (*t_RemoveAtIndex)(stdlist *std_list, const int idx),
    void (*t_ItemRelease)(void *),
    int (*t_ItemEquals)(void *, void *));

#endif