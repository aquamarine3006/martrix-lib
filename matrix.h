#ifndef MATRIX_H
#define MATRIX_H
#include<stdint.h>
#define MFORMAT(dimr,dimc, ...) ((i32[dimr][dimc]){__VA_ARGS__})

typedef int8_t i8;
typedef uint8_t u8;
typedef int32_t i32;
typedef uint32_t u32;

typedef struct{
	i32 dimr,dimc;
	i32 * data;
} matrix;

matrix* Mmake(u8 rows,u8 cols,i32 arr[rows][cols]);
void Mprint(const matrix*);
matrix* Msum(const matrix*,const matrix*,matrix*);
matrix* Msub(const matrix*,const matrix*,matrix*);
matrix* Mmul(const matrix*,const matrix*,matrix*);
void Mcpy(const matrix*,matrix*);
void Mzeros(matrix*,const i32);
void Mones(matrix*,const i32);
void Mscalar_mul(const i32,const matrix*,matrix*);
void Mtranspose(const matrix*,matrix*);

#endif
