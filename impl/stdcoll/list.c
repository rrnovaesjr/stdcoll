#include "stdcoll/list_impl.h"
#include "stdcoll/collection_impl.h"
#include <stdio.h>
#include <stdlib.h>

void _InitializeList(
    std_list **this,
    void **std_list_impl,
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

    std_collection *super = malloc(sizeof(std_collection));
    (*this)->super = super;


    _InitializeCollection(
        &super,
        &(*std_list_impl), 
        _Add, 
        _Remove,
        _ToArray, 
        _AddAll, 
        _Clear, 
        _Size, 
        _Contains);

    (*this)->std_list_impl = *std_list_impl;
    (*this)->_GetAtIndex = _GetAtIndex;
    (*this)->_Front = _Front;
    (*this)->_Back = _Back;
    (*this)->_RemoveAtIndex = _RemoveAtIndex;
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