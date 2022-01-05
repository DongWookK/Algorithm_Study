#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int>>a(n, vector<int>(n,0)); //n*n 2차원 벡터
	vector<vector<int>>d(n, vector<int>(n, 0)); //n*n 2차원 벡터

	for (int i = 0; i < n; i++) {
		for (int j = 0; j<=i; j++) {
			cin >> a[i][j];
		}
	}



	//최대가 되는 경로의 수의 합 찾기
	d[0][0] = a[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			d[i][j] = d[i - 1][j] + a[i][j];
			if (j - 1 >= 0 && d[i][j] < d[i - 1][j - 1] + a[i][j]) {
				d[i][j] = d[i - 1][j - 1] + a[i][j];
			}
		}
	}
	int ans = *max_element(d[n - 1].begin(), d[n - 1].end());
	cout << ans << endl;

	return 0;

}