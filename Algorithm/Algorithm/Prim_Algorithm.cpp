#define CRT_Secure_No_Warnings
#include <iostream>
#define NODE_MAX 1001
#define EDGE_MAX 20001
using namespace std;

//간선 연결리스트에서 힙으로 저장해 구현
//이외에 여러 자료구조 응용가능

struct Edge {
	int cost;
	int node;
};

struct PriorityQueue {
	Edge* heap[EDGE_MAX];
	int count;
};

void Swap(Edge* a, Edge* b) {
	Edge tmp;
	tmp.cost = a->cost;
	tmp.node = a->node;
	a->cost = b->cost;
	a->node = b->cost;
	b->cost = tmp.cost;
	b->node = tmp.node;
}

void push(PriorityQueue* pq, Edge* edge) {
	if (pq->count >= EDGE_MAX) return;
	pq->heap[pq->count] = edge;
	int now = pq->count;
	int parent = (pq->count - 1) / 2;
	while (now > 0 && pq->heap[now]->cost < pq->heap[parent]->cost) {
		swap(pq->heap[now], pq->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	pq->count++;
}
