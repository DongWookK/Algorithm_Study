#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;

int n, m;
int board[50][50];
int check[50][50];

int dx[8] = { 1, 0, -1, 0 , 1 , 1,-1,-1 };
int dy[8] = { 0, 1, 0 , -1, -1, 1,-1, 1 };

void dfs(int x, int y, int cnt) {
	check[x][y] = cnt;
	for (int k = 0; k < 8; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (board[nx][ny] == 1 && check[nx][ny] == 0) {
				dfs(nx, ny, cnt);
			}
		}
	}
}


int main() {

	while (1) {

		memset(check, 0, sizeof(check));
		cin >> n;
		cin >> m;
		if (n == 0 && m == 0)
			break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j];
			}
		}



		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1 && check[i][j] == 0) {
					dfs(i, j, ++cnt);
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}