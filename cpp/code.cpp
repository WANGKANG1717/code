/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: test.cpp
 * @filepath: cpp\code.cpp
 * @date: 2022-10-30 15:24:34
 * @description:  刷题
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/* 
// @date: 2022-11-28 19:15:44
// @brief: 46. 二叉搜索树的后序遍历序列
class Solution {
public:
    bool verifySequenceOfBST(vector<int> sequence) {
        return dfs(0, sequence.size()-1, sequence);
    }
    bool dfs(int l, int r, vector<int> &seq) {
        if(l>=r) {
            return true;
        }
        int root=seq[r];
        int k=l;
        while(k<r && seq[k]<root) {
            k++;
        }
        for(int j=k; j<r; j++) {
            if(seq[j]<root) {
                return false;
            }
        }
        return dfs(l, k-1, seq) && dfs(k, r-1, seq);
    }
};

 */
/* 
//之字形打印二叉树
class Solution {
public:
    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> tmp_ans;
        ans.clear();
        queue<TreeNode *> q;
        int cnt = 0;
        if (root != NULL) {
            q.push(root);
            cnt++;
        }
        int dep=0;
        while (!q.empty()) {
            int tmp_cnt = 0;
            tmp_ans.clear();
            while (cnt) {
                TreeNode *p = q.front();
                q.pop();
                tmp_ans.push_back(p->val);
                if (p->left != NULL) {
                    q.push(p->left);
                    tmp_cnt++;
                }
                if (p->right) {
                    q.push(p->right);
                    tmp_cnt++;
                }
                cnt--;
            }
            cnt = tmp_cnt;
            if(dep&1) reverse(tmp_ans.begin(), tmp_ans.end());
            dep++;
            ans.push_back(tmp_ans);
        }
        return ans;
    }
};
 */
/* 
// @date: 2022-11-28 18:56:38
// @brief: 44. 分行从上往下打印二叉树
class Solution {
   public:
    vector<vector<int>> printFromTopToBottom(TreeNode *root) {
        vector<vector<int>> ans;
        vector<int> tmp_ans;
        ans.clear();
        queue<TreeNode *> q;
        int cnt = 0;
        if (root != NULL) {
            q.push(root);
            cnt++;
        }
        while (!q.empty()) {
            int tmp_cnt = 0;
            tmp_ans.clear();
            while (cnt) {
                TreeNode *p = q.front();
                q.pop();
                tmp_ans.push_back(p->val);
                if (p->left != NULL) {
                    q.push(p->left);
                    tmp_cnt++;
                }
                if (p->right) {
                    q.push(p->right);
                    tmp_cnt++;
                }
                cnt--;
            }
            cnt = tmp_cnt;
            ans.push_back(tmp_ans);
        }
        return ans;
    }
}; */
/*
// @date: 2022-11-28 18:51:16
// @brief: 43. 不分行从上往下打印二叉树
class Solution {
public:
    vector<int> printFromTopToBottom(TreeNode* root) {
        vector<int> ans;
        ans.clear();
        queue<TreeNode *> q;
        if(root!=NULL) {
            q.push(root);
        }
        while(!q.empty()) {
            TreeNode *p=q.front();
            q.pop();
            ans.push_back(p->val);
            if(p->left!=NULL) {
                q.push(p->left);
            }
            if(p->right) {
                q.push(p->right);
            }
        }
        return ans;
    }
};
 */
/* // @date: 2022-11-28 18:46:49
// @brief: 一遍过 有点爽的
class Solution {
   public:
    bool isPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.size() != popV.size()) {
            return false;
        } else if (pushV.size() == 0 && popV.size() == 0) {
            return true;
        }
        stack<int> s;
        int p1 = 0, p2 = 0;
        while (p2 < popV.size()) {
            if (s.empty() || s.top() != popV[p2]) {
                do {
                    s.push(pushV[p1++]);
                } while (s.top() != popV[p2] && p1 < pushV.size());
            }
            if (!s.empty() && s.top() == popV[p2]) {
                s.pop();
                p2++;
            } else {
                return false;
            }
        }
        if (!s.empty()) {
            return false;
        } else {
            return true;
        }
    }
}; */

