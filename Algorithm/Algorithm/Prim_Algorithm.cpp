#define CRT_Secure_No_Warnings
#include <iostream>
#define NODE_MAX 100
#define EDGE_MAX 200001
using namespace std;

//간선 연결리스트에서 힙으로 저장해 구현
//이외에 여러 자료구조 응용가능

struct Edge {
	int cost;
	int node;
};

struct priorityQueue {
	Edge* heap[EDGE_MAX];
	int count;
};

void swap(Edge* a, Edge* b) {
	Edge temp;
	temp.cost = a->cost;
	temp.node = a->node;
	a->cost = b->cost;
	a->node = b->node;
	b->cost = temp.cost;
	b->node = temp.node;
}

void push(priorityQueue* pq, Edge* edge) {
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

Edge* pop(priorityQueue* pq) {
	if (pq->count <= 0) return NULL;
	Edge* res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;
	// 새 원소를 추출한 이후에 하향식으로 힙을 구성합니다.
	while (leftChild < pq->count) {
		if (pq->heap[target]->cost > pq->heap[leftChild]->cost) target = leftChild;
		if (pq->heap[target]->cost > pq->heap[rightChild]->cost && rightChild < pq->count) target = rightChild;
		if (target == now) break; // 더 이상 내려가지 않아도 될 때 종료
		else {
			swap(pq->heap[now], pq->heap[target]);
			now = target;
			leftChild = now * 2 + 1;
			rightChild = now * 2 + 2;
		}
	}
	return res;
}


struct Node {
	Edge* data;
	struct Node* next;
};

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

Node** adj;
int d[NODE_MAX]; //정점의 방문여부 확인

int main() {
	int n, m;
	cin >> n >> m;
	adj = new Node*[n+1]; //double pointer(노드배열)에 대한 동적할당  //여기가 문제일수도?
	for (int i = 1; i <= n; i++) {
		adj[i] = NULL;
	}
	priorityQueue* pq;
	//프림알고리즘 내에 사용할 우선순위 큐
	pq = new priorityQueue;
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

	//프림 알고리즘
	long long res = 0;
	Edge* start = new Edge;
	start->cost = 0; start->node = 1; push(pq, start);
	//우선순위큐에서 정점(Node)의 개수만큼 반복
	for (int i = 1; i <= n; i++) {
		int nextNode = -1, nextCost = INT_MAX;
		while (1) { //방문하지 않은 노드중에서 비용이 제일 적은 엣지를 우선순위큐에서 꺼내줌
			Edge* now = pop(pq);
			cout << "pqsize:" << pq->count << endl;
			if (now == NULL)break;
			nextNode = now->node;
			if (!d[nextNode]) { //d가 전역변수이므로 기본적으로 0, 방문했다면 1로 되어있음.
				nextCost = now->cost; 
				cout << "now cost:" <<nextCost<< endl;
				break;
			}
		}
		if (nextCost == INT_MAX) cout << "연결 그래프가 아닙니다.\n";

		res += nextCost;
		d[nextCost] = (int)1; //여기랑 여기 밑에 부분 이해 필요
		Node* cur = adj[nextNode];

		while (cur != NULL) {
			push(pq, cur->data);
			cur = cur->next; 
		} //그 노드와 인접한 모든 노드를 확인하면서 정보를 우선순위큐에 넣어둠
	}
	cout << res << endl;
	return 0;
}
