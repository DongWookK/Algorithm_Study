#include <iostream>
#include <vector>
using namespace std;


long long a[100][2];
long long go(int n) {
	//n�ڸ� ������ ������ ��ģ��  D[N] = D[N-1][0] + D[N-1][1];
	//�ʱ�ȭ �ؾ��� �� ?  ���� ù�ڸ�.
	//������ ���� 1�̸� 1�� �ȵ�
	if (n>=2) {


		//0�ΰ��� 1�ΰ�� �ΰ��� ��������Ѵ�
		a[n][0] = go(n - 1);
		a[n][1] = a[n - 1][0];
		return a[n][0] + a[n][1];
	}
	else if (n == 1) {
		a[1][0] = 0;
		a[1][1] = 1;
	}

	return 1;
}

int main() {
	long long n;
	cin >> n;
	cout << go(n);
	return 0;
}