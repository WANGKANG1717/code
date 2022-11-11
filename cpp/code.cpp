/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: test.cpp
 * @filepath: cpp\code.cpp
 * @date: 2022-10-30 15:24:34
 * @description:  刷题
 */
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
#define mk make_pair
const int MAXN = 1005, MOD = 1e9 + 7;
// @date: 2022-11-11 22:55:45
// @brief: 24. 机器人的运动范围 BFS版本
// 有待实现

/* // @date: 2022-11-11 22:53:59
// @brief: 一道简单的深度搜索题目，还让我花费了点时间调试。。。
class Solution123122 {
   private:
    int k, cols, rows;
    int ans;
    bool vis[1000][1000];

   public:
    int f(int i, int j) {
        int sum = 0;
        while (i) {
            sum += i % 10;
            i /= 10;
        }
        while (j) {
            sum += j % 10;
            j /= 10;
        }
        return sum;
    }
    void cnt(int x, int y) {
        if (x < 0 || y < 0 || x >= rows || y >= cols || f(x, y) > k) return;
        if (vis[x][y]) return;
        ans++;
        vis[x][y] = true;
        cnt(x + 1, y);
        cnt(x, y + 1);
        cnt(x - 1, y);
        cnt(x, y - 1);
    }
    int movingCount(int threshold, int rows, int cols) {
        k = threshold;
        this->cols = cols;
        this->rows = rows;
        cnt(0, 0);
        return ans;
    }
};
int main() {
    Solution123122 s;
    s.movingCount(10, 2, 2);
    return 0;
} */

/*
// @date: 2022-11-10 22:58:23
// @brief:  分组背包问题
int dp[MAXN];
int w[MAXN];
int v[MAXN];
int N, V, S;
int main() {
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 0; j < S; j++) {
            cin >> v[j] >> w[j];
        }
        // @date: 2022-11-09 22:55:02
        // @brief: 这里要注意 优化为一维背包后，必须将枚举物品的循环放在枚举提及的循化里面
        // for (int k = 0; k < S; k++) {
        //     for (int j = V; j >= 0; j--) {
        //         if (j >= v[k])
        //             dp[j] = max(dp[j], dp[j - v[k]] + w[k]);
        //     }
        // }
        for (int j = V; j >= 0; j--) {
            for (int k = 0; k < S; k++) {
                if (j >= v[k]) {
                    dp[j] = max(dp[j], dp[j - v[k]] + w[k]);
                }
            }
        }
    }
    cout << dp[V] << endl;

    return 0;
} */

/* // @date: 2022-11-08 22:30:23
// @brief: 01背包求字典序最小的方案
int dp[MAXN][MAXN];
int w[MAXN];
int v[MAXN];
int N, V;
int main() {
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = N; i >= 1; i--) {
        for (int j = 0; j <= V; j++) {
            dp[i][j] = dp[i + 1][j];
            if (j >= v[i]) {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - v[i]] + w[i]);
            }
        }
    }
    int i = 1, j = V;
    // @date: 2022-11-09 22:29:34
    // @brief: 因为要求字典序最小的方案，所以要从前向后推
    while (i <= N) {
        if (j >= v[i] && (dp[i + 1][j - v[i]] + w[i]) == dp[i][j]) {
            cout << i << " ";
            j -= v[i];
        }
        i++;
    }

    return 0;
} */

/* // @date: 2022-11-05 22:46:19
// @brief: 01背包问题求方案数一维版本
int dp[MAXN];
int cnt[MAXN];
int main() {
    int N, V;
    cin >> N >> V;
    int w, v;
    int val;
    // cnt[0] = 1;
    // @date: 2022-11-07 22:29:25
    // @brief: 初始化要这样
    fill(cnt, cnt + MAXN, 1);
    for (int i = 1; i <= N; i++) {
        int v, w;
        cin >> v >> w;
        // @date: 2022-11-07 22:29:04
        // @brief: 这里是体积v
        for (int j = V; j >= v; j--) {
            int val = dp[j - v] + w;
            // @date: 2022-11-07 22:29:40
            // @brief: 根据情况进行判断
            if (val > dp[j]) {
                dp[j] = val;
                cnt[j] = cnt[j - v];
            } else if (val == dp[j]) {
                cnt[j] = (cnt[j] + cnt[j - v]) % MOD;
            }
        }
    }
    cout << cnt[V] << endl;
    return 0;
} */

