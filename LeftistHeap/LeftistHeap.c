#include <stdio.h>
#include <stdlib.h>
#include "Leftist_heap.h"


void inorder_Traverse(LeftistHeap heap){
	if (!heap){
		return ;
	}
	if (heap->left){
		inorder_Traverse(heap->left);
	}
	printf("%d ", heap->key);
	if (heap->right){
		inorder_Traverse(heap->right);
	}
}

LeftistNode *Merge_LeftistHeap(LeftistHeap x, LeftistHeap y){
	//结束条件，也做参数判断
	if (!x){
		return y;
	}
	if (!y){
		return x;
	}
	//默认x的小堆
	if (x->key > y->key){
		Swap_Node_Leftist(x, y);
	}
	x->right = Merge_LeftistHeap(x->right, y);


		if (x->left == NULL || x->left->npl < x->right->npl){
			LeftistNode *tmp = x->left;
			x->left = x->right;
			x->right = tmp;
		}
	
	if (!x->left || !x->right){
		x->npl = 0;
	}
	else{
		x->npl = x->left->npl > x->right->npl ? x->right->npl + 1 : x->left->npl + 1;
	}

	//回归结束，最后一层返回根
	return  x;
}

LeftistNode *Insert_LeftistHeap(LeftistHeap heap, Type key){

	LeftistNode *node = NULL;
	
	if ((node = (LeftistNode *)malloc(sizeof(LeftistNode))) == NULL){
		return node;
	}
	node->key = key;
	node->left = node->right = NULL;
	node->npl = 0;

	return Merge_LeftistHeap(heap, node);
}

LeftistNode *Delete_LeftistHeap(LeftistHeap heap){
	if (!heap){
		return heap;
	}
	LeftistNode *left = heap->left;
	LeftistNode *right = heap->right;
	free(heap);

	return Merge_LeftistHeap(left, right);
}

void Swap_Node_Leftist(LeftistNode *x, LeftistNode *y){
	if (!x || !y){
		return NULL;
	}
	LeftistNode tmp = *x;
	*x = *y;
	*y = tmp;
	return;
}

void Destory_Leftist(LeftistHeap heap){
	if (!heap){
		return ;
	}
	if (heap->left){
		Destory_Leftist(heap->left);
	}
	if (heap->right){
		Destory_Leftist(heap->right);
	}
	free(heap);

	return;
}

void Print_Leftist(LeftistHeap heap){
	if (!heap){
		return ;
	}
	if (heap->left){
		printf("the left child of the node %d(%d) is the %d\n", heap->key, heap->npl,heap->left->key);
	}
	else{
		printf("the left child of the node %d(%d) is the null\n", heap->key, heap->npl);
	}
	if (heap->right){
		printf("the right child of the node %d(%d) is the %d\n", heap->key, heap->npl,heap->right->key);
	}
	else{
		printf("the right child of the node %d(%d) is the null\n", heap->key, heap->npl);
	}
	Print_Leftist(heap->left);
	Print_Leftist(heap->right);
	return;
}
