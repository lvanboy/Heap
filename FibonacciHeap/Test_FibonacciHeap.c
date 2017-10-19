#include <stdio.h>
#include "FibonacciHeap.h"
#define LENGTH(a) ( (sizeof(a)) / (sizeof(a[0])) )

int a[] = {
	12,
	7, 25, 15, 28,
	33, 41, 1
};
int b[] = {
	18,35,20,42,9,
	31,23,6,48,11,
	24,52,13,2
};

void test_basic(){
	FibHeap *hb = fib_heap_make();
	int blen = LENGTH(b);
	printf("== 斐波那契堆(hb)中依次添加:");
	for (int i = 0; i < blen; i++){
		printf("%d ", b[i]);
		fib_heap_insert_key(hb, b[i]);
	}
	printf("\n");
	printf("== 斐波那契堆(hb)删除最小节点\n");
	fib_heap_extract_min(hb);
	fib_heap_print(hb);
	//fib_heap_destory(hb);
	getchar();
	return;
}

int main()
{
	test_basic();
	return 0;
}
