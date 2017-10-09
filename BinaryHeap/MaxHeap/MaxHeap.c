#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MaxHeap.h"

void insert_maxheap(int data){
	//判断容器是否已满
	if (M_CAPACITY == m_size){
		return;
	}
	//放入容器
	m_heap[m_size] = data;

	//增加长度
	m_size++;

	//上调位置
	filterup_maxheap(data);

	return;
}
void filterup_maxheap(int data){
	int cur = 0;
	if ((cur = get_index(data)) == -1){
		return;
	}
	//父元素位置
	int par = (cur - 1) / 2;
	//当前元素副本
	int temp = m_heap[cur];
	while (cur > 0){
		if (m_heap[par] >= temp){
			break;
		}
		else{
			m_heap[cur] = m_heap[par];
			cur = par;
			par = (par - 1) / 2;
		}
	}
	m_heap[cur] = temp;
	return;
}

int get_index(int data){
	for (int i = 0; i < m_size; i++){
		if (data == m_heap[i]){
			return i;
		}
	}
	return -1;
}

int remove_maxheap(int data){
	int  index = -1;
	//容器必须有元素
	if (m_size == 0){
		return -1;
	}
	//容器中必须存在删除元素
	if ((index = get_index(data)) == -1){
		return -1;
	}
	//用最后一个元素覆盖需要删除的元素
	m_heap[index] = m_heap[--m_size];

	//下调
	filterdown_maxheap(index);

	return index;
}

void filterdown_maxheap(int pos){
	int cur = pos;
	int chd = pos * 2 + 1;
	int temp = m_heap[cur];

	while (chd < m_size - 1){

		//选择左右孩子中较大的进行比较
		if (chd < m_size - 1 && m_heap[chd] < m_heap[chd + 1]){
			chd++;
		}
		if (temp >= m_heap[chd]){
			break;
		}
		else{
			m_heap[cur] = m_heap[chd];
			cur = chd;
			chd = chd * 2 + 1;
		}
	}
	m_heap[cur] = temp;
	return;
}

void print_maxheap(){
	for (int i = 0; i < m_size; i++){
		printf("%d ", m_heap[i]);
	}
	printf("\n");
}
