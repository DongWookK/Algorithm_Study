#include <iostream>
using namespace std;
/*---------------------
Two dots - dfs cycle problem
baekjoon 16929
----------------------*/
char a[55][55];
bool check[55][55];
int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool go(int x, int y, int px, int py, char color) 
{
    if (check[x][y]) {
        return true;
    }
    check[x][y] = true;
    for (int k = 0; k < 4; k++) 
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) 
        {
            if (!(nx == px && ny == py)) 
            {
                if (a[nx][ny] == color) 
                {
                    if (go(nx, ny, x, y, color)) 
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check[i][j]) continue;
            bool ok = go(i, j, -1, -1, a[i][j]);
            if (ok) {
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    cout << "No" << '\n';
	return 0;
}