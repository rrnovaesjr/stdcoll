#ifndef __STD_ITR_IMPL_H__
#define __STD_ITR_IMPL_H__

#include "stditr/iterator.h"

typedef struct stditr
{
    void *m_itr_data;
    int (*m_IteratorHasNext)(const stditr *);
    void *(*m_IteratorGet)(const stditr *);
    stditr *(*m_IteratorNext)(stditr *);
    stditr *(*m_IteratorRemove)(stditr *);
    void (*m_IteratorDelete)(stditr *);
} stditr;

stditr *_IteratorCreate(void *t_itr_data,
                        int (*t_IteratorHasNext)(const stditr *),
                        void *(*t_IteratorGet)(const stditr *),
                        stditr *(*t_IteratorNext)(stditr *),
                        stditr *(*t_IteratorRemove)(stditr *));

#endif