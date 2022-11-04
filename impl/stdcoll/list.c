#include "stdcoll/list_impl.h"
#include "stdcoll/collection_impl.h"
#include <stdio.h>
#include <stdlib.h>

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
    void * (*_RemoveAtIndex)(std_list *std_list, const int idx)) {

    std_list *stdlist = malloc(sizeof(std_list));
    stdlist->super = _NewCollection(
        &(*std_list_impl), 
        _Add, 
        _Remove,
        _ToArray, 
        _AddAll, 
        _Clear, 
        _Size, 
        _Contains);

    stdlist->std_list_impl = &(*std_list_impl);
    stdlist->_GetAtIndex = _GetAtIndex;
    stdlist->_Front = _Front;
    stdlist->_Back = _Back;
    stdlist->_RemoveAtIndex = _RemoveAtIndex;

    return stdlist;
}

void * GetAtIndex(std_list *std_list, const int idx) {
    return std_list->_GetAtIndex(std_list, idx);
}

void * Front(std_list *std_list) {
    return std_list->_Front(std_list);
}

void * Back(std_list *std_list) {
    return std_list->_Back(std_list);
}

void * RemoveAtIndex(std_list *std_list, const int idx) {
    return std_list->_RemoveAtIndex(std_list, idx);
}

void * CastList(std_list *std_list) {
    return std_list->std_list_impl;
}

std_collection * ListToCollection(std_list *std_list) {
    return std_list->super;
}