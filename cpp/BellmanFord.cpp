/*
 * @Author: WANGKNG
 * @Date: 2022-12-02 16:07:45
 * @LastEditors: WANGKANG
 * @LastEditTime: 2022-12-02 16:17:51
 * @Description: Bellman ford 算法
 */
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
};
vector<Node> G[MAXN];
const int N = 5;  // 规定节点数
int len[MAXN];
void BellmanFord(int s) {
    fill(len, len + MAXN, MAXINT);
    len[s] = 0;
    for (int i = 0; i < N; i++) {
        for (auto it = G[i].begin(); it != G[i].end(); it++) {
            int to = it->to;
            int w = it->weight;
            if (len[s] + w < len[to]) {
                len[to] = len[s] + w;
            }
        }
    }
    //判断是否存在负环
    for (int i = 0; i < N; i++) {
        for (auto it = G[i].begin(); it != G[i].end(); it++) {
            int to = it->to;
            int w = it->weight;
            if (len[s] + w < len[to]) {
                cout << "存在负环" << endl;
                exit(0);
            }
        }
    }
    cout << "算法结束" << endl;
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
int main() {
    return 0;
}
