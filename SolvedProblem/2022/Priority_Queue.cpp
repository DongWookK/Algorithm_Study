#include <iostream>
using namespace std;
#define MAX_SIZE 99999
// 최대힙은 부모 노드가 자식 노드보다 값이 큰 '완전 이진 트리'를 의미한다. (+ 형제보다 클필요는 없음)
// 이진트리의 종류 다시 정리 필요 !


//삽입과정은 완전 이진트리를 유지하는 형태로 순차적 삽입.
// 왼쪽에서 오른쪽으로 순차적으로 삽입
// 삽입 이후에 루트노드까지 올라가며 정렬됨

struct PriorityQueue {
	int heap[MAX_SIZE];
	int count;
	
};

void swap(int *A, int *B) {
	int temp = *A;
	*A = *B;
	*B = temp;
}

void push(PriorityQueue* pq, int data) {
	if (pq->count >= MAX_SIZE) return;
	pq->heap[pq->count] = data;
	int now = pq->count; //완전 이진트리이므로 현재 count에 넣으면 가장 마지막 인덱스에 들어감
	int parent = ( pq->count - 1 ) / 2;  //트리에서 parent를 찾는 방법
	while (now > 0 && pq->heap[now] > pq->heap[parent]) {
		swap(&pq->heap[now], &pq -> heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;          // 패런트랑만 비교하면된다. 부모노드가 자식보다만 크면 되기 때문
	}
	pq->count++;
}

int pop(PriorityQueue* pq) {
	if (pq->count <= 0) return -9999;
	int res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq->count]; //제일끝에있는 원소를 루트로
	int now = 0, leftchild = 1, rightchild = 2;
	int target = now; //루트부터 하향식으로 비교하며 힙 구성

	while (leftchild < pq->count) {
		if (pq->heap[target] < pq->heap[leftchild]) target = leftchild;
		if (pq->heap[target] < pq->heap[rightchild] && rightchild < pq->count) target = rightchild;
		if (target == now) break; //더이상 내려가지 않아도 될 때???        //트리는 이미 정렬된상태이고 이는 부모보다 더 큰 자식이 없다는 것을 의미. right와 left를 비교해서 둘다 root보다 작으면 더 찾을 필요 없음
		else {
			swap(&pq->heap[now], &pq->heap[target]);
			now = target;
			leftchild = now * 2 + 1;
			rightchild = now * 2 + 2; //부모 인덱스 찾는것 반대로
		}
	}

	return res;
}

int main()
{
	int n, data;
	cin >> n;
	PriorityQueue pq;
	pq.count = 0;
	for (int i = 0; i < n; i++) {
		cin >> data;
		push(&pq, data);
	}

	for (int i = 0; i < n; i++) {
		int data = pop(&pq);
		cout << data << " ";
	}
	return 0;
}
