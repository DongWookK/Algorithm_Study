#include <iostream>
#include <algorithm>
using namespace std;

int arr[10] = { 2,8,4,6,7,5,1,3,10,9 };

   //�տ� a�� ������ b�� ū��
int cmp(int a, int b) {
	if (a % 2 && b % 2) {
		return a < b;
	}
	else if (a % 2) {
		return 1;
	}
	else if (b % 2) {
		return 0;
	}
	return a < b;
}

int main() {
	int arr[] = { 2,8,4,6,7,5,1,3,10,9 };
	cout << "Ŀ���� ������\n";
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	sort(arr, arr + 10, cmp);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
}