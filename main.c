#include"matrix.h"
#include<stdio.h>
int main(void){
	
	matrix* ONE = MAT(4, 4, {1,2,4,66},
			        {3,4,3,56},
	      	                {2,2,46,8},
			        {2,3,45,6});
	matrix* two = Mmul(Mones(4),Mones(4));	
	Mprint(two);
	return 0;
}
