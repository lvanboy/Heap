#include "MinHeap.h"

int main(){
	//����һ�����ݣ��������
	int data[] = { 90, 80, 70, 60, 40, 30, 20, 10, 50 };
	//�õ����鳤��
	int len = LENGTH(data);

	int addition = 85;

	printf("������ӣ�");
	for (int i = 0; i < len; i++){
		printf("%d ", data[i]);
		insert_minheap(data[i]);
	}
	printf("\n��С�ѣ�");
	print_minheap();

	insert_minheap(addition);
	printf("\n���Ԫ�أ�%d\n", addition);
	printf("��С�ѣ�");
	print_minheap();

	printf("\nɾ��Ԫ��90");
	remove_minheap(90);

	printf("\n��С�ѣ�");
	print_minheap();

	printf("\n");
	getchar();
	return 0;
}