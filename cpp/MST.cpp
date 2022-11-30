#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define MAXN 10001
#define MAXINT 0x7f7f7f7f
int G[MAXN][MAXN];
int N = 5;
int edgeNum = 7;
void build(int x[], int y[], int w[], int edgeNum) {
    // @date: 2022-11-30 18:29:32
    // @brief: 记得初始化所有的矩阵
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            G[i][j] = MAXINT;
        }
    }
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
    cout << endl;
}
// @date: 2022-11-30 18:14:37
// @brief: 最小生成树的prim算法
struct Node {
    int pre;
    int len;
    Node(int pre = -1, int len = MAXINT) {
        this->pre = pre;
        this->len = len;
    }
} edge[10000];
int vis[MAXN];
void prim(int s) {
    // for (int i = 0; i < 10; i++) {
    //     cout << edge[i].len << " " << edge[i].pre << endl;
    // }
    memset(vis, 0, sizeof(vis));
    // @date: 2022-11-30 18:20:58
    // @brief: 不主动初始化 使用特殊值，实现自动初始化
    edge[s].len = 0;
    for (int i = 0; i < N; i++) {
        int minlen = MAXINT;
        int k = -1;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && edge[j].len < minlen) {
                k = j;
                minlen = edge[j].len;
            }
        }
        if (k == -1) break;
        vis[k] = true;
        cout << "<pre:" << edge[k].pre << " k:" << k << " len:" << edge[k].len << ">" << endl;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && G[k][j] < edge[j].len) {
                edge[j].pre = k;
                edge[j].len = G[k][j];
            }
        }
    }
}
// @date: 2022-11-30 18:29:54
// @brief: 使用堆优化
struct Edge {
    int from;
    int to;
    int weight;
    // friend bool operator<(const Edge& a, const Edge& b) {
    //     return a.weight > b.weight;
    // }
    // 这里的const不可少
    bool operator<(const Edge& a) const {
        return this->weight > a.weight;
    }
    friend ostream& operator<<(ostream& out, const Edge& a) {
        out << a.from << " " << a.to << " " << a.weight;
        return out;
    }
};
struct cmp {
    bool operator()(const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    }
};

void prim2(int s) {
    memset(vis, 0, sizeof(vis));
    // 从-1出发 终点为s 距离为零    起始边界点
    Edge e0 = {-1, s, 0};
    priority_queue<Edge> p;
    // priority_queue<Edge, vector<Edge>, cmp> p;
    p.push(e0);
    // @date: 2022-11-30 18:47:38
    // @brief: 这里还可以根据访问的顶点数目提前结束循环
    while (!p.empty()) {
        Edge k = p.top();
        p.pop();
        if (!vis[k.to]) {
            cout << k << endl;
            vis[k.to] = true;
            for (int j = 0; j < N; j++) {
                if (!vis[j]) {
                    p.push(Edge{k.to, j, G[k.to][j]});
                }
            }
        }
    }
}
// @date: 2022-11-30 18:47:22
// @brief: Kruskal算法  非堆优化
// 并查集
int bing[MAXN];
void init() {
    for (int i = 0; i < N; i++) {
        bing[i] = i;
    }
}
int getRoot(int i) {
    return bing[i] == i ? i : getRoot(bing[i]);
}
void merge(int i, int j) {
    int r1 = getRoot(i);
    int r2 = getRoot(j);
    if (r1 != r2) {
        bing[r2] = r1;
    }
}
void kruskal() {
    // 初始化并查集
    init();
    memset(vis, 0, sizeof(vis));
    Edge e[MAXN];
    int ecnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (G[i][j] < MAXINT) e[ecnt++] = Edge{i, j, G[i][j]};
        }
    }
    for (int i = 0; i < N; i++) {
        int minlen = MAXINT;
        int k = 1;
        for (int j = 0; j < ecnt; j++) {
            if (!vis[j] && e[j].weight < minlen) {
                k = j;
                minlen = e[j].weight;
            }
        }
        if (k == -1) break;
        vis[k] = true;
        int from = e[k].from;
        int to = e[k].to;
        if (getRoot(from) != getRoot(to)) {
            cout << e[k] << endl;
            merge(from, to);
        }
    }
}
// @date: 2022-11-30 19:02:21
// @brief: 
int main() {
    int x[] = {0, 0, 0, 1, 1, 2, 3};
    int y[] = {1, 3, 4, 2, 4, 3, 4};
    int w[] = {2, 1, 3, 2, 4, 1, 5};
    build(x, y, w, edgeNum);
    // prim(0);
    // prim2(0);
    // kruskal();
    kruskal2();
    // print();

    return 0;
}
