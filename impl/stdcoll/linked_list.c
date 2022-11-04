#include "stdcoll/list_impl.h"
#include "stdcoll/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    void *_obj;
    struct _node *_next;
} _node;

typedef struct std_linked_list {
    std_list *super;
    _node *front;
    _node *back;
    size_t sz;
} std_linked_list;

int _Add(std_collection *std_coll, const void *obj) {
}

void * _Remove(std_collection *std_coll, const void *obj) {
}

void _ToArray(std_collection *std_coll, void *output) {

}

int _AddAll(std_collection *std_coll, std_collection *const other_coll) {

}

void _Clear(std_collection *std_collection) {

}

size_t _Size(std_collection *std_coll) {
    printf("Got here!! %lu\n", ((std_linked_list *) Cast(std_coll))->sz);
    return ((std_linked_list *) Cast(std_coll))->sz;
}

int _Contains(std_collection *std_coll) {

}

void * _CastCollection(std_collection *std_coll) {

}

void * _GetAtIndex(std_list *std_list, const int idx) {

}

void * _Front(std_list *std_list) {

}

void * _Back(std_list *std_list) {

}

void * _RemoveAtIndex(std_list *std_list, const int idx) {

}

void * _CastList(std_list *std_list) {

}

std_collection * _ListToCollection(std_list *std_list) {

}

std_linked_list * _NewLinkedList() {

}

std_list * LinkedListToList(std_linked_list *linked_list) {
    return linked_list->super;
}

std_collection * LinkedListToCollection(std_linked_list *linked_list) {
    return ListToCollection(linked_list->super);
}

std_linked_list * NewLinkedList() {
    std_linked_list *_linked_list = malloc(sizeof(std_linked_list));
    
    _linked_list->super = _NewList(
        &(*_linked_list),
        _Add,
        _Remove,
        _ToArray,
        _AddAll,
        _Clear,
        _Size,
        _Contains,
        _GetAtIndex,
        _Front,
        _Back,
        _RemoveAtIndex);

    _linked_list->sz = (size_t) 0;
    _linked_list->back = malloc(sizeof(_node));
    _linked_list->front = malloc(sizeof(_node));

    _linked_list->back->_next = _linked_list->front;
    _linked_list->front->_next = _linked_list->back;

    return _linked_list;
}

std_linked_list * NewLinkedListFromArray(void *base, size_t amount, size_t size) {

}