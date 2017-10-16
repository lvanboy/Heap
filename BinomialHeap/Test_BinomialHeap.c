#include <stdio.h>
#include <stdlib.h>
#include "BinomiaHeap.h"
#define LENGTH(a) ( (sizeof(a)) / (sizeof(a[0])) )

//两个二叉堆键值
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

	printf("==二项堆(ha)依次添加：");
	for (int i = 0; i < alen; i++){
		printf("%d ", a[i]);
		ha = Insert_Binomial(ha, a[i]);
	}
	printf("\n");
	printf("==二叉堆(ha)详细信息");
	Print_Binomial(ha);
}

void test_delete(){
	int blen = LENGTH(b);
	BinomialHeap hb = NULL;

	printf("==二项堆(hb)依次添加：");
	for (int i = 0; i < blen; i++){
		printf("%d ", b[i]);
		hb = Insert_Binomial(hb, b[i]);
	}
	printf("\n");
	printf("==二叉堆(ha)详细信息");
	Print_Binomial(hb);
	int key = 20;
	hb = Delete_Binomial(hb,key);
	printf("== 删除节点%d后的详细信息: \n", key);
	Print_Binomial(hb);
}

void test_union(){
	int alen = LENGTH(a);
	int blen = LENGTH(b);
	BinomialHeap ha = NULL;
	BinomialHeap hb = NULL;

	//ha
	printf("==二项堆(ha)依次添加：");
	for (int i = 0; i < alen; i++){
		printf("%d ", a[i]);
		ha = Insert_Binomial(ha, a[i]);
	}
	printf("\n");
	printf("==二叉堆(ha)详细信息");

	//hb
	Print_Binomial(ha);
	printf("==二项堆(ha)依次添加：");
	for (int i = 0; i < blen; i++){
		printf("%d ", b[i]);
		hb = Insert_Binomial(hb, b[i]);
	}
	printf("\n");
	printf("==二叉堆(ha)详细信息");
	Print_Binomial(hb);
	ha = Union_Binomial(ha, hb);
	printf("==二叉堆(ha+hb)详细信息\n");
	Print_Binomial(ha);
}

void test_decrease(){
	int blen = LENGTH(b);
	BinomialHeap hb = NULL;

	printf("==二项堆(hb)依次添加：");
	for (int i = 0; i < blen; i++){
		printf("%d ", b[i]);
		hb = Insert_Binomial(hb, b[i]);
	}
	printf("\n");
	printf("==二叉堆(ha)详细信息");
	Print_Binomial(hb);
	Update_Binomial(hb, 20, 2);
	printf("==更新节点20->2的详细信息\n");
	Print_Binomial(hb);
}

void test_increase(){
	int alen = LENGTH(a);
	BinomialHeap ha = NULL;

	printf("==二项堆(ha)依次添加：");
	for (int i = 0; i < alen; i++){
		printf("%d ", a[i]);
		ha = Insert_Binomial(ha, a[i]);
	}
	printf("\n");
	printf("==二叉堆(ha)详细信息");
	Print_Binomial(ha);
	Update_Binomial(ha, 28, 5);
	printf("==更新节点28->5的详细信息\n");
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