// @date: 2022-11-05 22:26:43
// @brief: 01背包问题求方案数
/* int dp[MAXN][MAXN];
int cnt[MAXN][MAXN];
int w[MAXN];
int v[MAXN];
int main() {
    int N, V;
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> v[i] >> w[i];
    }
    for (int j = 0; j <= V; j++) {
        cnt[0][j] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= V; j++) {
            if (j < v[i]) {
                dp[i][j] = dp[i - 1][j];
                cnt[i][j] = cnt[i - 1][j];
            } else {
                if (dp[i-1][j - v[i]] + w[i] > dp[i - 1][j]) {
                    cnt[i][j] = cnt[i - 1][j - v[i]];
                } else if (dp[i - 1][j - v[i]] + w[i] == dp[i - 1][j]) {
                    cnt[i][j] = (cnt[i - 1][j - v[i]] + cnt[i - 1][j]) % MOD;
                } else {
                    cnt[i][j] = cnt[i - 1][j];
                }
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    cout << cnt[N][V] << endl;

    return 0;
} */
/* // @date: 2022-11-04 22:41:54
// @brief: 货币求组合方案数
// @date: 2022-11-04 22:48:43
// @brief: 很难理解 需要慢慢理会了
#include <iostream>
using namespace std;
#define N 100
#define M 10001
#define ll long long
ll dp[N][M];
int w[N];
int main() {
    int n, m;
    // n为货币面值数 m为要凑的面值
    cin>>n>>m;
    for(int i=1; i<=n; i++)  {
        cin>>w[i];
    }
    dp[0][0]=1;
    // i代表当前取的是第几个面值
    for(int i=1; i<=n; i++) {
        // j代表当前是在凑多大的面值
        for(int j=0; j<=m; j++) {
            // k代表我拿做多少这种数额的纸币去进行凑面额
            for(int k=0; k*w[i]<=j; k++) {
                dp[i][j]+=dp[i-1][j-k*w[i]];
            }
        }
    }

    cout<<dp[n][m];

    return 0;
} */
// @date: 2022-11-03 17:43:02
// @brief: 可恶，终于可以说彻底搞懂这道题目了
// @date: 2022-11-03 17:41:42
// @brief:23. 矩阵中的路径
class Solution23__ {
   private:
    bool vis[100][100];
    int flag = 0;

