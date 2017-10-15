#include <stdio.h>
#include <stdlib.h>
#include "SkewHeap.h"

int main(){
	int a[] = { 10, 40, 24, 30, 36, 20, 12, 16 };
	int b[] = { 17, 13, 11, 15, 19, 21, 23 };
	int alen = sizeof(a) / sizeof(a[0]);
	int blen = sizeof(b) / sizeof(b[0]);
	SkewHeap ha, hb;
	ha = hb = NULL;
	//ha
	printf("���β���");
	for (int i = 0; i < alen; i++){
		printf("%d ", a[i]);
		ha = Insert_SkewHeap(ha, a[i]);
	}
	printf("\n��ha����ϸ��Ϣ\n");
	printf("the root is %d\n", ha->key);
	Print_SkewHeap(ha);
	//hb
	printf("���β���");
	for (int i = 0; i < blen; i++){
		printf("%d ", b[i]);
		hb = Insert_SkewHeap(hb, b[i]);
	}
	printf("\n��hb����ϸ��Ϣ\n");
	printf("the root is %d\n", hb->key);
	Print_SkewHeap(hb);

	printf("�ϲ�ha��hb");
	ha = Merge_SkewHeap(ha, hb);
	printf("\n��hc����ϸ��Ϣ\n");
	printf("the root is %d\n", ha->key);
	Print_SkewHeap(ha);

	getchar();
	return;
}