#include"matrix.h"
#include<stdio.h>
#include<stdlib.h>

matrix* Mmake(u8 rows, u8 cols, i32 arr[rows][cols]){
	matrix* tmp = (matrix*)malloc(sizeof(matrix) + rows * cols * sizeof(i32));
	if(!tmp) return NULL;
	tmp->dimr = rows;
	tmp->dimc = cols;
	tmp->data = (i32*)(tmp + 1);
	for(i8 i=0 ; i<rows ; i++)
		for(i8 j=0 ; j<cols ; j++)
			tmp->data[i * tmp->dimc + j] = arr[i][j];
	return tmp;
}

void Mprint(const matrix* mat){
	for(i32 i=0 ; i<(mat->dimr) ; i++){
		for(i32 j=0 ; j<(mat->dimc) ; j++)
			printf("%d ", mat->data[i * mat->dimc + j] );
		printf("\n");
		}
	printf("\n");
}

matrix* Msum(const matrix* x, const matrix* y, matrix* z){		
	if ( ( x->dimr != y->dimr ) || ( x->dimc != y->dimc ) ) return NULL;
	z->dimr = x->dimr;
	z->dimc = x->dimc;
	for(i32 i=0 ; i<(x->dimr) ; i++)
		for(i32 j=0 ; j<(x->dimc) ; j++)
			z->data[i * x->dimc + j]  = x->data[i * x->dimc + j]  + y->data[i * x->dimc + j] ; 
	return x;
}

matrix* Msub(const matrix* x, const matrix* y, matrix* z){		
	if ( ( x->dimr != y->dimr ) || ( x->dimc != y->dimc ) ) return NULL;
	z->dimr = x->dimr;
	z->dimc = x->dimc;
	for(i32 i=0 ; i<(x->dimr) ; i++)
		for(i32 j=0 ; j<(x->dimc) ; j++)
			z->data[i * z->dimc + j]  = x->data[i * x->dimc + j]  - y->data[i * y->dimc + j] ; 
	return x;
}

matrix* Mmul(const matrix* x,const matrix* y, matrix* z){
	if ( x->dimc != y->dimr) return NULL;
	z->dimr = x->dimr;
	z->dimc = y->dimc;
	for(i32 i=0 ; i<(z->dimr) ; i++)
		for(i32 j=0 ; j<(z->dimc) ; j++){
			i32 s=0;
			for(i32 l=0 ; l<(x->dimc) ; l++)
				s += x->data[i * x->dimc + j] *y->data[i * y->dimc + j] ;
			z->data[i * z->dimc + j]  = s;
			}
	return x;
}

void Mcpy(const matrix* src, matrix* dest){
	dest->dimr = src->dimr;
	dest->dimc = src->dimc;
	for(i32 i=0 ; i<(src->dimr) ; i++)
		for(i32 j=0 ; j<(src->dimc) ; j++)
			dest->data[i * dest->dimc + j]  = src->data[i * src->dimc + j] ;
}

void Mzeros(matrix* x,const i32 dim){
	x->dimr = dim;
	x->dimc = dim;
	for(i32 i=0 ; i<(x->dimr) ; i++)
		for(i32 j=0 ; j<(x->dimc) ; j++)
			x->data[i * x->dimc + j]  = 0;
}

void Mones(matrix* x,const i32 dim){
	Mzeros(x, dim);
	for(i32 i=0 ; i<(x->dimr) ; i++)
		x->data[i * x->dimc + i]  = 1;
}

void Mscalar_mul(const i32 scalar ,const matrix* src, matrix* res){
	res->dimr = src->dimr;
	res->dimc = src->dimc;
	for(i32 i=0 ; i<(res->dimr) ; i++)
		for(i32 j=0 ; j<(res->dimc) ; j++)
			res->data[i * res->dimc + j]  = scalar*src->data[i * src->dimc + j] ;
}

void Mtranspose(const matrix* src ,matrix* res){
	for(i32 i=0 ; i<(src->dimr) ; i++)
		for(i32 j=0 ; j<(src->dimc) ; j++)
			res->data[i * src->dimc + j]  = src->data[i * src->dimc + j] ;
}


