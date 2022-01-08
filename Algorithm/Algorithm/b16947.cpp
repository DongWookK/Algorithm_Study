#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> a[3000]; //노선 데이터. 어레이의 인덱스에 갈수있는 노선이 들어있음.
int check[3000]; // 0: not visited, 1: visited, 2: cycle
int dist[3000];
int go(int x, int p) {
    // -2: found cycle and not included
    // -1: not found cycle
    // 0~n-1: found cycle and start index
    if (check[x] == 1) {
        return x;
    }
    check[x] = 1;
    for (int y : a[x]) {
        if (y == p) continue;
        int res = go(y, x);
        if (res == -2) return -2;
        if (res >= 0) {
            check[x] = 2;
            if (x == res) return -2;
            else return res;
        }
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1; v -= 1;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    go(0, -1); //임의의 노선에서부터 사이클 dfs. 사이클시작
    queue<int> q; //사이클에 해당하는 정점들 들어가는 큐.

    //거리측정
    for (int i = 0; i < n; i++) {
        if (check[i] == 2) {
            dist[i] = 0;
            q.push(i);
        }
        else {
            dist[i] = -1;
        }
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int y : a[x]) {
            if (dist[y] == -1) { //사이클에 해당안하는애들 거리측정.
                q.push(y);
                dist[y] = dist[x] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    return 0;
}