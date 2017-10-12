#ifndef _LEFTIST_HEAP_H_
#define _LEFTIST_HEAP_H_
typedef int Type;
//节点结构
typedef struct LeftistNode{
	struct LeftistNode *left;
	struct LeftistNode *right;
	Type key;
	int npl;
}LeftistNode, *LeftistHeap;

//中序遍历
void inorder_Traverse(LeftistHeap heap);

//合并
LeftistNode *Merge_LeftistHeap(LeftistHeap x, LeftistHeap y);

//插入 
LeftistNode *Insert_LeftistHeap(LeftistHeap heap, Type key);

//删除
LeftistNode *Delete_LeftistHeap(LeftistHeap heap);

//交换节点
void Swap_Node_Leftist(LeftistNode *x, LeftistNode *y);

//销毁堆
void Destory_Leftist(LeftistHeap heap);

//打印关系
void Print_Leftist(LeftistHeap heap);
#endif