#ifndef __STD_LIST_IMPL_H__
#define __STD_LIST_IMPL_H__

#include "stdcoll/list.h"

typedef struct std_list {
    std_collection *super;
    void *std_list_impl;

    void * (*_GetAtIndex)(std_list *std_list, const int idx);
    void * (*_Front)(std_list *std_list);
    void * (*_Back)(std_list *std_list);
    void * (*_RemoveAtIndex)(std_list *std_list, const int idx);
} std_list;

std_list * _NewList(
    void *std_list_impl,
    int (*_Add)(std_collection *, const void *),
    void * (*_Remove)(std_collection *, const void *),
    void (*_ToArray)(std_collection *, void *),
    int (*_AddAll)(std_collection *, std_collection *const),
    void (*_Clear)(std_collection *),
    size_t (*_Size)(std_collection *),
    int (*_Contains)(std_collection *),
    void * (*_GetAtIndex)(std_list *std_list, const int idx),
    void * (*_Front)(std_list *std_list),
    void * (*_Back)(std_list *std_list),
    void * (*_RemoveAtIndex)(std_list *std_list, const int idx));

#endif