#include "MaxHeap.h"


int main(){
	//����һ�����ݣ��������
	int data[] = { 90, 80, 70, 60, 40, 30, 20, 10, 50};
	//�õ����鳤��
	int len = LENGTH(data);

	int addition = 85;

	printf("������ӣ�");
	for (int i = 0; i < len; i++){
		printf("%d ", data[i]);
		insert_maxheap(data[i]);
	}
	printf("\n���ѣ�");
	print_maxheap();

	insert_maxheap(addition);
	printf("\n���Ԫ�أ�%d\n",addition);
	printf("���ѣ�");
	print_maxheap();

	printf("\nɾ��Ԫ��90");
	remove_maxheap(90);

	printf("\n���ѣ�");
	print_maxheap();
	
	printf("\n");
	getchar();
	return 0;
}