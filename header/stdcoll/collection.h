#ifndef __STD_COLL_H__
#define __STD_COLL_H__

typedef struct std_collection std_collection;

int Add(std_collection *std_coll, const void *obj);

void * Remove(std_collection *std_coll, const void *obj);

void Iterate(std_collection *std_coll, void (*iterate_function)(void *const));

int AddAll(std_collection *std_coll, std_collection *const other_coll);

void Clear(std_collection *std_collection);

unsigned long Size(std_collection *std_coll);

int Contains(std_collection *std_coll);

#endif