#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXINT 0x3f3f3f3f
#define MAXN 1001
int x[] = {0, 0, 1, 2, 2, 2, 3, 4, 5, 5};
int y[] = {1, 2, 3, 1, 4, 5, 6, 6, 4, 6};
// int w[] = {};
int N = 7;
int edgeNum = 10;
// struct Node {
//     int to, weight;
//     Node(int to, int weigth) : to(to), weight(weight) {}
// };

// vector<Node> G[MAXN];  // 使用vector实现邻接表 (有向)
vector<int> G[MAXN];
void build() {
    for (int i = 0; i < edgeNum; i++) {
        int from = x[i];
        int to = y[i];
        G[from].push_back(to);
    }
}
int topo[MAXN];
int cnt;
int indegree[MAXN];
void toposort() {
    cnt = 0;
    memset(indegree, 0, sizeof(indegree));
    for (int i = 0; i < N; i++) {
        for (auto it = G[i].begin(); it != G[i].end(); it++) {
            indegree[*it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    cnt = 0;
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        topo[cnt++] = k;
        for (auto it = G[k].begin(); it != G[k].end(); it++) {
            indegree[*it]--;
            if (indegree[*it] == 0) {
                q.push(*it);
            }
        }
    }
    if (cnt < N) {
        cout << "Error" << endl;
    }
    for (int i = 0; i < cnt; i++) {
        cout << topo[i] << " ";
    }
    cout << endl;
}
// @date: 2022-12-01 19:03:15
// @brief:深度搜索实现逆拓扑排序
int vis[MAXN];
void dfs(int s) {
    vis[s] = true;
    for (auto it = G[s].begin(); it != G[s].end(); it++) {
        if (!vis[*it]) dfs(*it);
    }
    cout << s << " ";
}
void rtopoSort() {
    memset(vis, 0, sizeof(vis));
    dfs(0);
}
int main() {
    build();
    // toposort();
    rtopoSort();
    return 0;
}
