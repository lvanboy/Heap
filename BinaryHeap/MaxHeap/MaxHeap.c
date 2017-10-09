#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MaxHeap.h"

void insert_maxheap(int data){
	//�ж������Ƿ�����
	if (M_CAPACITY == m_size){
		return;
	}
	//��������
	m_heap[m_size] = data;

	//���ӳ���
	m_size++;

	//�ϵ�λ��
	filterup_maxheap(data);

	return;
}
void filterup_maxheap(int data){
	int cur = 0;
	if ((cur = get_index(data)) == -1){
		return;
	}
	//��Ԫ��λ��
	int par = (cur - 1) / 2;
	//��ǰԪ�ظ���
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
	//����������Ԫ��
	if (m_size == 0){
		return -1;
	}
	//�����б������ɾ��Ԫ��
	if ((index = get_index(data)) == -1){
		return -1;
	}
	//�����һ��Ԫ�ظ�����Ҫɾ����Ԫ��
	m_heap[index] = m_heap[--m_size];

	//�µ�
	filterdown_maxheap(index);

	return index;
}

void filterdown_maxheap(int pos){
	int cur = pos;
	int chd = pos * 2 + 1;
	int temp = m_heap[cur];

	while (chd < m_size - 1){

		//ѡ�����Һ����нϴ�Ľ��бȽ�
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
