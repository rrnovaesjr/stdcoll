#ifndef __STD_COLL_H__
#define __STD_COLL_H__

#include <stdio.h>

typedef struct stdcoll stdcoll;

int Add(stdcoll *, const void *obj);

void * Remove(stdcoll *, const void *obj);

void ToArray(stdcoll *, void *output);

int AddAll(stdcoll *, stdcoll *const other_coll);

void Clear(stdcoll *);

size_t Size(stdcoll *);

int Contains(stdcoll *);

void * CastCollection(stdcoll *);

#endif