/*
// @date: 2022-11-28 18:26:14
// @brief: 41. 包含min函数的栈
class MinStack {
public:
    #define MAXINT 0x7f7f7f7f
    int *s1;
    int *s2;     //单调栈
    int top1;
    int top2;
    MinStack() {
        s1=new int[10001];
        s2=new int[10001];
        top1=top2=-1;
    }

    void push(int x) {
        s1[++top1]=x;
        //单调栈    //注意这里的是<=
        if(top2==-1 || x<=s2[top2]) {
            s2[++top2]=x;
        }
    }

    void pop() {
       if(s1[top1]==s2[top2]) {
           top2--;
       }
       top1--;
    }

    int top() {
        return s1[top1];
    }

    int getMin() {
        return s2[top2];
    }
};
 */
/*
// @date: 2022-11-28 18:09:16
// @brief: 大整数算法
#include "../head/BigInteger.h"
int main() {
    // BigInteger a = -12345678;
    // cout << a << endl;
    // BigInteger b = "121321223";
    // cout << b << endl;
    // BigInteger x = b;
    // cout << x << endl;
    // string aa = "-12122";
    // BigInteger v = aa;
    // cout << v << endl;

    // BigInteger qq;
    // cin >> qq;
    // cout << qq << endl;

    // BigInteger qqq;
    // cout << qqq << endl;
    BigInteger a = -112;
    BigInteger b = "113";
    BigInteger c = a + b;
    // cout << a << endl;
    // cout << b << endl;
    // cout << c << endl;
    // BigInteger d = a - 1212;
    // BigInteger e = a * b;
    // BigInteger f = e.abs();
    // cout << f << endl;
    // cout << e << endl;
    // BigInteger p = a / 1;
    // cout << p << endl;
    // BigInteger r = a % 113;
    // cout << r << endl;
    // BigInteger q = a % b;
    // cout << q << endl;
    // BigInteger p = a.e(6);
    // cout << p << endl;
    // BigInteger p = a / 11;
    // cout << p << endl;
    // BigInteger q = 11;
    // BigInteger l = a / q;
    // cout << l << endl;
    cout << a + b << endl;
    return 0;
} */

/* // @date: 2022-11-27 14:39:31
// @brief: 进制转换
int main() {
    int a = 15;
    printf("%d\n", a);
    printf("%o\n", a);
    printf("%x\n", a);
    cout << oct << a << endl;
    cout << hex << a << endl;
    cout << dec << a << endl;

    string b = "12120";
    int c = atoi(b.c_str());
    cout << c << endl;
    char s[100];
    itoa(100000, s, 2);
    cout << s << endl;
    char ss[10000];
    sprintf(ss, "%d %x %o", s, 10, 10);         //很好用的哦
    cout << ss << endl;



    return 0;
} */

/* // @date: 2022-11-27 14:28:35
// @brief: 约瑟夫环 问题
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 100010
bool vis[MAXN];
int main() {
    int t;
    cin >> t;
    int num;
    while (t--) {
        cin >> num;
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        int i = 0;
        int p = 0;
        while (cnt < num) {
            if (!vis[i]) {
                p++;
                if (p % 3 == 0) {
                    cnt++;
                    cout << i + 1 << " ";
                    vis[i] = 1;
                }
            }
            i = (i + 1) % num;
        }
        cout << endl;
    }
    return 0;
} */

/* // @date: 2022-11-27 14:15:10
// @brief: 猴子吃桃问题
#include <iostream>
using namespace std;
int main() {
    int cnt = 0;
    int sum = 1;
    while (cnt < 10) {
        sum = (sum + 1) * 2;
        cnt++;
    }
    cout << sum << endl;

    return 0;
} */
/*
// @date: 2022-11-27 14:14:56
// @brief: 自由落体问题
#include <iostream>
using namespace std;
int main() {
    double h = 100;
    int sum = 0;
    int cnt = 0;
    while (cnt < 10) {
        sum += h * ((cnt == 0) ? 1 : 2);
        h /= 2;
        cnt++;
    }
    cout << sum << endl;
    cout << h << endl;

    return 0;
}
 */
