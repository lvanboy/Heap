#include <stdio.h>
#include <stdlib.h>
#include "Leftist_heap.h"

int main(){
	int a[] = { 10, 40, 24, 30, 36, 20, 12, 16 };
	int b[] = { 17, 13, 11, 15, 19, 21, 23 };
	int alen = sizeof(a) / sizeof(a[0]);
	int blen = sizeof(b) / sizeof(b[0]);
	LeftistHeap ha, hb;
	ha = hb = NULL;

	//ha
	printf("���β��룺");
	for (int i = 0; i < alen; i++){
		printf("%d ", a[i]);
		ha = Insert_LeftistHeap(ha, a[i]);
	}
	printf("\n�������ϸ��Ϣ(ha)\n");
	//Print_Leftist(ha);


	//hb
	printf("���β��룺");
	for (int i = 0; i < blen; i++){
		printf("%d ", b[i]);
		hb = Insert_LeftistHeap(hb, b[i]);
	}
	printf("\n�������ϸ��Ϣ(ha)\n");

	//Print_Leftist(hb);
	
	//�ϲ�a��b
	printf("�ϲ�������\n");
	ha = Merge_LeftistHeap(ha, hb);
	printf("�ϲ��󣬶ѵ���ϸ��Ϣ\n");
	printf("�ѵĸ���%d\n", ha->key);
	Print_Leftist(ha);

	Destory_Leftist(ha);
	getchar();
	return 0;
}