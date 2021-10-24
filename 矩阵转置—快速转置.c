#include<stdio.h>
typedef struct {
	int row, col;
	int val;
}T;
typedef struct {
	T bi[10];
	int mu, nu, num;//��������������������Ԫ�ظ���
}TMatrix;
void tranpose(TMatrix ts, TMatrix tv);
int  main()
{
    TMatrix TS;
    TS.mu = 5;TS.nu = 6;TS.num = 10;
    TS.bi[0].row = 0;TS.bi[0].col = 2;TS.bi[0].val = 35;	TS.bi[1].row = 0;TS.bi[1].col = 3;TS.bi[1].val = 13;
	TS.bi[2].row = 0;TS.bi[2].col = 5;TS.bi[2].val = 1;		TS.bi[3].row = 1;TS.bi[3].col = 0;TS.bi[3].val = 31;
	TS.bi[4].row = 1;TS.bi[4].col = 4;TS.bi[4].val = 17;	TS.bi[5].row = 2;TS.bi[5].col = 2;TS.bi[5].val = 1;
	TS.bi[6].row = 2;TS.bi[6].col = 5;TS.bi[6].val = 20;	TS.bi[7].row = 3;TS.bi[7].col = 1;TS.bi[7].val = 21;
	TS.bi[8].row = 1;TS.bi[8].col = 0;TS.bi[8].val = 2;		TS.bi[9].row = 4;TS.bi[9].col = 3;TS.bi[9].val = 8;
	TMatrix TV;
	tranpose(TS, TV);
	for (int i = 0; i < TV.num; i++) {
		printf("��%d,%d,%d��\n", TV.bi[i].row, TV.bi[i].col, TV.bi[i].val);
	}
}
void tranpose(TMatrix ts,TMatrix tv)
{
	int i,j,k;
	int n, t;
	n = ts.nu; t = ts.num;
	int nub[6],pot[6];
	//nub������¼������Ԫ���ڸ��е�Ԫ�ظ���	
	//pot����ָ������е�һ�����ֵķ���Ԫ�ص�λ��
	for (j = 0; j < n; j++)nub[j] = 0;//��ʼ��
	for (i = 0; i < t; i++)nub[ts.bi[i].col]++;//ͳ��ת�þ���ķ���Ԫ��
	for (pot[0] = 0, j = 1; j < n; j++)pot[j] = pot[j - 1] + nub[j - 1];
	//ת��
	for (i = 0; i < t;i++) {
		j = ts.bi[i].col;
		k = pot[j];
		tv.bi[k].row = j; tv.bi[k].col = ts.bi[i].row; ts.bi[k].val = ts.bi[i].val;
		pot[j]++;
	}
}