#ifndef _SKEW_HEAP_H_
#define _SKEW_HEAP_H_

typedef int Type;
//�ڵ�ṹ
typedef struct SkewNode{
	Type key;
	struct SkewNode *left;
	struct SkewNode *right;
}SkewNode, *SkewHeap;



//�������
void Inorder_Traverse(SkewHeap heap);

//�����ڵ�
void Swap_Node_SkewHeap(SkewNode *x, SkewNode *y);

//�ϲ�
SkewHeap Merge_SkewHeap(SkewHeap x, SkewHeap y);

//���
SkewHeap Insert_SkewHeap(SkewHeap heap, Type key);

//ɾ��
SkewHeap Delete_SkewHeap(SkewHeap heap);

//����
void Destroy_SkewHeap(SkewHeap heap);

//��ӡ
void Print_SkewHeap(SkewHeap heap);


#endif