/* #include <iostream>

#include "../head/BigInteger.h"
using namespace std;
int main() {
    BigInteger a;
    cout << a << endl;

    return 0;
} */

/* // @date: 2022-11-27 13:07:34
// @brief: 正整数分解
// @date: 2022-11-27 13:08:18
// @brief: 筛出1-n的质因子数
// 第一中方法 直接暴力求解
#define MAXN 10000001
int p[MAXN];
int cnt = 0;
bool prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= (int)sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
void f1(int n) {
    cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (prime(i)) {
            p[cnt++] = i;
        }
    }
}
// @date: 2022-11-27 13:22:22
// @brief: 埃氏筛 筛出素数   O(nlogn)
bool vis[MAXN];
void f2(int num) {
    for (int i = 2; i <= num; i++) {
        if (!vis[i]) {
            p[cnt++] = i;
            for (int j = i; j <= num; j += i) {
                vis[j] = true;
            }
        }
    }
}
// @date: 2022-11-27 13:36:00
// @brief: 线性筛   O(n)
void f3(int num) {
    for (int i = 2; i <= num; i++) {
        if (!vis[i]) {
            p[cnt++] = i;
            for (int j = 0; j <= cnt && p[j] * i < MAXN; j++) {
                vis[p[j] * i] = true;
            }
        }
    }
}

// @date: 2022-11-27 13:11:44
// @brief: 将一个数字分解为多个数字的质因数和
vector<int> v;
void solve(int num) {
    // f1(num);
    f2(num);
    v.clear();
    int i = 0;
    while (num > 1 && i < cnt) {
        while (num % p[i] == 0) {
            v.push_back(p[i]);
            num /= p[i];
        }
        i++;
    }
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
int main() {
    solve(100);
    for (auto it = 0; it < cnt; it++) {
        cout << p[it] << " ";
    }
    cout << endl;

    return 0;
} */

/*
// @date: 2022-11-26 17:06:12
// @brief: 输出指定范围的水仙花数
#include<iostream>
using namespace std;
int f2(int i) {
    return i*i*i;
}
int f(int n) {
    int ans=f2(n/100) + f2((n/10) %10) + f2(n%10);
    return ans;
}
int main() {
    int a, b;
    while(cin>>a>>b && b!=0) {
        int flag=false;
        for(int i=a; i<=b; i++) {
            if(i==f(i)) {
                cout<<i<<" ";
                flag=true;
            }
        }
        if(!flag) {
            cout<<"no";
        }
        cout<<endl;
    }


    return 0;
}
 */
// #include <cctype>
// #include <iostream>
// using namespace std;
// double f(int n) {
//     double ans = 1.0;
//     for (int i = 1; i <= n; i++) {
//         ans *= i;
//     }
//     return ans;
// }
// int main() {
//     /*     int x, y, z;
//         cin >> x >> y >> z;
//         if(x<y) {
//             swap(x, y);
//         }
//         if(x<z) {
//             swap(x, z);
//         }
//         if(y<z) {
//             swap(y, z);
//         }
//         cout << x<<" " << y<<" " << z << endl; */
//     /*  for (int i = 1; i <= 9; i++) {
//          for (int j = 1; j <= i; j++) {
//              cout << i << "*" << j << "=" << i * j << " ";
//          }
//          cout << endl;
//      } */
//     /*     int score;
//         cin >> score;
//         if (score >= 90) {
//             cout << "A" << endl;
//         } else if (score >= 60) {
//             cout << "B" << endl;
//         } else {
//             cout << "C" << endl;
//         } */
//     /*     string s;
//         cin >> s;
//         int num = 0, alpha = 0, other = 0;
//         for (int i = 0; i < s .length(); i++) {
//             if (isdigit(s[i])) {
//                 num++;
//             } else if (isalpha(s[i])) {
//                 alpha++;
//             } else {
//                 other++;
//             }
//         }
//         cout << num << " " << alpha << " " << other << endl; */
//     /*     int x, y, z;
//         cin >> x >> y >> z;
//         if (x < y) {
//             swap(x, y);
//         }
//         if (x < z) {
//             swap(x, z);
//         }
//         if (y < z) {
//             swap(y, z);
//         }
//         cout << x << " " << y << " " << z << endl;
//         if (x + y <= z) {
//             cout << "No!" << endl;
//         } else if (x == y && y == z) {
//             cout << "等边三角形" << endl;
//         } else if (x == y || x == z || y == z) {
//             cout << "等腰三角形" << endl;
//         } else if (x * x == y * y + z * z) {
//             cout << "等边三角形" << endl;
//         } else {
//             cout << "普通三角形" << endl;
//         } */
// /*
//     double ans = 1.0;
//     int n = 1;
//     do {
//         double p = 1.0 / f(n);
//         if (p < 1e-10) {
//             break;
//         }
//         n++;
//         ans += p;
//     } while (1);
//     cout << ans << endl; */

