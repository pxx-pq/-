#include<stdio.h>
struct str {
	int length;
	char ch[10];
};
typedef struct str SString;
int main()
{
	int num=1;
	SString S = { 10,"abcdefgabd" }, T = { 3,"abd" };
	num=BF(T,S);
	printf("%d", num);
	return 0;
}
int BF(SString T, SString S)//TÊÇ×Ö´®
{
	 int i=0,j=0;
	 while (i < S.length && j < T.length)
	 {
		 if (S.ch[i] == T.ch[j])
		 {
			 i++; 
			 j++;
		 }
		 else
		 {
			 j = 1; 
			 i = i - j + 2;
		 }
	 }
	 if (j == T.length)return i - T.length+1;
	 else return 0;
}