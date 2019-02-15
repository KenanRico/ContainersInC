#include "vector.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>



void InitVec(Vector* vp, int stride){
	vp->stride = stride; //bytes
	vp->size = 0;
	vp->capacity = 1;
	vp->head = malloc(vp->capacity*vp->stride);
	vp->tail = vp->head;
}

void PushBack(Vector* vp, void* ele){
	++vp->size;
	//if(vp->size%vp->capacity==0){
	if(vp->size>vp->capacity){
		vp->capacity *= 2;
		char* new_alloc = malloc(vp->capacity*vp->stride);
		//copy all current data to new alloc'ed location
		if(vp->head!=NULL){
			memcpy(new_alloc, vp->head, vp->capacity*vp->stride);
			free(vp->head);
		}
		vp->head = new_alloc;
		vp->tail = vp->head+(vp->size-1)*vp->stride;
	}
	memcpy(vp->tail, ele, vp->stride);
	vp->tail += vp->stride;
}

char const * GetElement(Vector const * vp, int i){
	return vp->head+i*vp->stride;
}

void Erase(Vector* vp, int i){
	char* erase_ptr = vp->head+i*vp->stride;
	memmove(erase_ptr, erase_ptr+vp->stride, (vp->size-i)*vp->stride);
	--vp->size;
	vp->tail -= vp->stride;
}

void Clear(Vector* vp){
	vp->tail = vp->head;
	vp->size = 0;
}

int VecSize(Vector const * vp){
	return vp->size;
}

void FreeVec(Vector* vp){
	free(vp->head);
}
