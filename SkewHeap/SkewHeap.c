#include <stdio.h>
#include <stdlib.h>
#include "SkewHeap.h"

SkewHeap Merge_SkewHeap(SkewHeap x, SkewHeap y){
	if (!x){
		return y;
	}
	if (!y){
		return x;
	}
	if (x->key > y->key){
		Swap_Node_SkewHeap(x, y);
	}
	SkewNode *tmp = Merge_SkewHeap(x->right, y);
	x->right = x->left;
	x->left = tmp;

	return x;
}


void Swap_Node_SkewHeap(SkewNode *x, SkewNode *y){
	SkewNode tmp = *x;
	*x = *y;
	*y = tmp;
	return;
}

SkewHeap Insert_SkewHeap(SkewHeap heap, Type key){
	SkewNode *node = NULL;
	if ((node = (SkewNode *)malloc(sizeof(SkewNode))) == NULL){
		return heap;
	}
	node->key = key;
	node->left = NULL;
	node->right = NULL;

	return Merge_SkewHeap(heap, node);
}

SkewHeap Delete_SkewHeap(SkewHeap heap){
	if (!heap){
		return heap;
	}
	SkewNode *left = heap->left;
	SkewNode *right = heap->right;

	free(heap);
	
	return Merge_SkewHeap(left, right);

}

void Destroy_SkewHeap(SkewHeap heap){
	if (!heap){
		return ;
	}
	if (heap->left){
		Destroy_SkewHeap(heap->left);
	}
	if (heap->right){
		Destroy_SkewHeap(heap->right);
	}
	free(heap);
	return;
}

void Inorder_Traverse(SkewHeap heap){
	if (!heap){
		return;
	}
	if (heap->left){
		Inorder_Traverse(heap->left);
	}
	printf("%d ", heap->key);
	if (heap->right){
		Inorder_Traverse(heap->right);
	}
	return;
}

void Print_SkewHeap(SkewHeap heap){
	if (!heap){
		return;
	}
	if (heap->left){
		printf("the left child of the node %d is the %d\n", heap->key, heap->left->key);
	}
	if (heap->right){
		printf("the right child of the node %d is the %d\n", heap->key, heap->right->key);
	}
	Print_SkewHeap(heap->left);
	Print_SkewHeap(heap->right);
	return;
}