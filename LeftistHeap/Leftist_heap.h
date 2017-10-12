#ifndef _LEFTIST_HEAP_H_
#define _LEFTIST_HEAP_H_
typedef int Type;
//�ڵ�ṹ
typedef struct LeftistNode{
	struct LeftistNode *left;
	struct LeftistNode *right;
	Type key;
	int npl;
}LeftistNode, *LeftistHeap;

//�������
void inorder_Traverse(LeftistHeap heap);

//�ϲ�
LeftistNode *Merge_LeftistHeap(LeftistHeap x, LeftistHeap y);

//���� 
LeftistNode *Insert_LeftistHeap(LeftistHeap heap, Type key);

//ɾ��
LeftistNode *Delete_LeftistHeap(LeftistHeap heap);

//�����ڵ�
void Swap_Node_Leftist(LeftistNode *x, LeftistNode *y);

//���ٶ�
void Destory_Leftist(LeftistHeap heap);

//��ӡ��ϵ
void Print_Leftist(LeftistHeap heap);
#endif