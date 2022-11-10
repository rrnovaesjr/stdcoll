#ifndef __STD_ITR_H__
#define __STD_ITR_H__

typedef struct stditr stditr;

int IteratorHasNext(const stditr *);

void *IteratorGet(const stditr *);

stditr *IteratorNext(stditr *);

void IteratorDelete(stditr *);

#endif