#include "MaxHeap.h"


int main(){
	//定义一组数据，依次添加
	int data[] = { 90, 80, 70, 60, 40, 30, 20, 10, 50};
	//拿到数组长度
	int len = LENGTH(data);

	int addition = 85;

	printf("依次添加：");
	for (int i = 0; i < len; i++){
		printf("%d ", data[i]);
		insert_maxheap(data[i]);
	}
	printf("\n最大堆：");
	print_maxheap();

	insert_maxheap(addition);
	printf("\n添加元素：%d\n",addition);
	printf("最大堆：");
	print_maxheap();

	printf("\n删除元素90");
	remove_maxheap(90);

	printf("\n最大堆：");
	print_maxheap();
	
	printf("\n");
	getchar();
	return 0;
}