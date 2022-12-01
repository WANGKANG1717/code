#include <cstring>
#include <iostream>
using namespace std;
#define MAXINT 0x7f7f7f7f
#define MAXN 10001
struct Node {
    int to, weight;
    Node *next;
    Node(int to = -1, int weight = MAXINT, Node *next = NULL) {
        this->to = to;
        this->weight = weight;
        this->next = next;
    }
    friend ostream &operator<<(ostream &out, const Node &a) {
        out << "<"
            << " " << a.to << " " << a.weight << ">";
        return out;
    };
};
// @date: 2022-12-01 16:01:20
// @brief: 因为只是测试，所以把个数写死了
Node *G[MAXN];
const int N = 5;
// @date: 2022-12-01 16:04:12
// @brief: 建立头节点不使用的一串连续空间
void init() {
    for (int i = 0; i < N; i++) {
        G[i] = new Node;
    }
}
// @date: 2022-12-01 16:06:15
// @brief: 这里使用无向表
void build(int x[], int y[], int w[], int edgeNum) {
    init();
    for (int i = 0; i < edgeNum; i++) {
        int from = x[i];
        int to = y[i];
        int weight = w[i];
        // 采用头插法
        Node *tmp = new Node(to, weight, G[from]->next);
        G[from]->next = tmp;
        Node *tmp2 = new Node(from, weight, G[to]->next);
        G[to]->next = tmp2;
    }
}
void printG() {
    Node *p;
    for (int i = 0; i < N; i++) {
        p = G[i]->next;
        while (p) {
            cout << *p << endl;
            p = p->next;
        }
    }
}
struct Edge {
    int from, weight;
    Edge(int from = -1, int weight = MAXINT) {
        this->from = from;
        this->weight = weight;
    }
    friend bool operator<(const Edge &a, const Edge &b) {
        return a.weight < b.weight;
    }
} edge[MAXN];
int vis[MAXN];
void prim(int s) {
    memset(vis, 0, sizeof(vis));
    edge[s].weight = 0;
    for (int i = 0; i < N; i++) {
        int k = -1;
        int minw = MAXINT;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && edge[j].weight < minw) {
                k = j;
                minw = edge[j].weight;
            }
        }
        if (k == -1) break;
        vis[k] = true;
        cout << "<" << edge[k].from << " " << k << " " << edge[k].weight << ">" << endl;
        Node *p = G[k]->next;
        while (p) {
            if (!vis[p->to] && p->weight < edge[p->to].weight) {
                edge[p->to].weight = p->weight;
                edge[p->to].from = k;
            }
            p = p->next;
        }
    }
}

// @date: 2022-12-01 16:28:11
// @brief:  克鲁斯卢卡尔算法（普通 以及 堆优化） + prim的堆优化不再实现（时间太紧张了）
int main() {
    int x[] = {0, 0, 0, 1, 1, 2, 3};
    int y[] = {1, 3, 4, 2, 4, 3, 4};
    int w[] = {2, 1, 3, 2, 4, 1, 5};
    build(x, y, w, 7);
    prim(0);
    // kruskal();
    // printG();
    return 0;
}
