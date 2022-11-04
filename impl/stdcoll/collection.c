#include "stdcoll/collection_impl.h"
#include <stdio.h>
#include <stdlib.h>

std_collection * _NewCollection(
    void *std_coll_impl,
    int (*_Add)(std_collection *, const void *),
    void * (*_Remove)(std_collection *, const void *),
    void (*_ToArray)(std_collection *, void *),
    int (*_AddAll)(std_collection *, std_collection *const),
    void (*_Clear)(std_collection *),
    size_t (*_Size)(std_collection *),
    int (*_Contains)(std_collection *)) {

    std_collection *stdcoll = malloc(sizeof(std_collection));

    stdcoll->std_coll_impl = &(*std_coll_impl);
    stdcoll->_Add = _Add;
    stdcoll->_Remove = _Remove;
    stdcoll->_ToArray = _ToArray;
    stdcoll->_Clear = _Clear;
    stdcoll->_Size = _Size;
    stdcoll->_Contains = _Contains;

    return stdcoll;
}

int Add(std_collection *std_coll, const void *obj) {
    std_coll->_Add(std_coll, obj);
}

void * Remove(std_collection *std_coll, const void *obj) {
    return std_coll->_Remove(std_coll, obj);
}

void ToArray(std_collection *std_coll, void *output) {
    std_coll->_ToArray(std_coll, output);
}

int AddAll(std_collection *std_coll, std_collection *const other_coll) {
    return std_coll->_AddAll(std_coll, other_coll);
}

void Clear(std_collection *std_collection) {
    std_collection->_Clear(std_collection);
}

unsigned long Size(std_collection *std_coll) {
    return std_coll->_Size(std_coll);
}

int Contains(std_collection *std_coll) {
    return std_coll->_Contains(std_coll);
}

void * CastCollection(std_collection *std_coll) {
    return std_coll->std_coll_impl;
}

void * Cast(std_collection *std_coll) {
    return std_coll->std_coll_impl;
}