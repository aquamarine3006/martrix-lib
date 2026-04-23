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

matrix* Msum(const matrix* x, const matrix* y){	
	if ( ( x->dimr != y->dimr ) || ( x->dimc != y->dimc ) ) return NULL;
	i32 arr[x->dimr][x->dimc];	
	for(i32 i=0 ; i<(x->dimr) ; i++)
		for(i32 j=0 ; j<(x->dimc) ; j++)
			arr[i][j]  = x->data[i * x->dimc + j] + y->data[i * x->dimc + j] ; 
	return Mmake(x->dimr,x->dimc,arr);
}

matrix* Msub(const matrix* x, const matrix* y){		
	if ( ( x->dimr != y->dimr ) || ( x->dimc != y->dimc ) ) return NULL;
	i32 arr[x->dimr][x->dimc];	
	for(i32 i=0 ; i<(x->dimr) ; i++)
		for(i32 j=0 ; j<(x->dimc) ; j++)
			arr[i][j]  = x->data[i * x->dimc + j] - y->data[i * x->dimc + j] ; 
	return Mmake(x->dimr,x->dimc,arr);
}

matrix* Mmul(const matrix* x,const matrix* y){
	if ( x->dimc != y->dimr) return NULL;
	i32 arr[x->dimr][y->dimc];
	for(i32 i=0 ; i<(x->dimr) ; i++)
		for(i32 j=0 ; j<(y->dimc) ; j++){
			i32 s=0;
			for(i32 l=0 ; l<(x->dimc) ; l++)
				s += x->data[i * x->dimc + l] *y->data[l * y->dimc + j] ;
			arr[i][j] = s;
			}
	return Mmake(x->dimr,y->dimc,arr);;
}

matrix* Mcpy(const matrix* src){
	i32 arr[src->dimr][src->dimc];
	for(i32 i=0 ; i<(src->dimr) ; i++)
		for(i32 j=0 ; j<(src->dimc) ; j++)
			arr[i][j] = src->data[i * src->dimc + j] ;
	return  Mmake(src->dimr,src->dimc,arr);

}

matrix* Mzeros(const i32 rows,const i32 cols){
	int arr[rows][cols];
	for(i8 i=0 ; i<(rows) ; i++)
		for(i8 j=0 ; j<(cols) ; j++)
			arr[i][j] = 0;
	return Mmake(rows,cols,arr);
}

matrix* Mones(const i32 dim){
	matrix* x = Mzeros(dim, dim);
	for(i32 i=0 ; i<(x->dimr) ; i++)
		x->data[i * x->dimc + i]  = 1;
	return x;
}

matrix* Mscalar_mul(const i32 scalar ,const matrix* src){
	i32 arr[src->dimr][src->dimc];
	for(i32 i=0 ; i<(src->dimr) ; i++)
		for(i32 j=0 ; j<(src->dimc) ; j++)
			arr[i][j]  = scalar*src->data[i * src->dimc + j] ;
	return Mmake(src->dimr, src->dimc, arr);
}

matrix*  Mtranspose(const matrix* src){
	i32 arr[src->dimr][src->dimc];
	for(i32 i=0 ; i<(src->dimr) ; i++)
		for(i32 j=0 ; j<(src->dimc) ; j++)
			arr[j][i]  = src->data[i * src->dimc + j] ;
	return  Mmake(src->dimr, src->dimc, arr);
}


