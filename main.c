#include"matrix.h"
#include<stdio.h>
int main(void){
	
	matrix* ONE = Mmake(4,4,MFORMAT(4, 4, {1,2,4,66},
			 		      {3,4,3,56},
			 	              {2,2,46,8},
			         	      {2,3,45,6}));
	Mprint(ONE);
	return 0;
}
