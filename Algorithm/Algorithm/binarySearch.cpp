#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int arr[], int n, int key) {
	int start = 0;
	int end = n;
	int mid;
	while (end-start >=0) { //�´����� ��̿� ���T x
		mid = (start + end) / 2;  // ���̽��� ���� start�� end�� �ٲ㰡�鼭 mid ����
		if (arr[mid] == key)
			return mid;
		else if (arr[mid] < key) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
}

int main() {
	return 0;
}