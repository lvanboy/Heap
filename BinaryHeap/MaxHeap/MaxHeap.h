#ifndef  _MAX_HEAP_H_
#define _MAX_HEAP_H_
#define LENGTH(a)   ( sizeof(a)/sizeof(a[0]) ) 
#define M_CAPACITY 15

//��������
int m_heap[M_CAPACITY];

//��ʼ����
static int m_size = 0;

//���
void insert_maxheap(int data);

//�ϵ�
void filterup_maxheap(int data);

//ɾ��
int remove_maxheap(int data);

//�µ�
void filterdown_maxheap(int pos);

//��ȡ����
int get_index(int data);

//��ӡ��
void print_maxheap();

#endif // !  _MAX_HEAP_H_

