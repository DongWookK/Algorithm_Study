#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<int> a[1001];
bool check[1001] = { false, };

void dfs(int start) {

	check[start] = true;
	cout << start <<" ";
	for (int i = 0; i < a[start].size(); i++)
	{
		int next = a[start][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
	
}

void bfs(int start) {
	queue<int> q;
	memset(check, false, sizeof(check));
	check[start] = true;
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node <<" ";

		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, v;
	cin >> n >> m >> v;
	

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}


	//bfs출력
	dfs(v);
	cout << endl;
	//dfs 출력
	bfs(v);

	return 0;
}