//     return 0;
// }

/*
// @date: 2022-11-26 16:04:37
// @brief: 判断八皇后
#include <cmath>
#include <iostream>
using namespace std;
int a[10002];
bool check(int a[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(a[i]==a[j] || abs(a[i]-a[j])==abs(i-j)) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        if(check(a, n)) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }




    return 0;
}
 */

/*
// @date: 2022-11-26 15:20:11
// @brief: 最长上升子序列
#include<iostream>
using namespace std;
int dp[1002];
int n;
int a[1003];
int main() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }
    int ans=-1;
    for(int i=1; i<=n; i++) {
        dp[i] = 1;
        for(int j=1; j<=i; j++) {
            if(a[i]>a[j]) {
                dp[i]=max(dp[i], dp[j]+1);
            }
        }
        ans=max(ans, dp[i]);
    }

    cout<<ans<<endl;
    return 0;
} */
/*
// @date: 2022-11-26 15:11:21
// @brief: 花了好久才算看着别人的代码一点点调试出来了
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// @date: 2022-11-26 14:23:07
// @brief: 最长公共子序列
#define N 5005
#define MOD 100000000
// @date: 2022-11-26 15:02:39
// @brief: 使用滚动数组 压缩空间
int dp[2][N];
int cnt[2][N];
int n, m;
int t = 0;
string a, b;

int main() {
    cin >> a >> b;
    n = a.length() - 1;
    m = b.length() - 1;
    a = " " + a;  // 0下表不使用
    b = " " + b;
    //初始化方案数
    for (int i = 0; i <= m; i++) {
        cnt[0][i] = 1;
    }
    cnt[1][0] = 1;

    for (int i = 1; i <= n; i++, t ^= 1) {
        for (int j = 1; j <= m; j++) {
            cnt[t ^ 1][j] = 0;
            if (a[i] == b[j]) {
                dp[t ^ 1][j] = dp[t][j - 1] + 1;
                cnt[t ^ 1][j] += cnt[t][j - 1];
            } else {
                dp[t ^ 1][j] = max(dp[t][j], dp[t ^ 1][j - 1]);
            }
            if (dp[t ^ 1][j] == dp[t][j]) {
                cnt[t ^ 1][j] += cnt[t][j];
            }
            if (dp[t ^ 1][j] == dp[t ^ 1][j - 1]) {
                cnt[t ^ 1][j] += cnt[t ^ 1][j - 1];
            }
            if (dp[t ^ 1][j] == dp[t][j - 1]) {
                cnt[t ^ 1][j] -= cnt[t][j - 1];
            }
            cnt[t ^ 1][j] = cnt[t ^ 1][j] % MOD;
        }
    }
    cout << dp[t][m] << endl;
    cout << cnt[t][m] << endl;

    return 0;
} */

/* #include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// @date: 2022-11-26 14:23:07
// @brief: 最长公共子序列
#define N 5005
#define MOD 100000000
int dp[N][N];
int cnt[N][N];
int n, m;
string a, b;

int main() {
    cin >> a >> b;
    n = a.length() - 1;
    m = b.length() - 1;
    a = " " + a;  // 0下表不使用
    b = " " + b;
    //初始化方案数
    for (int i = 0; i <= 5000; i++) {
        cnt[0][i] = 1;
    }
    for (int i = 0; i <= 5000; i++) {
        cnt[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                cnt[i][j] += cnt[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            if (dp[i][j] == dp[i - 1][j]) {
                cnt[i][j] += cnt[i - 1][j];
            }
            if (dp[i][j] == dp[i][j - 1]) {
                cnt[i][j] += cnt[i][j - 1];
            }
            if (dp[i][j] == dp[i - 1][j - 1]) {
                cnt[i][j] -= cnt[i - 1][j - 1];
            }
            cnt[i][j] = cnt[i][j] % MOD;
        }
    }
    cout << dp[n][m] << endl;
    cout << cnt[n][m] << endl;

    return 0;
} */

