#ifndef __STD_COLL_IMPL_H__
#define __STD_COLL_IMPL_H__

#include "stdcoll/collection.h"

typedef struct stdcoll {
    void *m_stdcoll_impl;

    int (*m_Add)(stdcoll *, void *);
    void * (*m_Remove)(stdcoll *, const void *);
    void (*m_ToArray)(stdcoll *, void *);
    int (*m_AddAll)(stdcoll *, stdcoll *const);
    void (*m_Clear)(stdcoll *);
    size_t (*m_Size)(stdcoll *);
    int (*m_IsEmpty)(stdcoll *);
    int (*m_Contains)(stdcoll *);
    void (*m_Delete)(stdcoll *);
    void (*m_ItemRelease)(void *);
    int (*m_ItemEquals)(void *, void *);
} stdcoll;

stdcoll * _Collection(
    void *t_stdcoll_impl,
    int (*t_Add)(stdcoll *, void *),
    void * (*t_Remove)(stdcoll *, const void *),
    void (*t_ToArray)(stdcoll *, void *),
    int (*t_AddAll)(stdcoll *, stdcoll *const),
    void (*t_Clear)(stdcoll *),
    size_t (*t_Size)(stdcoll *),
    int (*t_IsEmpty)(stdcoll *),
    int (*t_Contains)(stdcoll *),
    void (*t_Delete)(stdcoll *),
    void (*t_ItemRelease)(void *),
    int (*t_ItemEquals)(void *, void *)
);

int _CollectionIsEmpty(stdcoll *);

void _CollectionDelete(stdcoll *);

#endif