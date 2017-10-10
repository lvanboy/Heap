#ifndef  _MIN_HEAP_H_
#define _MIN_HEAP_H_
#define LENGTH(a)   ( sizeof(a)/sizeof(a[0]) ) 
#define M_CAPACITY 15

//��������
int m_heap[M_CAPACITY];

//��ʼ����
static int m_size = 0;

//���
void insert_minheap(int data);

//�ϵ�
void filterup_minheap(int data);

//ɾ��
int remove_minheap(int data);

//�µ�
void filterdown_minheap(int pos);

//��ȡ����
int get_index_minheap(int data);

//��ӡ��
void print_minheap();

#endif // !  _MIN_HEAP_H_