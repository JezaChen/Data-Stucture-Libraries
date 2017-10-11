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

        bool operator < (const HuffTree<E> other) {return weight() < other.weight(); }
        bool operator > (const HuffTree<E> other) {return weight() > other.weight(); }
    };

    template<typename E>
    HuffTree<E>*
    buildHuffTree(HuffTree<E>** TreeArr, int count)
    {
        PQ* P = new heap<HuffTree<E>*, COMPARE_LESS<E> >(TreeArr, count, count*2);
    }
}
#endif //DSL_HUFFTREE_H
