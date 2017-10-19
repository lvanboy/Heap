#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FibonacciHeap.h"
#define LOG2(x) ((log((double)(x))) / (log(2.0)))

void fib_node_remove(FibNode *node){
	node->left->right = node->right;
	node->right->left = node->left;
	return;
}

void fib_node_add(FibNode *node, FibNode *root){
	node->left = root->left;
	root->left->right = node;
	node->right = root;
	root->left = node;
	return;
}

void fib_node_cat(FibNode *a, FibNode *b){
	FibNode *tmp = a->right;
	a->right = b->right;
	b->right->left = a;
	b->right = tmp;
	tmp->left = b;
	return;
}

void fib_heap_insert_node(FibHeap *heap, FibNode *node){
	if (heap->keyNum == 0){
		heap->min = node;
	}
	else{
		fib_node_add(node, heap->min);
		if (node->key < heap->min->key){
			heap->min = node;
		}
	}
	heap->keyNum++;
}

FibNode *fib_node_make(Type key){
	FibNode *node = NULL;
	if ((node = (FibNode *)malloc(sizeof(FibNode))) == NULL){
		return node;
	}
	node->child = node->parent = NULL;
	node->left = node->right = node;
	node->degree = 0;
	node->key = key;

	return node;
}

FibHeap *fib_heap_make(){
	FibHeap *heap = NULL;
	if ((heap = (FibHeap *)malloc(sizeof(FibHeap))) == NULL){
		return heap;
	}
	 heap->min = NULL;
	 heap->cons = NULL;
	heap->keyNum = 0;
	heap->maxDegree = 0;
	return heap;
}

void fib_heap_insert_key(FibHeap *heap, Type key){
	FibNode *node = NULL;
	if (!heap){
		return;
	}
	node = fib_node_make(key);
	if (node){
		fib_heap_insert_node(heap, node);
	}
}

FibHeap *fib_heap_union(FibHeap *h1, FibHeap *h2){
	FibHeap *tmp;
	if (!h1){
		return h2;
	}
	if (!h2){
		return h1;
	}
	//默认h1大
	if (h1->maxDegree < h2->maxDegree){
		tmp = h1;
		h1 = h2;
		h2 = tmp;
	}
	if (!h1->min){
		h1->min = h2->min;
		h1->maxDegree = h2->maxDegree;
		free(h2->cons);
		free(h2);
	}
	else if (!h2->min){
		free(h2->cons);
		free(h2);
	}
	else{
		fib_node_cat(h1->min, h2->min);
		if (h1->min->key > h2->min->key){
			h1->min = h2->min;
		}
		h1->keyNum += h2->keyNum;
		free(h2->cons);
		free(h2);
	}
	return h1;
}

FibNode *_fib_heap_extract_min(FibHeap *heap){
	if (!heap || !heap->min){
		return NULL;
	}
	FibNode *min = heap->min;
	FibNode *child = NULL;
	while (min->child){
		child = min->child;
		fib_node_remove(child);
		if (child->right == child){
			min->child = NULL;
		}
		else{
			min->child = child->right;
		}
		fib_node_add(child, min);
		child->parent = NULL;
	}
	fib_node_remove(min);
	if (min->right == min){
		heap->min = NULL;
	}
	else{
		heap->min = min->right;
		fib_heap_consolidate(heap);
	}
	heap->keyNum--;
	return min;
}

void fib_heap_extract_min(FibHeap *heap){
	FibNode *node = NULL;
	if (!heap || !heap->min){
		return;
	}
	node = _fib_heap_extract_min(heap);
	if (node){
		free(node);
	}
	return;
}

void fib_heap_cons_make(FibHeap *heap){
	int old = heap->maxDegree;

	heap->maxDegree = (int)LOG2(heap->keyNum) + 1;

	if (old >= heap->maxDegree){
		return;
	}
	heap->cons = (FibNode **)realloc(heap->cons, sizeof(FibHeap *)*(heap->maxDegree+ 1) );
	return;
}

