#ifndef __STD_ITR_H__
#define __STD_ITR_H__

#include "stdcoll/collection.h"

typedef struct stditr stditr;

int IteratorHasNext(const stditr *);

void *IteratorGet(const stditr *);

stditr *IteratorNext(stditr *);

#endif