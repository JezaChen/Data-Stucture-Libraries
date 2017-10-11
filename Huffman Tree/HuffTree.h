//
// Created by jeza on 17-10-11.
//
#pragma once

#ifndef DSL_HUFFTREE_H
#define DSL_HUFFTREE_H

#include "HuffNode.h"
#include "../Priority Queue/Heap.h"
#include "../Common/Share.h"

namespace DSLibrary
{
    template<typename E>
    class HuffTree
    {
    private:
        HuffNode<E>* _root;
    public:
        HuffTree(const E& val, int frequency)
        {
            _root = new HuffLeafNode<E> (val, frequency);
        }
        HuffTree(HuffTree<E>* l, HuffTree<E> *r)
        {
            _root = new HuffIntlNode<E> (l->_root,r->_root);
        }
        ~HuffTree() {}
        HuffNode<E>* root() {return _root;}
        int weight() const {return _root->weight();}

        //必须重载运算符才行! 比较器需要用到比较符号
        bool operator < (const HuffTree<E> other) {return weight() < other.weight(); }
        bool operator > (const HuffTree<E> other) {return weight() > other.weight(); }
        bool operator = (const HuffTree<E> other) {return weight() == other.weight(); }
    };

    template<typename E>
    HuffTree<E>*
    buildHuffTree(HuffTree<E>** TreeArr, int count)
    {
        PQ* froest = new heap<HuffTree<E>*, COMPARE_LESS<E> >(TreeArr, count, count*2);
        HuffTree<char> *temp1, *temp2, *temp3 = NULL;
        while (froest->size() > 1)
        {
            temp1 = froest->delFirst();
            temp2 = froest->delFirst();
            temp3 = new HuffTree(temp1, temp2);
            froest->insert(temp3);
            release(temp1);
            release(temp2);
        }
        return temp3; //返回最后生成的树根
    }
}
#endif //DSL_HUFFTREE_H
