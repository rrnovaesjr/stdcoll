#include "stdcoll/list_impl.h"
#include "stdcoll/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct stdnode {
    void *m_obj;
    struct stdnode *m_next;
} stdnode;

typedef struct stdllist {
    stdlist *m_super;
    stdnode *m_front;
    stdnode *m_back;
    size_t m_size;
} stdllist;

int _Add(stdcoll *coll, const void *obj) {
}

void * _Remove(stdcoll *coll, const void *obj) {
}

void _ToArray(stdcoll *coll, void *output) {

}

int _AddAll(stdcoll *coll, stdcoll *const other_coll) {

}

void _Clear(stdcoll *coll) {

}

size_t _Size(stdcoll *coll) {
    return ((stdllist *) Cast(coll))->m_size;
}

int _Contains(stdcoll *coll) {

}

void * _CastCollection(stdcoll *coll) {

}

void * _GetAtIndex(stdlist *list, const int idx) {

}

void * _Front(stdlist *list) {

}

void * _Back(stdlist *list) {

}

void * _RemoveAtIndex(stdlist *list, const int idx) {

}

void * _CastList(stdlist *list) {

}

stdcoll * _ListToCollection(stdlist *list) {

}

stdllist * _NewLinkedList() {

}

stdlist * LinkedListToList(stdllist *linked_list) {
    return linked_list->m_super;
}

stdcoll * LinkedListToCollection(stdllist *linked_list) {
    return ListToCollection(linked_list->m_super);
}

stdllist * NewLinkedList() {
    stdllist *llist = malloc(sizeof(stdllist));
    
    llist->m_super = _NewList(
        &(*llist),
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

    llist->m_size = (size_t) 0;
    llist->m_back = malloc(sizeof(stdnode));
    llist->m_front = malloc(sizeof(stdnode));

    llist->m_back->m_next = llist->m_front;
    llist->m_front->m_next = llist->m_back;

    return llist;
}

stdllist * NewLinkedListFromArray(void *base, size_t amount, size_t size) {

}