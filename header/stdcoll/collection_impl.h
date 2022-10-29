#ifndef __STD_COLL_IMPL_H__
#define __STD_COLL_IMPL_H__

#include "stdcoll/collection.h"

typedef struct std_collection {
    const void *const std_coll_impl;
    int (*_hash_function)(void *const);
    int (*_equals_compare_function)(void *const, void *const);

    int (*_Add)(std_collection *, const void *obj);
    void (*_Remove)(std_collection *std_coll, const void *obj);
    void (*_Iterate)(std_collection *std_coll, void (*iterate_function)(void *const));
    int (*_AddAll)(std_collection *std_coll, std_collection *const other_coll);
    void (*_Clear)(std_collection *std_collection);
    unsigned long (*_Size)(std_collection *std_coll);
    int (*_Contains)(std_collection *std_coll);
} std_collection;

std_collection * NewStdCollection(int (*hash_function)(void *const), int (*equals_compare_function)(void *const, void *const));

void InitializeStdCollection(std_collection *std_coll, int (*hash_function)(void *const), int (*equals_compare)(void *const, void *const));

#endif