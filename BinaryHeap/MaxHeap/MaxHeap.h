#ifndef  _MAX_HEAP_H_
#define _MAX_HEAP_H_
#define LENGTH(a)   ( sizeof(a)/sizeof(a[0]) ) 
#define M_CAPACITY 15

//数据容器
int m_heap[M_CAPACITY];

//初始长度
static int m_size = 0;

//添加
void insert_maxheap(int data);

//上调
void filterup_maxheap(int data);

//删除
int remove_maxheap(int data);

//下调
void filterdown_maxheap(int pos);

//获取索引
int get_index(int data);

//打印堆
void print_maxheap();

#endif // !  _MAX_HEAP_H_

