/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: test.cpp
 * @filepath: cpp\code.cpp
 * @date: 2022-10-30 15:24:34
 * @description:  刷题
 */
// @date: 2022-11-01 14:06:27
// @brief: 背包问题基本搞定了
// @date: 2022-11-01 14:06:40
// @brief: 明天开始搞定二进制优化，再刷两道背包问题,然后开始学分治
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
#define MAXSIZE 1010
typedef long long ll;
#define MAXN 1003
void solve();
int main() {
    solve();

    return 0;
}
// @date: 2022-11-03 14:40:29
// @brief:
void solve() {
}
// @date: 2022-11-03 15:10:36
// @brief: 23. 矩阵中的路径
// @date: 2022-11-03 16:10:21
// @brief: made 花了我好长时间，都没做处理，总是出小bug，烦死了！！！！！！！！！！
class Solution23 {
   private:
    unordered_map<char, bool> mp;
    bool vis[100][100];
    int flag = 0;

   public:
    void dfs(vector<vector<char>>& matrix, string& str, int dep, int i, int j) {
        if (dep == str.length() - 1) {
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
