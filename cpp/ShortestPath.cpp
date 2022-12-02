#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXINT 0x3f3f3f3f
#define MAXN 101
int G[MAXN][MAXN];
// int N = 5;
// int edgeNum = 7;
// int x[] = {0, 0, 0, 1, 1, 2, 3};
// int y[] = {1, 3, 4, 2, 4, 3, 4};
// int w[] = {2, 1, 3, 2, 4, 1, 5};
int N = 6;
int edgeNum = 8;
int x[] = {0, 0, 0, 1, 1, 2, 2, 3};
int y[] = {1, 4, 5, 2, 4, 3, 5, 4};
int w[] = {10, 100, 50, 10, 1, 100, 3, 2};
void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            G[i][j] = MAXINT;
            if (i == j) G[i][j] = 0;
        }
    }
}
void build() {
    init();
    for (int i = 0; i < edgeNum; i++) {
        G[x[i]][y[i]] = w[i];
        G[y[i]][x[i]] = w[i];
    }
}
void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}
// @date: 2022-12-01 16:35:40
// @brief: 普通的DIJ
int len[MAXN];
int pre[MAXN];
int vis[MAXN];
void dij1(int s) {
    memset(vis, 0, sizeof(vis));
    fill(len, len + MAXN, MAXINT);
    fill(pre, pre + MAXN, MAXINT);
    len[s] = 0;
    for (int i = 0; i < N; i++) {
        int k = -1;
        int minlen = MAXINT;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && len[j] < minlen) {
                k = j;
                minlen = len[j];
            }
        }
        if (k == -1) break;
        vis[k] = -1;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && len[k] + G[k][j] < len[j]) {
                len[j] = len[k] + G[k][j];
                pre[j] = k;
            }
        }
    }
}
void printDijRes1() {
    cout << "len:" << endl;
    for (int i = 0; i < N; i++) {
        cout << len[i] << " ";
    }
    cout << endl;
    cout << "pre:" << endl;
    for (int i = 0; i < N; i++) {
        cout << pre[i] << " ";
    }
    cout << endl;
}
// @date: 2022-12-01 16:49:08
// @brief: 堆优化
struct Node {
    int to, weight;
    Node(int to = -1, int weight = MAXINT) : to(to), weight(weight) {
    }
    bool operator<(const Node &a) const {
        return weight > a.weight;
    }
    friend ostream &operator<<(ostream &out, const Node &a) {
        out << a.to << " " << a.weight;
        return out;
    }
};
void dij2(int s) {
    memset(vis, 0, sizeof(vis));
    fill(pre, pre + MAXN, -1);
    fill(len, len + MAXN, MAXINT);
    priority_queue<Node> q;
    len[s] = 0;
    q.push(Node(s, 0));
    while (!q.empty()) {
        Node k = q.top();
        q.pop();
        if (vis[k.to]) continue;
        vis[k.to] = true;
        cout << k << endl;
        int to = k.to;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && len[to] + G[to][j] < len[j]) {
                len[j] = len[to] + G[to][j];
                pre[j] = to;
                q.push(Node(j, len[j]));
            }
        }
    }
}
// @date: 2022-12-01 18:12:58
// @brief: floyd 算法
int dist[MAXN][MAXN];  // 拷贝图
int path[MAXN][MAXN];  // 路径
void floyd() {
    // @date: 2022-12-01 18:40:24
    // @brief: 这里的初始化要注意一下 要求：dist主对角线为0 dist主对角线为-1
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = G[i][j];
            if (i != j && G[i][j] < MAXINT) {
                path[i][j] = i;
            } else {
                path[i][j] = -1;
            }
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}

void printFloyd() {
    cout << "--------------------dist--------------\n";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------------------path--------------\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    build();
    // print();

    // dij1(0);
    // printDijRes1();
    // dij2(0);
    // floyd();
    // printFloyd();

    return 0;
}
