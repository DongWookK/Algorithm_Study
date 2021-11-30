#define CRT_Secure_No_Warnings
#include <iostream>
#define NODE_MAX 1001
#define EDGE_MAX 20001
using namespace std;

//���� ���Ḯ��Ʈ���� ������ ������ ����
//�̿ܿ� ���� �ڷᱸ�� ���밡��

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
		if (target == now) break; //���� ������
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

void addNode(Node** target, int index, Edge* edge) {
	if (target[index] == NULL) { //Ư�� ������ ����� ������ �ϳ��� ���ٸ�
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

Node** adj;
int d[NODE_MAX]; //������ �湮���� Ȯ��

int main() {
	int n, m;
	cin >> n >> m;
	adj = new Node*[(n + 1)]; //double pointer(���迭)�� ���� �����Ҵ�
	for (int i = 1; i <= n; i++) {
		adj[i] = NULL;
	}
	PriorityQueue* pq;
	//�����˰��� ���� ����� �켱���� ť
	pq = new PriorityQueue;
	pq->count = 0;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		Edge* edge1 = new Edge;
		edge1->node = b;
		edge1->cost = c;
		addNode(adj, a, edge1);
		Edge* edge2 = new Edge;
		edge2->node = a;
		edge2->cost = c;
		addNode(adj, b, edge2);
	}

	//���� �˰���
	long long res = 0;
	Edge* start = new Edge;
	start->cost = 0; start->node = 1; push(pq, start);
	//�켱����ť���� ����(Node)�� ������ŭ �ݺ�
	for (int i = 1; i <= n; i++) {
		int nextNode = -1, nextCost = INT_MAX;
		while (1) { //�湮���� ���� ����߿��� ����� ���� ���� ��带 �켱����ť���� ������
			Edge* now = pop(pq);
			if (now == NULL)break;
			nextNode = now->node;
			if (!d[nextNode]) { //d�� ���������̹Ƿ� �⺻������ 0, �湮�ߴٸ� 1�� �Ǿ�����.
				nextCost = now->cost; break;
			}
		}
		if (nextCost == INT_MAX) cout << "���� �׷����� �ƴմϴ�.\n";

		res += nextCost;
		cout << nextCost << endl;
		d[nextCost] = (int)1; //����� ���� �ؿ� �κ� ���� �ʿ�
		Node* cur = adj[nextNode];

		while (cur != NULL) {
			push(pq, cur->data);
			cur = cur->next; 
		} //�� ���� ������ ��� ��带 Ȯ���ϸ鼭 ������ �켱����ť�� �־��
	}
	cout << res << endl;
	return 0;
}
