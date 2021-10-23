#include<stdio.h>
#define M 10
typedef struct{
	int row, col;//�У���
	int val;//ֵ
}T;
typedef struct {
	T b[M];//��ž�����С��С�ֵ������
	int nu, mu, num;//��ŷ���Ԫ�ص������������ͷ��������
}TMatrix;
TMatrix transpose(TMatrix ts, TMatrix tv);
int main()
{
	TMatrix TS;
	TS.mu = 3;      TS.nu = 4;     TS.num = 5;//��������
	//�������ʼֵ
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
	printf("��%d,%d,%d��\n", TV.b[i].row, TV.b[i].col, TV.b[i].val);
	}
	return 0;
}
TMatrix transpose(TMatrix tv, TMatrix ts) {
	int q=0,i,j;
	ts.nu = tv.mu; ts.mu = tv.nu; ts.num = tv.num;//mu��������nu��������num�Ƿ�0Ԫ�ظ���
	if (ts.num) {
		for (i = 1; i <= tv.mu; i++) {
			for (j = 0; j < tv.num; j++) {
				if (tv.b[j].col == i) {//c����ֻ��һ��һ����
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
	3  (6	1	0)								 |	---->�������	(0	0	0	9)
	4  (0	0	9)     <--�Ǹ����� �ô�����������|
*/