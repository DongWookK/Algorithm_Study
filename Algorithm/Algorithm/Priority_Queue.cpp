#include <iostream>
using namespace std;
#define MAX_SIZE 99999
// �ִ����� �θ� ��尡 �ڽ� ��庸�� ���� ū '���� ���� Ʈ��'�� �ǹ��Ѵ�. (+ �������� Ŭ�ʿ�� ����)
// ����Ʈ���� ���� �ٽ� ���� �ʿ� !


//���԰����� ���� ����Ʈ���� �����ϴ� ���·� ������ ����.
// ���ʿ��� ���������� ���������� ����
// ���� ���Ŀ� ��Ʈ������ �ö󰡸� ���ĵ�

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
	int now = pq->count; //���� ����Ʈ���̹Ƿ� ���� count�� ������ ���� ������ �ε����� ��
	int parent = ( pq->count - 1 ) / 2;  //Ʈ������ parent�� ã�� ���
	while (now > 0 && pq->heap[now] > pq->heap[parent]) {
		swap(&pq->heap[now], &pq -> heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;          // �з�Ʈ���� ���ϸ�ȴ�. �θ��尡 �ڽĺ��ٸ� ũ�� �Ǳ� ����
	}
	pq->count++;
}

int pop(PriorityQueue* pq) {
	if (pq->count <= 0) return -9999;
	int res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq->count]; //���ϳ����ִ� ���Ҹ� ��Ʈ��
	int now = 0, leftchild = 1, rightchild = 2;
	int target = now; //��Ʈ���� ��������� ���ϸ� �� ����

	while (leftchild < pq->count) {
		if (pq->heap[target] < pq->heap[leftchild]) target = leftchild;
		if (pq->heap[target] < pq->heap[rightchild] && rightchild < pq->count) target = rightchild;
		if (target == now) break; //���̻� �������� �ʾƵ� �� ��???        //Ʈ���� �̹� ���ĵȻ����̰� �̴� �θ𺸴� �� ū �ڽ��� ���ٴ� ���� �ǹ�. right�� left�� ���ؼ� �Ѵ� root���� ������ �� ã�� �ʿ� ����
		else {
			swap(&pq->heap[now], &pq->heap[target]);
			now = target;
			leftchild = now * 2 + 1;
			rightchild = now * 2 + 2; //�θ� �ε��� ã�°� �ݴ��
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