FibNode *fib_heap_remove_min(FibHeap *heap){
	if (!heap||!heap->min){
		return NULL;
	}
	FibNode *min = heap->min;
	if (heap->min == min->right){
		heap->min = NULL;
	}
	else{
		fib_node_remove(min);
		heap->min = min->right;
	}
	//这里调了很长时间
	min->left = min->right = min;
	return min;
}


void fib_node_link(FibNode *node, FibNode *root){
	fib_node_remove(node);
	if (!root->child){
		root->child = node;
	}
	else{
		fib_node_add(node, root->child);
	}
	node->parent = root;
	root->degree++;
	node->marked = 0;
}



void fib_heap_consolidate(FibHeap *heap){
	if (!heap || !heap->min){
		return;
	}
	int d, D;
	FibNode *x, *y, *tmp;
	fib_heap_cons_make(heap);
	D = heap->maxDegree + 1;
	for (int i = 0; i < D; i++){
		heap->cons[i] = NULL;
	}
	while (heap->min){
		x = fib_heap_remove_min(heap);
		d = x->degree;
		//存在度数相同的树
		while (heap->cons[d]){
			y = heap->cons[d];
			if (x->key>y->key){
				tmp = x;
				x = y;
				y = tmp;
			}
			fib_node_link(y, x);
			heap->cons[d] = NULL;
			d++;
		}
		heap->cons[d] = x;
	}
	heap->min = NULL;
	for (int i = 0; i < D; i++){
		if (heap->cons[i]){
			if (heap->min){
				fib_node_add(heap->cons[i], heap->min);
				if (heap->cons[i]->key < heap->min->key){
					heap->min = heap->cons[i];
				}
			}
			else{
				heap->min = heap->cons[i];
			}
		}
	}

}

int fib_heap_get_min(FibHeap *heap, Type *pkey){
	if (!heap || !heap->min){
		return 0;
	}
	*pkey = heap->min->key;
	return 1;
}

void renew_degree(FibNode *parent, int degree){
	if (parent){
		parent->degree -= degree;
	}
	if (parent->parent){
		renew_degree(parent->parent, degree);
	}
	return;
}

void fib_heap_decrease(FibHeap *heap, FibNode *node, Type key){
	FibNode *parent = NULL;
	if (!heap || !heap->min || !node){
		return;
	}
	node->key = key;
	parent = node->parent;
	if (parent&&node->key < parent->key){
		fib_heap_cut(heap, node, parent);
		fib_heap_cascading_cut(heap, parent);
	}
	if (node->key < heap->min->key){
		heap->min = node;
	}
}

void fib_heap_cut(FibHeap *heap, FibNode *node, FibNode *parent){
	if (!heap || !heap->min || !node || !parent){
		return;
	}
	fib_node_remove(node);
	renew_degree(parent, node->degree);
	if (parent->child == node->right){
		parent->child = NULL;
	}
	else{
		parent->child = node->right;
	}
	node->parent = parent;
	node->left = node->right = node;
	node->marked = 0;
	fib_node_add(node, heap->min);

}

void fib_heap_cascading_cut(FibHeap *heap, FibNode *node){
	if (!heap || !heap->min || !node){
		return;
	}
	FibNode *parent = node->parent;
	if (!parent){
		return;
	}
	if (node->marked == 0){
		node->marked = 1;
	}
	else{
		fib_heap_cut(heap, node, parent);
		fib_heap_cascading_cut(heap, parent);
	}
}

