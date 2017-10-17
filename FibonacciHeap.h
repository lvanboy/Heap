#ifndef _FIBONACCI_HEAP_H_
#define _FIBONACCI_HEAP_H_

//键值
typedef int Type;

//fabonacci节点结构
typedef struct FibonacciNode{
	struct FibonacciNode *left;
	struct FibonacciNode *right;
	struct FibonacciNode *parent;
	struct FibonacciNode *child;
	Type key;
	int degree;
	int marked;
}FibonacciNode,FibNode;
//fabonacci结构
typedef struct FibonacciHeap{
	int keyNum;
	int maxDegree;
	FibNode *min;
	FibNode **cons;
}FibonacciHeap,FibHeap;


//将Node节点从循环链表root中删除
void fib_node_remove(FibNode *node);

//将Node节点添加到循环链表root中
void fib_node_add(FibNode *node, FibNode *root);

//将循环链表a 和循环链表b链接
void fib_node_cat(FibNode *a, FibNode *b);

//创建斐波拉契堆
FibHeap *fib_heap_make();

//创建斐波拉契节点
FibNode *fib_node_make();

//将Node节点插入到斐波拉契堆heap中
void fib_heap_insert_node(FibHeap *heap,FibNode *node);

//将值为key的节点添加到斐波拉契堆中
void fib_heap_insert_key(FibHeap *heap, Type key);

//合并h1和h2，返回合成的新堆
FibHeap *fib_heap_union(FibHeap *h1, FibHeap *h2);

//删除堆中最小节点，并返回该节点
FibNode *fib_heap_remove_min(FibHeap *heap);

//将node节点链接到root节点中
void fib_node_link(FibNode *node, FibNode *root);

//创建heap->cons所需要的空间
void fib_heap_cons_make(FibHeap *heap);

//合并斐波拉契根链表中左右度数相同的树
void fib_heap_consolidate(FibHeap *heap);

//移除最小节点，并返回新堆
FibHeap *_fib_heap_extract_min(FibHeap *heap);

void *fib_heap_extract_min(FibHeap *heap);

//获取堆中最小值
FibNode *fib_heap_get_min(FibHeap *heap);

//修改度数
void renew_degree(FibNode *parent, int degree);

//将node从parent子链中玻璃出来，使node 成为堆的根链表之一
void fib_heap_cut(FibHeap *heap, FibNode *node, FibNode *parent);

//对节点node进行"级联剪切"
void fib_heap_cascading_cut(FibHeap *heap, FibNode *node);

//将斐波拉契堆中node 的值减少为key
void fib_heap_decrease(FibHeap *heap, FibNode *node, Type key);

//将斐波拉契堆中node 的值增加为key
void fib_heap_increase(FibHeap *heap, FibNode *node, Type key);

//根据堆中的值更新
void fib_heap_update_key(FibHeap *heap, Type oldkey, Type newkey);

//根据堆中的节点更新
void fib_heap_update_node(FibHeap *heap, FibNode *node, Type key);

//在最小堆中搜索key，并返回key值节点
FibNode *fib_node_search(FibHeap *root, Type key);

//在斐波拉契堆中搜索key，返回key值节点
FibNode *fib_heap_search(FibHeap *heap, Type key);

//在斐波那契堆heap中是否存在键值为key的节点。
int fib_heap_contains(FibHeap *heap, Type key);

//删除节点
void fib_heap_delete_node(FibHeap *heap, FibNode *Node);

//根据key删除节点
void fib_heap_delete_key(FibHeap *heap, Type key);

//销毁斐波拉契节点
void fib_node_destory(FibNode *node);

//销毁斐波拉契堆
void fib_heap_destory(FibHeap *heap);

//打印斐波拉契堆
void fib_heap_print(FibHeap *heap);

void _fib_heap_print(FibNode *node,FibNode *pre,int direction);

#endif
