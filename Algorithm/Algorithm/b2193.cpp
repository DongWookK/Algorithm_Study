#include <iostream>
#include <vector>
using namespace std;


long long a[100][2];
long long go(int n) {
	//n자리 수에서 나오는 이친수  D[N] = D[N-1][0] + D[N-1][1];
	//초기화 해야할 수 ?  제일 첫자리.
	//이전의 값이 1이면 1은 안됨
	if (n>=2) {


		//0인경우랑 1인경우 두개를 더해줘야한다
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