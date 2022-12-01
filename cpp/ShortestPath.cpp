#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define MAXINT 0x3f3f3f3f
#define MAXN 10001
int G[MAXN][MAXN];
int N = 5;
int edgeNum = 7;
int x[] = {0, 0, 0, 1, 1, 2, 3};
int y[] = {1, 3, 4, 2, 4, 3, 4};
int w[] = {2, 1, 3, 2, 4, 1, 5};
void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            G[i][j] = MAXINT;
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
        vis[k.to] = true;
        cout << k << endl;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && len[k.to] + G[k.to][j] < len[j]) {
                len[j] = len[k.to] + G[k.to][j];
                pre[j] = k.to;
                q.push(Node(j, len[j]));
            }
        }
    }
}
int main() {
    build();
    // print();
    // dij1(0);
    // printDijRes1();
    dij2(0);
    return 0;
}
