#include"matrix.h"
#include<stdio.h>

void Mprint(matrix* mat){
	for(i32 i=0 ; i<(mat->indr) ; i++){
		for(i32 j=0 ; j<(mat->indc) ; j++)
			printf("%d ", mat->data[i][j]);
		printf("\n");
		}
	printf("\n");
}

matrix* Msum(matrix* x, matrix* y, matrix* z){		
	if ( ( x->indr != y->indr ) || ( x->indc != y->indc ) ) return NULL;
	z->indr = x->indr;
	z->indc = x->indc;
	for(i32 i=0 ; i<(x->indr) ; i++)
		for(i32 j=0 ; j<(x->indc) ; j++)
			z->data[i][j] = x->data[i][j] + y->data[i][j]; 
	return x;
}

matrix* Msub(matrix* x, matrix* y, matrix* z){		
	if ( ( x->indr != y->indr ) || ( x->indc != y->indc ) ) return NULL;
	z->indr = x->indr;
	z->indc = x->indc;
	for(i32 i=0 ; i<(x->indr) ; i++)
		for(i32 j=0 ; j<(x->indc) ; j++)
			z->data[i][j] = x->data[i][j] - y->data[i][j]; 
	return x;
}

matrix* Mmul(matrix* x,matrix* y, matrix* z){
	if ( x->indc != y->indr) return NULL;
	z->indr = x->indr;
	z->indc = y->indc;
	for(i32 i=0 ; i<(z->indr) ; i++)
		for(i32 j=0 ; j<(z->indc) ; j++){
			i32 s=0;
			for(i32 l=0 ; l<(x->indc) ; l++)
				s += x->data[i][l]*y->data[l][j];
			z->data[i][j] = s;
			}
	return x;
}