   public:
    void dfs(vector<vector<char>>& matrix, string& str, int dep, int i, int j) {
        //这里加个flag剪枝就好了
        if (flag || dep == str.length() - 1) {
            flag = true;
            return;
        }
        int n = matrix.size();
        int m = matrix[i].size();
        int a[] = {-1, 1, 0, 0};
        int b[] = {0, 0, 1, -1};
        for (int k = 0; k < 4; k++) {
            int x = i + a[k];
            int y = j + b[k];
            //这里是dep+1
            if ((x >= 0 && y >= 0 && x < n && y < m) && !vis[x][y] && matrix[x][y] == str[dep + 1]) {
                vis[x][y] = true;
                dfs(matrix, str, dep + 1, x, y);
                vis[x][y] = false;
            }
        }
    }
    bool hasPath(vector<vector<char>>& matrix, string& str) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == str[0]) {
                    vis[i][j] = true;
                    dfs(matrix, str, 0, i, j);
                    vis[i][j] = false;
                    if (flag == true) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
// @date: 2022-11-03 15:10:36
// @brief: 23. 矩阵中的路径
// @date: 2022-11-03 16:10:21
// @brief: made 花了我好长时间，都没做处理，总是出小bug，烦死了！！！！！！！！！！
// @date: 2022-11-03 17:17:52
// @brief: made 我的码力这么差了吗，这道题让我搞了好久才写出来。！
class Solution23_ {
   public:
    bool dfs(vector<vector<char>>& matrix, string& str, int dep, int i, int j) {
        //边界检查
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[i].size()) {
            return false;
        }
        //判断是否可以进行下一此递归
        if (matrix[i][j] != str[dep]) return false;
        if (dep == str.length() - 1) {
            return true;
        }
        char tmp = matrix[i][j];
        matrix[i][j] = '*';
        int a[] = {1, -1, 0, 0};
        int b[] = {0, 0, 1, -1};
        for (int k = 0; k < 4; k++) {
            int x = i + a[k];
            int y = j + b[k];  //这里一个等号 可害惨了我！！
            if (dfs(matrix, str, dep + 1, x, y)) return true;
        }
        matrix[i][j] = tmp;
        return false;
    }
    bool hasPath(vector<vector<char>>& matrix, string& str) {
        if (!matrix.size()) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == str[0]) {
                    if (dfs(matrix, str, 0, i, j)) return true;
                }
            }
        }
        return false;
    };
};
class Solution23 {
   public:
    int vis[100][100];
    int flag = 0;
    void dfs(vector<vector<char>>& matrix, string& str, int dep, int i, int j) {
        //边界检查
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[i].size()) {
            return;
        }
        //判断是否可以进行下一此递归
        if (flag || vis[i][j] || matrix[i][j] != str[dep]) return;
        if (dep == str.length() - 1) {
            flag = true;
            return;
        }
        vis[i][j] = true;
        dfs(matrix, str, dep + 1, i - 1, j);
        dfs(matrix, str, dep + 1, i + 1, j);
        dfs(matrix, str, dep + 1, i, j + 1);
        dfs(matrix, str, dep + 1, i, j - 1);
        vis[i][j] = false;
    }
    bool hasPath(vector<vector<char>>& matrix, string& str) {
        if (!matrix.size()) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == str[0]) {
                    dfs(matrix, str, 0, i, j);
                    if (flag) return true;
                }
            }
        }
        return false;
    };
};
// @date: 2022-11-03 14:54:13
// @brief: 22. 旋转数组的最小数字
class Solution22 {
   public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        int Min = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                Min = nums[i];
                return Min;
            } else {
                if (nums[i] < Min) {
                    Min = nums[i];
                }
            }
        }
        return Min;
    }
};
// @date: 2022-11-03 14:46:52
// @brief: 21. 斐波那契数列
class Solution {
   private:
    int fib[100];

   public:
    Solution() {
        getFib();
    }
    void getFib() {
        fib[0] = 0;
        fib[1] = 1;
        for (int i = 2; i <= 39; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    }
    int Fibonacci(int n) {
        return fib[n];
    }
};
// @date: 2022-11-03 14:40:04
// @brief: 用两个栈实现队列
class Stack {
   private:
    int* data;
    int top;
    int MAXSize = 100000;

   public:
    Stack() {
        top = 0;
        data = new int[100000];
    }
    ~Stack() {
        delete[] data;
    }
    bool Push(int x) {
        if (isFull()) {
            return false;
        }
        data[top++] = x;
        return true;
    }
    bool Pop(int& x) {
        if (isEmpty()) {
            return false;
        }
        x = data[--top];
        return true;
    }
    bool Top(int& x) {
        if (isEmpty()) {
            return false;
        }
        x = data[top - 1];
        return true;
    }
    bool isEmpty() {
        if (top == 0)
            return true;
        else
            return false;
    }
    bool isFull() {
        if (top == MAXSize)
            return true;
        else
            return false;
    }
};
class MyQueue {
   private:
    Stack S1, S2;

