#ifndef _BINNOMIAL_HEAP_H_
#define _BINNOMIAL_HEAP_H_

//节点结构
typedef int Type;
typedef struct BinomialNode{
	Type key;
	int degree;
	struct BinomialNode *left;
	struct BinomialNode *parent;
	struct BinomialNode *next;
}BinomialNode, *BinomialHeap;

//新建节点
BinomialNode *CreateNode_Binomial(Type key);

//插入节点
BinomialNode *Insert_Binomial(BinomialHeap heap, Type key);

//删除节点
BinomialNode *Delete_Binomial(BinomialHeap heap, Type key);

//反转二叉堆
BinomialNode *Reverse_Binomial(BinomialHeap heap);

//更新节点
void Update_Key_Binomial(BinomialHeap heap, BinomialNode *node, Type newkey);

//更新节点
void Update_Binomial(BinomialHeap heap, Type oldkey, Type newkey);

//减小节点值
void Decrease_Binomial(BinomialHeap heap, BinomialNode *node, Type newkey);

//增大节点值
void Increase_Binomial(BinomialHeap heap, BinomialNode *node, Type newkey);

// 合并二项堆
BinomialNode *Union_Binomial(BinomialHeap h1, BinomialHeap h2);

//二项堆根节点组成链表
BinomialNode *Merge_Binomial(BinomialHeap h1, BinomialHeap h2);

//合并孩子到二项堆
void Link_Binomial(BinomialHeap child, BinomialHeap heap);
 
//查找节点
BinomialNode *Search_Binomial(BinomialHeap heap, Type key);

//获取最小值
BinomialNode *Minimum_Binomial(BinomialHeap heap);

void _Minimum_Binomial(BinomialHeap heap, BinomialNode **pre_y, BinomialNode **y);

//删除最小值
BinomialNode *Extract_Minimum_Binomial(BinomialHeap heap);

//打印
void Print_Binomial(BinomialHeap heap);

void _Print_Binomial(BinomialNode *node, BinomialNode *pre, int direction);


#endif 
