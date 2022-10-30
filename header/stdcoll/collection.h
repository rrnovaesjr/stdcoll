#ifndef __STD_COLL_H__
#define __STD_COLL_H__

#include <stdio.h>

typedef struct std_collection std_collection;

int Add(std_collection *, const void *obj);

void * Remove(std_collection *, const void *obj);

void ToArray(std_collection *, void *output);

int AddAll(std_collection *, std_collection *const other_coll);

void Clear(std_collection *);

size_t Size(std_collection *);

int Contains(std_collection *);

void * Cast(std_collection *);

#endif