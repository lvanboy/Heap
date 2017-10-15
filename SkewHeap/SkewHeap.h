#ifndef _SKEW_HEAP_H_
#define _SKEW_HEAP_H_

typedef int Type;
//节点结构
typedef struct SkewNode{
	Type key;
	struct SkewNode *left;
	struct SkewNode *right;
}SkewNode, *SkewHeap;



//中序遍历
void Inorder_Traverse(SkewHeap heap);

//交换节点
void Swap_Node_SkewHeap(SkewNode *x, SkewNode *y);

//合并
SkewHeap Merge_SkewHeap(SkewHeap x, SkewHeap y);

//添加
SkewHeap Insert_SkewHeap(SkewHeap heap, Type key);

//删除
SkewHeap Delete_SkewHeap(SkewHeap heap);

//销毁
void Destroy_SkewHeap(SkewHeap heap);

//打印
void Print_SkewHeap(SkewHeap heap);


#endif