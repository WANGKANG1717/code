/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: huffmanTree.h
 * @filepath: head\huffmanTree.h
 * @date: 2022-11-29 16:15:54
 * @description: HuffmanTree
 */
#ifndef __HUFFMANTREE_H__
#define __HUFFMANTREE_H__
#include <stddef.h>  //NULL 所在头文件
/*
自定义优先队列的排序方式 有两种
优先队列默认是大根堆 也就是根据优先级从大到小
less    小根堆 a<b
greater 大根堆 a>b
第一种：重载operator<();
第二种：
    声明：priority_queue<struct/class,vector<struct/class>,cmp>
    定义：struct cmp {
            bool operator() (struct/class a, struct/class b)
            //a>b是小根堆， a<b是大根堆
        }
第三种：内置数据类型可以直接使用
        priority_queue<struct/class,vector<struct/class>,less<struct/class>  /  greater<struct/class>>
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
class TreeNode {
   public:
    int weight;
    char data;
    TreeNode *left, *right;

    TreeNode() : left(NULL), right(NULL) {}
    TreeNode(int weight, char data, TreeNode* left = NULL, TreeNode* right = NULL) : weight(weight), data(data), left(left), right(right) {}
    ~TreeNode() {}
    bool operator<(const TreeNode& b) {
        return weight < b.weight;
    }
};
class cmp {
   public:
    bool operator()(const TreeNode* a, const TreeNode* b) const {
        return a->weight > b->weight;
    }
};

class HuffmanTree {
   private:
    TreeNode* root;
    map<char, vector<int>> HuffmanCode;

   public:
    HuffmanTree() {
        root = NULL;
    }
    HuffmanTree(int a[], char b[], int n) {
        root = build(a, b, n);
    };
    TreeNode* build(int a[], char b[], int n) {
        if (n == 0 || n < 0) {
            return NULL;
        }
        priority_queue<TreeNode*, vector<TreeNode*>, cmp> q;
        // priority_queue<TreeNode*> q;     //神奇这种重载方式竟然用不了
        for (int i = 0; i < n; i++) {
            q.push(new TreeNode(a[i], b[i]));
        }
        while (q.size() > 1) {
            TreeNode* lc = q.top();
            q.pop();
            TreeNode* rc = q.top();
            q.pop();
            TreeNode* root = new TreeNode(lc->weight + rc->weight, '*', lc, rc);
            q.push(root);
        }
        return q.top();
    }

    void preOrder() {
        cout << "preOrder" << endl;
        preOrder_(root);
    }
    void preOrder_(TreeNode* T) {
        if (!T) return;
        cout << "<" << T->data << "-" << T->weight << "> ";
        preOrder_(T->left);
        preOrder_(T->right);
    }
    void getHuffmanCode() {
        vector<int> tmp;
        getCode(root, tmp);
    }
    void getCode(TreeNode* T, vector<int>& code) {
        if (T == NULL) return;
        if (T->left == NULL && T->right == NULL) {
            HuffmanCode[T->data] = code;
            return;
        }
        if (T->left != NULL) {
            code.push_back(0);
            getCode(T->left, code);
            code.pop_back();
        }
        if (T->right != NULL) {
            code.push_back(1);
            getCode(T->right, code);
            code.pop_back();
        }
    }
    void printHuffmanCode() {
        for (auto it = HuffmanCode.begin(); it != HuffmanCode.end(); it++) {
            cout << it->first << ":";
            for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
                cout << *it2;
            }
            cout << endl;
        }
    }
};
// @date: 2022-11-29 18:28:03
// @brief: 顺序存储结构实现哈夫曼树
struct Node {
    int weight;
    char tag;
    int parent, lchild, rchild;
    int pos;  //为了方便的建树，不得已又加了一个下标
    friend ostream& operator<<(ostream& out, const Node& a) {
        out << a.weight << " " << a.tag << " " << a.parent << " " << a.lchild << " " << a.rchild << " " << a.pos;
        return out;
    }
};

struct cmp2 {
    bool operator()(const Node& a, const Node& b) {
        return a.weight > b.weight;
    }
};

class HuffmanTreeSq {
   public:
    Node* data;
    map<char, vector<int>> HuffmanCode;
    int n;
    HuffmanTreeSq(int a[], char b[], int n) {
        // @date: 2022-11-29 18:38:34
        // @brief: n个节点 建成的哈夫曼树有2*n-1个节点
        data = new Node[2 * n - 1];
        for (int i = 0; i < n; i++) {
            data[i] = {a[i], b[i], -1, -1, -1, i};
        }
        this->n = n;
        getHuffmanTree();
    }
    void getHuffmanTree() {
        //仍然是使用优先队列来试下 O(logn) 的查找优先值
        priority_queue<Node, vector<Node>, cmp2> q;
        for (int i = 0; i < n; i++) {
            q.push(data[i]);
        }
        for (int i = n; i < 2 * n - 1; i++) {
            Node lc = q.top();
            q.pop();
            Node rc = q.top();
            q.pop();
            data[lc.pos].parent = i;
            data[rc.pos].parent = i;
            data[i] = {lc.weight + rc.weight, '*', -1, lc.pos, rc.pos, i};
            q.push(data[i]);
        }
    }
    void getHuffmanCode() {
        vector<int> tmp;
        tmp.clear();
        for (int i = 0; i < n; i++) {
            int p = data[i].parent;
            // pre不要忘记
            int pre = i;
            while (p != -1) {
                if (data[p].lchild == pre) {
                    tmp.push_back(0);
                } else {
                    tmp.push_back(1);
                }
                pre = p;
                p = data[p].parent;
            }
            //记得逆转一下
            reverse(tmp.begin(), tmp.end());
            HuffmanCode[data[i].tag] = tmp;
            tmp.clear();
        }
    }
    void printHuffmanTree() {
        for (int i = 0; i < 2 * n - 1; i++) {
            cout << data[i] << endl;
        }
    }
    void printHuffmanCode() {
        for (auto it = HuffmanCode.begin(); it != HuffmanCode.end(); it++) {
            cout << it->first << ":";
            for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
                cout << *it2;
            }
            cout << endl;
        }
    }
};

#endif
