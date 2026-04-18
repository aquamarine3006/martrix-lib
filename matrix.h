#include<stdint.h>

typedef int32_t i32;
typedef uint32_t u32;

typedef struct{
	i32 indr,indc;
	i32 data[10][10];
} matrix;

void Mprint(matrix*);
i32 Msum(matrix*,matrix*,matrix*);
i32 Msub(matrix*,matrix*,matrix*);
i32 Mmul(matrix*,matrix*,matrix*);
