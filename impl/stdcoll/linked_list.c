#include "stdcoll/collection_impl.h"
#include "stdcoll/list_impl.h"
#include "stdcoll/linked_list.h"
#include "stdcoll/operators.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct stdnode {
    void *m_obj;
    struct stdnode *m_next;
    struct stdnode *m_prev;
} stdnode;

typedef struct stdllist {
    stdlist *m_super;
    stdnode *m_front;
    stdnode *m_back;
    size_t m_size;

    void (*m_Super_Delete)(stdcoll *coll);
} stdllist;

int _Add(stdcoll *coll, void *obj) {
    stdllist *llist = ListCast(CollectionCast(coll));
    stdnode *last = llist->m_back;
    stdnode *new_node = malloc(sizeof(stdnode));
    if (!new_node)
        return 0;
    new_node->m_prev = last;
    new_node->m_obj = obj;
    new_node->m_next = NULL;
    if (!last)
        llist->m_front = new_node;
    else
        last->m_next = new_node;
    llist->m_size++;
    llist->m_back = new_node;
    return 1;
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
    stdllist *llist = ListCast(CollectionCast(coll));
    return llist->m_size;
}

int _Contains(stdcoll *coll) {

}

void * _CastCollection(stdcoll *coll) {

}

void * _GetAtIndex(stdlist *list, const int idx) {
    stdllist *llist = ListCast(list);
    size_t size = llist->m_size;

    if (idx < 0 || idx >= size)
        return NULL;

    int i;
    stdnode *t = NULL;
    if (idx < (size >> 1)) {
        for (i = 0, t = llist->m_front; i < idx && t != NULL; i++, t = t->m_next);
    } else {
        for (i = (int) size - 1, t = llist->m_back; i > idx && t != NULL; i--, t = t->m_prev);
    }

    if (t == NULL)
        return NULL;
    return (void *) t->m_obj;
}

void _LinkedListDelete(stdcoll *coll) {
    stdllist *llist = ListCast(CollectionCast(coll));
    llist->m_Super_Delete(coll);
    free(llist);
}

void * _Front(stdlist *list) {
    return ((stdllist *) ListCast(list))->m_front ? 
        ((stdllist *) ListCast(list))->m_front->m_obj : NULL;
}

void * _Back(stdlist *list) {
    return ((stdllist *) ListCast(list))->m_back ? 
        ((stdllist *) ListCast(list))->m_back->m_obj : NULL;
}

void * _RemoveAtIndex(stdlist *list, const int idx) {
    stdllist *llist = ListCast(list);
    size_t size = llist->m_size;

    if (idx < 0 || idx >= size)
        return NULL;

    int i;
    stdnode *t = NULL;

    if (idx < (size >> 1)) {
        for (i = 0, t = llist->m_front; i < idx && t != NULL; i++, t = t->m_next);
    } else {
        for (i = (int) size - 1, t = llist->m_back; i > idx && t != NULL; i--, t = t->m_prev);
    }

    void *val = (void *) t->m_obj;
    stdnode *next = t->m_next;
    stdnode *prev = t->m_prev;

    if (!prev) {
        llist->m_front = next;
    } else {
        prev->m_next = next;
    }

    if (!next) {
        llist->m_back = prev;
    } else {
        next->m_prev = prev;
    }
    free(t);
    llist->m_size--;
    return val;
}

void * _CastList(stdlist *list) {

}

stdcoll * _ListToCollection(stdlist *list) {

}

stdllist * _NewLinkedList() {

}

stdlist * LinkedListSuper(stdllist *linked_list) {
    return linked_list->m_super;
}

stdcoll * LinkedListToCollection(stdllist *linked_list) {
    return ListSuper(linked_list->m_super);
}

stdllist * LinkedListI(void (*t_ItemRelease)(void *), int (*t_ItemEquals)(void *, void *)) {
    stdllist *llist = malloc(sizeof(stdllist));
    llist->m_super = _List(
        llist,
        _Add,
        _Remove,
        _ToArray,
        _AddAll,
        _Size,
        _Contains,
        _GetAtIndex,
        _Front,
        _Back,
        _RemoveAtIndex,
        t_ItemRelease,
        t_ItemEquals);
    llist->m_Super_Delete = llist->m_super->m_super->m_Delete;
    llist->m_super->m_super->m_Delete = _LinkedListDelete;
    llist->m_front = NULL;
    llist->m_back = NULL;
    llist->m_size = (size_t) 0;
    return llist;
}

stdllist * LinkedList() {
    return LinkedListI(free, _NaturalEquals);
}

stdllist * LinkedListFromArray(void *base, size_t amount, size_t size) {

}

inline int LinkedListAdd(stdllist *llist, void *obj)
{
    return ListAdd(LinkedListSuper(llist), obj);
}

inline void * LinkedListRemove(stdllist *llist, const void *obj)
{
    return ListRemove(LinkedListSuper(llist), obj);
}

inline int LinkedListAddAll(stdllist *llist, stdcoll *const other_coll)
{
    return ListAddAll(LinkedListSuper(llist), other_coll);
}

inline void LinkedListClear(stdllist *llist)
{
    ListClear(LinkedListSuper(llist));
}

inline int LinkedListIsEmpty(stdllist *llist)
{
    return ListIsEmpty(LinkedListSuper(llist));
}

inline size_t LinkedListSize(stdllist *llist)
{
    return ListSize(LinkedListSuper(llist));
}

inline int LinkedListContains(stdllist *llist)
{
    return 0;
}

inline void LinkedListDelete(stdllist *llist)
{
    ListDelete(LinkedListSuper(llist));
}

inline void * LinkedListGetAtIndex(stdllist *llist, const int idx) {
    return ListGetAtIndex(LinkedListSuper(llist), idx);
}

inline int LinkedListAddAtIndex(stdllist *llist, void *obj, const int idx) {
    return ListAddAtIndex(LinkedListSuper(llist), obj, idx);
}

inline void * LinkedListFront(stdllist *llist) 
{
    return ListFront(LinkedListSuper(llist));
}

inline void * LinkedListBack(stdllist *llist)
{
    return ListBack(LinkedListSuper(llist));
}

inline void * LinkedListRemoveAtIndex(stdllist *llist, const int idx)
{
    return ListRemoveAtIndex(LinkedListSuper(llist), idx);
}