#include <stdio.h>
#include "vector.h"


int main(void){
	//init vector
	Vector vec;
	InitVec(&vec, sizeof(double));
	//fill vector
	for(int i=0; i<10; ++i){
		double d = (double)i;
		PushBack(&vec, (void*)&d);
	}
	//print vector
	Erase(&vec, 3);
	Erase(&vec, 6);
	printf("\n");
	for(int i=0; i<VecSize(&vec); ++i){
		printf("%f ", *((double*)GetElement(&vec, i)));
		//printf("%p ", (void*)GetElement(&vec, i));
	}
	printf("\n");
	//free vector
	FreeVec(&vec);
	return 0;
}
