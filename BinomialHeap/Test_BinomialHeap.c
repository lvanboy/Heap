#include <stdio.h>
#include <stdlib.h>
#include "BinomiaHeap.h"
#define LENGTH(a) ( (sizeof(a)) / (sizeof(a[0])) )

//��������Ѽ�ֵ
int a[] = {
	12,
	33, 41,
	7, 25, 15, 28
};
int b[] = {
	9,
	18,35,20,42,
	31,23,6,48,11,24,52,13
};

void test_insert(){
	int alen = LENGTH(a);
	BinomialHeap ha = NULL;

	printf("==�����(ha)������ӣ�");
	for (int i = 0; i < alen; i++){
		printf("%d ", a[i]);
		ha = Insert_Binomial(ha, a[i]);
	}
	printf("\n");
	printf("==�����(ha)��ϸ��Ϣ");
	Print_Binomial(ha);
}

void test_delete(){
	int blen = LENGTH(b);
	BinomialHeap hb = NULL;

	printf("==�����(hb)������ӣ�");
	for (int i = 0; i < blen; i++){
		printf("%d ", b[i]);
		hb = Insert_Binomial(hb, b[i]);
	}
	printf("\n");
	printf("==�����(ha)��ϸ��Ϣ");
	Print_Binomial(hb);
	int key = 20;
	hb = Delete_Binomial(hb,key);
	printf("== ɾ���ڵ�%d�����ϸ��Ϣ: \n", key);
	Print_Binomial(hb);
}

void test_union(){
	int alen = LENGTH(a);
	int blen = LENGTH(b);
	BinomialHeap ha = NULL;
	BinomialHeap hb = NULL;

	//ha
	printf("==�����(ha)������ӣ�");
	for (int i = 0; i < alen; i++){
		printf("%d ", a[i]);
		ha = Insert_Binomial(ha, a[i]);
	}
	printf("\n");
	printf("==�����(ha)��ϸ��Ϣ");

	//hb
	Print_Binomial(ha);
	printf("==�����(ha)������ӣ�");
	for (int i = 0; i < blen; i++){
		printf("%d ", b[i]);
		hb = Insert_Binomial(hb, b[i]);
	}
	printf("\n");
	printf("==�����(ha)��ϸ��Ϣ");
	Print_Binomial(hb);
	ha = Union_Binomial(ha, hb);
	printf("==�����(ha+hb)��ϸ��Ϣ\n");
	Print_Binomial(ha);
}

void test_decrease(){
	int blen = LENGTH(b);
	BinomialHeap hb = NULL;

	printf("==�����(hb)������ӣ�");
	for (int i = 0; i < blen; i++){
		printf("%d ", b[i]);
		hb = Insert_Binomial(hb, b[i]);
	}
	printf("\n");
	printf("==�����(ha)��ϸ��Ϣ");
	Print_Binomial(hb);
	Update_Binomial(hb, 20, 2);
	printf("==���½ڵ�20->2����ϸ��Ϣ\n");
	Print_Binomial(hb);
}

void test_increase(){
	int alen = LENGTH(a);
	BinomialHeap ha = NULL;

	printf("==�����(ha)������ӣ�");
	for (int i = 0; i < alen; i++){
		printf("%d ", a[i]);
		ha = Insert_Binomial(ha, a[i]);
	}
	printf("\n");
	printf("==�����(ha)��ϸ��Ϣ");
	Print_Binomial(ha);
	Update_Binomial(ha, 28, 5);
	printf("==���½ڵ�28->5����ϸ��Ϣ\n");
	Print_Binomial(ha);
}

int main(){
	test_insert();
	test_delete();
	test_union();
	test_decrease();
	test_increase();
	getchar();
	return 0;
}