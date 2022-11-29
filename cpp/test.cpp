/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: test.cpp
 * @filepath: cpp\test.cpp
 * @date: 2022-11-29 16:19:32
 * @description: 测试用
 */
#include <iostream>
#include <queue>

#include "../head/HuffmanTree.h"
using namespace std;
int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char b[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    HuffmanTreeSq tree(a, b, 5);
    tree.printHuffmanTree();
    tree.getHuffmanCode();
    tree.printHuffmanCode();
    HuffmanTree tree2(a, b, 10);
    // tree2.preOrder();
    // cout << endl;
    // tree2.getHuffmanCode();
    // tree2.printHuffmanCode();
    // queue<int> Q;
    // priority_queue<int> Q;

    return 0;
}
