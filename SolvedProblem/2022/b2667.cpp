#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <algorithm>

using namespace std;


/*-----------------

단지번호붙이기 b2667

------------------*/
int a[25][25];
int d[25][25]; //방문했는지 체크
int ans[25 * 25];
int n;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y, int num)
{
	d[x][y] = num;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n)
		{
			if (a[nx][ny] == 1 && d[nx][ny] == 0)
				dfs(nx, ny, num);
		}
	}

}

int main()
{
	//정사각형 크기 입력
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	//dfs 실행
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//조건 설립 - 방문하지않았고, 건물이 있으면
			if (a[i][j] == 1 && d[i][j] == 0)
				dfs(i, j, ++cnt);
				
		}
	}


	printf("%d\n", cnt);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans[d[i][j]] += 1;
		}
	}
	sort(ans + 1, ans + cnt + 1);

	for (int i = 1; i <= cnt; i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}