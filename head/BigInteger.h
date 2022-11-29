/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: BigInteger.h
 * @filepath: cpp\BigInteger.h
 * @date: 2022-11-27 14:04:11
 * @description: 大数类学习
 */

// @date: 2022-11-27 17:17:37
// @brief: 谢邀 一个大数类 我写了三百多行还没写完 真的会谢
// @date: 2022-11-28 16:57:17
// @brief: 写了三四个小时 终于搞定了
#ifndef __BIGINTEGER_H__
#define __BIGINTEGER_H__

#include <cstring>
#include <string>
#include <vector>
#define MAXN 9999
#define MAXSIZE 10
#define DLEN 4
using namespace std;
// @date: 2022-11-27 15:29:40
// @brief: 不考虑冗余的0的情况
class BigInteger {
   public:
    vector<int> num;            // 存储位数
    bool sign;                  // true 负数
    int length;                 // 大数长度         注意 0 的时候length=0 -> num.size()=1
    BigInteger(const int = 0);  //将一个int类型的变量转化为大数
    BigInteger(const char *);
    BigInteger(const string &);      //将一个字符串类型的变量转化为大数
    BigInteger(const BigInteger &);  //拷贝构造函数
    ~BigInteger();

    BigInteger &operator=(const int);
    BigInteger &operator=(const char *);
    BigInteger &operator=(const string &);
    BigInteger &operator=(const BigInteger &);  //重载赋值运算符，大数之间进行赋值运算

    friend istream &operator>>(istream &, const BigInteger &);  //重载输入运算符
    friend ostream &operator<<(ostream &, BigInteger &);        //重载输出运算符

    BigInteger operator+(const BigInteger &) const;
    BigInteger operator-(const BigInteger &) const;
    BigInteger operator*(const BigInteger &) const;
    BigInteger operator/(const int &) const;         // 大数除小数
    BigInteger operator/(const BigInteger &) const;  //大数除大数
    BigInteger operator%(const int &) const;         //大数取余小数
    BigInteger operator%(const BigInteger &) const;  //大数取余大数
    BigInteger operator^(const int &) const;         //大数阶乘

    BigInteger operator-() const;  //负号
    BigInteger operator+() const;  //正号
    bool operator==(const BigInteger &) const;
    bool operator!=(const BigInteger &) const;
    bool operator<(const BigInteger &) const;
    bool operator>(const BigInteger &) const;
    bool operator<=(const BigInteger &) const;
    bool operator>=(const BigInteger &) const;
    // 剪掉前导零
    void cutLeadingZero() {
        while (num.back() == 0 && num.size() != 1) {
            num.pop_back();
        }
    }
    //设置长度
    void setLength() {
        cutLeadingZero();
        if (num.back() == 0) {
            length = 0;
        } else {
            length = num.size();
        }
    }
    BigInteger abs() const {
        BigInteger ans(*this);
        ans.sign = false;
        return ans;
    }

    BigInteger e(int n) const {
        BigInteger ans;
        ans.length = n + 1;
        while (ans.num.size() <= n) {
            ans.num.push_back(0);
        }
        ans.num[n] = 1;
        return ans * (*this);
    }
};

BigInteger::BigInteger(int x) {
    *this = x;
}

BigInteger::BigInteger(const char *x) {
    *this = x;
}

BigInteger::BigInteger(const string &x) {
    *this = x;
}
BigInteger::BigInteger(const BigInteger &x) {
    *this = x;
}

BigInteger::~BigInteger() {
    // std::cout << "~BigInteger" << endl;
}

BigInteger &BigInteger::operator=(int x) {
    num.clear();
    if (x >= 0) {
        sign = false;
    } else {
        sign = true;
        x = -x;
    }
    num.clear();
    do {
        num.push_back(x % 10);
        x /= 10;
    } while (x > 0);
    setLength();
    return *this;
}

BigInteger &BigInteger::operator=(const char *x) {
    num.clear();
    sign = (x[0] == '-') ? true : false;
    for (int i = (strlen(x) - 1); i >= sign; i--) {
        num.push_back(x[i] - '0');
    }
    setLength();
    return *this;
}

BigInteger &BigInteger::operator=(const string &x) {
    num.clear();
    sign = (x[0] == '-') ? true : false;
    // cout << sign << endl;
    // cout << x.length() << endl;
    for (int i = (x.length() - 1); i >= sign; i--) {
        num.push_back(x[i] - '0');
    }
    setLength();
    return *this;
}

BigInteger &BigInteger::operator=(const BigInteger &x) {
    num.clear();
    num = x.num;
    sign = x.sign;
    length = x.length;
    return *this;
}

istream &operator>>(istream &in, BigInteger &x) {
    string s;
    in >> s;
    x = s;
    return in;
}

ostream &operator<<(ostream &out, const BigInteger &x) {
    if (x.sign) {
        out << "-";
    }
    for (auto it = x.num.end() - 1; it >= x.num.begin(); it--) {
        out << *it;
    }
    return out;
}
// @date: 2022-11-27 16:42:03
// @brief: 始终都是正数在加减
BigInteger BigInteger::operator+(const BigInteger &x) const {
    if (x.sign) {
        return *this - (-x);
    }
    if (sign) {
        return x - (-(*this));
    }
    BigInteger ans;
    ans.num.clear();
    int i = 0, k = 0;
    while (1) {
        if (i >= num.size() && i >= x.num.size() && k == 0) {
            break;
        }
        if (i < num.size()) {
            k += num[i];
        }
        if (i < x.num.size()) {
            k += x.num[i];
        }
        ans.num.push_back(k % 10);
        k /= 10;
        i++;
    }
    if (k) {
        ans.num.push_back(k);
        k /= 10;
    }
    ans.setLength();
    return ans;
}