   public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    bool push(int x) {
        if (S1.isFull()) {
            if (S2.isFull()) {
                return false;
            } else {
                int x;
                while (!S1.isEmpty()) {
                    S1.Pop(x);
                    S2.Push(x);
                }
            }
        }
        S1.Push(x);
        return true;
    }

    /** Removes the element from in front of queue and returns that element. */
    bool pop(int& x) {
        if (empty()) {
            return false;
        } else {
            if (!S1.isEmpty() && S2.isEmpty()) {
                int tmp;
                while (!S1.isEmpty()) {
                    S1.Pop(tmp);
                    S2.Push(tmp);
                }
            }
            S2.Pop(x);
            return true;
        }
    }

    /** Get the front element. */
    bool peek(int& x) {
        if (empty()) {
            return false;
        } else {
            if (!S1.isEmpty() && S2.isEmpty()) {
                int tmp;
                while (!S1.isEmpty()) {
                    S1.Pop(tmp);
                    S2.Push(tmp);
                }
            }
            S2.Top(x);
            return true;
        }
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if (S1.isEmpty() && S2.isEmpty()) {
            return true;
        } else
            return false;
    }
};

// @date: 2022-11-03 14:10:12
// @brief: 19. 二叉树的下一个节点
void solve12() {
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode *father;
     *     TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
     * };
     */
    // class Solution {
    //    public:
    //     TreeNode* inorderSuccessor(TreeNode* p) {
    //         if (p->right != NULL) {
    //             p = p->right;
    //             while (p->left) {
    //                 p = p->left;
    //             }
    //         } else {
    //             TreeNode* fa = p;
    //             while (p) {
    //                 fa = p->father;
    //                 if (fa == NULL) {
    //                     p = NULL;
    //                     break;
    //                 } else if (fa->left == p) {
    //                     p = fa;
    //                     break;
    //                 } else {
    //                     p = fa;
    //                     fa = fa->father;
    //                 }
    //             }
    //         }
    //         return p;
    //     }
    // };
}