/* // @date: 2022-11-26 13:41:57
// @brief: 利用快速排序的思想寻找数组中第k小的元素
#define MAXINT 0x7f7f7f7f
int getKthValue_(int data[], int n, int k, int low, int high) {
    int tmp = data[low];
    int l = low;
    int r = high;
    while (l < r) {
        while (l < r && data[r] > tmp) {
            r--;
        }
        data[l] = data[r];
        while (l < r && data[l] <= tmp) {
            l++;
        }
        data[r] = data[l];
    }
    data[l] = tmp;
    // cout << "----------------" << endl;
    // for(int i=0; i<n; i++) {
    //     cout << data[i] << " ";
    // }
    // cout << endl;
    if (l == (k - 1)) {
        return data[l];
    } else if (l < (k - 1)) {
        // @brief: 这里的l+1 \ l-1 要注意
        return getKthValue_(data, n, k, l + 1, high);
    } else {
        return getKthValue_(data, n, k, low, l - 1);
    }
}
/// @brief 主程序
/// @param data 数组
/// @param n 数组的大小         0 ~ n-1
/// @param k 要寻找的第k小的元素        1~n
/// @return 第k小的元素
int getKthValue(int data[], int n, int k) {
    if (k <= 0 || k > n) {
        return -MAXINT;
    }
    return getKthValue_(data, n, k, 0, n - 1);
}
int main() {
    int data[100020];
    int n;
    int k;
    cin >> n;
    unordered_map<int, bool> mp;
    int cnt = 0;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (mp[x] == false) {
            data[cnt++] = x;
            mp[x] = true;
        }
    }
    cin >> k;
    cout << getKthValue(data, cnt, k);

    return 0;
} */

/*
// @date: 2022-11-19 22:27:04
// @brief: 搞成蛇形输出了
class Solution {
public:
    #define debug(x) cout << #x << " = " << x << endl
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ans;
        // ans.reserve(10000);
        int sum=matrix.size() * matrix[0].size();
        int cnt=0;
        int i=0, j=0;
        int left, right, up, down;
        left=0;
        up=0;
        right=matrix[0].size()-1;
        down=matrix.size()-1;
        int x=1;    //控制x轴走向       横向
        int y=1;    //控制y轴走向       竖向
        while(cnt<sum) {
            ans.push_back(matrix[i][j]);
            cnt++;
            j+=x;
            if(j>right || j<0) {
                x*=-1;
                j+=x;
                i+=y;
                if(i>down || i<0) {
                    y*=-1;
                    i+=y;
                }
            }
        }
        return ans;
    }
};
 */

/*
class Solution {
public:
    bool Judge(TreeNode *p1, TreeNode * p2) {
        if(p1==NULL && p2==NULL) {
            return true;
        }
        else if(p1!=NULL && p2!=NULL && p1->val == p2->val) {
            return Judge(p1->left, p2->right) && Judge(p1->right, p2->left);
        }
        else {
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        return Judge(root, root);
    }
};
*/

/*
// @date: 2022-11-18 22:32:24
// @brief: 二叉树的镜像
class Solution {
public:
    void mirror(TreeNode* root) {
        if(root==NULL) {
            return ;
        }
        else {
            mirror(root->left);
            mirror(root->right);
            TreeNode* tmp=root->left;
            root->left=root->right;
            root->right=tmp;
        }
    }
};
*/