//保证大的减小的，正数相减
BigInteger BigInteger::operator-(const BigInteger &x) const {
    if (x.sign) {
        return *this + (-x);
    }
    if (sign) {
        return -(x + (-(*this)));
    }
    if (*this < x) {
        return -(x - *this);
    }
    BigInteger ans;
    ans.num.clear();
    int i = 0, k = 0;
    while (1) {
        if (i >= num.size() && i >= x.num.size() && k == 0) {
            break;
        }
        if (i < num.size()) {
            k += num[i];
        }
        if (i < x.num.size()) {
            k -= x.num[i];
        }
        int tmp = k;
        k = 0;
        if (tmp < 0) {
            tmp += 10;
            k = -1;
        }
        ans.num.push_back(tmp);
        i++;
    }
    if (k) {
        ans.num.push_back(k);
        k /= 10;
    }
    ans.setLength();
    return ans;
}
// 负号
BigInteger BigInteger::operator-() const {
    BigInteger ans(*this);
    BigInteger zero;
    if (ans != zero)
        ans.sign = !ans.sign;
    return ans;
}
//正号
BigInteger BigInteger::operator+() const {
    return *this;
}
BigInteger BigInteger::operator*(const BigInteger &x) const {
    vector<int> v;
    for (int i = 0; i < (length + x.length); i++) {
        v.push_back(0);
    }
    // 对应位相乘放在合适的位置，以待进一步进位
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < x.length; j++) {
            v[i + j] += num[i] * x.num[j];  //这里是+=号偶 还好去OJ上判了下
        }
    }
    // 退位
    while (v.back() == 0 && v.size() != 1) {
        v.pop_back();
    }
    //
    BigInteger ans;
    ans.num.clear();
    ans.sign = !((v.size() == 1 && v[0] == 0) /* 说明是零 */ ||
                 (sign == x.sign) /* 符号相同为正数 */);
    int tmp = 0;
    for (int i = 0; i < v.size(); i++) {
        ans.num.push_back((v[i] + tmp) % 10);
        tmp = (tmp + v[i]) / 10;
    }
    if (tmp) {
        ans.num.push_back(tmp);
    }
    ans.setLength();
    return ans;
}
BigInteger BigInteger::operator/(const int &s) const {
    int x = s;
    BigInteger ans;
    ans.num.clear();
    ans.sign = !((*this == 0) || ((sign && x < 0) || (!sign && x > 0)));
    if (x < 0) x = -x;  // 注意这里
    for (int i = 0; i < num.size(); i++) {
        ans.num.push_back(0);
    }
    int tmp = 0;
    for (int i = num.size() - 1; i >= 0; i--) {
        ans.num[i] = int((tmp * 10 + num[i]) / x);
        tmp = (tmp * 10 + num[i]) % x;
    }
    ans.setLength();
    return ans;
}
BigInteger BigInteger::operator/(const BigInteger &x) const {
    BigInteger a = ((*this).abs());
    BigInteger b = (x.abs());
    if (a < b) {
        return 0;
    }
    BigInteger ans, tmp;
    ans.num.clear();
    int lena = num.size();
    int lenb = x.num.size();
    char *str = new char[lena + 1];
    memset(str, 0, sizeof(char) * (lena + 1));

    for (int i = 0; i <= lena - lenb; i++) {
        tmp = b.e(lena - lenb - i);
        while (a >= tmp) {
            ++str[i];
            a = a - tmp;
        }
        str[i] += '0';
    }
    ans = str;
    delete[] str;
    ans.sign = !(ans == 0 || sign == b.sign);
    return ans;
}
BigInteger BigInteger::operator%(const BigInteger &x) const {
    return *this - (*this / x) * x;
}
BigInteger BigInteger::operator%(const int &x) const {
    long long ans = 0;  // 这里要用longlong 不然会爆int
    for (int i = num.size() - 1; i >= 0; i--) {
        ans = (ans * 10 + num[i]) % x;
    }
    return ans;
}
BigInteger BigInteger::operator^(const int &x) const {
    // @date: 2022-11-28 16:39:37
    // @brief: 快速幂
    BigInteger ans = 1, base = *this;
    int n = x;
    while (n) {
        if (n & 1) {
            ans = ans * base;
        }
        base = base * base;
        n >>= 1;
    }
    return ans;
}
bool BigInteger::operator==(const BigInteger &x) const {
    if (sign != x.sign || length != x.length) {
        return false;
    }
    for (int i = 0; i < length; i++) {
        if (num[i] != x.num[i]) {
            return false;
        }
    }
    return true;
}
bool BigInteger::operator!=(const BigInteger &x) const {
    return !(*this == x);
}
bool BigInteger::operator<(const BigInteger &x) const {
    if (!sign && x.sign) {  //正负
        return false;
    } else if (sign && !x.sign) {  //负正
        return true;
    } else if (sign && x.sign) {  //负负
        return -x < -*this;
    }
    //正正
    if (num.size() != x.num.size()) {
        return num.size() < x.num.size();
    }
    for (int i = num.size() - 1; i >= 0; i--) {
        if (num[i] != x.num[i]) {
            return num[i] < x.num[i];
        }
    }
    return false;
}
bool BigInteger::operator>(const BigInteger &x) const {
    return x < *this;
}

bool BigInteger::operator<=(const BigInteger &x) const {
    return !(*this > x);
}
bool BigInteger::operator>=(const BigInteger &x) const {
    return !(*this < x);
}
#endif
