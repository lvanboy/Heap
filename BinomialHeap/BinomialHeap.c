#include <stdio.h>
#include <stdlib.h>
#include "BinomiaHeap.h"
#define swap(a,b) (a^=b,b^=a,a^=b)

BinomialNode *Merge_Binomial(BinomialHeap h1, BinomialHeap h2){
	BinomialNode *head = NULL;
	BinomialNode **pos = &head;
	while (h1&&h2){
		if (h1->degree < h2->degree){
			*pos = h1;
			h1 = h1->next;
		}
		else{
			*pos = h2;
			h2 = h2->next;
		}
		pos = &(*pos)->next;
	}
	if (h1){
		*pos = h1;
	}
	else{
		*pos = h2;
	}
	return head;
}

void Link_Binomial(BinomialHeap child, BinomialHeap heap){
	child->parent = heap;
	child->next = heap->left;
	heap->left = child;
	heap->degree++;
	return ;
}

BinomialNode *Union_Binomial(BinomialHeap h1, BinomialHeap h2){
	BinomialHeap heap = NULL;
	BinomialNode *pre_x, *x, *next_x;

	//按度的大小合并二叉堆
	heap = Merge_Binomial(h1, h2);
	pre_x = NULL;
	x = heap;
	next_x = heap->next;
	while (next_x){
		if (x->degree != next_x->degree || next_x->next && next_x->degree == next_x->next->degree){
			pre_x = x;
			x = next_x;
		}
		else if (x->key <= next_x->key){
			x->next = next_x->next;
			Link_Binomial(next_x, x);
		}
		else{
			if (!pre_x){
				heap = next_x;
			}
			else{
				pre_x->next = next_x;
			}
			Link_Binomial(x, next_x);
			x = next_x;
		}

		next_x = x->next;
	}

	return heap;
}

BinomialNode *Search_Binomial(BinomialHeap heap, Type key){
	BinomialNode *child = NULL;
	BinomialNode *parent = heap;
	while (parent){
		if (parent->key == key){
			return parent;
		}
		else{
			if ((child = Search_Binomial(parent->left, key) != NULL)){
				return child;
			}
			parent = parent->next;
		}
	}
	return NULL;
}

BinomialNode *CreateNode_Binomial(Type key){
	BinomialNode *node = NULL;
	if ((node = (BinomialNode *)malloc(sizeof(BinomialNode))) == NULL){
		return node;
	}
	node->left = NULL;
	node->parent = NULL;
	node->next = NULL;
	node->key = key;
	node->degree = 0;
	return node;
}

BinomialNode *Insert_Binomial(BinomialHeap heap, Type key){
	BinomialNode *node = NULL;
	if (Search_Binomial(heap, key) != NULL){
		printf("the node which is inserted has been existed.");
		return heap;
	}
	node = CreateNode_Binomial(key);
	return Union_Binomial(heap, node);
}

BinomialNode *Reverse_Binomial(BinomialHeap heap){
	BinomialNode *next = NULL;
	BinomialNode *tail = NULL;
	if (!heap){
		return heap;
	}
	while (heap->next){
		next = heap->next;
		heap->next = tail;
		tail = heap;
		heap = next;
		heap->parent = NULL;
	}
	heap->next = tail;
	return heap;
}

BinomialNode *Delete_Binomial(BinomialHeap heap, Type key){
	BinomialNode *node = NULL;
	BinomialNode *parent, *pre, *pos;
	if (!heap){
		return heap;
	}
	if ((node = Search_Binomial(heap, key)) == NULL){
		return node;
	}
	//向上移动被删除节点
	parent = node->parent;
	while (parent){
		//交换子元素和父元素值
		swap(node->key, parent->key);
		//向上移动一个节点
		node = parent;
		parent = parent->parent;
	}
	//找到删除节点的前驱节点
	pre = NULL;
	pos = heap;
	while (pos!=node){
		pre = pos;
		pos = pos->next;
	}
	//移除node节点
	if (pre){
		pre->next = node->next;
	}
	else{
		//根节点没有前驱，也就是node = heap
		heap = node->next;
	}
	heap = Union_Binomial(heap, Reverse_Binomial(node->left));
	free(node);
	return heap;
}

void Decrease_Binomial(BinomialHeap heap, BinomialNode *node, Type newkey){
	BinomialNode *child = node;
	BinomialNode *parent = NULL;
	if (!heap){
		return;
	}
	if (Search_Binomial(heap, newkey) == NULL){
		printf("the key of the node is updated don't exist.");
		return;
	}
	node->key = newkey;
	parent = child->parent;
	while (parent){
		swap(child->key, parent->key);
		child = parent;
		parent = parent->parent;
	}
	return;
}

void Increase_Binomial(BinomialHeap heap, BinomialNode *node, Type newkey){

}

void Update_Binomial(BinomialHeap heap, BinomialNode *node, Type newkey){
	if (!heap || !node){
		return;
	}
	if (node->key > newkey){
		Decrease_Binomial(heap, node, newkey);
	}
	else if (node->key < newkey){
		Increase_Binomial(heap, node, newkey);
	}
	else{
		printf("no need to update!");
	}
	return;
}
