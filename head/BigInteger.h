/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: BigInteger.h
 * @filepath: cpp\BigInteger.h
 * @date: 2022-11-27 14:04:11
 * @description: 大数类学习
 */
https :  // blog.csdn.net/vsooda/article/details/8543351
#ifndef __BIGINTEGER_H__
#define __BIGINTEGER_H__

#include <vector>
#define MAXN 9999
#define MAXSIZE 10
#define DLEN 4

         class BigInteger {
   private:
    vector<int> num;  // 存储位数
    bool sign;        // true 负数
    int length;       // 大数长度
   public:
    BigInteger();                               //默认构造函数
    BigInteger(const int);                      //将一个int类型的变量转化为大数
    BigInteger(const char *);                   //将一个字符串类型的变量转化为大数
    BigInteger(const BigInteger &);             //拷贝构造函数
    BigInteger &operator=(const BigInteger &);  //重载赋值运算符，大数之间进行赋值运算

    friend istream &operator>>(istream &, BigInteger &);  //重载输入运算符
    friend ostream &operator<<(ostream &, BigInteger &);  //重载输出运算符

    BigInteger operator+(const BigInteger &) const;  //重载加法运算符，两个大数之间的相加运算
    BigInteger operator-(const BigInteger &) const;  //重载减法运算符，两个大数之间的相减运算
    BigInteger operator*(const BigInteger &) const;  //重载乘法运算符，两个大数之间的相乘运算
    BigInteger operator/(const int &) const;         //重载除法运算符，大数对一个整数进行相除运算

    BigInteger operator^(const int &) const;    //大数的n次方运算
    int operator%(const int &) const;           //大数对一个int类型的变量进行取模运算
    bool operator>(const BigInteger &T) const;  //大数和另一个大数的大小比较
    bool operator>(const int &t) const;         //大数和一个int类型的变量的大小比较
};

BigInteger::BigInteger() {
    num.clear();
    num.push_back(0);
}

#endif