void fib_heap_increase(FibHeap *heap, FibNode *node, Type key){
	FibNode *child, *parent,*right;
	if (!heap || !heap->min || !node){
		return;
	}
	while (node->child){
		child = node->child;
		fib_node_remove(child);
		if (node->child == child->right){
			node->child = NULL;
		}
		else{
			node->child = child->right;
		}
		fib_node_add(child, heap->min);
		child->parent = NULL;
	}
	node->degree = 0;
	node->key = key;
	parent = node->parent;
	if (parent){
		fib_heap_cut(heap, node, parent);
		fib_heap_cascading_cut(heap, parent);
	}
	else if (heap->min == node){
		right = node->right;
		while (right!=node){
			if (right->key < node->key){
				heap->min = right;
			}
			right = right->right;
		}
	}
}

void fib_heap_delete_node(FibHeap *heap, FibNode *Node){
	if (!heap || !Node){
		return;
	}
	Type min = heap->min->key;
	fib_heap_decrease(heap, Node, min - 1);
	_fib_heap_extract_min(heap);
	free(Node);
	return;
}

FibNode *fib_node_search(FibNode *root, Type key){
	FibNode *t = root;
	FibNode *p = NULL;
	if (!root){
		return root;
	}
	do{
		if (t->key == key){
			p = t;
			break;
		}
		else{
			if ((p = fib_node_search(t->child, key)) != NULL){
				break;
			}
		}
		t = t->right;
	} while (t != root);
	return p;
}

FibNode *fib_heap_search(FibHeap *heap, Type key){
	if (!heap || !heap->min){
		return NULL;
	}
	return fib_node_search(heap->min, key);
}

int fib_heap_contains(FibHeap *heap, Type key){
	return fib_heap_search(heap, key) != NULL ? 1 : 0;
}

void fib_heap_delete_key(FibHeap *heap, Type key){
	FibNode *node = NULL;
	if (!heap){
		return;
	}
	if ((node = fib_heap_search(heap, key) )== NULL){
		return;
	}
	fib_heap_delete_node(heap, node);
	return;
}

void fib_heap_update_node(FibHeap *heap, FibNode *node, Type key){
	if (!heap || !heap->min||!node){
		return;
	}
	if (key < node->key){
		fib_heap_decrease(heap, node, key);
	}
	else if (key> node->key){
		fib_heap_increase(heap, node, key);
	}
	else{
		printf("no need to update!");
	}
	return;
}

void fib_heap_update_key(FibHeap *heap, Type oldkey, Type newkey){
	FibNode *node = NULL;
	if (!heap||!heap->min){
		return;
	}
	if ((node = fib_heap_search(heap, oldkey)) == NULL){
		return;
	}
	if (fib_heap_search(heap, newkey) != NULL){
		return;
	}
	fib_heap_update_node(heap, node, newkey);
	return;
}

void fib_node_destory(FibNode *node){
	FibNode *start = node;
	if (!node){
		return;
	}
	do{
		if (node->child){
			fib_node_destory(node->child);
		}
		
		node = node->right;
		free(node->left);
	} while (start != node);
	return;
}

void fib_heap_destory(FibHeap *heap){
	if (!heap){
		return;
	}
	fib_node_destory(heap->min);
	free(heap->cons);
	free(heap);
	return;
}

void _fib_heap_print(FibNode *node, FibNode *pre, int direction){
	if (!node || !pre){
		return;
	}
	FibNode *start = node;
	do{
		if (direction == 1){
			printf("%8d(%d) is %2d's child\n",node->key,node->degree,pre->key);
		}
		else{
			printf("%8d(%d) is %2d's next\n", node->key, node->degree, pre->key);
		}
		if (node->child){
			_fib_heap_print(node->child, node, 1);
		}
		pre = node;
		node = node->right;
		direction = 2;
	} while (start != node);
	return;
}

void fib_heap_print(FibHeap *heap){
	if (!heap || !heap->min){
		return;
	}
	int i = 0;
	FibNode *p = heap->min;
	printf("== 斐波那契堆的详细信息: ==\n");
	do{
		i++;
		printf("%2d. %4d(%d) is root\n", i, p->key, p->degree);
		_fib_heap_print(p->child, p, 1);
		p = p->right;
	} while (p != heap->min);
	return;
}
