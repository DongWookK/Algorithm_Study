
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(vector<vector<char>> &col)
{
	int n = col.size();
	int i, j;
	int count = 1;
	int ans = 1;
	for (i = 0; i < n; i++) {
		for (j = 1; j < n; j++) {

			if (col[i][j] == col[i][j-1])
				count += 1;
			else
				count = 1;

			if (count > ans)
				ans = count;
		}
		count = 1;
		for (j = 1; j < n; j++) {
			if (col[j][i] == col[j-1][i])
				count += 1;
			else
				count = 1;
			if (count > ans)
				ans = count;
			

		}
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	int temp = 0;

	//이중벡터구현 
	vector<vector<char>> col(n, vector<char>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cin >> col[i][j];
	}

	ans = check(col);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j + 1 < n) {
				swap(col[i][j], col[i][j + 1]);
				int temp = check(col);
				if (ans < temp) ans = temp;
				swap(col[i][j], col[i][j + 1]);
			}
			if (i + 1 < n) {
				swap(col[i][j], col[i + 1][j]);
				int temp = check(col);
				if (ans < temp) ans = temp;
				swap(col[i][j], col[i + 1][j]);
			}
		}
	}

	cout << ans;
	
	return 0;
}