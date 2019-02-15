#ifndef VECTOR_H
#define VECTOR_H
//----------------------------------------------

#include <stddef.h>


typedef struct _Vector{
	char* head;
	char* tail;
	size_t size;
	int stride;
	int capacity;
} Vector;


void InitVec(Vector*, int);

void PushBack(Vector*, void*);

char const * GetElement(Vector const *, int);

void Erase(Vector*, int);

void Clear(Vector*);

int VecSize(Vector const *);

void FreeVec(Vector*);

//----------------------------------------------
#endif