// @date: 2022-11-02 13:58:00
// @brief: 13. 找出数组中重复的数字
int solve11(vector<int> nums) {
    map<int, int> mp;
    int ans = -1;
    int flag1 = false;
    int flag2 = false;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
        if (nums[i] >= 0 && nums[i] < n) {
            if (mp[nums[i]] > 1) {
                ans = nums[i];
                flag2 = true;
            }
        } else {
            flag1 = true;
            break;
        }
    }
    if (flag1 == true)
        return -1;
    else
        return ans;
}
void solve10() {
    int dp[MAXN];
    memset(dp, 0, sizeof(dp));
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
}
// @date: 2022-11-01 13:37:48
// @brief: 混合背包问题
void solve9() {
    int dp[MAXN], v[10 * MAXN], w[10 * MAXN];
    int cnt = 0;  //拆分后的数量  最后都转化为01背包
    memset(dp, 0, sizeof(dp));
    memset(v, 0, sizeof(v));
    memset(w, 0, sizeof(w));
    int N, V;
    cin >> N >> V;
    // @date: 2022-11-02 13:13:42
    // @brief: v 物品的体积 w 物品价值 s 物品数量
    /*
    si=−1 表示第 i 种物品只能用1次
    si=0 表示第 i 种物品可以用无限次
    si>0 表示第 i 种物品可以使用 si 次
    */
    int v_, w_, s;
    int p[MAXN];
    for (int i = 1; i <= N; i++) {
        cin >> v_ >> w_ >> s;
        //先转化为多重背包，再二进制优化转化为多重背包
        if (s < 0) {
            s = 1;
        } else if (s == 0) {
            s = V / v_;
        }
        // @date: 2022-11-01 14:00:23
        // @brief: 这里需要用到二进制优化
        // for (int k = 1; k <= s; k++) {
        //     for (int j = v; j <= V; j++) {
        //         dptmp[j] = max(dp[j], dp[j - v] + w);
        //     }
        //     memcpy(dp, dptmp, sizeof(dptmp));
        // }
        // @date: 2022-11-01 14:06:12
        // @brief: 这里的二进制优化稍微学一下
        // @date: 2022-11-02 13:24:16
        // @brief: 二进制优化 https://blog.csdn.net/hnjzsyjyj/article/details/109363826
        // @date: 2022-11-02 13:25:23
        // @brief: 终于搞明白所谓的二进制优化什么鬼了，也就是把数字拆分成2的倍数和的形式
        //用来拆分整数
        int binary = 1;
        while (binary <= s) {
            v[cnt] = v_ * binary;
            w[cnt++] = w_ * binary;
            s -= binary;
            binary *= 2;
        }
        if (s > 0) {
            v[cnt] = v_ * s;
            w[cnt++] = w_ * s;
        }
    }
    // @date: 2022-11-02 13:32:01
    // @brief: 按照二重背包的思路盘它
    for (int i = 0; i < cnt; i++) {
        for (int j = V; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[V];
}
// @date: 2022-11-01 13:26:05
// @brief: 多重背包问题1 优化
void solve8() {
    int dp[MAXN];
    int dptmp[MAXN];
    int N, V;
    cin >> N >> V;
    int v, w, s;
    for (int i = 1; i <= N; i++) {
        cin >> v >> w >> s;
        for (int k = 1; k <= s; k++) {
            for (int j = v; j <= V; j++) {
                dptmp[j] = max(dp[j], dp[j - v] + w);
            }
            memcpy(dp, dptmp, sizeof(dptmp));
            // for (int j = 0; j <= V; j++) {
            //     dp[j] = dptmp[j];
            // }
        }
    }
    cout << dp[V];
}
// @date: 2022-11-01 13:11:36
// @brief: 多重背包问题1
void solve7() {
    int dp[MAXN][MAXN];
    int N, V;
    cin >> N >> V;
    int v[MAXN];
    int w[MAXN];
    int s[MAXN];
    for (int i = 1; i <= N; i++) {
        cin >> v[i] >> w[i] >> s[i];
    }
    for (int i = 1; i <= N; i++) {
        //取背包中的一个
        for (int k = 1; k <= s[i]; k++) {
            //开始尝试放入
            for (int j = 0; j <= V; j++) {
                if (j < v[i]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
                }
            }
            // @date: 2022-11-01 13:25:32
            // @brief: 每次装入之后要把结返回到上一层
            for (int j = 0; j <= V; j++) {
                dp[i - 1][j] = dp[i][j];
            }
        }
    }
    cout << dp[N][V];
}
// @date: 2022-11-01 13:07:35
// @brief: 完全背包优化
void solve6() {
    int dp[MAXN];
    int N, V;
    cin >> N >> V;
    int v, w;
    for (int i = 1; i <= N; i++) {
        cin >> v >> w;
        for (int j = v; j <= V; j++) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }

    cout << dp[V];
}
// @date: 2022-11-01 12:58:59
// @brief: 完全背包问题
// @date: 2022-11-01 13:06:42
// @brief: 原来如此，我终于搞明白了
void solve5() {
    int dp[MAXN][MAXN];
    int N, V;
    int v[MAXN];
    int w[MAXN];
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= V; j++) {
            if (j < v[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - v[i]] + w[i]);
            }
        }
    }
    cout << dp[N][V];
}
void solve4_() {
    int dp[MAXN];
    memset(dp, 0, sizeof(dp));
    int N, V;
    int w, v;
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> v >> w;
        for (int j = V; j >= v; j--) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[V];
}

