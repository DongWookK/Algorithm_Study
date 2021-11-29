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

Edge* pop(PriorityQueue* pq) {
	if (pq->count <= 0) return NULL;
	Edge* res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;
	while (leftChild < pq->count) {
		if (pq->heap[target]->cost > pq->heap[leftChild]->cost) target = leftChild;
		if (pq->heap[target]->cost > pq->heap[rightChild]->cost) target = rightChild;
		if (target == now) break; //가장 작을때
		else {
			swap(pq->heap[now], pq->heap[target]);
			now = target;
			leftChild = now * 2 + 1;
			rightChild = now * 2 + 1;
		}
	}
	return res;
}


struct Node {
	Edge* data;
	struct Node* next;
};

Node** adj;
int d[NODE_MAX];

void addNode(Node** target, int index, Edge* edge) {
	if (target[index] == NULL) { //특정 정점에 연결된 간선이 하나도 없다면
		target[index] = new Node;
		target[index]->data = edge;
		target[index]->next = NULL;
	}
	else {
		Node* node = new Node;
		node->data = edge;
		node->next = target[index];
		target[index] = node;
	}
}
