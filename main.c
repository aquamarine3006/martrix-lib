#include"matrix.h"
#include<stdio.h>
int main(void){
	
	matrix* ONE = &(matrix){
		.indr = 4,
		.indc = 4,
		.data = {{1,2,4,66},
			 {3,4,3,56},
			 {2,2,46,8},
			 {2,3,45,6}}
	};
	matrix* TWO = &(matrix){ 
		.indr = 4,
		.indc = 3,
		.data = {{3,4,1,5},
			 {2,9,1,6},
			 {2,3,4,6}}
	};
			
	Mprint(ONE);
	Mprint(TWO);

	matrix* RES=&(matrix){0};

	if (NULL == Mmul(ONE,TWO,RES))
		printf("ERROR:Dimension Error");
	Mprint(RES);
	return 0;
}