// @date: 2022-10-31 16:33:29
// @brief: 01背包问题
void solve4() {
    int dp[MAXN][MAXN];
    int N, V;
    int w, v;
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> v >> w;
        // @date: 2022-10-31 16:57:53
        // @brief: 要从零开始，如果体积不够要复制一遍
        for (int j = 0; j <= V; j++) {
            if (j < v) {
                dp[i][j] = dp[i - 1][j];
            } else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v] + w);
        }
    }
    cout << dp[N][V];
}

// @date: 2022-10-31 15:55:33
// @brief:

int sumOfUnique(vector<int>& nums) {
    int cnt[1000];
    int max_ = 0;
    fill(cnt, cnt + 1000, 0);  //记得初始化
    for (int i = 0; i < nums.size(); i++) {
        // cout<<nums[i]<<" ";
        cnt[nums[i]]++;
        if (nums[i] > max_) max_ = nums[i];
    }
    // cout<<endl;
    int sum = 0;
    // cout<<max_<<endl;
    for (int i = 1; i <= max_; i++) {
        // cout<<cnt[i]<<" ";
        if (cnt[i] == 1) {
            sum += i;
        }
    }
    return sum;
}

// @date: 2022-10-31 15:51:26
// @brief: 809. 情感丰富的文字

int expressiveWords(string s, vector<string>& words) {
    char a[105];
    int cnt = 0;
    a[cnt] = s[0];
    int num[105];
    fill(num, num + 105, 1);
    for (int i = 1; i < s.size(); i++) {
        if (a[cnt] != s[i]) {
            a[++cnt] = s[i];
        } else {
            num[cnt]++;
        }
    }
    // for(int i=0; i<=cnt; i++) {
    //     cout<<a[i]<<" "<<num[i] <<endl;
    // }
    // cout<<endl;
    int ans = 0;
    int b[105];
    int cnt2 = 0;
    int num2[105];
    for (int k = 0; k < words.size(); k++) {
        cnt2 = 0;
        b[cnt2] = words[k][0];
        fill(num2, num2 + 105, 1);
        for (int i = 1; i < words[k].size(); i++) {
            if (b[cnt2] != words[k][i]) {
                b[++cnt2] = words[k][i];
            } else {
                num2[cnt2]++;
            }
        }
        if (cnt != cnt2) {
            continue;
        }
        // cout<<"---------------"<<endl;
        // for(int i=0; i<=cnt; i++) {
        // cout<<b[i]<<" "<<num2[i] <<endl;
        // }
        // cout<<endl;
        bool flag = true;
        for (int i = 0; i <= cnt; i++) {
            if (a[i] != b[i] || num[i] < num2[i] || (num[i] > num2[i] && num[i] < 3)) {
                flag = false;
            }
        }
        if (flag) {
            ans++;
        }
    }
    return ans;
}

// @date: 2022-10-30 15:45:46
// @brief: P1047 [NOIP2005 普及组] 校门外的树
void solve3() {
    int l[100000];
    int max_;
    int n;

    cin >> max_ >> n;
    int low, high;
    for (int i = 0; i < n; i++) {
        cin >> low >> high;
        for (int j = low; j <= high; j++) {
            l[j] = 1;
        }
    }
    int cnt = 0;
    for (int i = 0; i <= max_; i++) {
        if (!l[i]) cnt++;
    }
    cout << cnt << endl;
}

// @date: 2022-10-30 15:44:08
// @brief: P1046 [NOIP2005 普及组] 陶陶摘苹果
void solve2() {
    int a[100];
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    int p;
    cin >> p;
    p += 30;
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        if (a[i] <= p) cnt++;
    }
    cout << cnt << endl;
}

// @date: 2022-10-30 15:24:02
// @brief: P1035 [NOIP2002 普及组] 级数求和
void solve1() {
    int k;
    cin >> k;
    double i = 0;
    double K = k * 1.0;
    double sum = 0.0;
    while (sum <= k) {
        i += 1.0;
        // cout << sum << endl;
        sum += (1.0 / i);
    }
    cout << (int)i;
}
