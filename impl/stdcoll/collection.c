#include "stdcoll/collection_impl.h"
#include <stdio.h>
#include <stdlib.h>

stdcoll * _NewCollection(
    void *t_stdcoll_impl,
    int (*t_Add)(stdcoll *, const void *),
    void * (*t_Remove)(stdcoll *, const void *),
    void (*t_ToArray)(stdcoll *, void *),
    int (*t_AddAll)(stdcoll *, stdcoll *const),
    void (*t_Clear)(stdcoll *),
    size_t (*t_Size)(stdcoll *),
    int (*t_Contains)(stdcoll *),    
    void (*t_ReleaseFunction)(void *),
    int (*t_EqualsFunction)(void *, void *)) {

    stdcoll *coll = malloc(sizeof(stdcoll));

    coll->m_stdcoll_impl = t_stdcoll_impl;
    coll->m_Add = t_Add;
    coll->m_Remove = t_Remove;
    coll->m_ToArray = t_ToArray;
    coll->m_Clear = t_Clear;
    coll->m_Size = t_Size;
    coll->m_Contains = t_Contains;
    coll->m_ReleaseFunction = t_ReleaseFunction;
    coll->m_EqualsFunction = t_EqualsFunction;

    return coll;
}

int Add(stdcoll *std_coll, const void *obj) {
    std_coll->m_Add(std_coll, obj);
}

void * Remove(stdcoll *std_coll, const void *obj) {
    return std_coll->m_Remove(std_coll, obj);
}

void ToArray(stdcoll *std_coll, void *output) {
    std_coll->m_ToArray(std_coll, output);
}

int AddAll(stdcoll *std_coll, stdcoll *const other_coll) {
    return std_coll->m_AddAll(std_coll, other_coll);
}

void Clear(stdcoll *coll) {
    coll->m_Clear(coll);
}

unsigned long Size(stdcoll *std_coll) {
    return std_coll->m_Size(std_coll);
}

int Contains(stdcoll *std_coll) {
    return std_coll->m_Contains(std_coll);
}

void * CastCollection(stdcoll *std_coll) {
    return std_coll->m_stdcoll_impl;
}