#include "stditr/iterator_impl.h"
#include <stdlib.h>

int IteratorHasNext(const stditr *itr)
{
    return itr->m_IteratorHasNext(itr);
}

void *IteratorGet(const stditr *itr)
{
    return itr->m_IteratorGet(itr);
}

stditr *IteratorNext(stditr *itr)
{
    return itr->m_IteratorNext(itr);
}

void IteratorDelete(stditr *itr) 
{
    itr->m_IteratorDelete(itr);
}

void _IteratorDelete(stditr *itr)
{
    free(itr->m_itr_data);
    free(itr);
}

stditr *_IteratorCreate(void *t_itr_data,
                        int (*t_IteratorHasNext)(const stditr *),
                        void *(*t_IteratorGet)(const stditr *),
                        stditr *(*t_IteratorNext)(stditr *))
{
    stditr *itr = malloc(sizeof(stditr));
    itr->m_itr_data = t_itr_data;
    itr->m_IteratorGet = t_IteratorGet;
    itr->m_IteratorHasNext = t_IteratorHasNext;
    itr->m_IteratorNext = t_IteratorNext;
    itr->m_IteratorDelete = _IteratorDelete;

    return itr;
}