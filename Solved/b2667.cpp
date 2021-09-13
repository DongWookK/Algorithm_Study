#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int a[25][25];
bool check[25][25];
int ans[30] = { 0, };
int cnt = 1;

void dfs(int x, int y) {
	check[x][y] = true;


	if (a[x][y - 1] = 1 && check[x][y - 1] == false)
		dfs(x, y - 1);
	if (a[x][y + 1] = 1 && check[x][y + 1] == false)
		dfs(x, y + 1);
	if (a[x - 1][y] = 1 && check[x - 1][y] == false)
		dfs(x - 1, y);
	if (a[x + 1][y] = 1 && check[x + 1][y] == false)
		dfs(x + 1, y);

}

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	cout << endl;
	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 || a[i][j] == 0)
			{
				cnt = 1;
				dfs(i, j);
			}
				
		}
		cout << endl;
	}
	

	return 0;
}