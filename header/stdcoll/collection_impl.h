#ifndef __STD_COLL_IMPL_H__
#define __STD_COLL_IMPL_H__

#include "stdcoll/collection.h"

typedef struct stdcoll {
    void *m_stdcoll_impl;

    int (*m_Add)(stdcoll *, const void *);
    void * (*m_Remove)(stdcoll *, const void *);
    void (*m_ToArray)(stdcoll *, void *);
    int (*m_AddAll)(stdcoll *, stdcoll *const);
    void (*m_Clear)(stdcoll *);
    size_t (*m_Size)(stdcoll *);
    int (*m_IsEmpty)(stdcoll *);
    int (*m_Contains)(stdcoll *);
    void (*m_ReleaseFunction)(void *);
    int (*m_EqualsFunction)(void *, void *);
} stdcoll;

stdcoll * _NewCollection(
    void *t_stdcoll_impl,
    int (*t_Add)(stdcoll *, const void *),
    void * (*t_Remove)(stdcoll *, const void *),
    void (*t_ToArray)(stdcoll *, void *),
    int (*t_AddAll)(stdcoll *, stdcoll *const),
    void (*t_Clear)(stdcoll *),
    size_t (*t_Size)(stdcoll *),
    int (*t_IsEmpty)(stdcoll *),
    int (*t_Contains)(stdcoll *),    
    void (*t_ReleaseFunction)(void *),
    int (*t_EqualsFunction)(void *, void *)
);

int _IsEmpty(stdcoll *);

#endif