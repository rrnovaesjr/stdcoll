#ifndef __STD_COLL_IMPL_H__
#define __STD_COLL_IMPL_H__

#include "stdcoll/collection.h"

typedef struct std_collection {
    void *std_coll_impl;

    int (*_Add)(std_collection *, const void *);
    void * (*_Remove)(std_collection *, const void *);
    void (*_ToArray)(std_collection *, void *);
    int (*_AddAll)(std_collection *, std_collection *const);
    void (*_Clear)(std_collection *);
    size_t (*_Size)(std_collection *);
    int (*_Contains)(std_collection *);
} std_collection;

std_collection * _NewCollection(
    void *std_coll_impl,
    int (*_Add)(std_collection *, const void *),
    void * (*_Remove)(std_collection *, const void *),
    void (*_ToArray)(std_collection *, void *),
    int (*_AddAll)(std_collection *, std_collection *const),
    void (*_Clear)(std_collection *),
    size_t (*_Size)(std_collection *),
    int (*_Contains)(std_collection *)
);

#endif