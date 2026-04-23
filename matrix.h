#ifndef MATRIX_H
#define MATRIX_H
#include<stdint.h>
#define MFORMAT(dimr,dimc, ...) ((i32[dimr][dimc]){__VA_ARGS__})
#define MAT(rows, cols, ...) Mmake(rows, cols, MFORMAT(rows, cols, __VA_ARGS__))

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
matrix* Msum(const matrix*,const matrix*);
matrix* Msub(const matrix*,const matrix*);
matrix* Mmul(const matrix*,const matrix*);
matrix* Mcpy(const matrix*);
matrix* Mzeros(const i32,const i32);
matrix* Mones(const i32);
matrix* Mscalar_mul(const i32,const matrix*);
matrix* Mtranspose(const matrix*);

#endif
