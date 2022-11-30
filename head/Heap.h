/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: Heap.h
 * @filepath: head\Heap.h
 * @date: 2022-11-29 16:49:56
 * @description: Heap
 */

#ifndef __HEAP_H__
#define __HEAP_H__
#include <iostream>
using namespace std;
// @date: 2022-11-30 16:34:42
// @brief: 依然是我一贯的风格 0下标使用 不浪费一点空间
/*
堆的筛和插入有两种实现方式 一种是递归实现 一种是循环实现
 */
// @date: 2022-11-30 16:38:57
// @brief: 默认大根堆
/*
这里可以玩的更花一点，但是没必要 ，放弃了，，忍痛。。
 */
class Heap {
#define MAXSIZE 1000001
   private:
    int* data;
    int n;

   public:
    Heap(int a[], int n) {
        data = new int[MAXSIZE];
        for (int i = 0; i < n; i++) {
            data[i] = a[i];
        }
        this->n = n;
    }
    ~Heap() {
        delete[] data;
    }
    void buildHeap() {
        for (int i = parent(n); i >= 0; i--) {
            siftDown(i);
        }
    }
    void insertHeap(int x) {
        // @date: 2022-11-30 17:59:27
        // @brief: 尴尬的事情来了， 想动态的申请空间，发现竟然会出现莫名奇妙的错误，只得固定申请空间了
        // 最后一个元素是n-1
        data[n++] = x;
        int p = n - 1;
        while (p > 0 && data[parent(p)] < x) {
            data[p] = data[parent(p)];
            p = parent(p);
        }
        data[p] = x;
    }
    void siftDown(int i) {
        int x = data[i];
        int p;
        for (p = lchild(i); p < n; p = lchild(p)) {
            if (p + 1 < n && data[p + 1] > data[p]) p++;
            if (x > data[p]) break;
            data[parent(p)] = data[p];
        }
        // 这里是parent
        data[parent(p)] = x;
    }
    int parent(int i) {
        return (i - 1) / 2;
    }
    int lchild(int i) {
        return i * 2 + 1;
    }
    int rchild(int i) {
        return i * 2 + 2;
    }
    friend ostream& operator<<(ostream& out, const Heap& heap) {
        heap.printHeap();
        return out;
    }
    void printHeap() const {
        cout << "---------Heap-----------" << endl;
        for (int i = 0; i < n; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
        cout << "-------------------" << endl;
    }
};

#endif
