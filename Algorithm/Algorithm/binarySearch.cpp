#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int arr[], int n, int key) {
	int start = 0;
	int end = n;
	int mid;
	while (end-start >=0) { //맞닿으면 어레이에 조냊 x
		mid = (start + end) / 2;  // 케이스에 따라 start와 end를 바꿔가면서 mid 갱신
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