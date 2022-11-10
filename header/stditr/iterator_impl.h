#ifndef __STD_ITR_IMPL_H__
#define __STD_ITR_IMPL_H__

#include "stditr/iterator.h"

typedef struct stditr
{
    void *m_itr_data;
    int (*m_IteratorHasNext)(const stditr *);
    void *(*IteratorGet)(const stditr *);
    stditr *(*m_IteratorNext)(stditr *);
} stditr;

stditr *_IteratorCreate(void *m_itr_data,
                        int (*m_IteratorHasNext)(const stditr *),
                        void *(*IteratorGet)(const stditr *),
                        stditr * (*m_IteratorNext)(stditr *));

#endif