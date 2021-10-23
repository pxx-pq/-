#include<stdio.h>
#define M 10
typedef struct{
	int row, col;//行，列
	int val;//值
}T;
typedef struct {
	T b[M];//存放矩阵的行、列、值的数组
	int nu, mu, num;//存放非零元素的行数，列数和非零个数；
}TMatrix;
TMatrix transpose(TMatrix ts, TMatrix tv);
int main()
{
	TMatrix TS;
	TS.mu = 3;      TS.nu = 4;     TS.num = 5;//定矩阵框架
	//给矩阵初始值
    TS.b[0].row = 1;TS.b[0].col= 2;TS.b[0].val= 2;
    TS.b[1].row = 2;TS.b[1].col= 1;TS.b[1].val= 1;
    TS.b[2].row = 3;TS.b[2].col= 1;TS.b[2].val= 6;
	TS.b[3].row = 3;TS.b[3].col= 2;TS.b[3].val= 1;
    TS.b[4].row = 4;TS.b[4].col= 3;TS.b[4].val= 9;
	TMatrix TV;
	for (int k = 0; k < M; k++) {
	TV.b[k].row = 0;TV.b[k].col = 0;TV.b[k].val = 0;
	}
	TV = transpose(TS,TV);
	for (int i = 0; i < TV.num; i++) {
	printf("（%d,%d,%d）\n", TV.b[i].row, TV.b[i].col, TV.b[i].val);
	}
	return 0;
}
TMatrix transpose(TMatrix tv, TMatrix ts) {
	int q=0,i,j;
	ts.nu = tv.mu; ts.mu = tv.nu; ts.num = tv.num;//mu是行数，nu是列数，num是非0元素个数
	if (ts.num) {
		for (i = 1; i <= tv.mu; i++) {
			for (j = 0; j < tv.num; j++) {
				if (tv.b[j].col == i) {//c语言只能一个一个变
					ts.b[q].row= tv.b[j].col;
					ts.b[q].col = tv.b[j].row;
					ts.b[q].val = tv.b[j].val;
					q++;
				}
			}
		}
	}
	return ts;
}

/*
		1	2	3
	1  (0	2	0)								 |					(0	1	6	0)
	2  (1	0	0)								 |					(2	0	1	0)
	3  (6	1	0)								 |	---->变成这样	(0	0	0	9)
	4  (0	0	9)     <--是个矩阵 用大括号括起来|
*/