/*
// @date: 2022-11-18 22:29:40
// @brief: 树的子结构
class Solution {
public:
    #define debug(x) cout<<#x<<"="<<x<<endl
    queue<TreeNode *> Q;
    void Traverse(TreeNode *p1, int val) {
        if(p1==NULL) {
            return ;
        }
        else if(p1->val==val) {
            Q.push(p1);
        }
        Traverse(p1->left, val);
        Traverse(p1->right, val);
    }
    bool Judge(TreeNode *p1, TreeNode *p2) {
        // @date: 2022-11-18 22:30:36
        // @brief: 这里的判断条件要十分注意，有两个判断为true
        if(p1==NULL && p2==NULL) {
            return true;
        }
        else if(p1!=NULL && p2==NULL) {
            return true;
        }
        else if(p1!=NULL && p2!=NULL && p1->val == p2->val) {
            // debug(p1->val);
            // debug(p2->val);
            return Judge(p1->left, p2->left) && Judge(p1->right, p2->right);
        }
        else return false;
    }
    bool hasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(pRoot2==NULL) return false;
        Traverse(pRoot1, pRoot2->val);
        while(!Q.empty()) {
            // cout<<"-----------"<<endl;
            TreeNode *p=Q.front();
            Q.pop();
            bool flag=Judge(p, pRoot2);
            if(flag) {
                return true;
            }
        }
        return false;
    }
};
 */

/*
// @date: 2022-11-17 22:48:53
// @brief: 数值的整数次方
// @date: 2022-11-17 22:50:52
// @brief: 用优化后的快速幂写了一下
class Solution {
public:
    #define ll long long
    double Power(double base, int exponent) {
        ll pow_=exponent;
        int flag=(pow_<0? 1:0);
        pow_=abs(pow_);
        double ans=1.0;
        while(pow_) {
            if(pow_ & 1) {
                ans*=base;
            }
            base*=base;
            pow_>>=1;
        }

        if(flag) {
            ans=1.0/ans;
        }
        return ans;
    }
};


class Solution {
public:
    #define ll long long
    double Power(double base, int exponent) {
        ll pow_=exponent;
        int flag=(pow_<0? 1:0);
        pow_=abs(pow_);
        double ans=1.0;
        while(pow_) {
            if(pow_%2==0) {
                base*=base;
                pow_/=2;
            }
            else {
                pow_--;
                ans*=base;
                base*=base;
                pow_/=2;
            }
        }

        if(flag) {
            ans=1.0/ans;
        }
        return ans;
    }
};
 */
/*
// @date: 2022-11-16 22:55:44
// @brief: 二进制中1的个数
class Solution {
public:

    int NumberOf1(int n) {
        int cnt=0;
        for(int i=0; i<32; i++) {
            cnt+=(n>>i & 1);
        }
        return cnt;
    }
};
 */
/*
// @date: 2022-11-15 22:23:00
// @brief: 调整奇数和偶数的区别
class Solution {
public:
    void reOrderArray(vector<int> &array) {
         int i=0;
         int j=array.size();
         while(i<j) {
             while(i<j && array[i]%2!=0) {
                 i++;
             }
             while(i<j && array[j]%2==0) {
                 j--;
             }
             swap(array[i], array[j]);
             i++;
             j--;
         }
    }
};
 */
/*
// @date: 2022-11-13 22:47:30
// @brief: 合并链表
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode(-1);
        ListNode *i=head;
        ListNode*p=l1, *q=l2;
        while(p && q) {
            if(p->val<q->val) {
                i->next=p;
                i=p;
                p=p->next;
            }
            else {
                i->next=q;
                i=q;
                q=q->next;
            }
        }
        while(p) {
            i->next=p;
            i=p;
            p=p->next;
        }
        while(q) {
            i->next=q;
            i=q;
            q=q->next;
        }
        return head->next;
    }
};
 */

/*
// @date: 2022-11-13 22:43:07
// @brief: 反转链表递归
class Solution {
public:
    ListNode* reverse(ListNode* pre, ListNode* p) {
        if(p==NULL) return pre;
        ListNode* r=p->next;
        p->next=pre;
        return reverse(p, r);
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(NULL, head);
    }
};
 */

