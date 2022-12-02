/*
 * @Author: WANGKNG
 * @Date: 2022-12-02 16:07:45
 * @LastEditors: WANGKANG
 * @LastEditTime: 2022-12-02 17:10:13
 * @Description: Bellman ford 算法
 */

// @date: 2022-12-02 17:05:08
// @brief: 学算法真是太有意思了！！！！！
/*
    我宣布 BellmanFord 和SPFA 算法 我都已经拿下了！！！！！！
 */

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXINT 0x3f3f3f3f
#define MAXN 10001
struct Node {
    int to, weight;
    Node(int to, int weight) : to(to), weight(weight) {}
    bool operator<(const Node &a) const {
        return weight < a.weight;
    }
    friend ostream &operator<<(ostream &out, const Node &a) {
        out << "<" << a.to << " " << a.weight << "> ";
        return out;
    }
};
vector<Node> G[MAXN];
int N, M;  // 节点数 边数
// 有向图 邻接表
void printG() {
    cout << "printG()---" << endl;
    for (int i = 0; i < N; i++) {
        cout << i << endl;
        for (auto it = G[i].begin(); it != G[i].end(); it++) {
            cout << *it << endl;
        }
    }
}
void build() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        G[l].push_back(Node(r, w));
    }
    printG();
}
int len[MAXN];
void printLen() {
    cout << "----------------len--------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << len[i] << " ";
    }
    cout << endl;
}
void BellmanFord(int s) {
    fill(len, len + MAXN, MAXINT);
    len[s] = 0;
    for (int i = 0; i < N - 1; i++) {
        // 每次都要跑满所有的边
        int flag = 0;  // 标记此轮循环是否有信息更新 如果没有 提前退出循环
        for (int j = 0; j < N; j++) {
            for (auto it = G[j].begin(); it != G[j].end(); it++) {
                int to = it->to;
                int w = it->weight;
                if (len[j] + w < len[to]) {
                    len[to] = len[j] + w;
                    flag = 1;
                }
            }
            // printLen();
        }
        // 扫描完所有的边之后，发现没有边需要更改 直接退出循环
        if (!flag) {
            break;
        }
    }
    //判断是否存在负环
    for (int j = 0; j < N; j++) {
        for (auto it = G[j].begin(); it != G[j].end(); it++) {
            int to = it->to;
            int w = it->weight;
            if (len[j] + w < len[to]) {
                cout << "有负回路！" << endl;
            }
        }
        // printLen();
    }
    cout << "算法结束" << endl;
}
int vis[MAXN];  // 记录顶是否在队列中
int num[MAXN];  // 记录一个顶点的访问次数
void SPFA(int s) {
    // 数据的初始化
    memset(vis, 0, sizeof(vis));
    memset(num, 0, sizeof(num));
    memset(len, 0x3f, sizeof(len));
    // if (len[0] == MAXINT) {
    //     cout << "======" << endl;
    // }
    queue<int> q;
    len[s] = 0;
    q.push(s);
    vis[s] = true;
    num[s]++;
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        vis[k] = false;
        num[k]--;
        for (auto it = G[k].begin(); it != G[k].end(); it++) {
            int to = it->to;
            int w = it->weight;
            if (len[k] + w < len[to]) {
                len[to] = len[k] + w;
                if (!vis[to]) {
                    q.push(to);
                    vis[to] = true;
                    num[to]++;
                    if (num[to] >= N) {
                        cout << "可能存在负环" << endl;
                        exit(0);
                    }
                }
            }
        }
    }
    cout << "SPFA 结束" << endl;
}

int main() {
    build();
    // BellmanFord(0);
    SPFA(0);
    printLen();

    return 0;
}

/*
A B -1
A C 4
B C 3
B D 2
B E 2
D B 1
D C 5
E D -3
*/
/*
5 8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 1 1
3 2 5
4 3 -3
 */

//