/*
// @date: 2022-11-13 22:33:22
// @brief: 反转链表 非递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) {
            return head;
        }
        //
        ListNode *pre=NULL;
        ListNode *p=head;
        ListNode* r=p->next;
        while(p) {
            p->next=pre;
            pre=p;
            p=r;
            if(r) {
                r=r->next;
            }
        }
        return pre;
    }
}; */
/* // @date: 2022-11-12 22:42:54
// @brief: 剪绳子
class Solution {
   public:
#define debug(x) cout << #x << "=" << x << endl
    int maxProductAfterCutting(int length) {
        if (length <= 3) {
            return 1 * (length - 1);
        }
        int ans = 1;
        // @date: 2022-11-12 22:53:41
        // @brief: 这道题目的关键在于要用3来乘，剩下的较小的要单独处理
        while (length > 4) {
            ans *= 3;
            length -= 3;
        }
        ans *= length;

        return ans;
    }
}; */

/* // @date: 2022-11-11 22:55:45
// @brief: 24. 机器人的运动范围 BFS版本
class Solution {
   private:
    int k, cols, rows;
    bool vis[1000][1000];

   public:
#define pii pair<int, int>
#define mk make_pair
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
    int bfs() {
        // @date: 2022-11-12 22:40:56
        // @brief: 特殊情况 特殊判断
        if (!cols || !rows) {
            return 0;
        }
        int a[] = {1, -1, 0, 0};
        int b[] = {0, 0, 1, -1};
        queue<pii> Q;
        int ans = 0;
        Q.push({0, 0});
        vis[0][0] = true;
        ans++;// 别忘了这里
        while (!Q.empty()) {
            pii p = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int x = p.first + a[i];
                int y = p.second + b[i];
                // @date: 2022-11-12 22:41:28
                // @brief: 每次入队的总是合理的数据
                if (x >= 0 && x < rows && y >= 0 && y < cols && !vis[x][y] && f(x, y) <= k) {
                    Q.push({x, y});
                    vis[x][y] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
    int movingCount(int threshold, int rows, int cols) {
        k = threshold;
        this->cols = cols;
        this->rows = rows;

        return bfs();
    }
};
 */
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
/* // @date: 2022-11-03 17:43:02
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
}; */
/* // @date: 2022-11-03 15:10:36
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
}; */
/* class Solution23 {
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
}; */
/* // @date: 2022-11-03 14:54:13
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
}; */
/* // @date: 2022-11-03 14:46:52
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
}; */
/* // @date: 2022-11-03 14:40:04
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
    MyQueue() {
    }

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

    bool empty() {
        if (S1.isEmpty() && S2.isEmpty()) {
            return true;
        } else
            return false;
    }
};
 */
/* // @date: 2022-11-03 14:10:12
// @brief: 19. 二叉树的下一个节点
void solve12() {
    //   Definition for a binary tree node.
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode* father;
        TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
    };

    class Solution {
       public:
        TreeNode* inorderSuccessor(TreeNode* p) {
            if (p->right != NULL) {
                p = p->right;
                while (p->left) {
                    p = p->left;
                }
            } else {
                TreeNode* fa = p;
                while (p) {
                    fa = p->father;
                    if (fa == NULL) {
                        p = NULL;
                        break;
                    } else if (fa->left == p) {
                        p = fa;
                        break;
                    } else {
                        p = fa;
                        fa = fa->father;
                    }
                }
            }
            return p;
        }
    };
}
 */
/* // @date: 2022-11-02 13:58:00
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
 */
/* // @date: 2022-11-01 13:37:48
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
    //
    // si=−1 表示第 i 种物品只能用1次
    // si=0 表示第 i 种物品可以用无限次
    // si>0 表示第 i 种物品可以使用 si 次
    //
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
} */

/* // @date: 2022-11-01 13:26:05
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
} */

/* // @date: 2022-11-01 13:11:36
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
} */

/* // @date: 2022-11-01 13:07:35
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
} */

/* // @date: 2022-11-01 12:58:59
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
} */

/* // @date: 2022-10-31 16:33:29
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
} */

/* // @date: 2022-10-31 15:55:33
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
} */

/* // @date: 2022-10-31 15:51:26
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
} */

/* // @date: 2022-10-30 15:45:46
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
} */

/* // @date: 2022-10-30 15:44:08
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
} */

/* // @date: 2022-10-30 15:24:02
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
 */
